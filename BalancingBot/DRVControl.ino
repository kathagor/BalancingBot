
// Set IOs for the motor drivers
void SetupDrivers()
{
	pinMode(PIN_DIR_DRV1, OUTPUT);
	pinMode(PIN_DIR_DRV2, OUTPUT);
	pinMode(PIN_STEP_DRV1, OUTPUT);
	pinMode(PIN_STEP_DRV2, OUTPUT);
	pinMode(PIN_DRV_SLEEP, OUTPUT);
	pinMode(PIN_DRV_RESET, OUTPUT);

	digitalWrite(PIN_DRV_RESET, LOW);
	digitalWrite(PIN_DRV_SLEEP, LOW);
	digitalWrite(PIN_DIR_DRV1, LOW);
	digitalWrite(PIN_DIR_DRV2, LOW);
	digitalWrite(PIN_STEP_DRV1, LOW);
	digitalWrite(PIN_STEP_DRV2, LOW);
}
