#ifndef NAVPATHCLIENTCOORDINATIONSERVICECORE_H_
#define NAVPATHCLIENTCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "NavPathClientCoordinationService.hh"

 class NavPathClientCoordinationServiceCore {
 	friend class ACE_Singleton<NavPathClientCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	NavPathClientCoordinationServiceCore (){
		std::cout<<"Create NavPathClientCoordinationService Module Singelton..."<<std::endl;
	}
	~NavPathClientCoordinationServiceCore (){
		std::cout<<"Destroy NavPathClientCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, NavPathClientCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* NAVPATHCLIENTCOORDINATIONSERVICECORE_H_ */
