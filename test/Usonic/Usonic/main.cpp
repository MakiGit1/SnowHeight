/*
 * Usonic.cpp
 *
 * Created: 21.09.2018 11:18:07
 * Author : Dominik Ager
 */ 

#include <avr/io.h>
#include "configuration.h"
#include "usonic/usonic.h"
#include "usart/myUart.h"


int main(void)
{	
    while (1) 
    {
		sei();
		uart.enable();
		
		uart.write((uint16_t)uSonic.getAverageDistance(), true);
    }
}

ISR(usonicOVF_ISR)
{
	//Too far -> Increase Overflow
	uSonic.setOverflows(uSonic.getOverflows() + 1);
}

ISR(USONIC_OCRA_ISR)
{
	//Restarts the 16bit Timer when the TriggerPin is active
	if (
	USONIC_PIN & (1 << USONIC_TRIGGER_PIN))
	{
		USONIC_PRESCALER0();
		USONIC_PORT &= ~(1 << USONIC_TRIGGER_PIN);
		EIMSK |= (1 << USONIC_ECHO_INT);				// ext. INT 3
	}
}

ISR(USONIC_ECHO_ISR)
{	
	//Check if Interrupt was caused by raising edge or falling edge
	if (USONIC_PIN & (1 << USONIC_ECHO_PIN))
	{
		// raising edge detection
		USONIC_TCNT = 0;
		USONIC_PRESCALER1();		
	}
	else
	{
		// falling edge detection
		USONIC_PRESCALER0();
		EIMSK &= ~(1 << USONIC_ECHO_INT);
		cli();

		//TODO: Get the real Temperature * 10
		uint16_t convertedDistance = uSonic.convertDistance((uSonic.getOverflows() * UINT16_MAX) + USONIC_TCNT, 200);
		uSonic.setDistance(convertedDistance);
		sei();
		uSonic.setReady(true);

		USONIC_TCNT = 0;
	}
}