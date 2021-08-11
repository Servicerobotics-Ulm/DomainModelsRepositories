#ifndef KBCOORDINATIONSERVICECORE_H_
#define KBCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "KBCoordinationService.hh"

 class KBCoordinationServiceCore {
 	friend class ACE_Singleton<KBCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	KBCoordinationServiceCore (){
		std::cout<<"Create KBCoordinationService Module Singelton..."<<std::endl;
	}
	~KBCoordinationServiceCore (){
		std::cout<<"Destroy KBCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, KBCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* KBCOORDINATIONSERVICECORE_H_ */
