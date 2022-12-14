/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */
/**
 * Nudr_DataRepository API OpenAPI file
 * Unified Data Repository Service. © 2020, 3GPP Organizational Partners (ARIB,
 * ATIS, CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 2.1.2
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

#include "CagData.h"

namespace oai::udr::model {

CagData::CagData() {
  m_ProvisioningTime      = "";
  m_ProvisioningTimeIsSet = false;
}

CagData::~CagData() {}

void CagData::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const CagData& o) {
  j             = nlohmann::json();
  j["cagInfos"] = o.m_CagInfos;
  if (o.provisioningTimeIsSet()) j["provisioningTime"] = o.m_ProvisioningTime;
}

void from_json(const nlohmann::json& j, CagData& o) {
  j.at("cagInfos").get_to(o.m_CagInfos);
  if (j.find("provisioningTime") != j.end()) {
    j.at("provisioningTime").get_to(o.m_ProvisioningTime);
    o.m_ProvisioningTimeIsSet = true;
  }
}

std::map<std::string, CagInfo>& CagData::getCagInfos() {
  return m_CagInfos;
}
void CagData::setCagInfos(std::map<std::string, CagInfo> const& value) {
  m_CagInfos = value;
}
std::string CagData::getProvisioningTime() const {
  return m_ProvisioningTime;
}
void CagData::setProvisioningTime(std::string const& value) {
  m_ProvisioningTime      = value;
  m_ProvisioningTimeIsSet = true;
}
bool CagData::provisioningTimeIsSet() const {
  return m_ProvisioningTimeIsSet;
}
void CagData::unsetProvisioningTime() {
  m_ProvisioningTimeIsSet = false;
}

}  // namespace oai::udr::model
