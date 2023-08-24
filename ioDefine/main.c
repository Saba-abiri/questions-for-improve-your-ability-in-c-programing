#include <io.h>
#include <stdint.h>
#include <delay.h>
#include <soft_pwm.c>    
#include <math.h>

uint8_t i=0 , cnt =0;
uint16_t slow =0;
uint8_t pulse[100];
uint8_t pulse_sin[100];
void main(void)
{
    Gpio_PinConfig channel1 = {
        &GPIOA, Gpio_Pin0
    };
    Gpio_PinConfig channel2 = {
        &GPIOA, Gpio_Pin1
    };
                  
    for(i=0;i<100;i++)
    {   
        if(i < 50 )
            pulse[i] = i/4; 
        else
            pulse[i] = 25 - i/4; 
    } 
    for(i=0;i<100;i++)
    {   
        pulse_sin[i] = 10*(sin(2*PI*i/100)+1);    
    }
    
    SoftPWM_add(&channel1, 50);
    SoftPWM_add(&channel2, 50);  
    SoftPWM_init();
    
    while(1)
    {   
        if(1000 == slow)
        {
            if(100 > cnt )
            {   
                SoftPWM_dutychnge(0 , pulse[cnt]);
                SoftPWM_dutychnge(1 , pulse_sin[cnt]);
                cnt++;         
            } 
            else
            {
                cnt=0;
            }
            slow = 0;
        } 
        else
        {
            slow++;
        }
        
        SoftPWM_IRQ();
    }
}
