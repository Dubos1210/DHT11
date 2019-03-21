/* USART Library for Atmel AVR v0.4
 *  USART_init(9600);           //������������� USART �� �������� 9600 ���
 *  USART_send(0x**);           //�������� ����� 0x**
 *  USART_send_BK();            //�������� ������� "������� �������" (0x0D 0x0A)
 *  USART_send_string("Hello"); //�������� ������ Hello
 *  USART_send_integer(123);    //�������� ����� 0123 � ���� ASCII-�������� (����. - 9999)
 *  USART_send_long(12345);     //�������� �������� ����� � ���� ASCII-��������
 *  USART_send_decimal(123, 1); //�������� ���������� ����� 12,3 � ���� ASCII-��������
 */


#ifndef DUBOS_USART_H
#define DUBOS_USART_H

unsigned char str[16];

void USART_init(unsigned int baud);
void USART_send(unsigned char s);
void USART_send_BK(void);
void USART_send_string(const unsigned char *data);

#endif