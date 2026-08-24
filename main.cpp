#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

constexpr uint LED_PIN = 25;
constexpr uint USR_BUTTON_PIN = 24;

volatile bool button_pressed = false;
volatile absolute_time_t blink_start_time;
bool has_message_sent = false;

void usr_button_with_irq();
void gpio_callback(uint gpio, uint32_t events);

int main() {
    usr_button_with_irq();

    return 0;
}

void usr_button_with_irq() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    gpio_init(USR_BUTTON_PIN);
    gpio_set_dir(USR_BUTTON_PIN, GPIO_IN);
    gpio_pull_up(USR_BUTTON_PIN);

    gpio_set_irq_enabled_with_callback(USR_BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true) {
        if (button_pressed) {
            if (!has_message_sent) {
                printf(">> Button pressed\n");
                has_message_sent = true;
            }

            if (absolute_time_diff_us(blink_start_time, get_absolute_time()) >= 100000) {
                gpio_put(LED_PIN, 0);
                button_pressed = false;
                has_message_sent = false;
            }
        }

        sleep_ms(10);
    }
}

void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == USR_BUTTON_PIN && (events & GPIO_IRQ_EDGE_FALL)) {
        gpio_put(LED_PIN, 1);
        blink_start_time = get_absolute_time();
        button_pressed = true;
    }
}