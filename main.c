/**
 * Copyright (c) 2015 - 2017, Nordic Semiconductor ASA
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 * 
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
/** @file
 * @defgroup pwm_example_main main.c
 * @{
 * @ingroup pwm_example
 *
 * @brief  PWM Example Application main file.
 *
 * This file contains the source code for a sample application using PWM.
 *
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "app_error.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "app_pwm.h"
#include "nrf_log.h"

APP_PWM_INSTANCE(PWM0,0);
APP_PWM_INSTANCE(PWM1,1);                   // Create the instance "PWM1" using TIMER1.

static volatile bool ready_flag;            // A flag indicating PWM status.
static volatile uint32_t pre_value  = 1; // previous position of the pan motor.
static volatile uint32_t pre_value1 = 1; // previous position of the tilt motor.

void pwm_ready_callback(uint32_t pwm_id)    // PWM callback function
{
    ready_flag = true;
}

void home_set(void)
{
   while (app_pwm_channel_duty_set(&PWM0,0,1) == NRF_ERROR_BUSY);
   nrf_delay_ms(20);
   while (app_pwm_channel_duty_set(&PWM1,0,1) == NRF_ERROR_BUSY);
   nrf_delay_ms(1000);
}
 void pan_clockwise(uint32_t value)
     {
         for (uint8_t i = pre_value; i < value; i++)
        {
        while (app_pwm_channel_duty_set(&PWM0, 0, i) == NRF_ERROR_BUSY);
        nrf_delay_ms(20);
        }
        pre_value= value;

        app_pwm_disable(&PWM0);
     } 

     void pan_a_clockwise(uint32_t value)
     {
         for (uint8_t i = pre_value ; i > value; i--)
        {
        while (app_pwm_channel_duty_set(&PWM0, 0, i) == NRF_ERROR_BUSY);
        nrf_delay_ms(20);
        }
        pre_value= value;
     } 
     
     void tilt_up(uint32_t value)
     {
          for (uint8_t i = pre_value1; i < value; i++)
        {
        while (app_pwm_channel_duty_set(&PWM1, 0, i) == NRF_ERROR_BUSY);
        nrf_delay_ms(20);
        }
        pre_value1= value;
     }
     
     void tilt_down(uint32_t value)
     {
          for (uint8_t i = pre_value1 ; i > value; i--)
        {
        while (app_pwm_channel_duty_set(&PWM1, 0, i) == NRF_ERROR_BUSY);
        nrf_delay_ms(20);
        }
        pre_value1= value;
     }

     uint32_t val_cal(uint32_t x)
     {
         double val;
         uint32_t value;
         val = x;
         value = (((val/4095) * 90) + 5) ;
        // NRF_LOG_INFO("%lu", value);
        return value;
     }
     

int main(void)
{
    ret_code_t err_code;
   // int flag = 1;
    /* 2-channel PWM, 200Hz, output on DK LED pins. */
    app_pwm_config_t pwm_s1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(4000L, 17);
    app_pwm_config_t pwm_s2_cfg = APP_PWM_DEFAULT_CONFIG_1CH(4000L, 18);

    /* Switch the polarity of the second channel. */
    pwm_s1_cfg.pin_polarity[0] = APP_PWM_POLARITY_ACTIVE_HIGH;
    pwm_s2_cfg.pin_polarity[0] = APP_PWM_POLARITY_ACTIVE_HIGH;

    /* Initialize and enable PWM. */
    err_code = app_pwm_init(&PWM0,&pwm_s1_cfg,pwm_ready_callback);
    APP_ERROR_CHECK(err_code);

    err_code = app_pwm_init(&PWM1,&pwm_s2_cfg,pwm_ready_callback);
    APP_ERROR_CHECK(err_code);

    app_pwm_enable(&PWM0);
    app_pwm_enable(&PWM1);

    home_set();
    uint32_t x= 2048;

     val_cal(x);

    pan_clockwise(val_cal(x));

    while (true)
    {
      // do nothing;

    }

}


/** @} */
