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

#include "../../lib/sensors/drivers/hitechnic-irseeker-v2.h"
#include "../../lib/sensors/drivers/hitechnic-compass.h"
#include "../../lib/drivetrain_defs.h"
#include "../../lib/drivetrain_square.h"
#include "../../lib/dead_reckon.h"
#include "../../lib/data_log.h"
#include "../../lib/ir_utils.h"

#define LSERVO_CENTER 130
#define RSERVO_CENTER 114

task main()
{
    int lval, rval;
    ir_direction_t ldir;
    ir_direction_t rdir;

    servo[rightEye] = RSERVO_CENTER;
    servo[leftEye] = LSERVO_CENTER;
    wait1Msec(2000);

    while (true) {
       rdir = get_dir_to_beacon(irr_right);
       ldir = get_dir_to_beacon(irr_left);

       rval = ServoValue[rightEye];
       if (rdir == DIR_LEFT) {
            /* Move counterclockwise */
            rval++;
        } else if (rdir == DIR_RIGHT) {
            /* Move clockwise */
            rval--;
        }
        servo[rightEye] = lval;

        lval = ServoValue[leftEye];
        if (ldir == DIR_LEFT) {
            lval--;
        } else if (ldir == DIR_RIGHT) {
            lval++;
        }
        servo[leftEye] = lval;
    }
}
