#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/Command.h"
#include "Commands/AutonomousModeLeft.h"
#include "Commands/AutonomousModeCenter.h"
#include "Commands/AutonomousModeRight.h"
#include "Commands/WinchRewindCommand.h"
#include "Robotmap.h"

/**
  Main robot class
*/
class CommandBasedRobot : public IterativeRobot
{
private:
  LiveWindow* lw;
  Compressor* compressor;
  SendableChooser* choice;

  /** Runs when the robot starts up */
  virtual void RobotInit()
  {
    CommandBase::init();
    lw = LiveWindow::GetInstance();
    compressor = new Compressor(COMPRESSOR_RELAY, COMPRESSOR_SWITCH);
    choice = new SendableChooser();
    choice->AddDefault("Center Mode", new AutonomousModeCenter());
    choice->AddObject("Left Mode", new AutonomousModeLeft());
    choice->AddObject("Right Mode", new AutonomousModeRight());
    SmartDashboard::PutData("Autonomous Mode", choice);
  }

  /** Initializes an autonomous session */
  virtual void AutonomousInit()
  {
    compressor->Start();
    ((Command*)choice->GetSelected())->Start();
  }

  /** Runs continously during autonomous */
  virtual void AutonomousPeriodic()
  {
    Scheduler::GetInstance()->Run();
  }

  /** Initializes a teleop session */
  virtual void TeleopInit()
  {
	CommandBase::catapult->unlock();
    ((Command*)choice->GetSelected())->Cancel();
    (new WinchRewindCommand())->Start();
  }

  /** Runs continously during teleop */
  virtual void TeleopPeriodic()
  {
    Scheduler::GetInstance()->Run();
  }

  virtual void TestPeriodic()
  {
	//printf("Switch readout: %f", CommandBase::catapult->getWinchLimitSwitch() ? 1.0f : 0.0f);
    //lw->Run();
  }
};

START_ROBOT_CLASS(CommandBasedRobot);
