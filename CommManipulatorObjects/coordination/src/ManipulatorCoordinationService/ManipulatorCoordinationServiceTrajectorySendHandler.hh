#ifndef _MANIPULATORCOORDINATIONSERVICETRAJECTORYSENDHANDLER_HH_
#define _MANIPULATORCOORDINATIONSERVICETRAJECTORYSENDHANDLER_HH_

#include "CommManipulatorObjects/CommManipulatorTrajectory.hh"
#include <string>

class ManipulatorCoordinationServiceTrajectorySendHandler
{
public:

	ManipulatorCoordinationServiceTrajectorySendHandler(){

	}

	CommManipulatorObjects::CommManipulatorTrajectory handleSend(std::string inString);
};

#endif
