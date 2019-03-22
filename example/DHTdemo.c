/*
 * DHT_test.c
 *
 * Created: 21.03.2019 15:18:05
 *  Author: Vladimir
 */ 

#include "settings.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include "USART.h"
#include "DHT11.h"

char buf[32];
int8_t temp = 0;
uint8_t hum = 0;

int main(void)
{
	_delay_ms(10);
	USART_send(0);
	USART_init(38400);
	USART_send_string("DHT11 tester\r\n");	
	
    while(1)
    {
	    if(DHT11_getData(&temp, &hum)) {		
			//sprintf(buf, "T: %i C\t H: %u%%\r\n", temp, hum);
			sprintf(buf, "$%i;%u\r\n", temp, hum);
			USART_send_string(buf);
		}
		else {			
			USART_send_string("DHT11 error\r\n");
		}
		_delay_ms(2000);
    }
}