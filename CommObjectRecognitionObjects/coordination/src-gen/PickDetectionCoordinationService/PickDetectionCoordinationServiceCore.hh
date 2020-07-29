#ifndef PICKDETECTIONCOORDINATIONSERVICECORE_H_
#define PICKDETECTIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "PickDetectionCoordinationService.hh"

 class PickDetectionCoordinationServiceCore {
 	friend class ACE_Singleton<PickDetectionCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	PickDetectionCoordinationServiceCore (){
		std::cout<<"Create PickDetectionCoordinationService Module Singelton..."<<std::endl;
	}
	~PickDetectionCoordinationServiceCore (){
		std::cout<<"Destroy PickDetectionCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, PickDetectionCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* PICKDETECTIONCOORDINATIONSERVICECORE_H_ */
