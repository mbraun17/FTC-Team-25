#pragma config(UserModel, "../pragmas/baemax.h")

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define FOUR_WHEEL_DRIVE
#define DEAD_RECKON_GYRO

#include "../../lib/sensors/drivers/hitechnic-sensormux.h"

//#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "../../lib/sensors/drivers/hitechnic-sensormux.h"
#include "../../lib/sensors/drivers/hitechnic-protoboard.h"
#include "../../lib/sensors/drivers/hitechnic-irseeker-v2.h"
#include "../../lib/sensors/drivers/hitechnic-gyro.h"

const tMUXSensor HTGYRO  = msensor_S4_3;
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
#include "../../lib/us_cascade_utils.c"
#include "../library/auto_utils.h"

const tMUXSensor irr_left = msensor_S4_1;
const tMUXSensor irr_right = msensor_S4_2;
const tMUXSensor HTPB = msensor_S4_4;

task main () {

    while(true) {
    	nxtDisplayCenteredBigTextLine(4, "%d", SensorValue[carrot]);     // Display what "carrot" [ultrasonic sensor] sees.
    }
}
