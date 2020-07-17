#ifndef _VACUUMGRIPPERCOORDINATIONSERVICEGRIPPEREVENTEVENTHANDLERCORE_HH_
#define _VACUUMGRIPPERCOORDINATIONSERVICEGRIPPEREVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommManipulatorObjects/CommVacuumGripperEventResult.hh"
#include "CommManipulatorObjects/CommVacuumGripperEventParameter.hh"
#include "VacuumGripperCoordinationServiceGrippereventEventHandler.hh"

class VacuumGripperCoordinationServiceGrippereventEventHandlerCore : public Smart::IEventHandler<CommManipulatorObjects::CommVacuumGripperEventResult>
{
public:
	VacuumGripperCoordinationServiceGrippereventEventHandlerCore(Smart::IEventClientPattern<CommManipulatorObjects::CommVacuumGripperEventParameter, CommManipulatorObjects::CommVacuumGripperEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommManipulatorObjects::CommVacuumGripperEventResult &r) override;
	CommManipulatorObjects::CommVacuumGripperEventParameter activateEventParam(const std::string& parameterString);
private:
	VacuumGripperCoordinationServiceGrippereventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
