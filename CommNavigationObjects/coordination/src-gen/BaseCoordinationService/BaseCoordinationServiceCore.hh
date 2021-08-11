#ifndef BASECOORDINATIONSERVICECORE_H_
#define BASECOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "BaseCoordinationService.hh"

 class BaseCoordinationServiceCore {
 	friend class ACE_Singleton<BaseCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	BaseCoordinationServiceCore (){
		std::cout<<"Create BaseCoordinationService Module Singelton..."<<std::endl;
	}
	~BaseCoordinationServiceCore (){
		std::cout<<"Destroy BaseCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, BaseCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* BASECOORDINATIONSERVICECORE_H_ */
