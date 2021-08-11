#ifndef DEFAULTSERVICECORE_H_
#define DEFAULTSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "DefaultService.hh"

 class DefaultServiceCore {
 	friend class ACE_Singleton<DefaultServiceCore, ACE_Thread_Mutex>;
private:
	DefaultServiceCore (){
		std::cout<<"Create DefaultService Module Singelton..."<<std::endl;
	}
	~DefaultServiceCore (){
		std::cout<<"Destroy DefaultService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, DefaultService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* DEFAULTSERVICECORE_H_ */
