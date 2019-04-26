#include <tr1/math.h>
#include "main.h"
#include "hardware_def.cpp"
#include "initialize.cpp"

void drive (double unit){
  //sets motors velocity from 200 , -200
  lfront.move_velocity(unit);
  lback.move_velocity(unit);
  rfront.move_velocity(unit);
  rback.move_velocity(unit);
}

//target is an interger in inches
void p_loop (int direction, int target){

  //p-loop variables
  float Kp;
  float proportion;

  float error;

 //CONVERSION
  //diameter of wheel in inches
  double wheelDiameter = 4.125;
  //Pi*diameter or 2*Pi*radius
  double circumference = wheelDiameter * M_PI;
  //input converted to ticks
  //inches to ticks
  target = (360*target) / circumference;

  //TUNE constant value
  Kp = .5;

  while (error < target || error != 0){

   //update error each cycle (average between 2 sides)
   error = target - ((lfront.get_position()+rfront.get_position())/2);

   //make proportion = error (makes easier to read)
   proportion = error;
   //adjust proportion
   power = proportion*Kp*direction;

   drive(power);

   pros::Task::delay(20);

  }
}
