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
	
	
	#if SPK_EN	
		SPK_DDR |= (1<<SPK_WIRE);
		
		for(int i = 0; i < 50; i++) {
			SPK_PORT |= (1<<SPK_WIRE);
			_delay_ms(1);
			SPK_PORT &=~ (1<<SPK_WIRE);
			_delay_ms(1);
		}
		_delay_ms(10);
		for(int i = 0; i < 50; i++) {
			SPK_PORT |= (1<<SPK_WIRE);
			_delay_ms(1);
			SPK_PORT &=~ (1<<SPK_WIRE);
			_delay_ms(1);
		}
		_delay_ms(10);
		for(int i = 0; i < 50; i++) {
			SPK_PORT |= (1<<SPK_WIRE);
			_delay_ms(1);
			SPK_PORT &=~ (1<<SPK_WIRE);
			_delay_ms(1);
		}
		SPK_PORT &=~ (1<<SPK_WIRE);
	#endif
	
    while(1)
    {
	    if(DHT11_getData(&temp, &hum)) {		
			//sprintf(buf, "T: %i C\t H: %u%%\r\n", temp, hum);
			sprintf(buf, "$%d %d;\r\n", temp, hum);
			USART_send_string(buf);
			
			#if SPK_EN
				for(int i = 0; i < 25; i++) {
					SPK_PORT |= (1<<SPK_WIRE);
					_delay_us(500);
					SPK_PORT &=~ (1<<SPK_WIRE);
					_delay_us(500);
				}
				SPK_PORT &=~ (1<<SPK_WIRE);			
			#endif
		}
		else {			
			USART_send_string("DHT11 error\r\n");
			
			#if SPK_EN
				for(int i = 0; i < 1000; i++) {
					SPK_PORT |= (1<<SPK_WIRE);
					_delay_us(500);
					SPK_PORT &=~ (1<<SPK_WIRE);
					_delay_us(500);
				}
				SPK_PORT &=~ (1<<SPK_WIRE);
			#endif
		}
		_delay_ms(10000);
    }
}