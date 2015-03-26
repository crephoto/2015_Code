#include "TrashCan.h"
#include "../../RobotMap.h"
#include "../Lifter/AdjustLifter.h"
#include "../Gripper/Grab.h"
#include "../Lifter/CalibrateLifter.h"
#include "../Lifter/MoveToLevel.h"
#include "../Drive/DriveCommands/Move.h"
#include "../../CommandBase.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"

TrashCan::TrashCan()
{
	AddSequential(new Release());
	AddSequential(new DoNothing(.5));
	AddSequential(new Grab());
	AddSequential(new DoNothing(1));
	AddSequential(new AdjustLifter(300));
	AddSequential(new DoNothing(1));
	AddSequential(new Move(180, .5, 4.2));
	AddSequential(new DoNothing(1));
	AddSequential(new Release());
	AddSequential(new DoNothing(1));
	AddSequential(new CalibrateLifter());
	AddSequential(new MoveToLevel(TRASH_LEVEL));
	AddSequential(new DoNothing(1));
	AddSequential(new Grab());
}
