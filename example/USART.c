/* USART Library for Atmel AVR v0.4
 *  USART_init(9600);           //������������� USART �� �������� 9600 ���
 *  USART_send(0x**);           //�������� ����� 0x**
 *  USART_send_BK();            //�������� ������� "������� �������" (0x0D 0x0A)
 *  USART_send_string("Hello"); //�������� ������ Hello
 *  USART_send_integer(123);    //�������� ����� 0123 � ���� ASCII-�������� (����. - 9999)
 *  USART_send_long(12345);     //�������� �������� ����� � ���� ASCII-��������
 *  USART_send_decimal(123, 1); //�������� ���������� ����� 12,3 � ���� ASCII-��������
 */



#ifndef DUBOS_USART_C
#define DUBOS_USART_C

#include "settings.h"
#include <avr/io.h>
#include <string.h>
#include "USART.h"


/********************************************************************
 * �������	: ������������� USART
 * ��������	: baudrate (300, 600, 1 200, 2 400, 4 800, 9 600, 19 200,
			  38 400, 57 600, 115 200, 230 400, 460 800, 921 600)
 ********************************************************************/
void USART_init(unsigned int baud) {  
	DDRD &=~ (1<<0); //PD0 (RX) - ����� 
	DDRD |= (1<<1); //PD1 (TX) - ���� 
	
	unsigned int USART_ubrr = F_CPU / 16 / baud - 1;
	UBRR0H = (unsigned char) (USART_ubrr >> 8);
	UBRR0L = (unsigned char) USART_ubrr;
	UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (0<<USBS0)|(1<<UCSZ01)|(1<<UCSZ00);
}

/********************************************************************
 * �������	: �������� �����
 * ��������	: ���� ��� ��������
 ********************************************************************/
void USART_send(unsigned char s) {
	while(!(UCSR0A & (1<<UDRE0))) {};
	UDR0 = s;
}

/********************************************************************
 * �������	: �������� ������� "������� �������" (0x0D, 0x0A)
 ********************************************************************/
void USART_send_BK(void) {
	USART_send(0x0D);
	USART_send(0x0A);
}

/********************************************************************
 * �������	: �������� ������
 * ��������	: ������ ��� ��������
 ********************************************************************/
void USART_send_string(const unsigned char *data) {
	unsigned char c;
	while(( c = *data++ )) {
		USART_send(c);
	}
}

#endif