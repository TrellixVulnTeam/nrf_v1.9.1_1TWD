/**
 *
 *    Copyright (c) 2021 Project CHIP Authors
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

#include <app-common/zap-generated/attributes/Accessors.h>
#include <app-common/zap-generated/cluster-objects.h>
#include <app-common/zap-generated/ids/Attributes.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app/AttributeAccessInterface.h>
#include <app/CommandHandler.h>
#include <app/ConcreteCommandPath.h>
#include <app/EventLogging.h>
#include <app/util/af.h>
#include <app/util/attribute-storage.h>
#include <lib/core/Optional.h>
#include <platform/DiagnosticDataProvider.h>

using namespace chip;
using namespace chip::app;
using namespace chip::app::Clusters;
using namespace chip::app::Clusters::WiFiNetworkDiagnostics;
using namespace chip::app::Clusters::WiFiNetworkDiagnostics::Attributes;
using chip::DeviceLayer::DiagnosticDataProvider;
using chip::DeviceLayer::GetDiagnosticDataProvider;

namespace {

class WiFiDiagosticsAttrAccess : public AttributeAccessInterface
{
public:
    // Register for the WiFiNetworkDiagnostics cluster on all endpoints.
    WiFiDiagosticsAttrAccess() : AttributeAccessInterface(Optional<EndpointId>::Missing(), WiFiNetworkDiagnostics::Id) {}

    CHIP_ERROR Read(const ConcreteReadAttributePath & aPath, AttributeValueEncoder & aEncoder) override;

private:
    template <typename T>
    CHIP_ERROR ReadIfSupported(CHIP_ERROR (DiagnosticDataProvider::*getter)(T &), AttributeValueEncoder & aEncoder);

    CHIP_ERROR ReadWiFiBssId(AttributeValueEncoder & aEncoder);
};

template <typename T>
CHIP_ERROR WiFiDiagosticsAttrAccess::ReadIfSupported(CHIP_ERROR (DiagnosticDataProvider::*getter)(T &),
                                                     AttributeValueEncoder & aEncoder)
{
    T data;
    CHIP_ERROR err = (DeviceLayer::GetDiagnosticDataProvider().*getter)(data);
    if (err == CHIP_ERROR_UNSUPPORTED_CHIP_FEATURE)
    {
        data = 0;
    }
    else if (err != CHIP_NO_ERROR)
    {
        return err;
    }

    return aEncoder.Encode(data);
}

CHIP_ERROR WiFiDiagosticsAttrAccess::ReadWiFiBssId(AttributeValueEncoder & aEncoder)
{
    // TODO: Use Nullable<ByteSpan> after we get darwin converted over to the new APIs.
    Bssid::TypeInfo::Type bssid;

    if (DeviceLayer::GetDiagnosticDataProvider().GetWiFiBssId(bssid) == CHIP_NO_ERROR)
    {
        ChipLogProgress(Zcl, "Node is currently connected to Wi-Fi network with BSSID:");
        ChipLogByteSpan(Zcl, bssid);
    }
    else
    {
        ChipLogProgress(Zcl, "Node is not currently connected.");
    }

    return aEncoder.Encode(bssid);
}

WiFiDiagosticsAttrAccess gAttrAccess;

CHIP_ERROR WiFiDiagosticsAttrAccess::Read(const ConcreteReadAttributePath & aPath, AttributeValueEncoder & aEncoder)
{
    if (aPath.mClusterId != WiFiNetworkDiagnostics::Id)
    {
        // We shouldn't have been called at all.
        return CHIP_ERROR_INVALID_ARGUMENT;
    }

    switch (aPath.mAttributeId)
    {
    case Bssid::Id: {
        return ReadWiFiBssId(aEncoder);
    }
    case Attributes::SecurityType::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiSecurityType, aEncoder);
    }
    case WiFiVersion::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiVersion, aEncoder);
    }
    case ChannelNumber::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiChannelNumber, aEncoder);
    }
    case Rssi::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiRssi, aEncoder);
    }
    case BeaconLostCount::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiBeaconLostCount, aEncoder);
    }
    case BeaconRxCount::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiBeaconRxCount, aEncoder);
    }
    case PacketMulticastRxCount::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiPacketMulticastRxCount, aEncoder);
    }
    case PacketMulticastTxCount::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiPacketMulticastTxCount, aEncoder);
    }
    case PacketUnicastRxCount::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiPacketUnicastRxCount, aEncoder);
    }
    case PacketUnicastTxCount::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiPacketUnicastTxCount, aEncoder);
    }
    case CurrentMaxRate::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiCurrentMaxRate, aEncoder);
    }
    case OverrunCount::Id: {
        return ReadIfSupported(&DiagnosticDataProvider::GetWiFiOverrunCount, aEncoder);
    }
    default: {
        break;
    }
    }
    return CHIP_NO_ERROR;
}

class WiFiDiagnosticsDelegate : public DeviceLayer::WiFiDiagnosticsDelegate
{
    // Gets called when the Node detects Node’s Wi-Fi connection has been disconnected.
    void OnDisconnectionDetected(uint16_t reasonCode) override
    {
        ChipLogProgress(Zcl, "WiFiDiagnosticsDelegate: OnDisconnectionDetected");

        for (auto endpoint : EnabledEndpointsWithServerCluster(WiFiNetworkDiagnostics::Id))
        {
            // If WiFi Network Diagnostics cluster is implemented on this endpoint
            Events::Disconnection::Type event{ reasonCode };
            EventNumber eventNumber;

            if (CHIP_NO_ERROR != LogEvent(event, endpoint, eventNumber))
            {
                ChipLogError(Zcl, "WiFiDiagnosticsDelegate: Failed to record Disconnection event");
            }
        }
    }

    // Gets called when the Node fails to associate or authenticate an access point.
    void OnAssociationFailureDetected(uint8_t associationFailureCause, uint16_t status) override
    {
        ChipLogProgress(Zcl, "WiFiDiagnosticsDelegate: OnAssociationFailureDetected");

        Events::AssociationFailure::Type event{ static_cast<AssociationFailureCause>(associationFailureCause), status };

        for (auto endpoint : EnabledEndpointsWithServerCluster(WiFiNetworkDiagnostics::Id))
        {
            // If WiFi Network Diagnostics cluster is implemented on this endpoint
            EventNumber eventNumber;

            if (CHIP_NO_ERROR != LogEvent(event, endpoint, eventNumber))
            {
                ChipLogError(Zcl, "WiFiDiagnosticsDelegate: Failed to record AssociationFailure event");
            }
        }
    }

    // Gets when the Node’s connection status to a Wi-Fi network has changed.
    void OnConnectionStatusChanged(uint8_t connectionStatus) override
    {
        ChipLogProgress(Zcl, "WiFiDiagnosticsDelegate: OnConnectionStatusChanged");

        Events::ConnectionStatus::Type event{ static_cast<WiFiConnectionStatus>(connectionStatus) };
        for (auto endpoint : EnabledEndpointsWithServerCluster(WiFiNetworkDiagnostics::Id))
        {
            // If WiFi Network Diagnostics cluster is implemented on this endpoint
            EventNumber eventNumber;

            if (CHIP_NO_ERROR != LogEvent(event, endpoint, eventNumber))
            {
                ChipLogError(Zcl, "WiFiDiagnosticsDelegate: Failed to record ConnectionStatus event");
            }
        }
    }
};

WiFiDiagnosticsDelegate gDiagnosticDelegate;

} // anonymous namespace

bool emberAfWiFiNetworkDiagnosticsClusterResetCountsCallback(app::CommandHandler * commandObj,
                                                             const app::ConcreteCommandPath & commandPath,
                                                             const Commands::ResetCounts::DecodableType & commandData)
{
    EndpointId endpoint  = commandPath.mEndpointId;
    EmberAfStatus status = EMBER_ZCL_STATUS_SUCCESS;

    VerifyOrExit(DeviceLayer::GetDiagnosticDataProvider().ResetWiFiNetworkDiagnosticsCounts() == CHIP_NO_ERROR,
                 status = EMBER_ZCL_STATUS_FAILURE);

    status = WiFiNetworkDiagnostics::Attributes::BeaconLostCount::Set(endpoint, 0);
    VerifyOrExit(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "Failed to reset BeaconLostCount attribute"));

    status = WiFiNetworkDiagnostics::Attributes::BeaconRxCount::Set(endpoint, 0);
    VerifyOrExit(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "Failed to reset BeaconRxCount attribute"));

    status = WiFiNetworkDiagnostics::Attributes::PacketMulticastRxCount::Set(endpoint, 0);
    VerifyOrExit(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "Failed to reset PacketMulticastRxCount attribute"));

    status = WiFiNetworkDiagnostics::Attributes::PacketMulticastTxCount::Set(endpoint, 0);
    VerifyOrExit(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "Failed to reset PacketMulticastTxCount attribute"));

    status = WiFiNetworkDiagnostics::Attributes::PacketUnicastRxCount::Set(endpoint, 0);
    VerifyOrExit(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "Failed to reset PacketUnicastRxCount attribute"));

    status = WiFiNetworkDiagnostics::Attributes::PacketUnicastTxCount::Set(endpoint, 0);
    VerifyOrExit(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "Failed to reset PacketUnicastTxCount attribute"));

    status = WiFiNetworkDiagnostics::Attributes::OverrunCount::Set(endpoint, 0);
    VerifyOrExit(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "Failed to reset OverrunCount attribute"));

exit:
    emberAfSendImmediateDefaultResponse(status);

    return true;
}

void MatterWiFiNetworkDiagnosticsPluginServerInitCallback()
{
    registerAttributeAccessOverride(&gAttrAccess);
    GetDiagnosticDataProvider().SetWiFiDiagnosticsDelegate(&gDiagnosticDelegate);
}
