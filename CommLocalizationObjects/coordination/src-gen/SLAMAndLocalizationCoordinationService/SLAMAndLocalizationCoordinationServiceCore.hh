#ifndef SLAMANDLOCALIZATIONCOORDINATIONSERVICECORE_H_
#define SLAMANDLOCALIZATIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "SLAMAndLocalizationCoordinationService.hh"

 class SLAMAndLocalizationCoordinationServiceCore {
 	friend class ACE_Singleton<SLAMAndLocalizationCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	SLAMAndLocalizationCoordinationServiceCore (){
		std::cout<<"Create SLAMAndLocalizationCoordinationService Module Singelton..."<<std::endl;
	}
	~SLAMAndLocalizationCoordinationServiceCore (){
		std::cout<<"Destroy SLAMAndLocalizationCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, SLAMAndLocalizationCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* SLAMANDLOCALIZATIONCOORDINATIONSERVICECORE_H_ */
