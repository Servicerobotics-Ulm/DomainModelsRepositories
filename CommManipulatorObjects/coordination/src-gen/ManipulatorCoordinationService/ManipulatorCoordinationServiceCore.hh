#ifndef MANIPULATORCOORDINATIONSERVICECORE_H_
#define MANIPULATORCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "ManipulatorCoordinationService.hh"

 class ManipulatorCoordinationServiceCore {
 	friend class ACE_Singleton<ManipulatorCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	ManipulatorCoordinationServiceCore (){
		std::cout<<"Create ManipulatorCoordinationService Module Singelton..."<<std::endl;
	}
	~ManipulatorCoordinationServiceCore (){
		std::cout<<"Destroy ManipulatorCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, ManipulatorCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* MANIPULATORCOORDINATIONSERVICECORE_H_ */
