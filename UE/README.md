# oaisetup in full virtualized environment
Consists of three steps; (a) gNodeb (b)core and (c) UE preparations

## gNodeb Setup
### Download https://releases.ubuntu.com/16.04/  64bit
### Create VM with the image
### Inside VM install openssh server, git
```
sudo apt update; sudo apt install openssh-server git cmake cpufrequtils
sudo apt-get install libuhd-dev uhd-host
sudo add-apt-repository ppa:ettusresearch/uhd
sudo apt-get update
sudo apt-get install libuhd-dev uhd-host
```
### Use the following commands to compile the gNodeB source
```
mkdir ~/GIT
cd GIT
#git clone -b develop https://gitlab.eurecom.fr/oai/openairinterface5g.git
#git branch -a |grep "*"  # Check branch

git clone https://github.com/subhrendu1987/oaisetup

sudo apt-get install linux-image-4.15.0.142-lowlatency linux-headers-4.15.0.142-lowlatency
cd oaisetup/BBU/openairinterface5g/
source oaienv
cd cmake_targets/
# LTE USRP
./build_oai -I --eNB -x --install-system-files -w USRP
# UE USRP
./build_oai -I --gNB --nrUE
# gnodeb USRP 
./build_oai -I --gNB -x -w USRP

cd ran_build/build
sudo ./nr-softmodem -E --sa -O ../../../targets/PROJECTS/GENERIC-NR-5GC/CONF/gnb.sa.band78.fr1.106PRB.usrpb210.modified.conf --continuous -tx
```
### Debug
 * Check host system virtualization
 ```
  egrep -wo 'vmx|ept|vpid|npt|tpr_shadow|flexpriority|vnmi|lm|aes' /proc/cpuinfo 
  ## Only show Intel CPU flags ##
  egrep -wo 'vmx|ept|vpid|npt|tpr_shadow|flexpriority|vnmi|lm|aes' /proc/cpuinfo  | sort | uniq
  ## OR better use the following ##
  egrep -wo 'vmx|lm|aes' /proc/cpuinfo  | sort | uniq\
  | sed -e 's/aes/Hardware encryption=Yes (&)/g' \
  -e 's/lm/64 bit cpu=Yes (&)/g' -e 's/vmx/Intel hardware virtualization=Yes (&)/g'
 ```
 Check the meaning of the tags to understand the capabilities of the host system [here](https://www.cyberciti.biz/faq/linux-xen-vmware-kvm-intel-vt-amd-v-support/)
 * Check detected USRP `uhd_find_devices`
 * Check USB version used `lsusb -v |grep USB` or `lsusb -D /dev/bus/usb/<busno>/<devno>`
 * "Unable to change cpu clock" -> cpufreq is missing from /sys/devices/system/cpu/cpu0/
   --> Check `cat /proc/cpuinfo |grep "MHz"` <Pending>
 * Sampling issue
 ```
 [PHY]   rx_rf: Asked for 23040 samples, got 20737 from USRP
 [PHY]   problem receiving samples
 [HW]   [recv] received 20737 samples out of 23040
 [HW]   Time: 3.60604 s
 ERROR_CODE_OVERFLOW (Overflow)
 ```
 -> <Pending>



## core Setup
### Download https://releases.ubuntu.com/18.04/  64bit
   * Testing Ubuntu 20.04LTS 64bit
### Create VM with the image
### Inside VM install openssh server, git, docker
```
sudo apt update
sudo apt install openssh-server git docker
# INSTALL DEPENDENCIES
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin docker-compose
sudo apt install docker.io docker-compose


```
### Initial configuration pulling
```
mkdir ~/GIT
cd GIT/
git clone --branch v1.4.0 https://gitlab.eurecom.fr/oai/cn5g/oai-cn5g-fed.git

git clone https://github.com/subhrendu1987/oaisetup
cd oaisetup/Util/
sudo bash pullimgs.sh
sudo bash imgsTag.sh
sudo bash oaisetup/Util/pullimgs.sh
sudo bash oaisetup/Util/imgsTag.sh
```
### VM configurations
```
sudo apt install inetutils-tools
sudo apt install net-tools
# UPDATE ROUTING TABLE
sudo -s
sysctl net.ipv4.conf.all.forwarding=1
echo "net.ipv4.ip_forward=1           # For IPv4" >> /etc/sysctl.conf
echo "net.ipv6.conf.all.forwarding=1  # For IPv6" >> /etc/sysctl.conf
exit
sudo sysctl -p /etc/sysctl.conf
sudo iptables -P FORWARD ACCEPT
```
### VNF configurations
```
cd oai-cn5g-fed
git checkout -f v1.4.0
cd ~/GIT/oaisetup/CORE/oai-cn5g-fed
./scripts/syncComponents.sh
./scripts/syncComponents.sh --nrf-branch v1.4.0 --amf-branch v1.4.0 \
                              --smf-branch v1.4.0 --spgwu-tiny-branch v1.4.0 \
                              --udr-branch v1.4.0 --udm-branch v1.4.0 \
                              --ausf-branch v1.4.0 --upf-vpp-branch v1.4.0 \
                              --nssf-branch v1.4.0
```
### Start VNFs
```
#sudo docker network create   --driver=bridge   --subnet=192.168.70.128/26   -o "com.docker.network.bridge.name"="demo-oai"   demo-oai-public-net

cd docker-compose
sudo python3 core-network.py --type start-basic
sudo docker-compose -f docker-compose-basic-nrf.yaml up -d
# Check config 
sudo docker-compose -f docker-compose-basic-nrf.yaml logs --follow
telnet 
sudo docker-compose -f docker-compose-basic-nrf.yaml kill
```
### Expose AMF to gnodeB
* Configure bridged network in CORE_VM
<In gnodeB> `sudo ip route add 192.168.70.0/24 via <IP_CORE_VM>`


### Debug
* For SCTP checking go to `CORE/oai-cn5g-fed/component/amf-gnodeb-connection/README.md`


# UE

https://open-cells.com/index.php/uiccsim-programing/
## Check existing values of the sim
`sudo ./program_uicc`

## Ensure operator key consistency
`<In CORE> cat  docker-compose-basic-nrf.yaml |grep "OPERATOR_KEY"`

<MCC> and <MNC> gnodeB/target/PROJECTS.../, CORE/docker-compose/ .yaml file, CORE/docker-compose/.db

`sudo ./program_uicc --adm <PrintedOnSIM> --imsi <MCC><MNC>0100001101 --isdn 00000001 --acc 0001 --key 6874736969202073796d4b2079650a73 --opc <OperatorKeyfrom_OAI-AMF> -spn "OpenCells01" --authenticate --noreadafter`

`sudo ./program_uicc --adm 0c008508 --imsi 001010000000011 --key 6874736969202073796d4b2079650a73 --opc 504f20634f6320504f50206363500a4f -spn "OpenCells01" --authenticate`

* Find "AuthenticationSubscription" Table in CORE/docker-compose/oai_db2.sql and add a new value as 
(`ueid=UE.IMSI`, `authenticationMethod `, `encPermanentKey=UE.key`, `protectionParameterId=UE.key`, `sequenceNumber`, `authenticationManagementField`, `algorithmId`, `encOpcKey=OperatorKey_OAI-AMF`, `encTopcKey`, `vectorGenerationInHss`, `n5gcAuthMethod`, `rgAuthenticationInd`, `supi=UE.IMSI`)

* Find "SessionManagementSubscriptionData" Table in CORE/docker-compose/oai_db2.sql and add a new value as 
(`ueid=UE.IMSI`, `servingPlmnid=UE.MCC_MNC`, `singleNssai=SST,SD`, `dnnConfigurations`)


* APN setup
```
Name: <Choice>
APN: OpenCells01 # SPN

```