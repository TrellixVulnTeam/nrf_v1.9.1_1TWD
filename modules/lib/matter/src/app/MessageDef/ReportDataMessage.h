/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2016-2017 Nest Labs, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
/**
 *    @file
 *      This file defines ReportDataMessage parser and builder in CHIP interaction model
 *
 */

#pragma once

#include <app/AppBuildConfig.h>
#include <app/util/basic-types.h>
#include <lib/core/CHIPCore.h>
#include <lib/core/CHIPTLV.h>
#include <lib/support/CodeUtils.h>
#include <lib/support/logging/CHIPLogging.h>

#include "AttributeReportIBs.h"
#include "EventReportIBs.h"
#include "StructBuilder.h"
#include "StructParser.h"

namespace chip {
namespace app {
namespace ReportDataMessage {
enum
{
    kCsTag_SubscriptionId      = 0,
    kCsTag_AttributeReportIBs  = 1,
    kCsTag_EventReports        = 2,
    kCsTag_MoreChunkedMessages = 3,
    kCsTag_SuppressResponse    = 4,
};

class Parser : public StructParser
{
public:
#if CHIP_CONFIG_IM_ENABLE_SCHEMA_CHECK
    /**
     *  @brief Roughly verify the message is correctly formed
     *   1) all mandatory tags are present
     *   2) all elements have expected data type
     *   3) any tag can only appear once
     *   4) At the top level of the structure, unknown tags are ignored for forward compatibility
     *  @note The main use of this function is to print out what we're
     *    receiving during protocol development and debugging.
     *    The encoding rule has changed in IM encoding spec so this
     *    check is only "roughly" conformant now.
     *
     *  @return #CHIP_NO_ERROR on success
     */
    CHIP_ERROR CheckSchemaValidity() const;
#endif

    /**
     *  @brief Check whether a response (a StatusResponseMessage specifically) is to be sent back to the request.
     *  Next() must be called before accessing them.
     *
     *  @param [in] apSuppressResponse    A pointer to apSuppressResponse
     *
     *  @return #CHIP_NO_ERROR on success
     *          #CHIP_END_OF_TLV if there is no such element
     */
    CHIP_ERROR GetSuppressResponse(bool * const apSuppressResponse) const;

    /**
     *  @brief Get Subscription Id. Next() must be called before accessing them.
     *
     *  @param [in] apSubscriptionId    A pointer to apSubscriptionId
     *
     *  @return #CHIP_NO_ERROR on success
     *          #CHIP_END_OF_TLV if there is no such element
     */
    CHIP_ERROR GetSubscriptionId(uint64_t * const apSubscriptionId) const;

    /**
     *  @brief Get a TLVReader for the AttributesDataList. Next() must be called before accessing them.
     *
     *  @param [in] apAttributeReportIBs    A pointer to apAttributeReportIBs
     *
     *  @return #CHIP_NO_ERROR on success
     *          #CHIP_ERROR_WRONG_TLV_TYPE if there is such element but it's not a Array
     *          #CHIP_END_OF_TLV if there is no such element
     */
    CHIP_ERROR GetAttributeReportIBs(AttributeReportIBs::Parser * const apAttributeReportIBs) const;

    /**
     *  @brief Get a TLVReader for the EventReportIBs. Next() must be called before accessing them.
     *
     *  @param [in] apEventReports    A pointer to apEventReports
     *
     *  @return #CHIP_NO_ERROR on success
     *          #CHIP_ERROR_WRONG_TLV_TYPE if there is such element but it's not a Array
     *          #CHIP_END_OF_TLV if there is no such element
     */
    CHIP_ERROR GetEventReports(EventReportIBs::Parser * const apEventReports) const;

    /**
     *  @brief Check whether there are more chunked messages in a transaction. Next() must be called before accessing them.
     *
     *  @param [in] apMoreChunkedMessages   A pointer to apMoreChunkedMessages
     *
     *  @return #CHIP_NO_ERROR on success
     *          #CHIP_END_OF_TLV if there is no such element
     */
    CHIP_ERROR GetMoreChunkedMessages(bool * const apMoreChunkedMessages) const;
};

class Builder : public StructBuilder
{
public:
    /**
     *  @brief Inject SuppressResponse into the TLV stream to indicate whether a response (a StatusResponseMessage specifically)
     *  is to be sent back to the request.
     *
     *  @param [in] aSuppressResponse The boolean variable to indicate if request response is needed.
     *
     *  @return A reference to *this
     */
    ReportDataMessage::Builder & SuppressResponse(const bool aSuppressResponse);

    /**
     *  @brief Inject subscription id into the TLV stream, This field contains the Subscription ID
     *  to which the data is being sent against. This is not present when the ReportDataMessageRequest is
     *  sent in response to a ReadRequestMessage, but is present when sent in response to a SubscribeRequestMessage.
     *  Attempts should be made to ensure the SubscriptionId does not collide with IDs from previous
     *  subscriptions to ensure disambiguation.
     *
     *  @param [in] aSubscriptionId  Subscription Id for this report data
     *
     *  @return A reference to *this
     */
    ReportDataMessage::Builder & SubscriptionId(const uint64_t aSubscriptionId);

    /**
     *  @brief Initialize a AttributeReportIBs::Builder for writing into the TLV stream
     *
     *  @return A reference to AttributeReportIBs::Builder
     */
    AttributeReportIBs::Builder & CreateAttributeReportIBs();

    /**
     *  @brief Initialize a EventReportIBs::Builder for writing into the TLV stream
     *
     *  @return A reference to EventReportIBs::Builder
     */
    EventReportIBs::Builder & CreateEventReports();

    /**
     *  @brief This flag is set to ‘true’ when there are more chunked messages in a transaction.
     *  @param [in] aMoreChunkedMessages The boolean variable to indicate if there are more chunked messages in a transaction.
     *  @return A reference to *this
     */
    ReportDataMessage::Builder & MoreChunkedMessages(const bool aMoreChunkedMessages);

    /**
     *  @brief Mark the end of this ReportDataMessage
     *
     *  @return A reference to *this
     */
    ReportDataMessage::Builder & EndOfReportDataMessage();

private:
    AttributeReportIBs::Builder mAttributeReportIBsBuilder;
    EventReportIBs::Builder mEventReportsBuilder;
};
}; // namespace ReportDataMessage

}; // namespace app
}; // namespace chip
