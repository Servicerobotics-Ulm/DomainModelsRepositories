#ifndef WEBINTERFACECOORDINATIONSERVICECORE_H_
#define WEBINTERFACECOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "WebInterfaceCoordinationService.hh"

 class WebInterfaceCoordinationServiceCore {
 	friend class ACE_Singleton<WebInterfaceCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	WebInterfaceCoordinationServiceCore (){
		std::cout<<"Create WebInterfaceCoordinationService Module Singelton..."<<std::endl;
	}
	~WebInterfaceCoordinationServiceCore (){
		std::cout<<"Destroy WebInterfaceCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, WebInterfaceCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* WEBINTERFACECOORDINATIONSERVICECORE_H_ */
