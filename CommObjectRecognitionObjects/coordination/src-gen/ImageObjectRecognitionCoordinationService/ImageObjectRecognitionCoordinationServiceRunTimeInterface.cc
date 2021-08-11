#include "ImageObjectRecognitionCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<ImageObjectRecognitionCoordinationServiceCore, ACE_Thread_Mutex> IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initImageObjectRecognitionCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiImageObjectRecognitionCoordinationService(const std::string& ciInstanceName){
	return IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchImageObjectRecognitionCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return IMAGEOBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
