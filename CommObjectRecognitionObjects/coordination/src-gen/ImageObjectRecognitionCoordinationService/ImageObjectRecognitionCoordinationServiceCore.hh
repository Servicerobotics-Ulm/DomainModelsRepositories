#ifndef IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICECORE_H_
#define IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "ImageObjectRecognitionCoordinationService.hh"

 class ImageObjectRecognitionCoordinationServiceCore {
 	friend class ACE_Singleton<ImageObjectRecognitionCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	ImageObjectRecognitionCoordinationServiceCore (){
		std::cout<<"Create ImageObjectRecognitionCoordinationService Module Singelton..."<<std::endl;
	}
	~ImageObjectRecognitionCoordinationServiceCore (){
		std::cout<<"Destroy ImageObjectRecognitionCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, ImageObjectRecognitionCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode);

 };
#endif /* IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICECORE_H_ */
