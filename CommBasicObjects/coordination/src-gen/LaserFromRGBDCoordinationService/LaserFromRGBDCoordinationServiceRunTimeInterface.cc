#include "LaserFromRGBDCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<LaserFromRGBDCoordinationServiceCore, ACE_Thread_Mutex> LASERFROMRGBDCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initLaserFromRGBDCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	LASERFROMRGBDCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return LASERFROMRGBDCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiLaserFromRGBDCoordinationService(const std::string& ciInstanceName){
	return LASERFROMRGBDCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchLaserFromRGBDCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode)
{
	return LASERFROMRGBDCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,parameter,eventMode);
}
