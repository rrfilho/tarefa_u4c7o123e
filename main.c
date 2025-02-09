#include <stdio.h>
#include "pico/stdlib.h"
#include "pwm.h"

const float MIN_POWER = 2.5f;
const float MAX_POWER = 12.0f;
const float POWER_STEP = 0.025f; 
int rise = 1;
float power = MIN_POWER;

void initial_moves() {
    pwmx_set_power(12);
    sleep_ms(5000);
    pwmx_set_power(7.35);
    sleep_ms(5000);
    pwmx_set_power(2.5);
    sleep_ms(5000);
}

int main() {
    stdio_init_all();
    pwmx_init();
    initial_moves();
    while (true) {
        rise = (power >= MIN_POWER && power <= MAX_POWER) ? rise : -1 * rise;
        power = power + rise * POWER_STEP;
        pwmx_set_power(power);
        sleep_ms(10);
    }
}