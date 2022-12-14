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

#include "BackupAmfInfo.h"

namespace oai::udr::model {

BackupAmfInfo::BackupAmfInfo() {
  m_BackupAmf      = "";
  m_GuamiListIsSet = false;
}

BackupAmfInfo::~BackupAmfInfo() {}

void BackupAmfInfo::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const BackupAmfInfo& o) {
  j              = nlohmann::json();
  j["backupAmf"] = o.m_BackupAmf;
  if (o.guamiListIsSet() || !o.m_GuamiList.empty())
    j["guamiList"] = o.m_GuamiList;
}

void from_json(const nlohmann::json& j, BackupAmfInfo& o) {
  j.at("backupAmf").get_to(o.m_BackupAmf);
  if (j.find("guamiList") != j.end()) {
    j.at("guamiList").get_to(o.m_GuamiList);
    o.m_GuamiListIsSet = true;
  }
}

std::string BackupAmfInfo::getBackupAmf() const {
  return m_BackupAmf;
}
void BackupAmfInfo::setBackupAmf(std::string const& value) {
  m_BackupAmf = value;
}
std::vector<Guami>& BackupAmfInfo::getGuamiList() {
  return m_GuamiList;
}
void BackupAmfInfo::setGuamiList(std::vector<Guami> const& value) {
  m_GuamiList      = value;
  m_GuamiListIsSet = true;
}
bool BackupAmfInfo::guamiListIsSet() const {
  return m_GuamiListIsSet;
}
void BackupAmfInfo::unsetGuamiList() {
  m_GuamiListIsSet = false;
}

}  // namespace oai::udr::model
