#ifndef FESTOMPSVISUALDOCKINGCOORDINATIONSERVICECORE_H_
#define FESTOMPSVISUALDOCKINGCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "FestoMPSVisualDockingCoordinationService.hh"

 class FestoMPSVisualDockingCoordinationServiceCore {
 	friend class ACE_Singleton<FestoMPSVisualDockingCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	FestoMPSVisualDockingCoordinationServiceCore (){
		std::cout<<"Create FestoMPSVisualDockingCoordinationService Module Singelton..."<<std::endl;
	}
	~FestoMPSVisualDockingCoordinationServiceCore (){
		std::cout<<"Destroy FestoMPSVisualDockingCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, FestoMPSVisualDockingCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* FESTOMPSVISUALDOCKINGCOORDINATIONSERVICECORE_H_ */
