#ifndef DEFAULTCOORDINATIONSERVICECORE_H_
#define DEFAULTCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "DefaultCoordinationService.hh"

 class DefaultCoordinationServiceCore {
 	friend class ACE_Singleton<DefaultCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	DefaultCoordinationServiceCore (){
		std::cout<<"Create DefaultCoordinationService Module Singelton..."<<std::endl;
	}
	~DefaultCoordinationServiceCore (){
		std::cout<<"Destroy DefaultCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, DefaultCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* DEFAULTCOORDINATIONSERVICECORE_H_ */
