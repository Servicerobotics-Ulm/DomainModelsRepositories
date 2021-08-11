#ifndef LOCALIZATIONCOORDINATIONSERVICECORE_H_
#define LOCALIZATIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "LocalizationCoordinationService.hh"

 class LocalizationCoordinationServiceCore {
 	friend class ACE_Singleton<LocalizationCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	LocalizationCoordinationServiceCore (){
		std::cout<<"Create LocalizationCoordinationService Module Singelton..."<<std::endl;
	}
	~LocalizationCoordinationServiceCore (){
		std::cout<<"Destroy LocalizationCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, LocalizationCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* LOCALIZATIONCOORDINATIONSERVICECORE_H_ */
