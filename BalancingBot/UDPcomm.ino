enum UDPPacketID
{
	UDP_ERROR,
	UDP_PID1_PARAM,
	UDP_PID2_PARAM,
	UDP_WLAN_PARAM,
	UDP_REMOTE_CONTROL,
	UDP_TELEMETRIC,
	UDP_HANDSHAKE,
	UDP_STATUS

};

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


