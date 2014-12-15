#include "AutonomousModeOneBall.h"
#include "LoadCatapultGroup.h"
#include "Commands/WaitCommand.h"
#include "OperatorLowCommand.h"
#include "OperatorHighCommand.h"
#include "OperatorPickup1Command.h"
#include "OperatorPickup2Command.h"
#include "AutonomousPickupCommand.h"
#include "AutonomousDriveCommand.h"
#include "AutonomousCoastCommand.h"
#include "AutonomousLowGearCommand.h"
#include "DriveLaunchReleaseCommand.h"
#include "../Timing.h"

AutonomousModeOneBall::AutonomousModeOneBall()
{
  
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddSequential(new AutonomousDriveCommand(0.0f, TURN_CORRECTION, 0));
  wait 2;
  AddSequential(new AutonomousDriveCommand(1.0f, 1.0, 0.2));
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddSequential(new AutonomousDriveCommand(0.0f, TURN_CORRECTION, 0));
  wait 2;
  AddSequential(new AutonomousDriveCommand(1.0f, TURN_CORRECTION, 2.2));
  AddSequential(new AutonomousDriveCommand(0.0f, TURN_CORRECTION, 0));
  wait 2;
  
}
