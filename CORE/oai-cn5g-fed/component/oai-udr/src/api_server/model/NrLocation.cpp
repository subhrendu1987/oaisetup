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

#include "NrLocation.h"

namespace oai::udr::model {

NrLocation::NrLocation() {
  m_AgeOfLocationInformation      = 0;
  m_AgeOfLocationInformationIsSet = false;
  m_UeLocationTimestamp           = "";
  m_UeLocationTimestampIsSet      = false;
  m_GeographicalInformation       = "";
  m_GeographicalInformationIsSet  = false;
  m_GeodeticInformation           = "";
  m_GeodeticInformationIsSet      = false;
  m_GlobalGnbIdIsSet              = false;
}

NrLocation::~NrLocation() {}

void NrLocation::validate() {
  // TODO: implement validation
}

void to_json(nlohmann::json& j, const NrLocation& o) {
  j         = nlohmann::json();
  j["tai"]  = o.m_Tai;
  j["ncgi"] = o.m_Ncgi;
  if (o.ageOfLocationInformationIsSet())
    j["ageOfLocationInformation"] = o.m_AgeOfLocationInformation;
  if (o.ueLocationTimestampIsSet())
    j["ueLocationTimestamp"] = o.m_UeLocationTimestamp;
  if (o.geographicalInformationIsSet())
    j["geographicalInformation"] = o.m_GeographicalInformation;
  if (o.geodeticInformationIsSet())
    j["geodeticInformation"] = o.m_GeodeticInformation;
  if (o.globalGnbIdIsSet()) j["globalGnbId"] = o.m_GlobalGnbId;
}

void from_json(const nlohmann::json& j, NrLocation& o) {
  j.at("tai").get_to(o.m_Tai);
  j.at("ncgi").get_to(o.m_Ncgi);
  if (j.find("ageOfLocationInformation") != j.end()) {
    j.at("ageOfLocationInformation").get_to(o.m_AgeOfLocationInformation);
    o.m_AgeOfLocationInformationIsSet = true;
  }
  if (j.find("ueLocationTimestamp") != j.end()) {
    j.at("ueLocationTimestamp").get_to(o.m_UeLocationTimestamp);
    o.m_UeLocationTimestampIsSet = true;
  }
  if (j.find("geographicalInformation") != j.end()) {
    j.at("geographicalInformation").get_to(o.m_GeographicalInformation);
    o.m_GeographicalInformationIsSet = true;
  }
  if (j.find("geodeticInformation") != j.end()) {
    j.at("geodeticInformation").get_to(o.m_GeodeticInformation);
    o.m_GeodeticInformationIsSet = true;
  }
  if (j.find("globalGnbId") != j.end()) {
    j.at("globalGnbId").get_to(o.m_GlobalGnbId);
    o.m_GlobalGnbIdIsSet = true;
  }
}

Tai NrLocation::getTai() const {
  return m_Tai;
}
void NrLocation::setTai(Tai const& value) {
  m_Tai = value;
}
Ncgi NrLocation::getNcgi() const {
  return m_Ncgi;
}
void NrLocation::setNcgi(Ncgi const& value) {
  m_Ncgi = value;
}
int32_t NrLocation::getAgeOfLocationInformation() const {
  return m_AgeOfLocationInformation;
}
void NrLocation::setAgeOfLocationInformation(int32_t const value) {
  m_AgeOfLocationInformation      = value;
  m_AgeOfLocationInformationIsSet = true;
}
bool NrLocation::ageOfLocationInformationIsSet() const {
  return m_AgeOfLocationInformationIsSet;
}
void NrLocation::unsetAgeOfLocationInformation() {
  m_AgeOfLocationInformationIsSet = false;
}
std::string NrLocation::getUeLocationTimestamp() const {
  return m_UeLocationTimestamp;
}
void NrLocation::setUeLocationTimestamp(std::string const& value) {
  m_UeLocationTimestamp      = value;
  m_UeLocationTimestampIsSet = true;
}
bool NrLocation::ueLocationTimestampIsSet() const {
  return m_UeLocationTimestampIsSet;
}
void NrLocation::unsetUeLocationTimestamp() {
  m_UeLocationTimestampIsSet = false;
}
std::string NrLocation::getGeographicalInformation() const {
  return m_GeographicalInformation;
}
void NrLocation::setGeographicalInformation(std::string const& value) {
  m_GeographicalInformation      = value;
  m_GeographicalInformationIsSet = true;
}
bool NrLocation::geographicalInformationIsSet() const {
  return m_GeographicalInformationIsSet;
}
void NrLocation::unsetGeographicalInformation() {
  m_GeographicalInformationIsSet = false;
}
std::string NrLocation::getGeodeticInformation() const {
  return m_GeodeticInformation;
}
void NrLocation::setGeodeticInformation(std::string const& value) {
  m_GeodeticInformation      = value;
  m_GeodeticInformationIsSet = true;
}
bool NrLocation::geodeticInformationIsSet() const {
  return m_GeodeticInformationIsSet;
}
void NrLocation::unsetGeodeticInformation() {
  m_GeodeticInformationIsSet = false;
}
GlobalRanNodeId NrLocation::getGlobalGnbId() const {
  return m_GlobalGnbId;
}
void NrLocation::setGlobalGnbId(GlobalRanNodeId const& value) {
  m_GlobalGnbId      = value;
  m_GlobalGnbIdIsSet = true;
}
bool NrLocation::globalGnbIdIsSet() const {
  return m_GlobalGnbIdIsSet;
}
void NrLocation::unsetGlobalGnbId() {
  m_GlobalGnbIdIsSet = false;
}

}  // namespace oai::udr::model
