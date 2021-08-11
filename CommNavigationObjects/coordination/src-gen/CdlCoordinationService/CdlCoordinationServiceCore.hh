#ifndef CDLCOORDINATIONSERVICECORE_H_
#define CDLCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "CdlCoordinationService.hh"

 class CdlCoordinationServiceCore {
 	friend class ACE_Singleton<CdlCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	CdlCoordinationServiceCore (){
		std::cout<<"Create CdlCoordinationService Module Singelton..."<<std::endl;
	}
	~CdlCoordinationServiceCore (){
		std::cout<<"Destroy CdlCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, CdlCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* CDLCOORDINATIONSERVICECORE_H_ */
