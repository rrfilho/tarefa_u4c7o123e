#include "hardware/pwm.h"

static const uint PWM_LED = 12;
static const uint PWM_SERVO = 22;
static const float CLOCK_DIVIDER = 100.0;
static const uint WRAP = 25000;
static const uint MIN_DUTY_CYCLE = 0;
static const uint MAX_DUTY_CYCLE = 100;

void pwmx_init_pin(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_clkdiv(slice, CLOCK_DIVIDER);
    pwm_set_wrap(slice, WRAP);
    pwm_set_gpio_level(pin, MIN_DUTY_CYCLE);
    pwm_set_enabled(slice, true);
}

void pwmx_init() {
    pwmx_init_pin(PWM_LED);
    pwmx_init_pin(PWM_SERVO);
}

void pwmx_set_duty_cycle(float duty_cycle) {
    if (duty_cycle > MAX_DUTY_CYCLE) duty_cycle = MAX_DUTY_CYCLE;
    if (duty_cycle < MIN_DUTY_CYCLE) duty_cycle = MIN_DUTY_CYCLE;
    uint level = WRAP * duty_cycle/100;
    pwm_set_gpio_level(PWM_LED, level);
    pwm_set_gpio_level(PWM_SERVO, level);
}