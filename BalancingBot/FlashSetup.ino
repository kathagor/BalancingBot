
//Loading settings from Flash
void LoadingSettings()
{
	_WLANSettings = WLAN_Settings.read();

	if (_WLANSettings.valid == false)
	{
		_WLANSettings.SSID = "BalancingBot";
		_WLANSettings.key = "";
		_WLANSettings.Port = 2309;
		_WLANSettings.WifiMode = UDP_MESS_AP;
	}

	_PIDSpeedSettings = PID_Settings_Speed.read();
	_PIDAngleSettings = PID_Settings_Angle.read();

	if (_PIDSpeedSettings.valid == true && _PIDAngleSettings.valid == true)
	{

		PIDSpeed.SetTunings(_PIDSpeedSettings.kp, _PIDSpeedSettings.ki, _PIDSpeedSettings.kd);
		PIDAngle.SetTunings(_PIDAngleSettings.kp, _PIDAngleSettings.ki, _PIDAngleSettings.kd);

		_PIDSettingValid = true;	
	}
}


