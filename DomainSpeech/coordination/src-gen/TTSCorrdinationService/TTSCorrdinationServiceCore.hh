#ifndef TTSCORRDINATIONSERVICECORE_H_
#define TTSCORRDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "TTSCorrdinationService.hh"

 class TTSCorrdinationServiceCore {
 	friend class ACE_Singleton<TTSCorrdinationServiceCore, ACE_Thread_Mutex>;
private:
	TTSCorrdinationServiceCore (){
		std::cout<<"Create TTSCorrdinationService Module Singelton..."<<std::endl;
	}
	~TTSCorrdinationServiceCore (){
		std::cout<<"Destroy TTSCorrdinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, TTSCorrdinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* TTSCORRDINATIONSERVICECORE_H_ */
