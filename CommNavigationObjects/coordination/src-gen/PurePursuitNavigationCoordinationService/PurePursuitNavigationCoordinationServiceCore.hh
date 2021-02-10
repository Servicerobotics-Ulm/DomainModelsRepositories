#ifndef PUREPURSUITNAVIGATIONCOORDINATIONSERVICECORE_H_
#define PUREPURSUITNAVIGATIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "PurePursuitNavigationCoordinationService.hh"

 class PurePursuitNavigationCoordinationServiceCore {
 	friend class ACE_Singleton<PurePursuitNavigationCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	PurePursuitNavigationCoordinationServiceCore (){
		std::cout<<"Create PurePursuitNavigationCoordinationService Module Singelton..."<<std::endl;
	}
	~PurePursuitNavigationCoordinationServiceCore (){
		std::cout<<"Destroy PurePursuitNavigationCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, PurePursuitNavigationCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* PUREPURSUITNAVIGATIONCOORDINATIONSERVICECORE_H_ */
