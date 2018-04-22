#pragma once

#include "stm32l4xx_hal.h"
#include "errors.h"

#define EADC_HAL_INIT			(ADC_BASE + 0)
#define EADC_HAL_CONFIG_CHANNEL	(ADC_BASE + 1)
#define EADC_NO_INIT        	(ADC_BASE + 2)

typedef void (*adc_conversion_ready)(const uint16_t *p_adc_values, uint8_t num_values);

err_t adc_init(void);
err_t adc_start(void);
err_t adc_stop(void);
void adc_set_callback(adc_conversion_ready callback);
