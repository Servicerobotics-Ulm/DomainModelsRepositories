#ifndef IOQUERYCOORDINATIONSERVICECORE_H_
#define IOQUERYCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "IOQueryCoordinationService.hh"

 class IOQueryCoordinationServiceCore {
 	friend class ACE_Singleton<IOQueryCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	IOQueryCoordinationServiceCore (){
		std::cout<<"Create IOQueryCoordinationService Module Singelton..."<<std::endl;
	}
	~IOQueryCoordinationServiceCore (){
		std::cout<<"Destroy IOQueryCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, IOQueryCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* IOQUERYCOORDINATIONSERVICECORE_H_ */
