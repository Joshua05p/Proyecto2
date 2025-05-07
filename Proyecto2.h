/*
 * Proyecto2.h
 *
 * Created: 27/04/2025 19:23:13
 *  Author: perez
 */

#ifndef PROYECTO2_H_
#define PROYECTO2_H_
#include <avr/io.h>
#include <avr/eeprom.h>


 
void salidas();
void confi_timer0();
void confi_timer1();
void confi_timer2();
void iniciar_adc();
void iniciar_conversion();
void iniciar_USART();
void servo1(uint16_t ancho1);
void servo2(uint16_t ancho2);
void servo3(uint16_t ancho3);
void servo4(uint16_t ancho4);
 
#endif /* PROYECTO2_H_ */
