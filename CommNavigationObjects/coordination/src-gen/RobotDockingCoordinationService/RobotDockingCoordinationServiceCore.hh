#ifndef ROBOTDOCKINGCOORDINATIONSERVICECORE_H_
#define ROBOTDOCKINGCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "RobotDockingCoordinationService.hh"

 class RobotDockingCoordinationServiceCore {
 	friend class ACE_Singleton<RobotDockingCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	RobotDockingCoordinationServiceCore (){
		std::cout<<"Create RobotDockingCoordinationService Module Singelton..."<<std::endl;
	}
	~RobotDockingCoordinationServiceCore (){
		std::cout<<"Destroy RobotDockingCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, RobotDockingCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* ROBOTDOCKINGCOORDINATIONSERVICECORE_H_ */
