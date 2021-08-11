#ifndef ROBOTTOROBOTDOCKINGCOORDINATIONSERVICECORE_H_
#define ROBOTTOROBOTDOCKINGCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "RobotToRobotDockingCoordinationService.hh"

 class RobotToRobotDockingCoordinationServiceCore {
 	friend class ACE_Singleton<RobotToRobotDockingCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	RobotToRobotDockingCoordinationServiceCore (){
		std::cout<<"Create RobotToRobotDockingCoordinationService Module Singelton..."<<std::endl;
	}
	~RobotToRobotDockingCoordinationServiceCore (){
		std::cout<<"Destroy RobotToRobotDockingCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, RobotToRobotDockingCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* ROBOTTOROBOTDOCKINGCOORDINATIONSERVICECORE_H_ */
