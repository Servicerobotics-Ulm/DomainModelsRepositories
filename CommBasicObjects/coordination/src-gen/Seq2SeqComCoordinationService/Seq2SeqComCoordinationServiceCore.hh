#ifndef SEQ2SEQCOMCOORDINATIONSERVICECORE_H_
#define SEQ2SEQCOMCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "Seq2SeqComCoordinationService.hh"

 class Seq2SeqComCoordinationServiceCore {
 	friend class ACE_Singleton<Seq2SeqComCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	Seq2SeqComCoordinationServiceCore (){
		std::cout<<"Create Seq2SeqComCoordinationService Module Singelton..."<<std::endl;
	}
	~Seq2SeqComCoordinationServiceCore (){
		std::cout<<"Destroy Seq2SeqComCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, Seq2SeqComCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* SEQ2SEQCOMCOORDINATIONSERVICECORE_H_ */
