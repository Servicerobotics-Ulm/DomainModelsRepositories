#ifndef SLAMCOORDINATIONSERVICECORE_H_
#define SLAMCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "SLAMCoordinationService.hh"

 class SLAMCoordinationServiceCore {
 	friend class ACE_Singleton<SLAMCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	SLAMCoordinationServiceCore (){
		std::cout<<"Create SLAMCoordinationService Module Singelton..."<<std::endl;
	}
	~SLAMCoordinationServiceCore (){
		std::cout<<"Destroy SLAMCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, SLAMCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* SLAMCOORDINATIONSERVICECORE_H_ */
