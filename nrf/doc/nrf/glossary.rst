.. _glossary:

Glossary
########

.. contents::
   :local:
   :depth: 2

.. glossary::
   :sorted:

   Access Port Protection (APPROTECT)
      A register used to prevent read and write access to all CPU registers and memory-mapped addresses.

   Anycast addressing
      An addressing type that routes datagrams to a single member of a group of potential receivers that are all identified by the same destination address.
      This is a one-to-nearest association.

   API call return code
      An indication of success or failure of an API call.
      In case of failure, a comprehensive error code indicating the cause or reason for the failure is provided.

   Application
      An implementation example that includes a variety of libraries to implement a specific use case.
      It is possible to create a programmable image from it, as it includes a ``main()`` entry point.

   Application Programming Interface (API)
      A language and message format used by an application program to communicate with an operating system, application, or other services.

   Attribute Protocol (ATT)
      "[It] allows a device referred to as the server to expose a set of attributes and their associated values to a peer device referred to as the client."
      `Bluetooth Core Specification`_, Version 5.3, Vol 3, Part F, Section 1.1.

   AT command
      A command used to control the modem.

   Band-Pass Filter (BPF)
      An electronic device or circuit that passes frequencies within a certain range and rejects frequencies outside that range.

   Bluetooth® LE Controller layer
      A layer of the Bluetooth LE protocol stack that implements the :term:`Link Layer (LL)`.

   Bluetooth® LE Host layer
      A layer of the Bluetooth LE protocol stack comprised of multiple (non real-time) network and transport protocols enabling applications to communicate with peer devices in a standard and interoperable way.

   Board
      In Zephyr and the |NCS|, a data structure for describing the hardware on the development kit, its configuration files, and the variant (secure or non-secure) of the build.

   Branch
      A line of development composed of a sequence of :term:`commits <Commit>`.

   Carrier Wave (CW)
      A single-frequency electromagnetic wave that can be modulated in amplitude, frequency, or phase to convey information.

   Cat-M1
      LTE-M User Equipment (UE) category with a single RX antenna, specified in 3GPP Release 13.

   Cat-NB1
      Narrowband Internet of Things (NB-IoT) User Equipment (UE) category with 200 kHz UE bandwidth and a single RX antenna, specified in 3GPP Release 13.

   Certificate-Authenticated Session Establishment (CASE)
      A method of establishing a secure session between two network nodes, using the operational credentials obtained by the nodes during their commissioning into the network.

   Chain of Trust
      A sequence of properties identifying the trustworthiness of each layer in the system, all the way back to a property in the system referred to as :term:`Root of Trust (RoT)`.
      A secure system depends on building and maintaining a chain of trust through all the layers in the system.
      Each step in this chain guarantees that the next step can be trusted to have certain properties because any unauthorized modification of a subsequent step will be detected and the process halted.

   Clear to Send (CTS)
      In :term:`flow control <Hardware Flow Control (HWFC)>`, the receiving end is ready and telling the far end to start sending.

   Clone
      A local copy of a remote Git :term:`repository <Repository>` obtained using the command ``git clone``.

   Cluster
      In the context of a :ref:`Matter <ug_matter>` or :ref:`Zigbee <ug_zigbee>` network, a cluster is a representation of a single functionality within the network.
      Each cluster contains attributes that are stored in the device’s memory and commands that can be used to modify or read the state of the device, including the cluster attributes.
      Clusters appropriate for a single device type such as a sensor or a light bulb are organized into an addressable container that is called an endpoint.

   Commissioning
      In a thread mesh network, the process of authenticating and joining new devices to the network.

   Commit
      A snapshot of the history of each project file, taken at a specific moment in time.
      It is associated with a unique SHA and a message describing the edits it contains.

   Commit tag
      A tag prepended to the first line of the commit message to ease filtering and identification of particular :term:`commit <Commit>` types.

   Contribution
      A change to the codebase sent to a remote :term:`repository <Repository>` for inclusion.

   Cortex Microcontroller Software Interface Standard (CMSIS)
      A vendor-independent hardware abstraction layer for the Cortex-M processor series that defines generic tool interfaces.

   Data Terminal Ready (DTR)
      A control signal in RS-232 serial communications transmitted from data terminal equipment, such as a computer, to data communication equipment.

   Development Kit (DK)
      A hardware development platform used for application development.

   Device Firmware Update (DFU)
      A mechanism for upgrading the firmware of a device.

   Devicetree
      A data structure for describing hardware and its boot-time configuration, including peripherals on a development kit, boot-time clock frequencies, and interrupt lines.

   Devicetree Specification (DTSpec)
      A document that defines the source and binary representations of a :term:`devicetree <Devicetree>`, along with some common characteristics of the data structure, such as interrupts and memory addressing.

   Device Under Test (DUT)
      A manufactured product undergoing testing.

   Docker
      A set of software tools using OS-level virtualization to create and run applications and their dependencies in self-contained environments called :term:`Docker containers <Docker container>`.

   Docker container
      A self-contained environment created by running a :term:`Docker container image` in the :term:`Docker engine`.

   Docker container image
      A standard set of binary data that contains an application (or more than one) and all the required dependencies.
      When run on the :term:`Docker engine`, it creates a :term:`Docker container`.

   Docker engine
      The :term:`Docker container` runtime that runs :term:`Docker images <Docker container image>`.

   Domain Name System (DNS)
      A hierarchical distributed naming system for computers, services, or any resource connected to the Internet or a private network.
      It associates various information with domain names assigned to each of the participating entities.
      Most prominently, it translates domain names, which can be easily memorized by humans, to the numerical IP addresses needed for computer services and devices worldwide.
      The Domain Name System is an essential component of the functionality of most Internet services because it is the Internet's primary directory service.

   Downstream fork
      A :term:`repository <Repository>` located downstream, relative to another repository, in the flow of information.
      See :ref:`dm_repo_types`.

   Endpoint
      In the context of a :ref:`Matter <ug_matter>` or :ref:`Zigbee <ug_zigbee>` network, an addressable container that contains *clusters* appropriate for a single device type such as a sensor or a light bulb.

   Evaluation Kit (EK)
      A platform used to evaluate different development platforms.

   Extended Discontinuous Reception (eDRX)
      A method to conserve the battery of an Internet of Things (IoT) device by allowing it to remain inactive for extended periods.

   Firmware Over-the-Air (FOTA) update
      A firmware update performed remotely over-the-air (OTA).

   Floating-Point Unit (FPU)
      A part of a CPU specially designed to perform operations on floating-point numbers.

   Fork
      A server-hosted downstream copy of an upstream :term:`repository <Repository>` that intends to follow the changes made in the original upstream repository as time goes by, while at the same time keeping some other changes unique to it.
      It can be hosted on GitHub or elsewhere.

   GitHub fork
      A `GitHub fork`_ is a copy of a repository inside GitHub, that allows the user to create a :term:`Pull Request`.

   General Packet Radio Services (GPRS)
      Packet-based mobile data service for 2G and 3G mobile networks with data rates of 56-114 kbps/second and continuous connection to the Internet.

   General-Purpose Input/Output (GPIO)
      A digital signal pin that can be used as input, output, or both.
      It is uncommitted and controllable by the user at runtime.

   General-Purpose Input/Output Tasks and Events (GPIOTE)
      A module that provides functionality for accessing GPIO pins using tasks and events.
      Each GPIOTE channel can be assigned to one pin.

   Generic Access Profile (GAP)
      A base profile that all Bluetooth devices implement.
      It defines the basic requirements of a Bluetooth device.
      See `Bluetooth Core Specification`_, Version 5.3, Vol 1, Part A, Section 6.2.

   Generic Attribute Profile (GATT)
      "Generic Attribute Profile (GATT) is built on top of the Attribute Protocol (ATT) and establishes common operations and a framework for the data transported and stored by the Attribute Protocol."
      `Bluetooth Core Specification`_, Version 5.3, Vol 1, Part A, Section 6.4.2.

   Global Navigation Satellite System (GNSS)
      A satellite navigation system with global coverage.
      The system provides signals from space transmitting positioning and timing data to GNSS receivers, which use this data to determine location.

   Global Positioning System (GPS)
      A satellite-based radio navigation system that provides its users with accurate location and time information over the globe.

   Hardware Flow Control (HWFC)
      A handshaking mechanism used to prevent an overflow of bytes in modems.
      It uses two dedicated pins on the RS-232 connector, :term:`Request to Send (RTS)` and :term:`Clear to Send (CTS)`.

   Host Controller Interface (HCI)
      Standardized communication between the host stack (for example, a PC or mobile phone OS) and the controller (the Bluetooth IC).
      This standard allows the host stack or controller IC to be swapped with minimal adaptation.

   Human Interface Device (HID)
      Type of a computer device that interacts directly with, and most often takes input from, humans and may deliver output to humans.
      The term *HID* most commonly refers to the USB-HID specification.
      This standard allows the host stack or controller IC to be swapped with minimal adaptation.

   Integrated Circuit (IC)
      A semiconductor chip consisting of fabricated transistors, resistors, and capacitors.

   Integrated Circuit Card Identifier (ICCID)
      A unique serial number of a SIM card.

   Integrated Development Environment (IDE)
      A software application that provides facilities for software development.

   International Mobile (Station) Equipment Identity (IMEI)
      A unique code consisting of 14 digits and one check digit for identifying 3GPP-based mobile devices.

   Internet Control Message Protocol (ICMP)
      The control protocol of the IP stack that enables the establishment of reachability, routes, and so on.
      This protocol is an integral part of any IP but is unique as it is not a transport protocol to exchange data between hosts.

   Internet Protocol version 4 (IPv4)
      The fourth version in the development of the Internet Protocol (IP).
      It is the communications protocol that provides an identification and location system for computers on networks.
      It routes most traffic on the Internet.

   Internet Protocol version 6 (IPv6)
      The latest version of the Internet Protocol (IP).
      It is the communications protocol that provides an identification and location system for computers on networks and routes traffic across the Internet.

   IPv4 address
      A numerical label that is used to identify a network interface of a computer or other network node participating in an IPv4 computer network.

   IPv6 address
      An alphanumerical label that is used to identify a network interface of a computer or other network node participating in an IPv6 computer network.

   Kconfig file
      A configuration file for a module or a sample, written in the :term:`Kconfig language` syntax.
      It defines build-time configuration options, also called symbols, namely application-specific values for one or more kernel configuration options.
      It also defines how they are grouped into menus and sub-menus, and dependencies between them that determine what configurations are valid.
      Kconfig files use the :file:`.conf` extension.

   Kconfig fragment
      A configuration file used for building an application image with or without software support from specific :term:`Kconfig options <Kconfig option>`.
      Examples include things like whether to add networking support or which drivers are needed by the application.
      Kconfig fragments use the :file:`.conf` extension.

   Kconfig language
      A `configuration language <Kconfig language_>`_ used in Kconfig files and fragments.
      It was initially created for the Linux kernel.

   Kconfig option
      A configuration option used in a :term:`Kconfig file` or :term:`fragment <Kconfig fragment>`.

   Kconfig project configuration
      A :term:`Kconfig fragment`, usually called :file:`prj.conf`, used to define default :term:`Kconfig options <Kconfig option>` for an application.
      These are foundational options for the application that will always be applied to its built image.
      However, they can be overridden by applying an additional :term:`Kconfig fragment` at build time.

   Link Layer (LL)
      "A control protocol for the link and physical layers that is carried over logical links in addition to user data."
      `Bluetooth Core Specification`_, Version 5.3, Vol 1, Part A, Section 1.2.
      It is implemented in the Bluetooth LE Controller layer.

   Logical Link Control and Adaptation Protocol (L2CAP)
      A protocol used within the Bluetooth protocol stack.
      "[It] provides a channel-based abstraction to applications and services.
      It carries out segmentation and reassembly of application data and multiplexing and de-multiplexing of multiple channels over a shared logical link."
      `Bluetooth Core Specification`_, Version 5.3, Vol 1, Part A, Section 1.1.

   Low Latency Packet Mode (LLPM)
      A mode that allows shorter connection intervals than specified in the `Bluetooth Core Specification`_.

   Low-Noise Amplifier (LNA)
      In a radio receiving system, an electronic amplifier that amplifies a very low-power signal without significantly degrading its signal-to-noise ratio.

   LTE-M
      An open standard that is most suitable for medium-throughput applications requiring low power, low latency, and/or mobility, like asset tracking, wearables, medical, Point of Sale (POS), and home security applications.
      Also known as Cat-M1.

   Lightweight Machine to Machine (LwM2M)
      An application layer protocol.
      It defines the service architecture for IoT devices and the protocol for device management.

   Man-in-the-Middle (MITM)
      A man-in-the-middle attack is a form of eavesdropping where communication between two devices is monitored and modified by an unauthorized party who relays information between the two devices giving the illusion that they are directly connected.

   Mass Storage Device (MSD)
      Any storage device that makes it possible to store and port large amounts of data in a permanent and machine-readable fashion.

   Matter controller
      A role of a Matter node meant to initiate communication and control other nodes in a Matter network.

   Matter device
      In :ref:`ug_matter`, a physical equipment with appropriate firmware that allows to create a single or several Matter *network nodes*.
      A Matter device can operate in an IPv6 network, such as :ref:`ug_thread`.
      Also referred to as *Matter accessory device*.

   Maximum Transmission Unit (MTU)
      The largest packet or frame that can be sent in a single network-layer transaction.

   MCUboot
      A secure bootloader for 32-bit microcontroller units, which is independent of hardware and operating system.

   Mcumgr
      A management library for 32-bit MCUs.
      It uses the :term:`Simple Management Procotol (SMP)`.

   Memory Watch Unit (MWU)
      A peripheral that can be used to generate events when a memory region is accessed by the CPU.

   Message Queue Telemetry Transport (MQTT)
      A machine-to-machine (M2M) connectivity protocol used by some IoT devices.
      It is designed as an extremely lightweight publish/subscribe messaging transport.
      It is useful for connections with remote locations where a small code footprint is required and/or network bandwidth is at a premium.
      For example, it has been used in sensors communicating to a broker through a satellite link, over occasional dial-up connections with healthcare providers, and in a range of home automation and small device scenarios.

   Microcontroller Unit (MCU)
      A small computer on an integrated circuit.

   Menuconfig
      A tool to view and edit Kconfig settings.
      It was initially created for the Linux kernel.
      It uses the Kconfig configuration language.

   Multicast addressing
      An addressing type that uses a one-to-many association, where datagrams are routed from a single sender to multiple selected endpoints simultaneously in a single transmission.

   Narrowband Internet of Things (NB-IoT)
      A narrowband technology standard with longer range, lower throughput, and better penetration in, for example, cellars and parking garages compared to LTE-M.
      NB-IoT is most suitable for static, low throughput applications like smart metering, smart agriculture, and smart city applications.
      Also known as Cat-NB1.

   Near Field Communication (NFC)
      A standards-based short-range wireless connectivity technology that enables two electronic devices to establish communication by bringing them close to each other.

   Network Co-Processor (NCP)
      A co-processor offloading network functions from the host processor.
      In the |NCS| context, it is typically used in :term:`OpenThread` and Zigbee platform designs.

   Network node
      An element of a mesh network that has a unique network address, a role, and a type.
      Such nodes are proper of :ref:`Thread <ug_thread>` or :ref:`Bluetooth mesh <ug_bt_mesh>` networks.

      In the context of :ref:`Matter <ug_matter>` or :ref:`Zigbee <ug_zigbee>` networks, a network node also has a unique ID and operational credentials.
      After being commissioned into the respective network, it can be controlled remotely using *clusters*.

   Network Time Protocol (NTP)
      A networking protocol for clock synchronization between computer systems over packet-switched, variable-latency data networks.

   NFC-A Listen Mode
      The initial mode of an NFC Forum Device when it does not generate a carrier.
      The device listens for the remote field of another device.
      See :term:`Near Field Communication (NFC)`.

   Noise Factor (NF)
      The relation of the :term:`Signal-to-Noise Ratio (SNR)` in the device input to the SNR in the device output.

   Non-volatile Memory (NVM)
      A type of memory that can retrieve stored information even after having been power-cycled.

   Non-volatile Memory Controller (NVMC)
      A controller used for writing and erasing the internal flash memory and the :term:`User Information Configuration Registers (UICR)`.

   nRF Cloud
      Nordic Semiconductor's platform for connecting IoT devices to the cloud, viewing and analyzing device message data, prototyping ideas that use Nordic Semiconductor chips, and more.
      It includes a public REST API that can be used for building IoT solutions.
      See `nRF Cloud`_.

   nRF repository
      An |NCS| repository, hosted in the `nrfconnect GitHub organization`_, that does not have an externally maintained, open-source upstream.
      It is exclusive to Nordic development.

   nRF Secure Immutable Bootloader (NSIB)
      A bootloader created and maintained by Nordic Semiconductor that is built on Chain of Trust architecture.

   OpenAMP
      A framework that provides software components that enable the development of software applications for Asymmetric Multiprocessing (AMP) systems.
      See `OpenAMP`_.

   OpenThread
      A portable and flexible `open-source implementation <OpenThread.io_>`_ of the Thread networking protocol.

   OpenThread Border Router (OTBR)
      A router that connects a Thread network to other IP-based networks, like Wi-Fi or Ethernet.
      A Thread network requires a Border Router to connect to other networks.

   Operating System (OS)
      A set of functions and data structures that manages system resources, hardware components, and the execution of programs and processes.
      It is usually composed of a kernel, a scheduler, a file system, a memory manager, and other components.

   Operational Amplifier (op-amp)
      A high-gain voltage amplifier that has a differential input and, usually, a single output.

   OSS repository
      An |NCS| repository, hosted in the `nrfconnect GitHub organization`_, that tracks an upstream Open Source Software counterpart that is externally maintained.

   Out-of-Band (OOB)
      A communication channel that is outside of the defined activity.
      For example, in Bluetooth® Low Energy, Out-of-Band pairing can be used to share encryption keys or authentication data using a different communication channel (such as NFC).

   Over-the-Air (OTA)
      Any type of wireless transmission.

   Packet Traffic Arbitration (PTA)
      A collaborative coexistence mechanism for colocated wireless protocols.

   Password-Authenticated Session Establishment (PASE)
      A method of establishing a secure session between two network nodes, using a pre-shared secret.

   Patch
      A method to describe changes in one or more source code files.
      It does not require a repository.
      Sometimes it is improperly used as a synonym of :term:`commit <Commit>`.

   Personal Unblocking Key (PUK)
      A key used to to reset a PIN that has been lost or forgotten for a SIM card.

   Power Amplifier (PA)
      A device used to increase the transmit power level of a radio signal.

   Power Management Integrated Circuit (PMIC)
      A chip used for various functions related to power management.

   Power Saving Mode (PSM)
      A feature introduced in 3GPP Release 12 to improve the battery life of IoT (Internet of Things) devices by minimizing energy consumption.
      The device stays dormant during the PSM window.

   Preview Development Kit (PDK)
      A development platform used for application development.
      A Preview Development Kit uses an engineering sample of the chip and it is not production-ready in comparison to the Development Kit that uses a production-ready version of the chip.

   Printed Circuit Board (PCB)
      A board that connects electronic components.

   Programmable Peripheral Interconnect (PPI)
      It enables peripherals to interact autonomously with each other using tasks and events independently of the CPU.

   Protocol Data Unit (PDU)
      Information transferred as a single unit between peer entities of a computer network and containing control and address information or data.
      PDU mode is one of the two ways of sending and receiving SMS messages.

   Provisioning
      * In a Thread Mesh network, the process of associating a device to the appropriate service, and performing any application or vendor-specific configuration.
        It is a step in the commissioning process.
      * In a Bluetooth Mesh network, the process of adding devices to the network.
      * In a bootloader, the process of storing public key hashes in a separate region of memory from the bootloader image.

   Pull Request
      A set of :term:`commits <Commit>` that are sent to contribute to a :term:`repository <Repository>`.

   Qualified Design Identification (QDID)
      A unique identifier assigned to a design that has completed the Bluetooth Qualification Process.

   Quality of Service (QoS)
      The measured overall performance of a service, such as a network, a connection, or a cloud computing service.

   Radio Co-Processor (RCP)
      A co-processor offloading radio functions from the host processor.
      In the |NCS| context, it is typically used in :term:`OpenThread` and Zigbee platform designs.

   Real-time operating system (RTOS)
      An operating system that reacts to input within a specific period of time.
      A real-time deadline can be so small that system reaction appears instantaneous.

   Real-Time Transfer (RTT)
      Proprietary technology for bidirectional communication that supports J-Link devices and Arm-based microcontrollers, developed by SEGGER Microcontroller.

   Receive Data (RXD)
      A signal line in a serial interface that receives data from another device.

   Received Signal Strength Indication (RSSI)
      An indication of the power of a received radio signal.

   Remote Procedure Call (RPC)
      A form of inter-process communication that allows for calling a function on remote processors from a local processor, both synchronously and asynchronously.

   Repository
      The entire set of files and folders of which a project is composed, together with the revision history of each file.
      It is often composed of multiple branches.
      It is also known as *Git repository* or *Git project*, and is similar to a *Git submodule*.

   Request to Send (RTS)
      In :term:`flow control <Hardware Flow Control (HWFC)>`, the transmitting end is ready and requesting the far end for permission to transfer data.

   Root of Trust (RoT)
      The property or component in a secure system that provides the foundation of a :term:`Chain of Trust`.

   Sample
      An implementation example that showcases a single feature or library.
      It is possible to create a programmable image from it, as it includes a ``main()`` entry point.

   Secure Access Port Protection (SECUREAPPROTECT)
      A register used to prevent read and write access to all secure CPU registers and secure memory-mapped addresses.
      See :term:`Access Port Protection (APPROTECT)`.

   Security Manager Protocol (SMP)
      A protocol used for pairing and key distribution.

   SEGGER Embedded Studio (SES)
      A cross-platform Integrated Development Environment (IDE) for embedded C/C++ programming with support for Nordic Semiconductor devices, produced by SEGGER Microcontroller.
      The |NCS| uses a custom :ref:`Nordic Edition of SES <installing_ses>`.

   Signal-to-Noise Ratio (SNR)
      The level of signal power compared to the level of noise power, often expressed in decibels (dB).

   Simple Management Procotol (SMP)
      A transport protocol used by :term:`Mcumgr`.

   Simple Network Time Protocol (SNTP)
      A less complex implementation of :term:`Network Time Protocol (NTP)`, using the same protocol but without requiring the storage of state over extended periods of time.

   Soft fork
      A :term:`fork <Fork>` that contains a very small set of changes when compared to its upstream.

   SoftDevice
      A wireless protocol stack that complements the nRF5 Series SoCs.
      Nordic Semiconductor provides these stacks as qualified, precompiled binary files.

   Software Development Kit (SDK)
      A set of tools used for developing applications for a specific device or operating system.

   Spinel
      A general management protocol for enabling a host device to communicate with and manage co-processors, like a network co-processor (NCP) or a radio co-processor (RCP).

   Submodule
      A child of another Git :term:`repository <Repository>`, managed using the ``git submodule`` command family.
      Also referred to as *Git submodule*.

   Supervisor Call (SVC)
      It generates a software exception in which access to system resources or privileged operations can be provided.

   System in Package (SiP)
      Several integrated circuits, often from different technologies, enclosed in a single module that performs as a system or subsystem.

   System on Chip (SoC)
      A microchip that integrates all the necessary electronic circuits and components of a computer or other electronic systems on a single integrated circuit.

   System Protection Unit (SPU)
      The central point in the system that controls access to memories, peripherals, and other resources.
      It is a peripheral used only by Nordic Semiconductor.

   Target
      The goal of an operation, for example, programming a specific image on a device, compiling a specific set of files, or removing previously generated files.

   Transmission Control Protocol (TCP)
      A connection-oriented protocol that provides reliable transport.
      This reliability comes at the cost of control packets overhead of the protocol itself, making it unsuitable for bandwidth-constrained applications.

   Toolchain
      A set of development tools.
      See `GNU Arm Embedded Toolchain`_.

   Transmit Data (TXD)
      A signal line in a serial interface that transmits data to another device.

   UART Hardware Flow Control (UART HWFC)
      A handshaking mechanism used to prevent a buffer overflow in the receiver (in embedded computing use cases).
      In a serial connection, when the transmission baud rate is high enough for data to appear faster than it can be processed by the receiver, the communicating devices can synchronize with each other, using :term:`Request to Send (RTS)` and :term:`Clear to Send (CTS)` pins.

   Unicast addressing
      An addressing type that uses a one-to-one association between the destination address and the network endpoint.
      Each destination address uniquely identifies a single receiver endpoint.

   Universal Asynchronous Receiver/Transmitter (UART)
      A hardware device for asynchronous serial communication between devices.

   Universal Serial Bus (USB)
      An industry standard that establishes specifications for cables and connectors and protocols for connection, communication, and power supply between computers, peripheral devices, and other computers.

   Upmerge
      In the |NCS|, the act of updating (synchronizing) a downstream :term:`repository <Repository>` with a newer revision of its :term:`upstream <Upstream repository>` OSS repository.

   Upstream repository
      A :term:`repository <Repository>` located upstream, relative to another repository, in the flow of information.
      See :ref:`dm_repo_types`.

   User Datagram Protocol (UDP)
      One of the core IP protocols.
      UDP with its connectionless model, no handshaking dialogues makes it a suitable transport for systems with constrained bandwidth like Bluetooth low energy.

   User Information Configuration Registers (UICR)
      Non-volatile memory registers used to configure user-specific settings.

   Watchdog timer (WDT)
      A timer that causes a system reset if it is not poked periodically.

   West
      A command-line tool providing a management system for multiple :term:`repositories <Repository>`, used by Zephyr and the |NCS|.
      It is expandable, as you can write your own extension commands to add additional features.
      See :ref:`zephyr:west`.

   West manifest file
      The main file describing the contents of a :term:`West` workspace, which is located in the :term:`West manifest repository`.
      In the |NCS| and Zephyr, it is named :file:`west.yml`.

   West manifest repository
      A :term:`repository <Repository>` that contains a :term`West manifest file`` and can be used to configure a west workspace.
      See :ref:`dm_repo_types`.

   West project
      Any of the listed :term:`repositories <Repository>` inside a :term:`West manifest file`.

   Wireshark
      A free software tool that captures wireless traffic and reproduces it in a readable format.
      It is a cross-platform network protocol analyzer that can be used to view, analyze, and troubleshoot packets sent over a data network.
