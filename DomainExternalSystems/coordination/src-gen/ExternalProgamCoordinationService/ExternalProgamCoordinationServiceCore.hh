#ifndef EXTERNALPROGAMCOORDINATIONSERVICECORE_H_
#define EXTERNALPROGAMCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "ExternalProgamCoordinationService.hh"

 class ExternalProgamCoordinationServiceCore {
 	friend class ACE_Singleton<ExternalProgamCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	ExternalProgamCoordinationServiceCore (){
		std::cout<<"Create ExternalProgamCoordinationService Module Singelton..."<<std::endl;
	}
	~ExternalProgamCoordinationServiceCore (){
		std::cout<<"Destroy ExternalProgamCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, ExternalProgamCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* EXTERNALPROGAMCOORDINATIONSERVICECORE_H_ */
