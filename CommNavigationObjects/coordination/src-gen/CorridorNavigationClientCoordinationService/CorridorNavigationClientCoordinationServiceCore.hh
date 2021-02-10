#ifndef CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICECORE_H_
#define CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "CorridorNavigationClientCoordinationService.hh"

 class CorridorNavigationClientCoordinationServiceCore {
 	friend class ACE_Singleton<CorridorNavigationClientCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	CorridorNavigationClientCoordinationServiceCore (){
		std::cout<<"Create CorridorNavigationClientCoordinationService Module Singelton..."<<std::endl;
	}
	~CorridorNavigationClientCoordinationServiceCore (){
		std::cout<<"Destroy CorridorNavigationClientCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, CorridorNavigationClientCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* CORRIDORNAVIGATIONCLIENTCOORDINATIONSERVICECORE_H_ */
