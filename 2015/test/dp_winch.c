#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Motor,  mtr_S1_C2_1,     driveRearRight, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     driveFrontRight, tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     elbow,         tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     driveFrontLeft, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     driveRearLeft, tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S1_C1_1,    finger,               tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    brush,                tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    arm,                  tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    dockarm,              tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define RETRACTED 137
#define EXTENDED 100

/*
 * Positive value for motor speed raises the arm.
 * Negative value lowers.
 */
task main()
{
    int val;

    servo[dockarm] = 127;

    servo[arm] = 100;

    while (true) {
        displayString(3, "winch %d", ServoValue[arm]);
    }
}
