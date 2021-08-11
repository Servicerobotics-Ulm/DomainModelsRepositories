#ifndef MANIPULATIONPLANNERCOORDINATIONSERVICECORE_H_
#define MANIPULATIONPLANNERCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "ManipulationPlannerCoordinationService.hh"

 class ManipulationPlannerCoordinationServiceCore {
 	friend class ACE_Singleton<ManipulationPlannerCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	ManipulationPlannerCoordinationServiceCore (){
		std::cout<<"Create ManipulationPlannerCoordinationService Module Singelton..."<<std::endl;
	}
	~ManipulationPlannerCoordinationServiceCore (){
		std::cout<<"Destroy ManipulationPlannerCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, ManipulationPlannerCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* MANIPULATIONPLANNERCOORDINATIONSERVICECORE_H_ */
