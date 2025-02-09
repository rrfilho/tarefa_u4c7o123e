#include "hardware/pwm.h"

static const uint PWM_LED = 12;
static const uint PWM_SERVO = 22;
static const float CLOCK_DIVIDER = 100.0;
static const uint WRAP = 25000;
static const uint MIN_DUTY_CICLE = 0;
static const uint MAX_DUTY_CICLE = 100;

void pwmx_init_pin(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_clkdiv(slice, CLOCK_DIVIDER);
    pwm_set_wrap(slice, WRAP);
    pwm_set_gpio_level(pin, MIN_DUTY_CICLE);
    pwm_set_enabled(slice, true);
}

void pwmx_init() {
    pwmx_init_pin(PWM_LED);
    pwmx_init_pin(PWM_SERVO);
}

void pwmx_set_power(float power) {
    if (power > MAX_DUTY_CICLE) power = MAX_DUTY_CICLE;
    if (power < MIN_DUTY_CICLE) power = MIN_DUTY_CICLE;
    uint level = WRAP * power/100;
    pwm_set_gpio_level(PWM_LED, level);
    pwm_set_gpio_level(PWM_SERVO, level);
}