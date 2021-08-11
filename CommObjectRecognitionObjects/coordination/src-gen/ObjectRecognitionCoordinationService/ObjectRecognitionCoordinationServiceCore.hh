#ifndef OBJECTRECOGNITIONCOORDINATIONSERVICECORE_H_
#define OBJECTRECOGNITIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "ObjectRecognitionCoordinationService.hh"

 class ObjectRecognitionCoordinationServiceCore {
 	friend class ACE_Singleton<ObjectRecognitionCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	ObjectRecognitionCoordinationServiceCore (){
		std::cout<<"Create ObjectRecognitionCoordinationService Module Singelton..."<<std::endl;
	}
	~ObjectRecognitionCoordinationServiceCore (){
		std::cout<<"Destroy ObjectRecognitionCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, ObjectRecognitionCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* OBJECTRECOGNITIONCOORDINATIONSERVICECORE_H_ */
