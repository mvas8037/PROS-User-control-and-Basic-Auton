#include "main.h"
#include "opcontrol.cpp"
#include "methodLibrary.cpp"


//Motor definitions----------------------------------------------------------------------------------------------
//true/false is for direction of motor (true = reversed)
pros::Controller Controller1(pros::E_CONTROLLER_MASTER);
pros::Motor lfront(11, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lback(12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rfront(20, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor rback (19, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

//sensor definitions---------------------------------------------------------------------------------------------

//encoder ports A-H numbered 1-8
//false meaning value not reversed
 pros::ADIEncoder lEncoder (3, 4, false);
 pros::ADIEncoder rEncoder (5, 6, false);

 //gyro definition
 pros::ADIGyro  gyroDrive(5);
