#ifndef MANIPULATIONCOORDINATIONSERVICECORE_H_
#define MANIPULATIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "ManipulationCoordinationService.hh"

 class ManipulationCoordinationServiceCore {
 	friend class ACE_Singleton<ManipulationCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	ManipulationCoordinationServiceCore (){
		std::cout<<"Create ManipulationCoordinationService Module Singelton..."<<std::endl;
	}
	~ManipulationCoordinationServiceCore (){
		std::cout<<"Destroy ManipulationCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, ManipulationCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* MANIPULATIONCOORDINATIONSERVICECORE_H_ */
