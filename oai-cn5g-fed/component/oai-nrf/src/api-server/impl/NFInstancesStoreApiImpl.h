/**
 * NRF NFDiscovery Service
 * NRF NFDiscovery Service. © 2019, 3GPP Organizational Partners (ARIB, ATIS,
 * CCSA, ETSI, TSDSI, TTA, TTC). All rights reserved.
 *
 * The version of the OpenAPI document: 1.1.0.alpha-1
 *
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * (https://openapi-generator.tech). https://openapi-generator.tech Do not edit
 * the class manually.
 */

/*
 * NFInstancesStoreApiImpl.h
 *
 *
 */

#ifndef NF_INSTANCES_STORE_API_IMPL_H_
#define NF_INSTANCES_STORE_API_IMPL_H_

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <memory>

#include <NFInstancesStoreApi.h>

#include <pistache/optional.h>

#include "AccessType.h"
#include "AtsssCapability.h"
#include "ComplexQuery.h"
#include "DataSetId.h"
#include "EventId.h"
#include "Guami.h"
#include "Ipv6Prefix.h"
//#include "NFType.h"
#include "NwdafEvent.h"
#include "PduSessionType.h"
#include "PlmnId.h"
#include "PlmnSnssai.h"
#include "ProblemDetails.h"
#include "SearchResult.h"
#include "ServiceName.h"
#include "Snssai.h"
#include "Tai.h"
#include "nrf_app.hpp"
#include <string>
#include <set>

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::model;
using namespace oai::nrf::app;

class NFInstancesStoreApiImpl : public oai::nrf::api::NFInstancesStoreApi {
 public:
  NFInstancesStoreApiImpl(
      std::shared_ptr<Pistache::Rest::Router>, nrf_app* nrf_app_inst,
      std::string address);
  ~NFInstancesStoreApiImpl() {}

  void get_nf_instances(
      const Pistache::Optional<std::string>& nfType,
      const Pistache::Optional<int32_t>& limit,
      Pistache::Http::ResponseWriter& response);
  void options_nf_instances(Pistache::Http::ResponseWriter& response);

 private:
  nrf_app* m_nrf_app;
  std::string m_address;
};

}  // namespace api
}  // namespace nrf
}  // namespace oai

#endif