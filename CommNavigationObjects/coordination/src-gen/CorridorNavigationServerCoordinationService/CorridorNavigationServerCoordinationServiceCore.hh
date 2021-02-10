#ifndef CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICECORE_H_
#define CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "CorridorNavigationServerCoordinationService.hh"

 class CorridorNavigationServerCoordinationServiceCore {
 	friend class ACE_Singleton<CorridorNavigationServerCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	CorridorNavigationServerCoordinationServiceCore (){
		std::cout<<"Create CorridorNavigationServerCoordinationService Module Singelton..."<<std::endl;
	}
	~CorridorNavigationServerCoordinationServiceCore (){
		std::cout<<"Destroy CorridorNavigationServerCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, CorridorNavigationServerCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* CORRIDORNAVIGATIONSERVERCOORDINATIONSERVICECORE_H_ */
