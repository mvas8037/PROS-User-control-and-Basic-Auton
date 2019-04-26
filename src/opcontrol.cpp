#include "main.h"
#include "hardware_def.cpp"


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 // parenthesis in motor defines which port the motor is going to


void opcontrol() {

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

   //continually update joystick value
		double leftStick = Controller1.get_analog(ANALOG_LEFT_Y);
		double rightStick = Controller1.get_analog(ANALOG_RIGHT_Y);

  //assigns drivetrain motors to joystick's value
		lfront.move_velocity(leftStick);
		lback.move_velocity(leftStick);
		rfront.move_velocity(rightStick);
		rfront.move_velocity(rightStick);

		pros::delay(20);
	}
}
