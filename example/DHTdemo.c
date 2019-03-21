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

int main(void)
{
	_delay_ms(100);
	USART_send_string("\r\n");
	USART_init(38400);
	USART_send_string("DHT11 tester\r\n");
	
	int16_t temp = 0;
	uint8_t hum = 0;
	
	
    while(1)
    {
	    DHT11_getData(&temp, &hum);
	    sprintf(buf, "T: %i C\t H: %u%%\r\n", temp, hum);
	    USART_send_string(buf);
		_delay_ms(1000);
    }
}