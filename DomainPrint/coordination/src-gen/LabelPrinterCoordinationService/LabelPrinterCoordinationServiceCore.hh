#ifndef LABELPRINTERCOORDINATIONSERVICECORE_H_
#define LABELPRINTERCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "LabelPrinterCoordinationService.hh"

 class LabelPrinterCoordinationServiceCore {
 	friend class ACE_Singleton<LabelPrinterCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	LabelPrinterCoordinationServiceCore (){
		std::cout<<"Create LabelPrinterCoordinationService Module Singelton..."<<std::endl;
	}
	~LabelPrinterCoordinationServiceCore (){
		std::cout<<"Destroy LabelPrinterCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, LabelPrinterCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* LABELPRINTERCOORDINATIONSERVICECORE_H_ */
