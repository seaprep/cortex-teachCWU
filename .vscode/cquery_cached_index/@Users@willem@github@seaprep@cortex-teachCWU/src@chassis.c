#include "main.h"    // includes API.h and other headers
#include "chassis.h" // ensures that the corresponding header file (chassis.h) is included
#include "portdef.h" // All port defintions on the cortex need to be included

// Place all chassis specific functions here, forexample
// void driveForDistancePD(int speed, int distance) {}

void driveRobot(int speed) {
  // This function drives the robot forward/backwards at given speed
  motorSet(LEFT_M_FRONT, speed);
  motorSet(RIGHT_M_FRONT, -speed);  // RIght motor is mirrored does needs to run reverse

}

void chassisSetOpcontrol(int left, int right) {
  motorSet(LEFT_M_FRONT, left);
  motorSet(RIGHT_M_FRONT, -right);
}

void chassisStopDrive(){
  motorSet(LEFT_M_FRONT, 0);
  motorSet(RIGHT_M_FRONT, 0);
}

void drivePID(int masterPower) {
  // USE PD to drive straight forever - that is the fucntion is called and a delayMsec
  // is used for how long the robot drives

  if(masterPower == 0 ) {
     masterPower = 30;
  } else if(masterPower > 110) {
    masterPower = 100;              // make sure we have head room for slave
                                    // motor to increass
  }
  int slavePower = masterPower;

  int error = 0;
  int kp = 5;

   //Reset the encoders.
   encoderReset(encoderLM);
   encoderReset(encoderRM);
   //Repeat ten times a second.
    while(true)
    {
      //Set the motor powers to their respective variables.
      motorSet(LEFT_M_FRONT, masterPower);
      motorSet(RIGHT_M_FRONT, -slavePower);


      error = encoderGet(encoderLM) - encoderGet(encoderRM);
      slavePower += error / kp;

      //Reset the encoders every loop.
      encoderReset(encoderLM);
      encoderReset(encoderRM);

      if(DEBUG_ON){
        // We are goign to write soem stuff to the terminal for debugging
        printf("MasterPower: %d ", masterPower);
        printf("SlavePower: %d ", slavePower);
        printf("Error: %d ", error);
        printf("Kp: %d ", kp);
        printf("\n ");
      }
      
      wait(100);
    }
}
