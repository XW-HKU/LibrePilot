/**
 ******************************************************************************
 * @addtogroup OpenPilotSystem OpenPilot System
 * @{
 * @addtogroup OpenPilotCore OpenPilot Core
 * @{
 * @file       pios_board.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @brief      Defines board hardware for the OpenPilot Version 1.1 hardware.
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef PIOS_BOARD_H
#define PIOS_BOARD_H

#include <stdbool.h>

// ------------------------
// Timers and Channels Used
// ------------------------
/*
   Timer | Channel 1 | Channel 2 | Channel 3 | Channel 4
   ------+-----------+-----------+-----------+----------
   TIM1  |           |           |           |
   TIM2  | --------------- PIOS_DELAY -----------------
   TIM3  |           |           |           |
   TIM4  |           |           |           |
   TIM5  |           |           |           |
   TIM6  |           |           |           |
   TIM7  |           |           |           |
   TIM8  |           |           |           |
   ------+-----------+-----------+-----------+----------
 */

// ------------------------
// DMA Channels Used
// ------------------------
/* Channel 1  -                                 */
/* Channel 2  - SPI1 RX                         */
/* Channel 3  - SPI1 TX                         */
/* Channel 4  - SPI2 RX                         */
/* Channel 5  - SPI2 TX                         */
/* Channel 6  -                                 */
/* Channel 7  -                                 */
/* Channel 8  -                                 */
/* Channel 9  -                                 */
/* Channel 10 -                                 */
/* Channel 11 -                                 */
/* Channel 12 -                                 */

// ------------------------
// BOOTLOADER_SETTINGS
// ------------------------
#define BOARD_READABLE     true
#define BOARD_WRITABLE     true
#define MAX_DEL_RETRYS     3

// ------------------------
// PIOS_LED
// ------------------------
#define PIOS_LED_HEARTBEAT 0
#define PIOS_LED_ALARM     1

// ------------------------
// PIOS_SPI
// See also pios_board.c
// ------------------------
#define PIOS_SPI_MAX_DEVS        3
extern uint32_t pios_spi_gyro_id;
extern uint32_t pios_spi_accel_id;
#define PIOS_SPI_L3GD20_ADAPTER  (pios_spi_gyro_id)
#define PIOS_SPI_BMA180_ADAPTER  (pios_spi_accel_id)
#define PIOS_SPI_MPU6000_ADAPTER (pios_spi_gyro_id)

// ------------------------
// PIOS_WDG
// ------------------------
#define PIOS_WATCHDOG_TIMEOUT    250
#define PIOS_WDG_REGISTER        RTC_BKP_DR4
#define PIOS_WDG_ACTUATOR        0x0001
#define PIOS_WDG_STABILIZATION   0x0002
#define PIOS_WDG_ATTITUDE        0x0004
#define PIOS_WDG_MANUAL          0x0008
#define PIOS_WDG_SENSORS         0x0010
#define PIOS_WDG_AUTOTUNE        0x0020

// ------------------------
// PIOS_I2C
// See also pios_board.c
// ------------------------
#define PIOS_I2C_MAX_DEVS                 3
extern uint32_t pios_i2c_mag_adapter_id;
extern uint32_t pios_i2c_pressure_adapter_id;

#define PIOS_I2C_MS5611_INTERNAL_ADAPTER  (pios_i2c_pressure_adapter_id)
#define PIOS_I2C_HMC5X83_INTERNAL_ADAPTER (pios_i2c_mag_adapter_id)

extern uint32_t pios_i2c_flexiport_adapter_id;
#define PIOS_I2C_FLEXI_ADAPTER            (pios_i2c_flexiport_adapter_id)
#define PIOS_I2C_ETASV3_ADAPTER           (PIOS_I2C_FLEXI_ADAPTER)
#define PIOS_I2C_EXTERNAL_ADAPTER         (pios_i2c_flexiport_adapter_id)


// -------------------------
// PIOS_USART
//
// See also pios_board.c
// -------------------------
#define PIOS_USART_MAX_DEVS         5
// Inverter for SBUS handling
#define PIOS_USART_INVERTER_PORT    UART4
#define PIOS_USART_INVERTER_GPIO    GPIOC
#define PIOS_USART_INVERTER_PIN     GPIO_Pin_3
#define PIOS_USART_INVERTER_ENABLE  Bit_SET
#define PIOS_USART_INVERTER_DISABLE Bit_RESET

// -------------------------
// PIOS_COM
//
// See also pios_board.c
// -------------------------
#define PIOS_COM_MAX_DEVS 4
// extern uint32_t pios_com_telem_rf_id;
// extern uint32_t pios_com_gps_id;
// extern uint32_t pios_com_aux_id;
// extern uint32_t pios_com_telem_usb_id;
// extern uint32_t pios_com_bridge_id;
// extern uint32_t pios_com_vcp_id;
// extern uint32_t pios_com_hkosd_id;
// extern uint32_t pios_com_msp_id;
// extern uint32_t pios_com_mavlink_id;
//
// #define PIOS_COM_AUX          (pios_com_aux_id)
// #define PIOS_COM_GPS          (pios_com_gps_id)
// #define PIOS_COM_TELEM_USB    (pios_com_telem_usb_id)
// #define PIOS_COM_TELEM_RF     (pios_com_telem_rf_id)
// #define PIOS_COM_BRIDGE       (pios_com_bridge_id)
// #define PIOS_COM_VCP          (pios_com_vcp_id)
// #define PIOS_COM_DEBUG        PIOS_COM_AUX
// #define PIOS_COM_OSDHK        (pios_com_hkosd_id)
// #define PIOS_COM_MSP          (pios_com_msp_id)
// #define PIOS_COM_MAVLINK      (pios_com_mavlink_id)

// ------------------------
// TELEMETRY
// ------------------------
#define TELEM_QUEUE_SIZE      80
#define PIOS_TELEM_STACK_SIZE 800

// -------------------------
// System Settings
//
// See also System_stm32f4xx.c
// -------------------------
// These macros are deprecated
// please use PIOS_PERIPHERAL_APBx_CLOCK According to the table below
// #define PIOS_MASTER_CLOCK
// #define PIOS_PERIPHERAL_CLOCK
// #define PIOS_PERIPHERAL_CLOCK

#define PIOS_SYSCLK 168000000
// Peripherals that belongs to APB1 are:
// DAC			|PWR				|CAN1,2
// I2C1,2,3		|UART4,5			|USART3,2
// I2S3Ext		|SPI3/I2S3		|SPI2/I2S2
// I2S2Ext		|IWDG				|WWDG
// RTC/BKP reg
// TIM2,3,4,5,6,7,12,13,14

// Calculated as SYSCLK / APBPresc * (APBPre == 1 ? 1 : 2)
// Default APB1 Prescaler = 4
#define PIOS_PERIPHERAL_APB1_CLOCK (PIOS_SYSCLK / 2)

// Peripherals belonging to APB2
// SDIO			|EXTI				|SYSCFG			|SPI1
// ADC1,2,3
// USART1,6
// TIM1,8,9,10,11
//
// Default APB2 Prescaler = 2
//
#define PIOS_PERIPHERAL_APB2_CLOCK   PIOS_SYSCLK

// -------------------------
// Interrupt Priorities
// -------------------------
#define PIOS_IRQ_PRIO_LOW            12              // lower than RTOS
#define PIOS_IRQ_PRIO_MID            8               // higher than RTOS
#define PIOS_IRQ_PRIO_HIGH           5               // for SPI, ADC, I2C etc...
#define PIOS_IRQ_PRIO_HIGHEST        4               // for USART etc...
// ------------------------
// PIOS_RCVR
// See also pios_board.c
// ------------------------
#define PIOS_RCVR_MAX_DEVS           3
#define PIOS_RCVR_MAX_CHANNELS       12
#define PIOS_GCSRCVR_TIMEOUT_MS      100

// -------------------------
// Receiver PPM input
// -------------------------
#define PIOS_PPM_MAX_DEVS            1
#define PIOS_PPM_NUM_INPUTS          16

// -------------------------
// Receiver PWM input
// -------------------------
#define PIOS_PWM_MAX_DEVS            1
#define PIOS_PWM_NUM_INPUTS          8

// -------------------------
// Receiver SPEKTRUM input
// -------------------------
#define PIOS_SPEKTRUM_MAX_DEVS       2
#define PIOS_SPEKTRUM_NUM_INPUTS     12

// -------------------------
// Receiver S.Bus input
// -------------------------
#define PIOS_SBUS_MAX_DEVS           1
#define PIOS_SBUS_NUM_INPUTS         (16 + 2)

// -------------------------
// Receiver DSM input
// -------------------------
#define PIOS_DSM_MAX_DEVS            2
#define PIOS_DSM_NUM_INPUTS          12

// -------------------------
// Servo outputs
// -------------------------
#define PIOS_SERVO_UPDATE_HZ         50
#define PIOS_SERVOS_INITIAL_POSITION 0 /* dont want to start motors, have no pulse till settings loaded */
#define PIOS_SERVO_BANKS             6

// --------------------------
// Timer controller settings
// --------------------------
#define PIOS_TIM_MAX_DEVS            6

// -------------------------
// ADC
// PIOS_ADC_PinGet(0) = Current sensor
// PIOS_ADC_PinGet(1) = Voltage sensor
// PIOS_ADC_PinGet(2) = VREF
// PIOS_ADC_PinGet(3) = Temperature sensor
// PIOS_ADC_PinGet(4) = Board Power
// -------------------------
#define PIOS_DMA_PIN_CONFIG                                                                         \
    {                                                                                                   \
        { GPIOC, GPIO_Pin_0, ADC_Channel_10, true },                                                        \
        { GPIOC, GPIO_Pin_1, ADC_Channel_11, true },                                                        \
        { NULL, 0, ADC_Channel_Vrefint, true }, /* Voltage reference */         \
        { NULL, 0, ADC_Channel_TempSensor, true }, /* Temperature sensor */        \
        { GPIOC, GPIO_Pin_2, ADC_Channel_12, true }  \
    }

/* we have to do all this to satisfy the PIOS_ADC_MAX_SAMPLES define in pios_adc.h */
/* which is annoying because this then determines the rate at which we generate buffer turnover events */
/* the objective here is to get enough buffer space to support 100Hz averaging rate */
#define PIOS_ADC_NUM_CHANNELS     4
#define PIOS_ADC_MAX_OVERSAMPLING 2
#define PIOS_ADC_USE_ADC2         0

#define PIOS_ADC_USE_TEMP_SENSOR
#define PIOS_ADC_TEMPERATURE_PIN  3          /* V */

// -------------------------
// USB
// -------------------------
#define PIOS_USB_MAX_DEVS         1
#define PIOS_USB_ENABLED          1 /* Should remove all references to this */
#define PIOS_USB_HID_MAX_DEVS     1

#endif /* PIOS_BOARD_H */

/**
 * @}
 * @}
 */
