
/*
 * Tells the drivetrain layer that we are using
 * four motors to drive the wheels instead either
 * just two motors, or two motors and chain.
 */
#define FOUR_WHEEL_DRIVE

/*
 * If defined, put definitions for devices on the
 * mux in mux_defs.h.  If not defined and the same
 * definitions are in the pragmas, then software will
 * build.
 */
#define USING_SENSOR_MUX

#define ENCPERINCH              120
#define ENC_TICKS_PER_DEGREE    26

#define BLOCK_SERVO_RETRACTED   6
#define BLOCK_SERVO_EXTENDED    250
