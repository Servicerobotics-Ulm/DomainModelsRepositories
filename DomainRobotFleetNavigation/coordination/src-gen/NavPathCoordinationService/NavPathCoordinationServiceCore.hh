#ifndef NAVPATHCOORDINATIONSERVICECORE_H_
#define NAVPATHCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "NavPathCoordinationService.hh"

 class NavPathCoordinationServiceCore {
 	friend class ACE_Singleton<NavPathCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	NavPathCoordinationServiceCore (){
		std::cout<<"Create NavPathCoordinationService Module Singelton..."<<std::endl;
	}
	~NavPathCoordinationServiceCore (){
		std::cout<<"Destroy NavPathCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, NavPathCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* NAVPATHCOORDINATIONSERVICECORE_H_ */
