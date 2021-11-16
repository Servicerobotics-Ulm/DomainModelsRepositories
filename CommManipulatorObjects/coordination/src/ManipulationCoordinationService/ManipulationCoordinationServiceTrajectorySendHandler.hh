#ifndef _MANIPULATIONCOORDINATIONSERVICETRAJECTORYSENDHANDLER_HH_
#define _MANIPULATIONCOORDINATIONSERVICETRAJECTORYSENDHANDLER_HH_

#include "CommManipulatorObjects/CommManipulationTrajectory.hh"
#include <string>

class ManipulationCoordinationServiceTrajectorySendHandler
{
public:

	ManipulationCoordinationServiceTrajectorySendHandler(){

	}

	CommManipulatorObjects::CommManipulationTrajectory handleSend(std::string inString);
};

#endif
