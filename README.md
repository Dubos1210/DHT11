# DHT11
## Цифровой датчик влажности и температуры
### Библиотека и тестовая программа

  + __example__ - демонстрационный проект  
  Микроконтроллер: Atmel ATmega328P (Arduino UNO). Шина данных датчика подключена к выводу PD2 (2 контакт платы Arduino)  
  ![Схема подключения для тестовой программы](https://github.com/Dubos1210/DHT11/blob/master/img/sch.jpg)  
  Проект создан в Atmel Studio 6.2
  
  + __DHT11.h__ и __DHT11.c__ - файлы библиотеки. Занести в Solution Explorer, файл _DHT11.h_ подключить в строке _#define_
  ```c	
  int8_t DHT11_temperature;                          //Переменная для хранения темературы
  uint8_t DHT11_humidity;                             //Переменная для хранения влажности
  DHT11_getData(&DHT11_temperature, &DHT11_humidity); //Чтение данных с датчика и запись в переменные
  ```
