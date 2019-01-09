/*
* Usonic.cpp
*
* Created: 05.12.2018 11:18:07
* Author : grtizhar
*/

#include <avr/io.h>
#include "general.h"
#include "util/delay.h"
#include "SDCard/sdcard.h"
#include "usonic/usonic.h"
#include "usart/myUart.h"
//#include "weathersensor/WeatherSensor.h"
//#include "DistanceLaser/DistanceLaser.h"
//#include "ServoControl/Servo.h"
//#include "Eeprom/eeprom.h"

//WeatherSensor wSens(0b11101111);
////
//Servo serv;
//DistanceLaser laser;
using namespace std;
int main(void)
{
	//
	/*/////////////////////////////////////////////////////////////////////////////
	//SDCard
	/////////////////////////////////////////////////////////////////////////////*/
	//
	uinit();
	uputs((unsigned char*)"Hallo\0");
	
	

	while (1)
	{
	}
	
	////sei();
	//uart.enable();
	//uart.write("(Laser) Distance: ");
	//
	//EEPROM prom;
	//
	//prom.clearEeprom();
	//
	//prom.m_oParameters.bWatchdog = false;
	//prom.m_oParameters.nCountLasermeasurements = 200;
	//prom.m_oParameters.nHeight = 3000;
	//prom.m_oParameters.nLaserDelay = 500;
	//prom.m_oParameters.nPowerSaveVoltage = 100;
	//prom.m_oParameters.nServoDrivingTime = 500;
	//prom.m_oParameters.nUltraSonicDelay = 200;
	//prom.WriteToEeprom();
	//
	//prom.GotoFirstValue();
	//for (int i = 0; i < 200; i++) {
	//prom.SetValueX(i);
	//prom.SetValueY(i * 2);
	//prom.GotoNextValue();
	//}
	//
	////
	////long var = wSens.getTemperatureS1();
	////long var2 = wSens.getPressureS1();
	//////Funktioniert derzeit nicht
	////long var3 = laser.getDistance();
	////
	////
	////
	////_delay_ms(10000);
	////
	////uart.write("Temperatur: ");
	////uart.write((uint16_t)var,true);
	////
	////uart.write("Pressure: ");
	////uart.write((uint16_t)var2,true);
	////
	////uart.write("(Usonic) Distance: ");
	////uart.write((uint16_t)uSonic.getAverageDistance(), true);
	////
	////uart.write("(Laser) Distance: ");
	////uart.write((uint16_t) var3, true);
	//}
	//}
	//
	//
	///*//////////////////////////////////////////////////////////////////////////
	//Usonic
	////////////////////////////////////////////////////////////////////////////*/
	//
	//ISR(usonicOVF_ISR)
	//{
	////Too far -> Increase Overflow
	//uSonic.setOverflows(uSonic.getOverflows() + 1);
	//}
	//
	//ISR(USONIC_OCRA_ISR)
	//{
	////Restarts the 16bit Timer when the TriggerPin is active
	//if (
	//USONIC_PIN & (1 << USONIC_TRIGGER_PIN))
	//{
	//USONIC_PRESCALER0();
	//USONIC_PORT &= ~(1 << USONIC_TRIGGER_PIN);
	//EIMSK |= (1 << USONIC_ECHO_INT);				// ext. INT 3
	//}
	//}
	//
	//ISR(USONIC_ECHO_ISR)
	//{
	////Check if Interrupt was caused by raising edge or falling edge
	//if (USONIC_PIN & (1 << USONIC_ECHO_PIN))
	//{
	//// raising edge detection
	//USONIC_TCNT = 0;
	//USONIC_PRESCALER1();
	//}
	//else
	//{
	//// falling edge detection
	//USONIC_PRESCALER0();
	//EIMSK &= ~(1 << USONIC_ECHO_INT);
	//cli();
	//
	////TODO: Get the real Temperature * 10
	//uint16_t convertedDistance = uSonic.convertDistance((uSonic.getOverflows() * UINT16_MAX) + USONIC_TCNT, 200);
	//uSonic.setDistance(convertedDistance);
	//sei();
	//uSonic.setReady(true);
	//
	//USONIC_TCNT = 0;
	//}
}