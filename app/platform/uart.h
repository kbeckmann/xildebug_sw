#pragma once

#include <FreeRTOS.h>
#include <queue.h>
#include <stdbool.h>

#include "errors.h"

#define EUART_NO_INIT					(EUART_BASE + 0x00)
#define EUART_DISABLED					(EUART_BASE + 0x01)
#define EUART_INVALID_ARG				(EUART_BASE + 0x02)
#define EUART_HAL_INIT					(EUART_BASE + 0x03)
#define EUART_TX_SEMPH					(EUART_BASE + 0x04)
#define EUART_TX_TIMEOUT				(EUART_BASE + 0x05)
#define EUART_TX						(EUART_BASE + 0x06)
#define EUART_RX_SEMPH					(EUART_BASE + 0x07)
#define EUART_RX_TIMEOUT				(EUART_BASE + 0x08)
#define EUART_RX						(EUART_BASE + 0x09)
#define EUART_FLUSH_RX					(EUART_BASE + 0x0A)

enum uart_stopbits {
	UART_STOPBITS_CONFIG_1		= 0,
	UART_STOPBITS_CONFIG_1_5	= 1,
	UART_STOPBITS_CONFIG_2		= 2,
};

enum uart_parity {
	UART_PARITY_CONFIG_NONE		= 0,
	UART_PARITY_CONFIG_ODD		= 1,
	UART_PARITY_CONFIG_EVEN		= 2,
	UART_PARITY_CONFIG_MARK		= 3,
	UART_PARITY_CONFIG_SPACE	= 4,
};

struct uart_line_coding {
	uint32_t			baudrate_bps;
	enum uart_stopbits	stopbits : 8;
	enum uart_parity	parity : 8;
	uint8_t				databits;
} __packed;

err_t uart_tx(const uint8_t *p_buf, uint32_t size, uint32_t timeout_ticks, bool blocking);
err_t uart_start_rx(QueueHandle_t queue);
err_t uart_flush_rx(void);
err_t uart_config_set(const struct uart_line_coding * const p_config);
err_t uart_enable(void);
err_t uart_disable(void);
err_t uart_init(void);
