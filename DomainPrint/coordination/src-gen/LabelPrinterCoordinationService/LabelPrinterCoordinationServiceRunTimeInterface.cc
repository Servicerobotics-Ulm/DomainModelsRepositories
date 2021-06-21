#include "LabelPrinterCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<LabelPrinterCoordinationServiceCore, ACE_Thread_Mutex> LABELPRINTERCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initLabelPrinterCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	LABELPRINTERCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return LABELPRINTERCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiLabelPrinterCoordinationService(const std::string& ciInstanceName){
	return LABELPRINTERCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchLabelPrinterCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return LABELPRINTERCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
