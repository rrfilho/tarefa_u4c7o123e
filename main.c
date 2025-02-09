#include <stdio.h>
#include "pico/stdlib.h"
#include "pwm.h"

const float DOWN_DUTY_CYCLE = 2.5f;
const float TOP_DUTY_CYCLE = 12.0f;
const float DUTY_CYCLE_STEP = 0.025f;
int rise = 1;
float duty_cycle = DOWN_DUTY_CYCLE;

void initial_moves() {
    pwmx_set_duty_cycle(12);
    sleep_ms(5000);
    pwmx_set_duty_cycle(7.35);
    sleep_ms(5000);
    pwmx_set_duty_cycle(2.5);
    sleep_ms(5000);
}

int main() {
    stdio_init_all();
    pwmx_init();
    initial_moves();
    while (true) {
        rise = (duty_cycle >= DOWN_DUTY_CYCLE && duty_cycle <= TOP_DUTY_CYCLE) ? rise : -1 * rise;
        duty_cycle = duty_cycle + rise * DUTY_CYCLE_STEP;
        pwmx_set_duty_cycle(duty_cycle);
        sleep_ms(10);
    }
}