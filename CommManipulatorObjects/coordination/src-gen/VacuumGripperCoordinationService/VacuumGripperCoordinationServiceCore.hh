#ifndef VACUUMGRIPPERCOORDINATIONSERVICECORE_H_
#define VACUUMGRIPPERCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "VacuumGripperCoordinationService.hh"

 class VacuumGripperCoordinationServiceCore {
 	friend class ACE_Singleton<VacuumGripperCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	VacuumGripperCoordinationServiceCore (){
		std::cout<<"Create VacuumGripperCoordinationService Module Singelton..."<<std::endl;
	}
	~VacuumGripperCoordinationServiceCore (){
		std::cout<<"Destroy VacuumGripperCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, VacuumGripperCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* VACUUMGRIPPERCOORDINATIONSERVICECORE_H_ */
