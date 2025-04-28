/*
 * Libreria.h
 *
 * Created: 7/04/2025 08:58:26
 *  Author: perez
 */ 


#ifndef LIBRERIA_H_
#define LIBRERIA_H_

#include <avr/io.h>

void setupL();
void iniciar_adc();
void iniciar_conversion();
void ancho_pulso(uint16_t ancho);


#endif /* LIBRERIA_H_ */
