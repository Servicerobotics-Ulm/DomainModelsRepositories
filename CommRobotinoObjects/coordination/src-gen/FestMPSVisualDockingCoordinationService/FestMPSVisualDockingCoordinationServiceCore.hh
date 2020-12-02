#ifndef FESTMPSVISUALDOCKINGCOORDINATIONSERVICECORE_H_
#define FESTMPSVISUALDOCKINGCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "FestMPSVisualDockingCoordinationService.hh"

 class FestMPSVisualDockingCoordinationServiceCore {
 	friend class ACE_Singleton<FestMPSVisualDockingCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	FestMPSVisualDockingCoordinationServiceCore (){
		std::cout<<"Create FestMPSVisualDockingCoordinationService Module Singelton..."<<std::endl;
	}
	~FestMPSVisualDockingCoordinationServiceCore (){
		std::cout<<"Destroy FestMPSVisualDockingCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, FestMPSVisualDockingCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* FESTMPSVISUALDOCKINGCOORDINATIONSERVICECORE_H_ */
