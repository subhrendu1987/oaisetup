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
 * NrV2xAuth.h
 *
 *
 */

#ifndef NrV2xAuth_H_
#define NrV2xAuth_H_

#include <nlohmann/json.hpp>

#include "UeAuth.h"

namespace oai::udr::model {

/// <summary>
///
/// </summary>
class NrV2xAuth {
 public:
  NrV2xAuth();
  virtual ~NrV2xAuth();

  void validate();

  /////////////////////////////////////////////
  /// NrV2xAuth members

  /// <summary>
  ///
  /// </summary>
  UeAuth getVehicleUeAuth() const;
  void setVehicleUeAuth(UeAuth const& value);
  bool vehicleUeAuthIsSet() const;
  void unsetVehicleUeAuth();
  /// <summary>
  ///
  /// </summary>
  UeAuth getPedestrianUeAuth() const;
  void setPedestrianUeAuth(UeAuth const& value);
  bool pedestrianUeAuthIsSet() const;
  void unsetPedestrianUeAuth();

  friend void to_json(nlohmann::json& j, const NrV2xAuth& o);
  friend void from_json(const nlohmann::json& j, NrV2xAuth& o);

 protected:
  UeAuth m_VehicleUeAuth;
  bool m_VehicleUeAuthIsSet;
  UeAuth m_PedestrianUeAuth;
  bool m_PedestrianUeAuthIsSet;
};

}  // namespace oai::udr::model

#endif /* NrV2xAuth_H_ */
