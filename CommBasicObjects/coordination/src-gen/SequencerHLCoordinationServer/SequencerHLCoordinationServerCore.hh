#ifndef SEQUENCERHLCOORDINATIONSERVERCORE_H_
#define SEQUENCERHLCOORDINATIONSERVERCORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "SequencerHLCoordinationServer.hh"

 class SequencerHLCoordinationServerCore {
 	friend class ACE_Singleton<SequencerHLCoordinationServerCore, ACE_Thread_Mutex>;
private:
	SequencerHLCoordinationServerCore (){
		std::cout<<"Create SequencerHLCoordinationServer Module Singelton..."<<std::endl;
	}
	~SequencerHLCoordinationServerCore (){
		std::cout<<"Destroy SequencerHLCoordinationServer Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, SequencerHLCoordinationServer, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* SEQUENCERHLCOORDINATIONSERVERCORE_H_ */
