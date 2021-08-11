#ifndef FESTOMPSDOCKINGCOORDINATIONSERVICECORE_H_
#define FESTOMPSDOCKINGCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "FestoMPSDockingCoordinationService.hh"

 class FestoMPSDockingCoordinationServiceCore {
 	friend class ACE_Singleton<FestoMPSDockingCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	FestoMPSDockingCoordinationServiceCore (){
		std::cout<<"Create FestoMPSDockingCoordinationService Module Singelton..."<<std::endl;
	}
	~FestoMPSDockingCoordinationServiceCore (){
		std::cout<<"Destroy FestoMPSDockingCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, FestoMPSDockingCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* FESTOMPSDOCKINGCOORDINATIONSERVICECORE_H_ */
