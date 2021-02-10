#include "Seq2SeqComCoordinationServiceCore.hh"
#include "runTimeInterface.hh"

typedef ACE_Singleton<Seq2SeqComCoordinationServiceCore, ACE_Thread_Mutex> SEQ2SEQCOMCOORDINATIONSERVICE_MODULE;

//INIT FUNCTION

extern "C" int initSeq2SeqComCoordinationService(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string,  CiConnection, ciLessLibC > &ciConnectionsMap){
	SEQ2SEQCOMCOORDINATIONSERVICE_MODULE::instance()->addNewModuleInstance(ciInstanceName);

	return SEQ2SEQCOMCOORDINATIONSERVICE_MODULE::instance()->initCiInstance(component,ciInstanceName,ciConnectionsMap);
}



//FINI FUNCTION

extern "C" int finiSeq2SeqComCoordinationService(const std::string& ciInstanceName){
	return SEQ2SEQCOMCOORDINATIONSERVICE_MODULE::instance()->finiCiInstance(ciInstanceName);
}


//SWITCH FUNCTION

extern "C" std::string switchSeq2SeqComCoordinationService(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString)
{
	return SEQ2SEQCOMCOORDINATIONSERVICE_MODULE::instance()->switchCi(ciInstanceName,componentName,componentInstanceName,service,inString);
}
