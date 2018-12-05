/*
 * general.h
 *
 * Created: 21.03.2017 16:03:18
 *  Author: ARTHUR
 */ 

#ifndef GENERAL_H_
#define GENERAL_H_

// global constants
#define F_CPU						16000000UL	// CPU Frequency - constant must be defined as "F_CPU" for API compatibilities with API "I2C_MASTER"

//EEPROM
#define EEPROM_MatrixStart			0x00FC
#define EEPROM_ParameterStart		0x0000

//Real Time Clock
#define DS3231_ADDR					(0x68<<1) //device address
#define DS3231_I2CINIT				1
#define DS3231_EICR					EICRA
#define DS3231_ISC0					ISC20
#define DS3231_ISC1					ISC21
#define DS3231_ISR					INT2_vect
#define DS3231_INT					INT2
#define DS3231_EnableRisingEdge()	(DS3231_EICR |= (1 << DS3231_ISC1))
#define DS3231_EnableExtInterrupt() ( EIMSK |= ( 1 << DS3231_INT))
#define DS3231_Alarm1Bit			0
#define DS3231_Alarm1Flag			0

// weather sensor - Bosch BME280 sensor
#define WEATHER_SENSOR_ADDRESS		0x77

// ultrasonic measuring sensor
#define USONIC_PORT					PORTD
#define USONIC_PIN					PIND
#define USONIC_DIR					DDRD
#define USONIC_ECHO_PIN				PD3 // DONE
#define USONIC_TRIGGER_PIN			PD7 //DONE 
#define USONIC_ECHO_ISR				INT3_vect
#define USONIC_ECHO_EICR			EICRA
#define USONIC_INTERRUPT			ISC30
#define USONIC_ECHO_INT				INT3

#define USONIC_TIMSK				TIMSK5
#define USONIC_TOVF					TOIE5
#define USONIC_OCRA					OCIE5A
#define USONIC_TRIGGER_IMPULS		OCR5A
#define USONIC_TCNT					TCNT5
#define	usonicOVF_ISR				TIMER5_OVF_vect				
#define USONIC_PRESCALER1()			(TCCR5B |= (1 << CS50))
#define USONIC_PRESCALER0()			(TCCR5B &= ~((1 << CS50) | (1 << CS51) | (1 << CS52)))
#define USONIC_OCRA_ISR				TIMER5_COMPA_vect
// 16bit max unsigned int value
//#define UINT16_MAX					65536

//SERVOS
#define ServoPWMPort				PORTB				//Port B
#define ServoPWMDir					DDRB				//Data Direction Registry B
#define Servo1PWMOut				PB5					//Pin PB5 (Pin 11)
#define Servo2PWMOut				PB6					//Pin PB6 (Pin 12)
#define BatteryMeasureOut			PB7					//Pin PB7 (Pin 13)
//AF - Define Cutoff Port
#define CutoffPort					PORTH				//Port H
#define CutoffDir					DDRH				//Data Direction Registry H
#define ServoCutoff					PH4					//Pin PH4 (Pin 7)
#define ModuleCutoff				PH3					//Pin PH3 (Pin 6)

#define maxCurrentADC				40					//max. ADC-Value (~100 mA)
#define maxBatteryValue				13672				//(14 / 1024) * 1000 000
#define Mask						0b1111111111111000	//Bit-Mask (16 Bit)

#endif /* GENERAL_H_ */