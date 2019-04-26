#include "main.h"
#include "hardware_def.cpp"
#include "methodLibrary.cpp"
#include "PID_P-loop_IME.cpp"
/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

lfront.move_velocity(200);
pros::Task::delay(10000);

//direction (1 or -1) and target distance in inches
robotMove(1, 24);

//wait 10 seconds
pros::Task::delay(10000);

//p-loop
p_loop (1, 24);


}
