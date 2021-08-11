#ifndef VISIONCOORDINATIONSERVICECORE_H_
#define VISIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "VisionCoordinationService.hh"

 class VisionCoordinationServiceCore {
 	friend class ACE_Singleton<VisionCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	VisionCoordinationServiceCore (){
		std::cout<<"Create VisionCoordinationService Module Singelton..."<<std::endl;
	}
	~VisionCoordinationServiceCore (){
		std::cout<<"Destroy VisionCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, VisionCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* VISIONCOORDINATIONSERVICECORE_H_ */
