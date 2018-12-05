/*
 * eeprom.h
 *
 * Created: 19.10.2018 11:27:41
 *  Author: alrhomberg
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

class EEPROM
{
	public:
	EEPROM(bool bClearEEPROM = false);
	//AF - Struct for Parameters
	struct eepromstr_Parameters
	{
		//Height of the SHM to the ground in millimeters.
		uint16_t nHeight;
		//Timespan of the cycle for the ultrasonic and environmental measurements.
		uint8_t nUltraSonicDelay;
		//Timespan of the cycle for the laser measurements.
		uint16_t nLaserDelay;
		//Timespan between servo driving and laser measurement.S
		uint16_t nServoDrivingTime;
		//Bool for Watchdog Timer
		bool bWatchdog;
		//Value for the power save voltage, Value = voltage * 10
		uint8_t nPowerSaveVoltage;
		//Amount of mueassurements for laser
		uint8_t nCountLasermeasurements;
	} m_oParameters;
	//Array for the laser measurement matrix

	//uint16_t iLaserMatrix[500][2];

	void clearEeprom();
	void WriteToEeprom();
	void ReadFromEeprom();

	//uint16_t* GetMeasurementpoint(uint16_t iValueregister);
	bool GotoFirstValue();
	uint16_t GetValueX();
	uint16_t GetValueY();
	void SetValueX(uint16_t ValueX);
	void SetValueY(uint16_t ValueY);
	bool GotoNextValue();
	private:
	uint16_t iValueregister;
	uint16_t nCurrentLasercount = 0;
};
#endif /* EEPROM_H_ */