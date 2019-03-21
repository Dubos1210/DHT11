/* USART Library for Atmel AVR v0.4
 *  USART_init(9600);           //Инициализация USART на скорости 9600 бод
 *  USART_send(0x**);           //Отправка байта 0x**
 *  USART_send_BK();            //Отправка сигнала "Возврат каретки" (0x0D 0x0A)
 *  USART_send_string("Hello"); //Отправка строки Hello
 *  USART_send_integer(123);    //Отправка числа 0123 в виде ASCII-символов (макс. - 9999)
 *  USART_send_long(12345);     //Отправка большого числа в виде ASCII-символов
 *  USART_send_decimal(123, 1); //Отправка десятичной дроби 12,3 в виде ASCII-символов
 */


#ifndef DUBOS_USART_H
#define DUBOS_USART_H

unsigned char str[16];

void USART_init(unsigned int baud);
void USART_send(unsigned char s);
void USART_send_BK(void);
void USART_send_string(const unsigned char *data);

#endif