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

/*
 *  itti_msg_sbi.hpp
 *
 *  Date: 2021
 *  Company KCL
 *  Author: shivam.gandhi@kcl.ac.uk
 */

#ifndef ITTI_MSG_SBI_HPP_INCLUDED_
#define ITTI_MSG_SBI_HPP_INCLUDED_

#include "itti_msg.hpp"
#include "pistache/http.h"
#include "amf_msg.hpp"
#include "N1MessageNotification.h"
#include "UeN1N2InfoSubscriptionCreateData.h"

// using namespace oai::amf::model;
using namespace amf_application;

class itti_sbi_msg : public itti_msg {
 public:
  itti_sbi_msg(
      const itti_msg_type_t msg_type, const task_id_t orig,
      const task_id_t dest)
      : itti_msg(msg_type, orig, dest) {}
  itti_sbi_msg(const itti_sbi_msg& i) : itti_msg(i) {}
  itti_sbi_msg(
      const itti_sbi_msg& i, const task_id_t orig, const task_id_t dest)
      : itti_sbi_msg(i) {
    origin      = orig;
    destination = dest;
  }
};

//-----------------------------------------------------------------------------
class itti_sbi_event_exposure_request : public itti_sbi_msg {
 public:
  itti_sbi_event_exposure_request(const task_id_t orig, const task_id_t dest)
      : itti_sbi_msg(SBI_EVENT_EXPOSURE_REQUEST, orig, dest),
        event_exposure(),
        http_version(1) {}
  itti_sbi_event_exposure_request(const itti_sbi_event_exposure_request& i)
      : itti_sbi_msg(i), event_exposure(i.event_exposure), http_version(1) {}
  itti_sbi_event_exposure_request(
      const itti_sbi_event_exposure_request& i, const task_id_t orig,
      const task_id_t dest)
      : itti_sbi_msg(i, orig, dest),
        event_exposure(i.event_exposure),
        http_version(i.http_version) {}
  const char* get_msg_name() { return "SBI_EVENT_EXPOSURE_REQUEST"; };
  event_exposure_msg event_exposure;
  uint8_t http_version;
};

//-----------------------------------------------------------------------------
class itti_sbi_notification_data : public itti_sbi_msg {
 public:
  itti_sbi_notification_data(const task_id_t orig, const task_id_t dest)
      : itti_sbi_msg(SBI_NOTIFICATION_DATA, orig, dest),
        notification_msg(),
        http_version(1) {}
  itti_sbi_notification_data(const itti_sbi_notification_data& i)
      : itti_sbi_msg(i),
        notification_msg(i.notification_msg),
        http_version(1) {}
  itti_sbi_notification_data(
      const itti_sbi_notification_data& i, const task_id_t orig,
      const task_id_t dest)
      : itti_sbi_msg(i, orig, dest),
        notification_msg(i.notification_msg),
        http_version(i.http_version) {}
  const char* get_msg_name() { return "SBI_NOTIFICATION_DATA"; };
  data_notification_msg notification_msg;
  uint8_t http_version;
};

//-----------------------------------------------------------------------------
class itti_sbi_notify_subscribed_event : public itti_sbi_msg {
 public:
  itti_sbi_notify_subscribed_event(const task_id_t orig, const task_id_t dest)
      : itti_sbi_msg(SBI_NOTIFY_SUBSCRIBED_EVENT, orig, dest),
        notif_id(),
        http_version() {}

  itti_sbi_notify_subscribed_event(const itti_sbi_notify_subscribed_event& i)
      : itti_sbi_msg(i), notif_id(i.notif_id), http_version(i.http_version) {}
  itti_sbi_notify_subscribed_event(
      const itti_sbi_notify_subscribed_event& i, const task_id_t orig,
      const task_id_t dest)
      : itti_sbi_msg(i, orig, dest),
        notif_id(i.notif_id),
        http_version(i.http_version) {}
  const char* get_msg_name() { return "SBI_NOTIFY_SUBSCRIBED_EVENT"; };

  std::string notif_id;
  std::vector<amf_application::event_notification> event_notifs;
  uint8_t http_version;
};

//-----------------------------------------------------------------------------
class itti_sbi_n1_message_notification : public itti_sbi_msg {
 public:
  itti_sbi_n1_message_notification(const task_id_t orig, const task_id_t dest)
      : itti_sbi_msg(SBI_N1_MESSAGE_NOTIFICATION, orig, dest),
        notification_msg(),
        ue_id(),
        n1sm(),
        http_version(1) {}
  itti_sbi_n1_message_notification(const itti_sbi_n1_message_notification& i)
      : itti_sbi_msg(i),
        notification_msg(i.notification_msg),
        ue_id(i.ue_id),
        n1sm(i.n1sm),
        http_version(1) {}
  itti_sbi_n1_message_notification(
      const itti_sbi_n1_message_notification& i, const task_id_t orig,
      const task_id_t dest)
      : itti_sbi_msg(i, orig, dest),
        notification_msg(i.notification_msg),
        ue_id(i.ue_id),
        n1sm(i.n1sm),
        http_version(i.http_version) {}
  const char* get_msg_name() { return "SBI_N1_MESSAGE_NOTIFICATION"; };
  oai::amf::model::N1MessageNotification notification_msg;
  std::string ue_id;
  std::string n1sm;
  uint8_t http_version;
};

//-----------------------------------------------------------------------------
class itti_sbi_n1n2_message_subscribe : public itti_sbi_msg {
 public:
  itti_sbi_n1n2_message_subscribe(
      const task_id_t orig, const task_id_t dest, uint32_t pid)
      : itti_sbi_msg(SBI_N1N2_MESSAGE_SUBSCRIBE, orig, dest),
        ue_cxt_id(),
        subscription_data(),
        http_version(1),
        promise_id(pid) {}
  itti_sbi_n1n2_message_subscribe(const itti_sbi_n1n2_message_subscribe& i)
      : itti_sbi_msg(i),
        ue_cxt_id(i.ue_cxt_id),
        subscription_data(i.subscription_data),
        http_version(1),
        promise_id() {}
  itti_sbi_n1n2_message_subscribe(
      const itti_sbi_n1n2_message_subscribe& i, const task_id_t orig,
      const task_id_t dest)
      : itti_sbi_msg(i, orig, dest),
        ue_cxt_id(i.ue_cxt_id),
        subscription_data(i.subscription_data),
        http_version(i.http_version),
        promise_id(i.promise_id) {}
  const char* get_msg_name() { return "SBI_N1N2_MESSAGE_SUBSCRIBE"; };
  std::string ue_cxt_id;
  oai::amf::model::UeN1N2InfoSubscriptionCreateData subscription_data;
  uint8_t http_version;
  uint32_t promise_id;
};

//-----------------------------------------------------------------------------
class itti_sbi_n1n2_message_unsubscribe : public itti_sbi_msg {
 public:
  itti_sbi_n1n2_message_unsubscribe(
      const task_id_t orig, const task_id_t dest, uint32_t pid)
      : itti_sbi_msg(SBI_N1N2_MESSAGE_SUBSCRIBE, orig, dest),
        ue_cxt_id(),
        subscription_id(),
        http_version(1),
        promise_id(pid) {}
  itti_sbi_n1n2_message_unsubscribe(const itti_sbi_n1n2_message_unsubscribe& i)
      : itti_sbi_msg(i),
        ue_cxt_id(i.ue_cxt_id),
        subscription_id(i.subscription_id),
        http_version(1),
        promise_id() {}
  itti_sbi_n1n2_message_unsubscribe(
      const itti_sbi_n1n2_message_unsubscribe& i, const task_id_t orig,
      const task_id_t dest)
      : itti_sbi_msg(i, orig, dest),
        ue_cxt_id(i.ue_cxt_id),
        subscription_id(i.subscription_id),
        http_version(i.http_version),
        promise_id(i.promise_id) {}
  const char* get_msg_name() { return "SBI_N1N2_MESSAGE_UNSUBSCRIBE"; };
  std::string ue_cxt_id;
  std::string subscription_id;
  uint8_t http_version;
  uint32_t promise_id;
};
#endif /* ITTI_MSG_SBI_HPP_INCLUDED_ */
