/**
 * Nsmf_PDUSession
 * SMF PDU Session Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 4.1.1-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "Tai.h"

namespace oai {
namespace smf {
namespace model {

Tai::Tai() {
  m_Tac = utility::conversions::to_string_t("");
}

Tai::~Tai() {}

void Tai::validate() {
  // TODO: implement validation
}

web::json::value Tai::toJson() const {
  web::json::value val = web::json::value::object();

  val[utility::conversions::to_string_t("plmnId")] =
      ModelBase::toJson(m_PlmnId);
  val[utility::conversions::to_string_t("tac")] = ModelBase::toJson(m_Tac);

  return val;
}

void Tai::fromJson(const web::json::value& val) {
  std::shared_ptr<PlmnId> newPlmnId(new PlmnId());
  newPlmnId->fromJson(val.at(utility::conversions::to_string_t("plmnId")));
  setPlmnId(newPlmnId);
  setTac(ModelBase::stringFromJson(
      val.at(utility::conversions::to_string_t("tac"))));
}

void Tai::toMultipart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t& prefix) const {
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(".")) {
    namePrefix += utility::conversions::to_string_t(".");
  }

  m_PlmnId->toMultipart(
      multipart, utility::conversions::to_string_t("plmnId."));
  multipart->add(ModelBase::toHttpContent(
      namePrefix + utility::conversions::to_string_t("tac"), m_Tac));
}

void Tai::fromMultiPart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t& prefix) {
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(".")) {
    namePrefix += utility::conversions::to_string_t(".");
  }

  std::shared_ptr<PlmnId> newPlmnId(new PlmnId());
  newPlmnId->fromMultiPart(
      multipart, utility::conversions::to_string_t("plmnId."));
  setPlmnId(newPlmnId);
  setTac(ModelBase::stringFromHttpContent(
      multipart->getContent(utility::conversions::to_string_t("tac"))));
}

std::shared_ptr<PlmnId> Tai::getPlmnId() const {
  return m_PlmnId;
}

void Tai::setPlmnId(const std::shared_ptr<PlmnId>& value) {
  m_PlmnId = value;
}

utility::string_t Tai::getTac() const {
  return m_Tac;
}

void Tai::setTac(const utility::string_t& value) {
  m_Tac = value;
}

}  // namespace model
}  // namespace smf
}  // namespace oai