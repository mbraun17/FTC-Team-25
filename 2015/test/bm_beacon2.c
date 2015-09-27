#pragma config(UserModel, "../pragmas/baemax.h")

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define FOUR_WHEEL_DRIVE
#define DEAD_RECKON_GYRO

#include "../../lib/sensors/drivers/hitechnic-sensormux.h"

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "../../lib/sensors/drivers/hitechnic-sensormux.h"
#include "../../lib/sensors/drivers/hitechnic-protoboard.h"
#include "../../lib/sensors/drivers/hitechnic-irseeker-v2.h"
#include "../../lib/sensors/drivers/hitechnic-gyro.h"

const tMUXSensor HTGYRO  = msensor_S4_3;
const tMUXSensor irr_left = msensor_S4_1;
const tMUXSensor irr_right = msensor_S4_2;

bool beacon_done;
int distance_monitor_distance;

#include "../library/baemax_defs.h"
#include "../../lib/baemax_drivetrain_defs.h"
#include "../../lib/drivetrain_square.h"
#include "../../lib/limit_switch.h"
#include "../../lib/dead_reckon.h"
#include "../../lib/data_log.h"
#include "../../lib/ir_utils.h"
#include "../../lib/us_utils.h"
#include "../../lib/button_utils.h"
#include "../../lib/us_cascade_utils.c"
#include "../library/auto_utils.h"

const tMUXSensor HTPB = msensor_S4_4;

#define CENTER_SPEED 5

void counterclockwise()
{
    motor[driveRearRight] = -CENTER_SPEED;
    motor[driveRearLeft] = CENTER_SPEED;
    motor[driveFrontRight] = -CENTER_SPEED;
    motor[driveFrontLeft] = CENTER_SPEED;
}

void clockwise()
{
    motor[driveRearRight] = CENTER_SPEED;
    motor[driveRearLeft] = -CENTER_SPEED;
    motor[driveFrontRight] = CENTER_SPEED;
    motor[driveFrontLeft] = -CENTER_SPEED;
}

void off()
{
    motor[driveRearRight] = 0;
    motor[driveRearLeft] = 0;
    motor[driveFrontRight] = 0;
    motor[driveFrontLeft] = 0;
}


task main()
{
    int segment;
    int left_edge;
    int right_edge;
    int dist;

    disableDiagnosticsDisplay();
    eraseDisplay();
    servo[rightEye] = 105;

    wait1Msec(500);

    segment = HTIRS2readACDir(irr_right);

    while (segment != 6) {
        nxtDisplayCenteredBigTextLine(4, "%d", segment);
        if (segment > 6) {
            motor[driveRearRight] = -CENTER_SPEED;
            motor[driveRearLeft] = CENTER_SPEED;
            motor[driveFrontRight] = -CENTER_SPEED;
            motor[driveFrontLeft] = CENTER_SPEED;
        } else {
            motor[driveRearRight] = CENTER_SPEED;
            motor[driveRearLeft] = -CENTER_SPEED;
            motor[driveFrontRight] = CENTER_SPEED;
            motor[driveFrontLeft] = -CENTER_SPEED;
        }
        segment = HTIRS2readACDir(irr_right);
    }
    motor[driveRearRight] = 0;
    motor[driveRearLeft] = 0;
    motor[driveFrontRight] = 0;
    motor[driveFrontLeft] = 0;

    nMotorEncoder[driveFrontRight] = 0;
    counterclockwise();
    while (segment = HTIRS2readACDir(irr_right) == 6) {
    }
    off();
    left_edge = nMotorEncoder[driveFrontRight];

    nMotorEncoder[driveFrontRight] = 0;
    clockwise();
    while (segment = HTIRS2readACDir(irr_right) <= 6) {
    }
    off();
    right_edge = nMotorEncoder[driveFrontRight];
    dist = abs(left_edge) + abs(right_edge);

    nxtDisplayCenteredBigTextLine(2, "%d %d", left_edge, right_edge);
    nMotorEncoder[driveFrontRight] = 0;
    counterclockwise();
    while (abs(nMotorEncoder[driveFrontRight]) <= dist/2) {
        nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[driveFrontRight]);
    }
    off();

    while(true) {
        segment = HTIRS2readACDir(irr_right);
        nxtDisplayCenteredBigTextLine(4, "%d", segment);
    }
}
