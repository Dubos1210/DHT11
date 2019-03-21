/*
 * DHT11 AVR C library
 * Author: Vladimir Dubos
 * http://dubos.tech
 * http://github.com/Dubos1210/DHT11
 *
 */
 
#ifndef DHT11_H_
#define DHT11_H_

#define DHT_WIRE		2
#define DHT_DDR			DDRD
#define DHT_PORT		PORTD
#define DHT_PIN			PIND

#define DHT11_CHECKSUM	true	//Write "false" or "0" to disable checksum checking

#define DHT11_OK		0xFF
#define DHT11_ERROR		0x00

uint8_t DHT11_getData(int16_t* temperature, uint8_t* humidity);
uint8_t DHT11_readByte(void);

#endif /* DHT11_H_ */