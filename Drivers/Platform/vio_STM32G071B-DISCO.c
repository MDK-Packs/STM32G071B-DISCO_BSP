/******************************************************************************
 * @file     vio_STM32G071B-DISCO.c
 * @brief    Virtual I/O implementation for board STM32G071B-DISCO
 * @version  V2.0.0
 * @date     9. October 2023
 ******************************************************************************/
/*
 * Copyright (c) 2021-2023 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*! \page vio_STM32G071B-DISCO Physical I/O Mapping

The table below lists the physical I/O mapping of this CMSIS-Driver VIO implementation.

Virtual Resource  | Variable       | Physical Resource on STM32G071B-DISCO          |
:-----------------|:---------------|:-----------------------------------------------|
vioBUTTON0        | vioSignalIn.0  | GPIO C.0:  Joystic SELECT (with define VIO_BUTTON_REMAP) |
vioJOYup          | vioSignalIn.4  | GPIO C.4:  Joystic UP                          |
vioJOYdown        | vioSignalIn.5  | GPIO C.2:  Joystic DOWN                        |
vioJOYleft        | vioSignalIn.6  | GPIO C.1:  Joystic LEFT                        |
vioJOYright       | vioSignalIn.7  | GPIO C.3:  Joystic RIGHT                       |
vioJOYselect      | vioSignalIn.8  | GPIO C.0:  Joystic SELECT                      |
vioLED0           | vioSignalOut.0 | GPIO D.9:  LD4 ORANGE                          |
vioLED1           | vioSignalOut.1 | GPIO D.8:  LD5                                 |
vioLED2           | vioSignalOut.2 | GPIO D.5:  LD6 GREEN                           |
vioLED3           | vioSignalOut.3 | GPIO C.12: LD7                                 |
*/

/* History:
 *  Version 2.0.0
 *    Updated to API 1.0.0
 *  Version 1.0.0
 *    Initial release
 */

#include <string.h>
#include "cmsis_vio.h"

#include "RTE_Components.h"                 // Component selection
#include CMSIS_device_header

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
#include "stm32g071b_discovery.h"
#endif

// VIO input, output definitions
#define VIO_VALUE_NUM           3U          // Number of values

// VIO input, output variables
__USED uint32_t vioSignalIn;                // Memory for incoming signal
__USED uint32_t vioSignalOut;               // Memory for outgoing signal
__USED int32_t  vioValue[VIO_VALUE_NUM];    // Memory for value used in vioGetValue/vioSetValue

#if !defined CMSIS_VOUT
// Add global user types, variables, functions here:

#endif

#if !defined CMSIS_VIN
// Add global user types, variables, functions here:

#endif

// Initialize test input, output.
void vioInit (void) {
#if !defined CMSIS_VOUT
// Add user variables here:

#endif
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  vioSignalIn  = 0U;
  vioSignalOut = 0U;

  memset(vioValue, 0, sizeof(vioValue));

#if !defined CMSIS_VOUT
  // Initialize LEDs pins
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);
  BSP_LED_Init(LED7);
#endif

#if !defined CMSIS_VIN
  // Initialize joystick pins
  BSP_JOY_Init(JOY_MODE_GPIO);
#endif
}

// Set signal output.
void vioSetSignal (uint32_t mask, uint32_t signal) {
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  vioSignalOut &= ~mask;
  vioSignalOut |=  mask & signal;

#if !defined CMSIS_VOUT
  // Output signals to LEDs
  if ((mask & vioLED0) != 0U) {
    if ((signal & vioLED0) != 0U) {
      BSP_LED_On(LED4);
    } else {
      BSP_LED_Off(LED4);
    }
  }

  if ((mask & vioLED1) != 0U) {
    if ((signal & vioLED1) != 0U) {
      BSP_LED_On(LED5);
    } else {
      BSP_LED_Off(LED5);
    }
  }

  if ((mask & vioLED2) != 0U) {
    if ((signal & vioLED2) != 0U) {
      BSP_LED_On(LED6);
    } else {
      BSP_LED_Off(LED6);
    }
  }

  if ((mask & vioLED3) != 0U) {
    if ((signal & vioLED3) != 0U) {
      BSP_LED_On(LED7);
    } else {
      BSP_LED_Off(LED7);
    }
  }
#endif
}

// Get signal input.
uint32_t vioGetSignal (uint32_t mask) {
  uint32_t signal;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

#if !defined CMSIS_VIN
  // Get input signals from joystick
#if defined VIO_BUTTON_REMAP
  if ((mask & vioBUTTON0) != 0U) {
    if (BSP_JOY_GetState() == (!JOY_NONE) ) {
      vioSignalIn |=  vioBUTTON0;
    } else {
      vioSignalIn &= ~vioBUTTON0;
    }
  }
#endif

  if ((mask & vioJOYup) != 0U) {
    if (BSP_JOY_GetState() == JOY_UP) {
      vioSignalIn |=  vioJOYup;
    } else {
      vioSignalIn &= ~vioJOYup;
    }
  }

  if ((mask & vioJOYselect) != 0U) {
    if (BSP_JOY_GetState() == JOY_SEL) {
      vioSignalIn |=  vioJOYselect;
    } else {
      vioSignalIn &= ~vioJOYselect;
    }
  }

  if ((mask & vioJOYright) != 0U) {
    if (BSP_JOY_GetState() == JOY_RIGHT) {
      vioSignalIn |=  vioJOYright;
    } else {
      vioSignalIn &= ~vioJOYright;
    }
  }

  if ((mask & vioJOYleft) != 0U) {
    if (BSP_JOY_GetState() == JOY_LEFT) {
      vioSignalIn |=  vioJOYleft;
    } else {
      vioSignalIn &= ~vioJOYleft;
    }
  }

  if ((mask & vioJOYdown) != 0U) {
    if (BSP_JOY_GetState() == JOY_DOWN) {
      vioSignalIn |=  vioJOYdown;
    } else {
      vioSignalIn &= ~vioJOYdown;
    }
  }
#endif

  signal = vioSignalIn & mask;

  return signal;
}

// Set value output.
void vioSetValue (uint32_t id, int32_t value) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioValue[index] = value;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get value input.
int32_t vioGetValue (uint32_t id) {
  uint32_t index = id;
  int32_t  value = 0;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return value;                       /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioValue[index] = ...;
#endif

  value = vioValue[index];

  return value;
}
