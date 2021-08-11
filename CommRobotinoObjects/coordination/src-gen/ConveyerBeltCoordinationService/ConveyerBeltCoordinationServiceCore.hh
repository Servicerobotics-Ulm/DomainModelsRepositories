#ifndef CONVEYERBELTCOORDINATIONSERVICECORE_H_
#define CONVEYERBELTCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "ConveyerBeltCoordinationService.hh"

 class ConveyerBeltCoordinationServiceCore {
 	friend class ACE_Singleton<ConveyerBeltCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	ConveyerBeltCoordinationServiceCore (){
		std::cout<<"Create ConveyerBeltCoordinationService Module Singelton..."<<std::endl;
	}
	~ConveyerBeltCoordinationServiceCore (){
		std::cout<<"Destroy ConveyerBeltCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, ConveyerBeltCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* CONVEYERBELTCOORDINATIONSERVICECORE_H_ */
