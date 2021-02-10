#ifndef _LASERSAFETYCOORDINATIONSERVICESAFETYFIELDEVENTEVENTHANDLERCORE_HH_
#define _LASERSAFETYCOORDINATIONSERVICESAFETYFIELDEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommBasicObjects/CommLaserSafetyField.hh"
#include "CommBasicObjects/CommLaserSafetyEventParam.hh"
#include "LaserSafetyCoordinationServiceSafetyFieldEventEventHandler.hh"

class LaserSafetyCoordinationServiceSafetyFieldEventEventHandlerCore : public Smart::IEventHandler<CommBasicObjects::CommLaserSafetyField>
{
public:
	LaserSafetyCoordinationServiceSafetyFieldEventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommLaserSafetyField &r) override;
	CommBasicObjects::CommLaserSafetyEventParam activateEventParam(const std::string& parameterString);
private:
	LaserSafetyCoordinationServiceSafetyFieldEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
