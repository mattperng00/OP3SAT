/* Auto-generated config file hpl_tc_config.h */
#ifndef HPL_TC_CONFIG_H
#define HPL_TC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <peripheral_clk_config.h>

#ifndef CONF_TC0_ENABLE
#define CONF_TC0_ENABLE 1
#endif

// <h> Basic settings

// <y> Prescaler
// <TC_CTRLA_PRESCALER_DIV1_Val"> No division
// <TC_CTRLA_PRESCALER_DIV2_Val"> Divide by 2
// <TC_CTRLA_PRESCALER_DIV4_Val"> Divide by 4
// <TC_CTRLA_PRESCALER_DIV8_Val"> Divide by 8
// <TC_CTRLA_PRESCALER_DIV16_Val"> Divide by 16
// <TC_CTRLA_PRESCALER_DIV64_Val"> Divide by 64
// <TC_CTRLA_PRESCALER_DIV256_Val"> Divide by 256
// <TC_CTRLA_PRESCALER_DIV1024_Val"> Divide by 1024
// <i> This defines the prescaler value
// <id> tc_prescaler
#ifndef CONF_TC0_PRESCALER
#define CONF_TC0_PRESCALER TC_CTRLA_PRESCALER_DIV8_Val
#endif

// </h>

// <h> PWM Waveform Output settings
// <o> Waveform Period Value (uS) <0x00-0xFFFFFFFF>
// <i> The unit of this value is us.
// <id> tc_arch_wave_per_val
#ifndef CONF_TC0_WAVE_PER_VAL
#define CONF_TC0_WAVE_PER_VAL 0x3e8
#endif

// <o> Waveform Duty Value (0.1%) <0x00-0x03E8>
// <i> The unit of this value is 1/1000.
// <id> tc_arch_wave_duty_val
#ifndef CONF_TC0_WAVE_DUTY_VAL
#define CONF_TC0_WAVE_DUTY_VAL 0x1f4
#endif

/* Caculate pwm ccx register value based on WAVE_PER_VAL and Waveform Duty Value */
#if CONF_TC0_PRESCALER < TC_CTRLA_PRESCALER_DIV64_Val
#define CONF_TC0_CC0                                                                                                   \
	((uint32_t)(((double)CONF_TC0_WAVE_PER_VAL * CONF_GCLK_TC0_FREQUENCY) / 1000000 / (1 << CONF_TC0_PRESCALER) - 1))
#define CONF_TC0_CC1 ((CONF_TC0_CC0 * CONF_TC0_WAVE_DUTY_VAL) / 1000)

#elif CONF_TC0_PRESCALER == TC_CTRLA_PRESCALER_DIV64_Val
#define CONF_TC0_CC0 ((uint32_t)(((double)CONF_TC0_WAVE_PER_VAL * CONF_GCLK_TC0_FREQUENCY) / 64000000 - 1))
#define CONF_TC0_CC1 ((CONF_TC0_CC0 * CONF_TC0_WAVE_DUTY_VAL) / 1000)

#elif CONF_TC0_PRESCALER == TC_CTRLA_PRESCALER_DIV256_Val
#define CONF_TC0_CC0 ((uint32_t)(((double)CONF_TC0_WAVE_PER_VAL * CONF_GCLK_TC0_FREQUENCY) / 256000000 - 1))
#define CONF_TC0_CC1 ((CONF_TC0_CC0 * CONF_TC0_WAVE_DUTY_VAL) / 1000)

#elif CONF_TC0_PRESCALER == TC_CTRLA_PRESCALER_DIV1024_Val
#define CONF_TC0_CC0 ((uint32_t)(((double)CONF_TC0_WAVE_PER_VAL * CONF_GCLK_TC0_FREQUENCY) / 1024000000 - 1))
#define CONF_TC0_CC1 ((CONF_TC0_CC0 * CONF_TC0_WAVE_DUTY_VAL) / 1000)
#endif

// </h>

// <h> Advanced settings
// <y> Mode
// <TC_CTRLA_MODE_COUNT16_Val"> Counter in 16-bit mode
// <TC_CTRLA_MODE_COUNT32_Val"> Counter in 32-bit mode
// <i> These bits mode
// <id> tc_arch_mode
#ifndef CONF_TC0_MODE
#define CONF_TC0_MODE TC_CTRLA_MODE_COUNT16_Val
#endif

/*  Unused in 16/32 bit PWM mode */
#ifndef CONF_TC0_PER
#define CONF_TC0_PER 0x32
#endif

/* Commented intentionally. Timer uses fixed value. May be used by other abstractions based on TC. */
//#define CONF_TC0_WAVEGEN   TC_CTRLA_WAVEGEN_MFRQ_Val

// <q> Run in standby
// <i> Indicates whether the will continue running in standby sleep mode or not
// <id> tc_arch_runstdby
#ifndef CONF_TC0_RUNSTDBY
#define CONF_TC0_RUNSTDBY 0
#endif

// <y> Prescaler and Counter Synchronization Selection
// <TC_CTRLA_PRESCSYNC_GCLK_Val"> Reload or reset counter on next GCLK
// <TC_CTRLA_PRESCSYNC_PRESC_Val"> Reload or reset counter on next prescaler clock
// <TC_CTRLA_PRESCSYNC_RESYNC_Val"> Reload or reset counter on next GCLK and reset prescaler counter
// <i> These bits select if on retrigger event, the Counter should be cleared or reloaded on the next GCLK_TCx clock or on the next prescaled GCLK_TCx clock.
// <id> tc_arch_presync
#ifndef CONF_TC0_PRESCSYNC
#define CONF_TC0_PRESCSYNC TC_CTRLA_PRESCSYNC_GCLK_Val
#endif

/* Commented intentionally. Timer uses fixed value. May be used by other abstractions based on TC. */
//#define CONF_TC0_DIR     0
//#define CONF_TC0_ONESHOT 0

/* Commented intentionally. Timer uses fixed value. May be used by other abstractions based on TC. */
//#define CONF_TC0_INVEN0 0
//#define CONF_TC0_INVEN1 0
//#define CONF_TC0_CPTEN0 0
//#define CONF_TC0_CPTEN1 0

// <q> Debug Running Mode
// <i> Indicates whether the Debug Running Mode is enabled or not
// <id> tc_arch_dbgrun
#ifndef CONF_TC0_DBGRUN
#define CONF_TC0_DBGRUN 0
#endif

// </h>

// <e> Event control
// <id> timer_event_control
#ifndef CONF_TC0_EVENT_CONTROL_ENABLE
#define CONF_TC0_EVENT_CONTROL_ENABLE 0
#endif

// <q> Overflow/Underflow Event Output
// <i> Generates event for counter overflows/underflows
// <id> tc_arch_ovfeo
#ifndef CONF_TC0_OVFEO
#define CONF_TC0_OVFEO 0
#endif

// <q> TC Event Asynchronous input
// <i> Enables Asynchronous input events to the TC
// <id> tc_arch_tcei
#ifndef CONF_TC0_TCEI
#define CONF_TC0_TCEI 0
#endif

// <q> TC Inverted Event Input Polarity
// <i> Used to invert the asynchronous input event source
// <id> tc_arch_tceinv
#ifndef CONF_TC0_TCINV
#define CONF_TC0_TCINV 0
#endif

// <y> Event Action
// <i> Defines the event action the TC will perform on an event
// <TC_EVCTRL_EVACT_OFF_Val"> Event action disabled
// <TC_EVCTRL_EVACT_RETRIGGER_Val"> Start, restart or retrigger TC on event
// <TC_EVCTRL_EVACT_COUNT_Val"> Count on event
// <TC_EVCTRL_EVACT_START_Val"> Start TC on event
// <TC_EVCTRL_EVACT_PPW_Val"> Period captured in CC0, pulse width in CC1
// <TC_EVCTRL_EVACT_PWP_Val"> Period captured in CC1, pulse width in CC0
// <id> tc_arch_evact
#ifndef CONF_TC0_EVACT
#define CONF_TC0_EVACT TC_EVCTRL_EVACT_OFF_Val
#endif

// <q> Match/Capture channel 0 Event
// <i> Enables the generation of an event for every match or capture on channel 0
// <id> tc_arch_mceo0
#ifndef CONF_TC0_MCEO0
#define CONF_TC0_MCEO0 0
#endif
// <q> Match/Capture channel 1 Event
// <i> Enables the generation of an event for every match or capture on channel 1
// <id> tc_arch_mceo1
#ifndef CONF_TC0_MCEO1
#define CONF_TC0_MCEO1 0
#endif

// </e>

#ifndef CONF_TC1_ENABLE
#define CONF_TC1_ENABLE 1
#endif

#include "peripheral_clk_config.h"

// <h> Basic configuration

// <y> Prescaler
// <TC_CTRLA_PRESCALER_DIV1_Val"> No division
// <TC_CTRLA_PRESCALER_DIV2_Val"> Divide by 2
// <TC_CTRLA_PRESCALER_DIV4_Val"> Divide by 4
// <TC_CTRLA_PRESCALER_DIV8_Val"> Divide by 8
// <TC_CTRLA_PRESCALER_DIV16_Val"> Divide by 16
// <TC_CTRLA_PRESCALER_DIV64_Val"> Divide by 64
// <TC_CTRLA_PRESCALER_DIV256_Val"> Divide by 256
// <TC_CTRLA_PRESCALER_DIV1024_Val"> Divide by 1024
// <i> This defines the prescaler value
// <id> timer_prescaler
#ifndef CONF_TC1_PRESCALER
#define CONF_TC1_PRESCALER TC_CTRLA_PRESCALER_DIV8_Val
#endif

// <o> Length of one timer tick in uS <0-4294967295>
// <id> timer_tick
#ifndef CONF_TC1_TIMER_TICK
#define CONF_TC1_TIMER_TICK 1000
#endif
// </h>

// <e> Advanced configuration
// <id> timer_advanced_configuration
#ifndef CONF_TC1__ADVANCED_CONFIGURATION_ENABLE
#define CONF_TC1__ADVANCED_CONFIGURATION_ENABLE 0
#endif

// <y> Prescaler and Counter Synchronization Selection
// <TC_CTRLA_PRESCSYNC_GCLK_Val"> Reload or reset counter on next GCLK
// <TC_CTRLA_PRESCSYNC_PRESC_Val"> Reload or reset counter on next prescaler clock
// <TC_CTRLA_PRESCSYNC_RESYNC_Val"> Reload or reset counter on next GCLK and reset prescaler counter
// <i> These bits select if on retrigger event, the Counter should be cleared or reloaded on the next GCLK_TCx clock or on the next prescaled GCLK_TCx clock.
// <id> tc_arch_presync
#ifndef CONF_TC1_PRESCSYNC
#define CONF_TC1_PRESCSYNC TC_CTRLA_PRESCSYNC_GCLK_Val
#endif

// <q> Run in standby
// <i> Indicates whether the module will continue to run in standby sleep mode
// <id> tc_arch_runstdby
#ifndef CONF_TC1_RUNSTDBY
#define CONF_TC1_RUNSTDBY 0
#endif

// <q> Run in debug mode
// <i> Indicates whether the module will run in debug mode
// <id> tc_arch_dbgrun
#ifndef CONF_TC1_DBGRUN
#define CONF_TC1_DBGRUN 0
#endif

// </e>

// <e> Event control
// <id> timer_event_control
#ifndef CONF_TC1_EVENT_CONTROL_ENABLE
#define CONF_TC1_EVENT_CONTROL_ENABLE 0
#endif

// <q> Overflow/Underflow Event Output
// <i> Generates event for counter overflows/underflows
// <id> tc_arch_ovfeo
#ifndef CONF_TC1_OVFEO
#define CONF_TC1_OVFEO 0
#endif

// <q> TC Event Asynchronous input
// <i> Enables Asynchronous input events to the TC
// <id> tc_arch_tcei
#ifndef CONF_TC1_TCEI
#define CONF_TC1_TCEI 0
#endif

// <q> TC Inverted Event Input Polarity
// <i> Used to invert the asynchronous input event source
// <id> tc_arch_tceinv
#ifndef CONF_TC1_TCINV
#define CONF_TC1_TCINV 0
#endif

// <y> Event Action
// <i> Defines the event action the TC will perform on an event
// <TC_EVCTRL_EVACT_OFF_Val"> Event action disabled
// <TC_EVCTRL_EVACT_RETRIGGER_Val"> Start, restart or retrigger TC on event
// <TC_EVCTRL_EVACT_COUNT_Val"> Count on event
// <TC_EVCTRL_EVACT_START_Val"> Start TC on event
// <TC_EVCTRL_EVACT_PPW_Val"> Period captured in CC0, pulse width in CC1
// <TC_EVCTRL_EVACT_PWP_Val"> Period captured in CC1, pulse width in CC0
// <id> tc_arch_evact
#ifndef CONF_TC1_EVACT
#define CONF_TC1_EVACT TC_EVCTRL_EVACT_OFF_Val
#endif

// <q> Match/Capture channel 0 Event
// <i> Enables the generation of an event for every match or capture on channel 0
// <id> tc_arch_mceo0
#ifndef CONF_TC1_MCEO0
#define CONF_TC1_MCEO0 0
#endif
// <q> Match/Capture channel 1 Event
// <i> Enables the generation of an event for every match or capture on channel 1
// <id> tc_arch_mceo1
#ifndef CONF_TC1_MCEO1
#define CONF_TC1_MCEO1 0
#endif

// </e>

// Default values which the driver needs in order to work correctly

// Mode set to 32-bit
#ifndef CONF_TC1_MODE
#define CONF_TC1_MODE TC_CTRLA_MODE_COUNT32_Val
#endif

// CC 1 register set to 0
#ifndef CONF_TC1_CC1
#define CONF_TC1_CC1 0
#endif

// Not used in 32-bit mode
#define CONF_TC1_PER 0

// Calculating correct top value based on requested tick interval.
#define CONF_TC1_PRESCALE (1 << CONF_TC1_PRESCALER)

#if CONF_TC1_PRESCALER > TC_CTRLA_PRESCALER_DIV16_Val
#undef CONF_TC1_PRESCALE
#define CONF_TC1_PRESCALE 64
#endif

#if CONF_TC1_PRESCALER > TC_CTRLA_PRESCALER_DIV64_Val
#undef CONF_TC1_PRESCALE
#define CONF_TC1_PRESCALE 256
#endif

#if CONF_TC1_PRESCALER > TC_CTRLA_PRESCALER_DIV256_Val
#undef CONF_TC1_PRESCALE
#define CONF_TC1_PRESCALE 1024
#endif

#ifndef CONF_TC1_CC0
#define CONF_TC1_CC0                                                                                                   \
	(uint32_t)(((float)CONF_TC1_TIMER_TICK / 1000000.f) / (1.f / (CONF_GCLK_TC1_FREQUENCY / CONF_TC1_PRESCALE)))
#endif

// <<< end of configuration section >>>

#endif // HPL_TC_CONFIG_H
