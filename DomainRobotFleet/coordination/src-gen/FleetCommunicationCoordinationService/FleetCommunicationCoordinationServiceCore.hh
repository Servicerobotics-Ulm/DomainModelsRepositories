#ifndef FLEETCOMMUNICATIONCOORDINATIONSERVICECORE_H_
#define FLEETCOMMUNICATIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "FleetCommunicationCoordinationService.hh"

 class FleetCommunicationCoordinationServiceCore {
 	friend class ACE_Singleton<FleetCommunicationCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	FleetCommunicationCoordinationServiceCore (){
		std::cout<<"Create FleetCommunicationCoordinationService Module Singelton..."<<std::endl;
	}
	~FleetCommunicationCoordinationServiceCore (){
		std::cout<<"Destroy FleetCommunicationCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, FleetCommunicationCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* FLEETCOMMUNICATIONCOORDINATIONSERVICECORE_H_ */
