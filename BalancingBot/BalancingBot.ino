/*
 Name:		BalancingBot.ino
 Created:	05.01.2017 00:43:35
 Author:	mklem
*/


#include <Wire.h>
#include <FlashStorage.h>
#include <PID_v1.h>
#include <Kalman.h>
#include <UDPMessengerLib.h>


#define PIN_DIR_DRV1 0
#define PIN_STEP_DRV1 1

#define PIN_DIR_DRV2 2
#define PIN_STEP_DRV2 3

#define PIN_DRV_SLEEP 4
#define PIN_DRV_RESET 5


typedef struct 
{
	bool valid;
	double kp;
	double ki;
	double kd;

}PIDSettings;


typedef struct
{
	bool valid;
	String SSID;
	String key;
	int Port;
	bool WifiMode;
}WLANSettings;

UDPMessenger udpMessenger;

WLANSettings _WLANSettings;

PIDSettings _PIDSpeedSettings, _PIDAngleSettings;

double _SpeedSetpoint, _SpeedInput, _AngleOutput;
double _AngleSetpoint, _AngleInput, _SpeedOutput;

PID	PIDSpeed(&_SpeedInput,&_AngleOutput, &_SpeedSetpoint, _PIDSpeedSettings.kp,_PIDSpeedSettings.ki,_PIDSpeedSettings.kd,DIRECT);
PID	PIDAngle(&_AngleInput, &_SpeedOutput, &_AngleSetpoint, _PIDAngleSettings.kp, _PIDAngleSettings.ki, _PIDAngleSettings.kd, DIRECT);

bool _PIDSettingValid;

FlashStorage(WLAN_Settings, WLANSettings);
FlashStorage(PID_Settings_Speed, PIDSettings);
FlashStorage(PID_Settings_Angle, PIDSettings);


// the setup function runs once when you press reset or power the board

void setup() 
{

	LoadingSettings();
	SetupDrivers();

	udpMessenger.InitMessenger(_WLANSettings.SSID, _WLANSettings.key, _WLANSettings.Port, _WLANSettings.WifiMode);



	//Setup Objects and variables

	//Setup PID Settings (min,max // tziming // usw.) 

	//Setup arduino in- and outputs

	//Setup WLAN depending on settings

	//Setup MPU650

	//Wait for connection to remotecontrol

	

}

// the loop function runs over and over again until power down or reset
void loop() 

{
	//Read Data vom MPU

	// Process data:
	// kalmann filter
	// PIDloop1 (taking Speed, sets angle setpoint)
	// PIDloop2 (taking angle, sets motorspeed)
	// set output to Motors
	// calculate Speed
	
}



