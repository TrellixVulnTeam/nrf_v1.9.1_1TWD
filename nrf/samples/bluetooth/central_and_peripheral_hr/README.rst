.. _central_and_peripheral_hrs:

Bluetooth: Central and Peripheral HRS
#####################################

.. contents::
   :local:
   :depth: 2

The Central and Peripheral HRS sample demonstrates how to use Bluetooth® with Central and Peripheral roles concurrently.
It also demonstrates how to use the :ref:`lib_hrs_client_readme` library.
It uses the HRS Client to retrieve heart rate measurement data from a remote device that provides a Heart Rate service.
It relays this data to another remote device that provides a Heart Rate Service client implementation.

Overview
********

The sample demonstrates both Bluetooth® LE roles:
  * Central role - scans for a remote device providing Heart Rate Service.
  * Peripheral role - advertises and exposes a Heart Rate Service.

When a device is connected as central, the sample starts the service discovery procedure to search for the Heart Rate Service.
If this succeeds, the sample reads the Body Sensor Location characteristic and subscribes to the Heart Rate Measurement characteristic to receive notifications.
When connected also as peripheral to the device acting as a Heart Rate Service client, the sample starts working as relay.
It collects data from a remote device with Heart Rate Service that is sending notifications and sends this data to another remote device providing a Heart Rate Service client.

Requirements
************

The sample supports the following development kits:

.. table-from-rows:: /includes/sample_board_rows.txt
   :header: heading
   :rows: nrf5340dk_nrf5340_cpuapp_and_cpuapp_ns, nrf52840dk_nrf52840, nrf52dk_nrf52832, nrf52833dk_nrf52833, nrf52833dk_nrf52820, nrf21540dk_nrf52840

To test just the Bluetooth® LE Central Role operation, you need one of the following setups:

  * A smartphone or a tablet running a compatible application.
  * Another development kit running the :ref:`zephyr:peripheral_hr` sample.
    See the documentation for that sample for detailed instructions.

To test the Relay mode operation, you need one of the following setups:

  * A smartphone or a tablet running a compatible application.
  * Two additional development kits running :ref:`zephyr:bluetooth_central_hr` and :ref:`zephyr:peripheral_hr` samples.

You can also mix devices when testing this sample.
For a simple echo test, you only need one additional device.
Alternatively, you can use a smartphone providing the HRS functionality and a development kit running the :ref:`zephyr:bluetooth_central_hr` sample.

User interface
**************

LED 1:
   Blinks when the main loop is running (that is, the device is advertising) with a period of two seconds, duty cycle 50%.

LED 2:
   On when the development kit is connected as central.

LED 3:
  On when the development kit is connected as peripheral.

Building and running
********************
.. |sample path| replace:: :file:`samples/bluetooth/central_and_peripheral_hr`

.. include:: /includes/build_and_run.txt


.. _central_and_peripheral_hrs_testing:

Testing
=======

After programming the sample to your development kit, test it either by connecting to other development kits that are running the :ref:`zephyr:peripheral_hr` sample, or by using the `nRF Connect for Desktop`_ **Bluetooth Low Energy** application that emulates an HRS server.

Testing with other development kits
-----------------------------------

1. |connect_terminal_specific|
#. Program the other development kit with the :ref:`zephyr:peripheral_hr` sample and reset it.
#. Wait until the HRS is detected by the central.
   Observe that **LED 2** is on.
#. In the terminal window, check for information similar to the following::

        Heart Rate Sensor body location: Chest
        Heart Rate Measurement notification received:

            Heart Rate Measurement Value Format: 8 - bit
            Sensor Contact detected: 1
            Sensor Contact supported: 1
            Energy Expended present: 0
            RR-Intervals present: 0

            Heart Rate Measurement Value: 134 bpm

   Notifications will be displayed periodically with a frequency determined by the HR server.

#. Program another development kit with the :ref:`zephyr:bluetooth_central_hr` sample and reset it.
#. Wait until central is connected to your development kit.
   Observe that **LED 3** is on.
#. In terminal windows connected to device with the :ref:`zephyr:bluetooth_central_hr` sample, check for information similar to following::

        [NOTIFICATION] data 0x20006779 length 2

The sample works as relay now.

Testing with nRF Connect for Desktop
------------------------------------
1. |connect_terminal_specific|
#. Reset the development kit.
#. Start `nRF Connect for Desktop`_ and select the connected dongle that is used for communication.
#. Open the :guilabel:`SERVER SETUP` tab.
#. Click the dongle configuration and select :guilabel:`Load setup`.
#. Load the :file:`hr_service.ncs` file that is located under :file:`samples/bluetooth/central_and_peripheral_hr` in the |NCS| folder structure.
#. Click :guilabel:`Apply to device`.
#. Open the :guilabel:`CONNECTION MAP` tab.
#. Click the dongle configuration(gear ikon) and select :guilabel:`Advertising setup`.

   The current version of nRF Connect can store the advertising setup.

#. Click :guilabel:`Load setup`.
   Load the :file:`hrs_adv_setup.ncs` file that is located under :file:`samples/bluetooth/central_and_peripheral_hr` in the |NCS| folder structure.
#. Click :guilabel:`Apply` and :guilabel:`Close`.

#. Click the gear icon to open the Adapter settings and select :guilabel:`Start advertising`.
#. Wait until the development kit running the Central and Peripheral HRS connects.
   Observe that **LED 2** is on.
#. Explore the :guilabel:`Heart Rate Measurement` characteristic.
#. Write value ``06 80`` and click the :guilabel:`Play` button to send a notification.
   In the terminal window, check for information similar to the following::

        Heart Rate Sensor body location: Chest
        Heart Rate Measurement notification received:

            Heart Rate Measurement Value Format: 8 - bit
            Sensor Contact detected: 1
            Sensor Contact supported: 1
            Energy Expended present: 0
            RR-Intervals present: 0

            Heart Rate Measurement Value: 128 bpm

#. The `nRF Connect for Desktop`_ also detects the Central and Peripheral HRS sample Heart Rate Service.
#. Enable the notification for the :guilabel:`Heart Rate Measurement` characteristic.
#. Write again value ``06 80`` and click the :guilabel:`Play` button to send a notification.
   The same value appears for the sample :guilabel:`Heart Rate Measurement` characteristic, sample works as relay for Heart Rate Service.

Dependencies
************

This sample uses the following |NCS| libraries:

* :ref:`lib_hrs_client_readme`
* :ref:`dk_buttons_and_leds_readme`
* :ref:`gatt_dm_readme`
* :ref:`nrf_bt_scan_readme`

In addition, it uses the following Zephyr libraries:

* ``include/zephyr.h``

* :ref:`zephyr:bluetooth_api`:

  * ``include/bluetooth/bluetooth.h``
  * ``include/bluetooth/gatt.h``
  * ``include/bluetooth/conn.h``
  * ``include/bluetooth/uuid.h``
  * ``include/bluetooth/services/hrs.h``
  * ``include/bluetooth/services/bas.h``
