#ifndef _CONVEYERBELTCOORDINATIONSERVICELOADEVENTEVENTHANDLERCORE_HH_
#define _CONVEYERBELTCOORDINATIONSERVICELOADEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommRobotinoObjects/CommRobotinoConveyerBeltEventResult.hh"
#include "CommRobotinoObjects/CommRobotinoConveyerBeltEventParameter.hh"
#include "ConveyerBeltCoordinationServiceLoadeventEventHandler.hh"

class ConveyerBeltCoordinationServiceLoadeventEventHandlerCore : public Smart::IEventHandler<CommRobotinoObjects::CommRobotinoConveyerBeltEventResult>
{
public:
	ConveyerBeltCoordinationServiceLoadeventEventHandlerCore(Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoConveyerBeltEventParameter, CommRobotinoObjects::CommRobotinoConveyerBeltEventResult> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommRobotinoObjects::CommRobotinoConveyerBeltEventResult &r) override;
	CommRobotinoObjects::CommRobotinoConveyerBeltEventParameter activateEventParam(const std::string& parameterString);
private:
	ConveyerBeltCoordinationServiceLoadeventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
