#pragma once

#include <stdbool.h>
#include "stm32l4xx_hal.h"
#include "errors.h"

#define EUART_HAL_INIT					(EUART_BASE + 0)
#define EUART_TX_SEMPH					(EUART_BASE + 1)
#define EUART_RX_SEMPH					(EUART_BASE + 2)
#define EUART_TX_TIMEOUT				(EUART_BASE + 3)
#define EUART_RX_TIMEOUT				(EUART_BASE + 4)
#define EUART_TX						(EUART_BASE + 5)
#define EUART_RX						(EUART_BASE + 6)

err_t uart_tx(const uint8_t *p_buf, uint32_t size, uint32_t timeout_ticks, bool blocking);
err_t uart_rx(uint8_t *p_buf, uint32_t size, uint32_t timeout_ticks);
err_t uart_config_set(UART_InitTypeDef *p_config);
err_t uart_init(void);
