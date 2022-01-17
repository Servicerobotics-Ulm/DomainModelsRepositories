#ifndef BUNDLEDNAVIGATIONCOORDINATIONSERVICECORE_H_
#define BUNDLEDNAVIGATIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "BundledNavigationCoordinationService.hh"

 class BundledNavigationCoordinationServiceCore {
 	friend class ACE_Singleton<BundledNavigationCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	BundledNavigationCoordinationServiceCore (){
		std::cout<<"Create BundledNavigationCoordinationService Module Singelton..."<<std::endl;
	}
	~BundledNavigationCoordinationServiceCore (){
		std::cout<<"Destroy BundledNavigationCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, BundledNavigationCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* BUNDLEDNAVIGATIONCOORDINATIONSERVICECORE_H_ */
