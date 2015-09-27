#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     irr_right,      sensorI2CCustom)
#pragma config(Sensor, S3,     irr_left,       sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     driveRearRight, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     driveRearLeft, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    leftEye,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    rightEye,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#define USE_COMPASS_CORRECTION

#define SERVO_MAX 255
#define SERVO_MIN 0

bool done;

tSensors link;

task calibrateServo()
{
    int val;

    while (!done) {
	    val = ServoValue[link];
        servo[link] = --val;
		displayString(4, "Location: %d", val);
        wait1Msec(300);
    }
}

task main()
{
    link = leftEye;

    done = false;
    servoChangeRate[link]  = 5;

    // servo[link] = SERVO_MAX/2;
    servo[link] = 167;

    wait1Msec(1000);

    startTask(calibrateServo);

    while (1) {
        if (nNxtButtonPressed == 3) {
            done = true;
        }
    }

    while(1) {}
}
