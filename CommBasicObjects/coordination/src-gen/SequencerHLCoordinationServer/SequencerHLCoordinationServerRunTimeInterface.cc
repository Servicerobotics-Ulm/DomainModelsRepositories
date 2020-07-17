#include "SequencerHLCoordinationServerCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<SequencerHLCoordinationServerCore, ACE_Thread_Mutex> SEQUENCERHLCOORDINATIONSERVER_MODULE;

//INIT FUNCTION

extern "C" int initSequencerHLCoordinationServer(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	SEQUENCERHLCOORDINATIONSERVER_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return SEQUENCERHLCOORDINATIONSERVER_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiSequencerHLCoordinationServer(const std::string& ciInstanceName){
	return SEQUENCERHLCOORDINATIONSERVER_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchSequencerHLCoordinationServer(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return SEQUENCERHLCOORDINATIONSERVER_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
