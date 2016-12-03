package opmodes;


import com.qualcomm.robotcore.eventloop.opmode.Autonomous;
import com.qualcomm.robotcore.eventloop.opmode.Disabled;
import com.qualcomm.robotcore.hardware.DcMotor;


import team25core.DeadReckon;
import team25core.DeadReckonTask;
import team25core.FourWheelGearedDriveDeadReckon;
import team25core.Robot;
import team25core.RobotEvent;


/**
 * Created by maddie on 12/3/16.
 */
@Autonomous(name="Daisy: Beacon 2 Corner Park", group="Team25")
@Disabled
public class DaisyBeacon2CornerParkAutonomous extends Robot
{
    private DcMotor frontLeft;
    private DcMotor frontRight;
    private DcMotor rearLeft;
    private DcMotor rearRight;
    private DeadReckonTask beacon2Task;
    private DeadReckonTask cornerParkTask;
    private FourWheelGearedDriveDeadReckon beacon2Path;
    private FourWheelGearedDriveDeadReckon cornerParkPath;
    private final int TICKS_PER_INCH = DaisyConfiguration.TICKS_PER_INCH;
    private final int TICKS_PER_DEGREE = DaisyConfiguration.TICKS_PER_DEGREE;
    private final double STRAIGHT_SPEED = DaisyConfiguration.STRAIGHT_SPEED;
    private final double TURN_SPEED = DaisyConfiguration.TURN_SPEED;

    @Override
    public void handleEvent(RobotEvent e)
    {
        // Nothing for now.
    }

    @Override
    public void init()
    {
        frontLeft = hardwareMap.dcMotor.get("frontLeft");
        frontRight = hardwareMap.dcMotor.get("frontRight");
        rearLeft = hardwareMap.dcMotor.get("rearLeft");
        rearRight = hardwareMap.dcMotor.get("rearRight");

        beacon2Path = new FourWheelGearedDriveDeadReckon(this, TICKS_PER_INCH, TICKS_PER_DEGREE, frontLeft, frontRight, rearLeft, rearRight);
        beacon2Path.addSegment(DeadReckon.SegmentType.STRAIGHT, 117, STRAIGHT_SPEED);
        // or until white line detected with ODS
        beacon2Path.addSegment(DeadReckon.SegmentType.TURN, 254, TURN_SPEED);
        beacon2Path.addSegment(DeadReckon.SegmentType.STRAIGHT, 22, STRAIGHT_SPEED);
        //or until <1in space detected by ultrasonic sensor

        beacon2Task = new DeadReckonTask(this, beacon2Path);

        cornerParkPath = new FourWheelGearedDriveDeadReckon(this, TICKS_PER_INCH, TICKS_PER_DEGREE, frontLeft, frontRight, rearLeft, rearRight);
        cornerParkPath.addSegment(DeadReckon.SegmentType.STRAIGHT, -22, STRAIGHT_SPEED);
        cornerParkPath.addSegment(DeadReckon.SegmentType.TURN, 90, TURN_SPEED);
        cornerParkPath.addSegment(DeadReckon.SegmentType.STRAIGHT, 95, STRAIGHT_SPEED);
        cornerParkPath.addSegment(DeadReckon.SegmentType.TURN, -30, TURN_SPEED);
        cornerParkPath.addSegment(DeadReckon.SegmentType.STRAIGHT, 13, STRAIGHT_SPEED);

        cornerParkTask = new DeadReckonTask(this, cornerParkPath);
    }

    @Override
    public void start()
    {
        addTask(beacon2Task);
    }
}




