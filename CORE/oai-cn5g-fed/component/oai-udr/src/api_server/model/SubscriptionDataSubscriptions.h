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
/*
 * SubscriptionDataSubscriptions.h
 *
 *
 */

#ifndef SubscriptionDataSubscriptions_H_
#define SubscriptionDataSubscriptions_H_

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "SdmSubscription.h"

namespace oai::udr::model {

/// <summary>
///
/// </summary>
class SubscriptionDataSubscriptions {
 public:
  SubscriptionDataSubscriptions();
  virtual ~SubscriptionDataSubscriptions();

  void validate();

  /////////////////////////////////////////////
  /// SubscriptionDataSubscriptions members

  /// <summary>
  ///
  /// </summary>
  std::string getUeId() const;
  void setUeId(std::string const& value);
  bool ueIdIsSet() const;
  void unsetUeId();
  /// <summary>
  ///
  /// </summary>
  std::string getCallbackReference() const;
  void setCallbackReference(std::string const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getOriginalCallbackReference() const;
  void setOriginalCallbackReference(std::string const& value);
  bool originalCallbackReferenceIsSet() const;
  void unsetOriginalCallbackReference();
  /// <summary>
  ///
  /// </summary>
  std::vector<std::string>& getMonitoredResourceUris();
  void setMonitoredResourceUris(std::vector<std::string> const& value);
  /// <summary>
  ///
  /// </summary>
  std::string getExpiry() const;
  void setExpiry(std::string const& value);
  bool expiryIsSet() const;
  void unsetExpiry();
  /// <summary>
  ///
  /// </summary>
  SdmSubscription getSdmSubscription() const;
  void setSdmSubscription(SdmSubscription const& value);
  bool sdmSubscriptionIsSet() const;
  void unsetSdmSubscription();
  /// <summary>
  ///
  /// </summary>
  std::string getSubscriptionId() const;
  void setSubscriptionId(std::string const& value);
  bool subscriptionIdIsSet() const;
  void unsetSubscriptionId();
  /// <summary>
  ///
  /// </summary>
  std::string getSupportedFeatures() const;
  void setSupportedFeatures(std::string const& value);
  bool supportedFeaturesIsSet() const;
  void unsetSupported_features();

  friend void to_json(
      nlohmann::json& j, const SubscriptionDataSubscriptions& o);
  friend void from_json(
      const nlohmann::json& j, SubscriptionDataSubscriptions& o);

 protected:
  std::string m_UeId;
  bool m_UeIdIsSet;
  std::string m_CallbackReference;

  std::string m_OriginalCallbackReference;
  bool m_OriginalCallbackReferenceIsSet;
  std::vector<std::string> m_MonitoredResourceUris;

  std::string m_Expiry;
  bool m_ExpiryIsSet;
  SdmSubscription m_SdmSubscription;
  bool m_SdmSubscriptionIsSet;
  std::string m_SubscriptionId;
  bool m_SubscriptionIdIsSet;
  std::string m_Supported_features;
  bool m_Supported_featuresIsSet;
};

}  // namespace oai::udr::model

#endif /* SubscriptionDataSubscriptions_H_ */
