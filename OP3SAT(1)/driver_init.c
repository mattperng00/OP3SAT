/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_adc_base.h>

/*! The buffer size for USART */
#define SERIAL_BUFFER_SIZE 16

struct spi_m_sync_descriptor  SPI_0;
struct usart_async_descriptor SERIAL;
struct timer_descriptor       TIMER_0;

static uint8_t SERIAL_buffer[SERIAL_BUFFER_SIZE];

struct adc_sync_descriptor ADC_0;

struct flash_descriptor FLASH_0;

struct pwm_descriptor PWM_0;

struct ac_sync_descriptor AC_0;

struct dac_sync_descriptor DAC_0;

void ADC_0_PORT_init(void)
{
}

void ADC_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, ADC);
	_gclk_enable_channel(ADC_GCLK_ID, CONF_GCLK_ADC_SRC);
}

void ADC_0_init(void)
{
	ADC_0_CLOCK_init();
	ADC_0_PORT_init();
	adc_sync_init(&ADC_0, ADC, (void *)NULL);
}

void EXTERNAL_IRQ_0_init(void)
{
	_gclk_enable_channel(EIC_GCLK_ID, CONF_GCLK_EIC_SRC);

	ext_irq_init();
}

void FLASH_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBB, NVMCTRL);
}

void FLASH_0_init(void)
{
	FLASH_0_CLOCK_init();
	flash_init(&FLASH_0, NVMCTRL);
}

void SPI_0_PORT_init(void)
{

	gpio_set_pin_level(PA00,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA00, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA00, PINMUX_PA00D_SERCOM1_PAD0);

	gpio_set_pin_level(PA01,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(PA01, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(PA01, PINMUX_PA01D_SERCOM1_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(PA18, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PA18,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PA18, PINMUX_PA18C_SERCOM1_PAD2);
}

void SPI_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM1);
	_gclk_enable_channel(SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC);
}

void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_m_sync_init(&SPI_0, SERCOM1);
	SPI_0_PORT_init();
}

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void SERIAL_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void SERIAL_PORT_init()
{

	gpio_set_pin_function(PA24, PINMUX_PA24C_SERCOM3_PAD2);

	gpio_set_pin_function(PA25, PINMUX_PA25C_SERCOM3_PAD3);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void SERIAL_init(void)
{
	SERIAL_CLOCK_init();
	usart_async_init(&SERIAL, SERCOM3, SERIAL_buffer, SERIAL_BUFFER_SIZE, (void *)NULL);
	SERIAL_PORT_init();
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void PWM_0_PORT_init(void)
{
}

void PWM_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC0);
	_gclk_enable_channel(TC0_GCLK_ID, CONF_GCLK_TC0_SRC);
}

void PWM_0_init(void)
{
	PWM_0_CLOCK_init();
	PWM_0_PORT_init();
	pwm_init(&PWM_0, TC0, _tc_get_pwm());
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC1);
	_gclk_enable_channel(TC1_GCLK_ID, CONF_GCLK_TC1_SRC);

	timer_init(&TIMER_0, TC1, _tc_get_timer());
}

void AC_0_PORT_init(void)
{
}

void AC_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBC, AC);
	_gclk_enable_channel(AC_GCLK_ID_DIG, CONF_GCLK_DIG_AC_SRC);
	_gclk_enable_channel(AC_GCLK_ID_ANA, CONF_GCLK_ANA_AC_SRC);
}

void AC_0_init(void)
{
	AC_0_CLOCK_init();
	ac_sync_init(&AC_0, AC);
	AC_0_PORT_init();
}

void DAC_0_PORT_init(void)
{
}

void DAC_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBC, DAC);
	_gclk_enable_channel(DAC_GCLK_ID, CONF_GCLK_DAC_SRC);
}

void DAC_0_init(void)
{
	DAC_0_CLOCK_init();
	dac_sync_init(&DAC_0, DAC);
	DAC_0_PORT_init();
}

/**
 * \brief PTC initialization function
 *
 * Enables PTC peripheral, clocks and initializes PTC driver
 */
static void PTC_0_clock_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, PTC);
	_gclk_enable_channel(PTC_GCLK_ID, CONF_GCLK_PTC_SRC);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA14

	gpio_set_pin_level(BLINK,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   0);

	// Set pin direction to output
	gpio_set_pin_direction(BLINK, GPIO_DIRECTION_OUT);
	
	gpio_set_pin_level(BLINK,
	// <y> Initial level
	// <id> pad_initial_level
	// <false"> Low
	// <true"> High
	0);
	
	gpio_set_pin_function(BLINK, GPIO_PIN_FUNCTION_OFF);

	ADC_0_init();
	EXTERNAL_IRQ_0_init();

	FLASH_0_init();

	SPI_0_init();
	SERIAL_init();

	delay_driver_init();

	PWM_0_init();

	TIMER_0_init();
	AC_0_init();

	DAC_0_init();

	PTC_0_clock_init();
}
