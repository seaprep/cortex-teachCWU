# cortext-template

This is a template project file for use with in PROS for a Cortex based root.  The template is organized where the robot has the functionality divided up by subsystem.  This template is based aroudn a robot witht he following common subsystem:

  lift        -- lift.h and lift.c
  intake      -- intake.h and intake.c
  manipulator -- manipulator.h and manipulator.c
  shooter     -- shooter.h and shooter.c
  chassis     -- chassis.h and chassis.c
  
  
It also uses common include file called portdef.h which is intended to name and describe all cortex ports, as well as any other overall goblas, such a #define DEBUG true

The autonomous portion of the competition template relies on a seperate auto.h and autoroutines.c file pair.  The autoroutines.c is intended to be used to contain various autonomous functions, compising a defiend autonomous program sequence, depending on the state of the robot.  You will likely have one or more for competition autonomous, where you may be on any of two red or blue tiles and mayhave other sequences turned off dependign o nstrategy, and several for skill based autonomous.

These different autonomous functions then should be called in auto.c in the autonomous() function based on soem selector made durign robot setup.

To use this template, you should FORK the repository to your PROS install, and create your own subsequent code for your robot based on the template.
