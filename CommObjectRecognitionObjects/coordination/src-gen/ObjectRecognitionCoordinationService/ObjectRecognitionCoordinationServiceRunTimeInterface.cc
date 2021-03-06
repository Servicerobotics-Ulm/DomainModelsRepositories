#include "ObjectRecognitionCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<ObjectRecognitionCoordinationServiceCore, ACE_Thread_Mutex> OBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initObjectRecognitionCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	OBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return OBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiObjectRecognitionCoordinationService(const std::string& ciInstanceName){
	return OBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchObjectRecognitionCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return OBJECTRECOGNITIONCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
