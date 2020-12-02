#ifndef LASERSAFETYCOORDINATIONSERVICECORE_H_
#define LASERSAFETYCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "LaserSafetyCoordinationService.hh"

 class LaserSafetyCoordinationServiceCore {
 	friend class ACE_Singleton<LaserSafetyCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	LaserSafetyCoordinationServiceCore (){
		std::cout<<"Create LaserSafetyCoordinationService Module Singelton..."<<std::endl;
	}
	~LaserSafetyCoordinationServiceCore (){
		std::cout<<"Destroy LaserSafetyCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, LaserSafetyCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* LASERSAFETYCOORDINATIONSERVICECORE_H_ */
