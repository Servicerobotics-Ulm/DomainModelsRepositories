#ifndef LASERFROMRGBDCOORDINATIONSERVICECORE_H_
#define LASERFROMRGBDCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "LaserFromRGBDCoordinationService.hh"

 class LaserFromRGBDCoordinationServiceCore {
 	friend class ACE_Singleton<LaserFromRGBDCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	LaserFromRGBDCoordinationServiceCore (){
		std::cout<<"Create LaserFromRGBDCoordinationService Module Singelton..."<<std::endl;
	}
	~LaserFromRGBDCoordinationServiceCore (){
		std::cout<<"Destroy LaserFromRGBDCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, LaserFromRGBDCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* LASERFROMRGBDCOORDINATIONSERVICECORE_H_ */
