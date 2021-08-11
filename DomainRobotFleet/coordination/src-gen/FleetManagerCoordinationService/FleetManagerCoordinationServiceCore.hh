#ifndef FLEETMANAGERCOORDINATIONSERVICECORE_H_
#define FLEETMANAGERCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "FleetManagerCoordinationService.hh"

 class FleetManagerCoordinationServiceCore {
 	friend class ACE_Singleton<FleetManagerCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	FleetManagerCoordinationServiceCore (){
		std::cout<<"Create FleetManagerCoordinationService Module Singelton..."<<std::endl;
	}
	~FleetManagerCoordinationServiceCore (){
		std::cout<<"Destroy FleetManagerCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, FleetManagerCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* FLEETMANAGERCOORDINATIONSERVICECORE_H_ */
