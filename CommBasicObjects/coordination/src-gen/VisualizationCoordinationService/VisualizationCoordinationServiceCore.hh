#ifndef VISUALIZATIONCOORDINATIONSERVICECORE_H_
#define VISUALIZATIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "VisualizationCoordinationService.hh"

 class VisualizationCoordinationServiceCore {
 	friend class ACE_Singleton<VisualizationCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	VisualizationCoordinationServiceCore (){
		std::cout<<"Create VisualizationCoordinationService Module Singelton..."<<std::endl;
	}
	~VisualizationCoordinationServiceCore (){
		std::cout<<"Destroy VisualizationCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, VisualizationCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* VISUALIZATIONCOORDINATIONSERVICECORE_H_ */
