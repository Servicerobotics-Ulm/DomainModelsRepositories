#ifndef TRACKERCOORDINATESERVICECORE_H_
#define TRACKERCOORDINATESERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "TrackerCoordinateService.hh"

 class TrackerCoordinateServiceCore {
 	friend class ACE_Singleton<TrackerCoordinateServiceCore, ACE_Thread_Mutex>;
private:
	TrackerCoordinateServiceCore (){
		std::cout<<"Create TrackerCoordinateService Module Singelton..."<<std::endl;
	}
	~TrackerCoordinateServiceCore (){
		std::cout<<"Destroy TrackerCoordinateService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, TrackerCoordinateService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* TRACKERCOORDINATESERVICECORE_H_ */
