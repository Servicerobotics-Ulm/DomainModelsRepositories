#include "TrackerCoordinateServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<TrackerCoordinateServiceCore, ACE_Thread_Mutex> TRACKERCOORDINATESERVICE_MODULE;

//INIT FUNCTION

extern "C" int initTrackerCoordinateService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	TRACKERCOORDINATESERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return TRACKERCOORDINATESERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiTrackerCoordinateService(const std::string& ciInstanceName){
	return TRACKERCOORDINATESERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchTrackerCoordinateService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return TRACKERCOORDINATESERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
