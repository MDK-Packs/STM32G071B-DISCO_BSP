# STMicroelectronics STM32G071B-DISCO

## Overview

The STM32G071B-DISCO Discovery board is a demonstration and development platform for the STMicroelectronics Arm® Cortex® -M0+ core-based STM32G071RB USB Type-C™ and Power Delivery microcontroller.
The STM32G071B-DISCO Discovery board is presented with all necessary interfaces for easy connection and interoperability with other USB Type-C™ devices.
The STM32G071B-DISCO Discovery board is intended for discovery and display of USB Type-C™ port characteristics such as data role, power role, VBUS and IBUS monitoring. STM32G071B-DISCO board photoIt offers an advanced user mode when associated with the STM32CubeMonUCPD software GUI and can be used as a USB Type-C™ and Power Delivery analyzer.

## Schematics

- [STM32G071B-DISCO board schematic](https://www.st.com/resource/en/schematic_pack/mb1378-c02_schematic.pdf)

## CMSIS-Drivers

This board support pack contains a CMSIS-Driver for the [VIO](https://arm-software.github.io/CMSIS_5/develop/Driver/html/group__vio__interface__gr.html) interface.
This is a virtual I/O abstraction for peripherals that are typically used in example projects.
The **Blinky** example uses this interface to create a blinking light with the USER LED mounted on the board that can be controlled by the **Button USER**.

Virtual Resource  | Variable       | Physical Resource on STM32G071B-DISCO                    |
:-----------------|:---------------|:---------------------------------------------------------|
vioBUTTON0        | vioSignalIn.0  | GPIO C.0:  Joystic SELECT (with define VIO_BUTTON_REMAP) |
vioJOYup          | vioSignalIn.4  | GPIO C.4:  Joystic UP                                    |
vioJOYdown        | vioSignalIn.5  | GPIO C.2:  Joystic DOWN                                  |
vioJOYleft        | vioSignalIn.6  | GPIO C.1:  Joystic LEFT                                  |
vioJOYright       | vioSignalIn.7  | GPIO C.3:  Joystic RIGHT                                 |
vioJOYselect      | vioSignalIn.8  | GPIO C.0:  Joystic SELECT                                |
vioLED0           | vioSignalOut.0 | GPIO D.9:  LD4 ORANGE                                    |
vioLED1           | vioSignalOut.1 | GPIO D.8:  LD5                                           |
vioLED2           | vioSignalOut.2 | GPIO D.5:  LD6 GREEN                                     |
vioLED3           | vioSignalOut.3 | GPIO C.12: LD7                                           |

Refer to the [schematics](#schematics) for board connection information.
