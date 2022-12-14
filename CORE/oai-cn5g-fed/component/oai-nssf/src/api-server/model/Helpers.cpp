/**
 * NRF NFManagement Service
 * NRF NFManagement Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */
#include "Helpers.h"
#include "logger.hpp"

namespace oai {
namespace nssf_server {
namespace helpers {

std::string toStringValue(const std::string& value) {
  return std::string(value);
}

std::string toStringValue(const int32_t& value) {
  return std::to_string(value);
}

std::string toStringValue(const int64_t& value) {
  return std::to_string(value);
}

std::string toStringValue(const bool& value) {
  return value ? std::string("true") : std::string("false");
}

std::string toStringValue(const float& value) {
  return std::to_string(value);
}

std::string toStringValue(const double& value) {
  return std::to_string(value);
}

bool fromStringValue(const std::string& inStr, std::string& value) {
  value = std::string(inStr);
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::NFType& value) {
  Logger::nssf_sbi().info(" Query_PARAM::NF_TYPE - %s", inStr.c_str());

  if (inStr.compare("AMF") == 0)
    value.setEnumValue(
        oai::nssf_server::model::NFType_anyOf::eNFType_anyOf::AMF);
  else if (inStr.compare("NSSF") == 0)
    value.setEnumValue(
        oai::nssf_server::model::NFType_anyOf::eNFType_anyOf::NSSF);
  else if (inStr.compare("SMF") == 0)
    value.setEnumValue(
        oai::nssf_server::model::NFType_anyOf::eNFType_anyOf::SMF);
  else if (inStr.compare("NWDAF") == 0)
    value.setEnumValue(
        oai::nssf_server::model::NFType_anyOf::eNFType_anyOf::NWDAF);
  else {
    value.setEnumValue(oai::nssf_server::model::NFType_anyOf::eNFType_anyOf::
                           INVALID_VALUE_OPENAPI_GENERATED);
    return false;
  }

  return true;
}

bool fromStringValue(const std::string& inStr, int32_t& value) {
  try {
    value = std::stoi(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool fromStringValue(const std::string& inStr, int64_t& value) {
  try {
    value = std::stol(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool fromStringValue(const std::string& inStr, bool& value) {
  bool result                                = true;
  inStr == "true" ? value                    = true :
                    inStr == "false" ? value = false : result = false;
  return result;
}

bool fromStringValue(const std::string& inStr, float& value) {
  try {
    value = std::stof(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool fromStringValue(const std::string& inStr, double& value) {
  try {
    value = std::stod(inStr);
  } catch (const std::invalid_argument&) {
    return false;
  }
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::ServiceName& value) {
  // TODO
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::PlmnId& value) {
  Logger::nssf_sbi().info(" Query_PARAM::HOME_PLMN_ID - %s", inStr.c_str());
  nlohmann::json::parse(inStr.c_str()).get_to(value);
  return true;
}

bool fromStringValue(
    const std::string& inStr,
    oai::nssf_server::model::SliceInfoForPDUSession& value) {
  Logger::nssf_sbi().info(
      " Query_PARAM::SLICE_INFO_PDU_SESSION - %s", inStr.c_str());
  nlohmann::json::parse(inStr.c_str()).get_to(value);
  return true;
}

bool fromStringValue(
    const std::string& inStr,
    oai::nssf_server::model::SliceInfoForRegistration& value) {
  Logger::nssf_sbi().info(
      " Query_PARAM::SLICE_INFO_RESGISTRATION - %s", inStr.c_str());
  nlohmann::json::parse(inStr.c_str()).get_to(value);
  return true;
}

bool fromStringValue(
    const std::string& inStr,
    oai::nssf_server::model::SliceInfoForUEConfigurationUpdate& value) {
  Logger::nssf_sbi().info(" Query_PARAM::SLICE_INFO_UE_CU - %s", inStr.c_str());
  nlohmann::json::parse(inStr.c_str()).get_to(value);
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::Snssai& value) {
  // TODO
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::PlmnSnssai& value) {
  // TODO
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::PduSessionType& value) {
  // TODO
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::EventId& value) {
  // TODO
  return true;
}
bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::NwdafEvent& value) {
  // TODO
  return true;
}
bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::AccessType& value) {
  // TODO
  return true;
}
bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::ComplexQuery& value) {
  // TODO
  return true;
}
bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::AtsssCapability& value) {
  // TODO
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::Tai& value) {
  Logger::nssf_sbi().info(" Query_PARAM::TAI - %s", inStr.c_str());
  nlohmann::json::parse(inStr.c_str()).get_to(value);
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::Guami& value) {
  // TODO
  return true;
}

bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::Ipv6Prefix& value) {
  // TODO
  return true;
}
bool fromStringValue(
    const std::string& inStr, oai::nssf_server::model::DataSetId& value) {
  // TODO
  return true;
}
}  // namespace helpers
}  // namespace nssf_server
}  // namespace oai
