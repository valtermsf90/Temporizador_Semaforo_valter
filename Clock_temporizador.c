#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_G 11 //pino led verde
#define LED_R 13 //pino led vermelho

bool status = true;
int sinal = 0;

bool semaforo(struct repeating_timer *t) {
   
   if(sinal == 3){
        sinal = 1;
    }else{
        sinal++;
    }
    switch (sinal)
    {
    case 1:
        gpio_put(LED_G, !status);
        gpio_put(LED_R, status);
        printf("vermelho\n");
        break;
        case 2:
        gpio_put(LED_G, status);
        gpio_put(LED_R, status);
        printf("amarelo\n");
        break;
        case 3:
        gpio_put(LED_G, status);
        gpio_put(LED_R, !status);   
        printf("verde\n");
        break;    
    default:
        break;
    }
    return true;
}





int main()
{
    stdio_init_all();

    gpio_init(LED_G);
    gpio_init(LED_R);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_R, GPIO_OUT);

   struct repeating_timer timer ;
   add_repeating_timer_ms(3000, semaforo, NULL, &timer);
   
    while (true) {
        printf("Respeite a sinalização.\n");
        sleep_ms(1000);
    }

    return 0;
}
