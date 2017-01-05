/*
 Name:		BalancingBot.ino
 Created:	05.01.2017 00:43:35
 Author:	mklem
*/


#include <FlashStorage.h>
#include <PID_v1.h>
#include <Kalman.h>
#include <UDPMessengerLib.h>




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


#pragma region UDPMessengerlib Callbacks

//Callback from UDPMessengerlib
//Set values Kp, Ki & kd for PIDLoop1
void SetPID1Parameter()
{}

//Callback from UDPMessengerlib
//Get values Kp, Ki & kd for PIDloop1
void GetPID1Parameter()
{}

//Callback from UDPMessengerlib
//Set values Kp, Ki & kd for PIDloop2
void SetPID2Parameter()
{}

//Callback from UDPMessengerlib
//Get values Kp, Ki & kd for PIDloop2
void GetPID2Parameter()
{}

//Callback from UDPMessengerlib
//Set Wlan parameters (SSID, key)
void SetWLANParameter()
{}

//Callback from UDPMessengerlib
//Set control values, i.e. speed, turnrate, motors enabled...
void RemoteControl()
{}

#pragma endregion




