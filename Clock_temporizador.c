#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_G 11 // pino led verde
#define LED_B 12 // pino led amarelo
#define LED_R 13 // pino led vermelho

bool status = true;
int sinal = 1;

// semaforo
bool semaforo(struct repeating_timer *t)
{
    // troca sinal
    if (sinal == 3)
    {
        sinal = 1;
    }
    else
    {
        sinal++;
    }
    switch (sinal) // verifica sinal
    {
    case 1: // vermelho
        gpio_put(LED_G, !status);
        gpio_put(LED_R, status);
        gpio_put(LED_B, !status);
        printf("PARE\n");
        break;
    case 2: // amarelo
        gpio_put(LED_G, !status);        
        gpio_put(LED_R, !status);        
        gpio_put(LED_B, status);
        printf("ATENÇÃO\n");
        break;
    case 3: // verde
        gpio_put(LED_G, status);
        gpio_put(LED_R, !status);
        gpio_put(LED_B, !status);
        printf("SIGA\n");
        break;
    }
    return true;
}

int main()
{
    // inicia comunicacao serial
    stdio_init_all();

    // inicia GPIO
    gpio_init(LED_G);
    gpio_init(LED_R);
    gpio_init(LED_B);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);

    // inicia led vermelho ligado
    gpio_put(LED_R, status);

    // inicia semaforo
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, semaforo, NULL, &timer);

    // loop
    while (true)
    {
        printf("Respeite a sinalização.\n");
        sleep_ms(1000);
    }

    return 0;
}
