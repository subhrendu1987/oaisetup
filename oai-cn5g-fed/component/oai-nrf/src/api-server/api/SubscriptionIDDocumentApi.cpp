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

#include "SubscriptionIDDocumentApi.h"
#include "Helpers.h"
#include "nrf_config.hpp"

extern oai::nrf::app::nrf_config nrf_cfg;

namespace oai {
namespace nrf {
namespace api {

using namespace oai::nrf::helpers;
using namespace oai::nrf::model;

SubscriptionIDDocumentApi::SubscriptionIDDocumentApi(
    std::shared_ptr<Pistache::Rest::Router> rtr) {
  router = rtr;
}

void SubscriptionIDDocumentApi::init() {
  setupRoutes();
}

void SubscriptionIDDocumentApi::setupRoutes() {
  using namespace Pistache::Rest;

  Routes::Delete(
      *router,
      base + nrf_cfg.sbi_api_version + "/subscriptions/:subscriptionID",
      Routes::bind(
          &SubscriptionIDDocumentApi::remove_subscription_handler, this));
  Routes::Patch(
      *router,
      base + nrf_cfg.sbi_api_version + "/subscriptions/:subscriptionID",
      Routes::bind(
          &SubscriptionIDDocumentApi::update_subscription_handler, this));

  // Default handler, called when a route is not found
  router->addCustomHandler(Routes::bind(
      &SubscriptionIDDocumentApi::subscription_id_document_api_default_handler,
      this));
}

void SubscriptionIDDocumentApi::remove_subscription_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto subscriptionID = request.param(":subscriptionID").as<std::string>();

  try {
    this->remove_subscription(subscriptionID, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}
void SubscriptionIDDocumentApi::update_subscription_handler(
    const Pistache::Rest::Request& request,
    Pistache::Http::ResponseWriter response) {
  // Getting the path params
  auto subscriptionID = request.param(":subscriptionID").as<std::string>();

  // Getting the body param
  std::vector<PatchItem> patchItem;

  try {
    nlohmann::json::parse(request.body()).get_to(patchItem);
    this->update_subscription(subscriptionID, patchItem, response);
  } catch (nlohmann::detail::exception& e) {
    // send a 400 error
    response.send(Pistache::Http::Code::Bad_Request, e.what());
    return;
  } catch (Pistache::Http::HttpError& e) {
    response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
    return;
  } catch (std::exception& e) {
    // send a 500 error
    response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    return;
  }
}

void SubscriptionIDDocumentApi::subscription_id_document_api_default_handler(
    const Pistache::Rest::Request&, Pistache::Http::ResponseWriter response) {
  response.send(
      Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

}  // namespace api
}  // namespace nrf
}  // namespace oai