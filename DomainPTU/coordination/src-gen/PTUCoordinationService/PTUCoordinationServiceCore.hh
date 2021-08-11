#ifndef PTUCOORDINATIONSERVICECORE_H_
#define PTUCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "PTUCoordinationService.hh"

 class PTUCoordinationServiceCore {
 	friend class ACE_Singleton<PTUCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	PTUCoordinationServiceCore (){
		std::cout<<"Create PTUCoordinationService Module Singelton..."<<std::endl;
	}
	~PTUCoordinationServiceCore (){
		std::cout<<"Destroy PTUCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, PTUCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* PTUCOORDINATIONSERVICECORE_H_ */
