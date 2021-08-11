#ifndef PLANNERCOORDINATIONSERVICECORE_H_
#define PLANNERCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "PlannerCoordinationService.hh"

 class PlannerCoordinationServiceCore {
 	friend class ACE_Singleton<PlannerCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	PlannerCoordinationServiceCore (){
		std::cout<<"Create PlannerCoordinationService Module Singelton..."<<std::endl;
	}
	~PlannerCoordinationServiceCore (){
		std::cout<<"Destroy PlannerCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, PlannerCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* PLANNERCOORDINATIONSERVICECORE_H_ */
