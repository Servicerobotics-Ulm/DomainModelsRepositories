#ifndef _LASERSAFETYCOORDINATIONSERVICESAFETYFIELDEVENTEVENTHANDLER_HH_
#define _LASERSAFETYCOORDINATIONSERVICESAFETYFIELDEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommBasicObjects/CommLaserSafetyField.hh"
#include "CommBasicObjects/CommLaserSafetyEventParam.hh"

class LaserSafetyCoordinationServiceSafetyFieldEventEventHandler
{
public:
	std::string handleEvent(const CommBasicObjects::CommLaserSafetyField &r) throw();
	CommBasicObjects::CommLaserSafetyEventParam activateEventParam(const std::string& parameterString);
};

#endif
