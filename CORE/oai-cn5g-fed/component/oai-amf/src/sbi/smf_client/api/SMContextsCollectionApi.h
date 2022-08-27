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

/*
 * SMContextsCollectionApi.h
 *
 *
 */

#ifndef OAI_SMF_API_SMContextsCollectionApi_H_
#define OAI_SMF_API_SMContextsCollectionApi_H_

#include "../ApiClient.h"

#include "SmContextMessage.h"
#include "ProblemDetails.h"
#include "SmContextCreateError.h"
#include "SmContextCreatedData.h"

#include <boost/optional.hpp>

namespace oai {
namespace smf {
namespace api {

using namespace oai::smf::model;

class SMContextsCollectionApi {
 public:
  explicit SMContextsCollectionApi(std::shared_ptr<ApiClient> apiClient);

  virtual ~SMContextsCollectionApi();

  /// <summary>
  /// Create SM Context
  /// </summary>
  /// <remarks>
  ///
  /// </remarks>
  /// <param name="SmContextMessage"></param>
  pplx::task<std::shared_ptr<SmContextCreatedData>> postSmContexts(
      std::shared_ptr<SmContextMessage> smContextMessage);

 protected:
  std::shared_ptr<ApiClient> m_ApiClient;
};

}  // namespace api
}  // namespace smf
}  // namespace oai

#endif /* OAI_SMF_API_SMContextsCollectionApi_H_ */