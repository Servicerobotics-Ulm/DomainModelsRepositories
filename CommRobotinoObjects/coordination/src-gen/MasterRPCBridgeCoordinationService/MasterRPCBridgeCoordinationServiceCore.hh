#ifndef MASTERRPCBRIDGECOORDINATIONSERVICECORE_H_
#define MASTERRPCBRIDGECOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "MasterRPCBridgeCoordinationService.hh"

 class MasterRPCBridgeCoordinationServiceCore {
 	friend class ACE_Singleton<MasterRPCBridgeCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	MasterRPCBridgeCoordinationServiceCore (){
		std::cout<<"Create MasterRPCBridgeCoordinationService Module Singelton..."<<std::endl;
	}
	~MasterRPCBridgeCoordinationServiceCore (){
		std::cout<<"Destroy MasterRPCBridgeCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, MasterRPCBridgeCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* MASTERRPCBRIDGECOORDINATIONSERVICECORE_H_ */
