#include <stdbool.h>
#include <stm8s.h>
#include "main.h"
#include "milis.h"
// Nucleo Kit
#define LED_PORT GPIOC
#define LED_PIN  GPIO_PIN_5
#define BTN_PORT GPIOE
#define BTN_PIN  GPIO_PIN_4


void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);      // taktovani MCU na 16MHz
    init_milis();

    GPIO_Init(LED_PORT, LED_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

}


int main(void)
{
  
    uint32_t time = 0;
    bool btn_state = PUSH(BTN);

    init();

    while (1) {
        if (milis() - time > 10 ) {
            time = milis();
            
            if (btn_state != 1 && PUSH(BTN) == 1) {
                REVERSE(LED);
            }
            btn_state = PUSH(BTN);
        }
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
