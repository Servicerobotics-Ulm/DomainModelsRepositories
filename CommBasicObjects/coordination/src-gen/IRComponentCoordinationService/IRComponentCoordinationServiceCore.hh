#ifndef IRCOMPONENTCOORDINATIONSERVICECORE_H_
#define IRCOMPONENTCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "IRComponentCoordinationService.hh"

 class IRComponentCoordinationServiceCore {
 	friend class ACE_Singleton<IRComponentCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	IRComponentCoordinationServiceCore (){
		std::cout<<"Create IRComponentCoordinationService Module Singelton..."<<std::endl;
	}
	~IRComponentCoordinationServiceCore (){
		std::cout<<"Destroy IRComponentCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, IRComponentCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* IRCOMPONENTCOORDINATIONSERVICECORE_H_ */
