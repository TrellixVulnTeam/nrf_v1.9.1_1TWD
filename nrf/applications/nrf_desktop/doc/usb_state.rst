.. _nrf_desktop_usb_state:

USB state module
################

.. contents::
   :local:
   :depth: 2

The |usb_state| is responsible for tracking the USB connection.
It is also responsible for transmitting data through USB on the application's device.

Module events
*************

.. include:: event_propagation.rst
    :start-after: table_usb_state_start
    :end-before: table_usb_state_end

.. note::
    |nrf_desktop_module_event_note|

Configuration
*************

The module is enabled by selecting :kconfig:`CONFIG_DESKTOP_USB_ENABLE`.
It depends on :kconfig:`CONFIG_USB_DEVICE_HID`.

When enabling the USB support for the device, set the following generic device options:

* :kconfig:`CONFIG_USB_DEVICE_MANUFACTURER` - Manufacturer's name.
* :kconfig:`CONFIG_USB_DEVICE_PRODUCT` - Product name.
* :kconfig:`CONFIG_USB_DEVICE_VID` - Vendor ID (VID) number.
* :kconfig:`CONFIG_USB_DEVICE_PID` - Product ID (PID) number.

Additionally, you can also configure the options described in the following sections.

Low latency device configuration
================================

For low latency devices, make sure that the device requests a polling rate of 1 ms by setting :kconfig:`CONFIG_USB_HID_POLL_INTERVAL_MS` to ``1``.

Boot protocol configuration
===========================

If the device is meant to support the boot protocol, set the following options:

#. Enable :kconfig:`CONFIG_USB_HID_BOOT_PROTOCOL`.
#. Set the :kconfig:`CONFIG_USB_HID_PROTOCOL_CODE` Kconfig option to one of the following values to use the device for forwarding either the HID boot keyboard or the HID boot mouse reports, respectively:

* If you want to forward HID boot keyboard reports, set the option to ``1``.
* If you want to forward HID boot mouse reports, set the option to ``2``.

USB device instance configuration
=================================

The nRF Desktop device can provide multiple instances of a HID-class USB device.
The number of instances is controlled by :kconfig:`CONFIG_USB_HID_DEVICE_COUNT`.

* The Bluetooth® Peripheral device will be able to use a single instance only.
* The Bluetooth® Central device can use either a single instance or a number of instances equal to :kconfig:`CONFIG_BT_MAX_PAIRED`.

On the Bluetooth Central device, if only one instance is used, reports from all Peripherals connected to the Central are forwarded to the same instance.
In other cases, reports from each of the bonded peripherals will be forwarded to a dedicated HID-class USB device instance.
The same instance is used after reconnection.

USB wakeup configuration
========================

The nRF Desktop device can work as a source of wakeup events for the host device if connected through the USB.

To use the feature, select :kconfig:`CONFIG_USB_DEVICE_REMOTE_WAKEUP`.

When host enters the suspended state, the USB will be suspended as well.
With this feature enabled, this state change is used to suspend the nRF Desktop device (see :ref:`nrf_desktop_power_manager`).
When the nRF Desktop device wakes up from standby, the |usb_state| will issue a wakeup request on the USB.

.. note::
    The USB wakeup request is transmitted to the host only if the host enables this request before suspending the USB.


Implementation details
**********************

The |usb_state| registers the :kconfig:`CONFIG_USB_HID_DEVICE_COUNT` instances of HID-class USB device and initializes the USB subsystem.

The necessary callbacks are connected to the module to ensure that the state of the USB connection is tracked.
From the application's viewpoint, USB can be in the following states:

* :c:enum:`USB_STATE_DISCONNECTED` - USB cable is not connected.
* :c:enum:`USB_STATE_POWERED` - The device is powered from USB but is not configured for the communication.
* :c:enum:`USB_STATE_ACTIVE` - The device is ready to exchange data with the host.
* :c:enum:`USB_STATE_SUSPENDED` - The host has requested the device to enter the suspended state.

These states are broadcast by the |usb_state| with a :c:struct:`usb_state_event`.
When the device is connected to the host and configured for the communication, the module will broadcast the :c:enum:`USB_STATE_ACTIVE` state.
The module will also subscribe to all HID reports available in the application for the selected protocol.

When the device is disconnected from the host, the module will unsubscribe from receiving the HID reports.

When the HID report data is transmitted through :c:struct:`hid_report_event`, the module will pass it to the associated endpoint.
Upon data delivery, :c:struct:`hid_report_sent_event` is submitted by the module.

.. note::
    Only one report can be transmitted by the module to a single instance of HID-class USB device at any given time.
    Different instances can transmit reports in parallel.

The |usb_state| is a transport for :ref:`nrf_desktop_config_channel` when the channel is enabled.

The module also handles an HID keyboard LED output report received through USB from the connected host.
The module sends the report using ``hid_report_event``, that is handled either by :ref:`nrf_desktop_hid_state` (for peripheral) or by the :ref:`nrf_desktop_hid_forward` (for dongle).

.. |usb_state| replace:: USB state module
