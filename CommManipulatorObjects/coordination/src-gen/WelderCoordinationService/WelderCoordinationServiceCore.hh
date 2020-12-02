#ifndef WELDERCOORDINATIONSERVICECORE_H_
#define WELDERCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "WelderCoordinationService.hh"

 class WelderCoordinationServiceCore {
 	friend class ACE_Singleton<WelderCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	WelderCoordinationServiceCore (){
		std::cout<<"Create WelderCoordinationService Module Singelton..."<<std::endl;
	}
	~WelderCoordinationServiceCore (){
		std::cout<<"Destroy WelderCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, WelderCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* WELDERCOORDINATIONSERVICECORE_H_ */
