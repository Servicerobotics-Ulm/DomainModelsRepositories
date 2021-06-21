#ifndef REMOTECONTROLCOORDINATIONSERVICECORE_H_
#define REMOTECONTROLCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "RemoteControlCoordinationService.hh"

 class RemoteControlCoordinationServiceCore {
 	friend class ACE_Singleton<RemoteControlCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	RemoteControlCoordinationServiceCore (){
		std::cout<<"Create RemoteControlCoordinationService Module Singelton..."<<std::endl;
	}
	~RemoteControlCoordinationServiceCore (){
		std::cout<<"Destroy RemoteControlCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, RemoteControlCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* REMOTECONTROLCOORDINATIONSERVICECORE_H_ */
