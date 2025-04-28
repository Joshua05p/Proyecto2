/*
 * Proyecto2.c
 *
 * Created: 27/04/2025 19:23:01
 *  Author: perez
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Proyecto2.h"

void setupL(void) {
	//SALIDA
	DDRB |= (1 << DDB1) | (1<<DDB2);
	DDRD = 0xFF;
	
	//CONFIGURACION TIMER2
	TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);		//Fast PWM OCR2A MAX y no invertido
	TCCR2B = (1 << WGM22) | (1 << CS22) | (1 << CS20);		//Prescaler 1024

	//CONFIGURACION TIMER1
	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);

	ICR1 = 39999; // TOP = 20 ms (50 Hz): 8MHz /(8*50) = 20000 ticks
	
	//CONFIGURACION TIMER0

	TCCR0A = (1 << WGM01); //Modo CTC
	TCCR0B = (1 << CS02) | (1 << CS00); //Prescaler 1024
	
	//Interrupcion timer0
	TIMSK0 |= (1<<OCIE0B) | (1<<OCIE0A);
	
	OCR0A = 234;
}
void iniciar_adc(){
	cli();
	ADMUX |= (1<<REFS0);							// Voltaje de referencia 5V
	ADMUX |= (1<<MUX2) | (1<<MUX1);					// Selecciona el canal 6

	ADCSRA = (1 << ADEN)  |							// Habilitar ADC
	(1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) |	// Prescaler 128 (125 kHz)
	(1 << ADIE);									// Habilitar interrupción del ADC

	sei();
}
void iniciar_conversion(){
	ADCSRA |= (1 << ADSC);
}
void ancho_pulso(uint16_t ancho) {
	OCR1A = ancho;
}
void ancho_pulso2(uint16_t ancho2) {
	OCR2B = ancho2;
}

