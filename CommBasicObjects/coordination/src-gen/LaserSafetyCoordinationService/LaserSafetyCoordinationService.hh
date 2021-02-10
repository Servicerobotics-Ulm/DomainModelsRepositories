#ifndef LASERSAFETYCOORDINATIONSERVICE_H_
#define LASERSAFETYCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommLaserSafetyEventParam.hh>
#include <CommBasicObjects/CommLaserSafetyEventParamACE.hh>
#include <CommBasicObjects/CommLaserSafetyEventState.hh>
#include <CommBasicObjects/CommLaserSafetyEventStateACE.hh>
#include <CommBasicObjects/CommLaserSafetyField.hh>
#include <CommBasicObjects/CommLaserSafetyFieldACE.hh>


#include "LaserSafetyCoordinationServiceSafetyFieldEventEventHandlerCore.hh"


class LaserSafetyCoordinationService {
 	
public:
	LaserSafetyCoordinationService ();
	~LaserSafetyCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField> *laserSafetyCoordinationServicesafetyFieldEventClient;
	LaserSafetyCoordinationServiceSafetyFieldEventEventHandlerCore *laserSafetyCoordinationServicesafetyFieldEventEventHandlerCore;
 };
#endif /* LASERSAFETYCOORDINATIONSERVICE_H_ */
