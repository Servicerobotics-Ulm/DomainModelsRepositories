#ifndef FILEOPERATIONSCOORDINATIONSERVICECORE_H_
#define FILEOPERATIONSCOORDINATIONSERVICECORE_H_
#include "aceSmartSoft.hh"
#include "runTimeInterface.hh"

#include <string>
#include <map>
#include <iostream>

#include "FileOperationsCoordinationService.hh"

 class FileOperationsCoordinationServiceCore {
 	friend class ACE_Singleton<FileOperationsCoordinationServiceCore, ACE_Thread_Mutex>;
private:
	FileOperationsCoordinationServiceCore (){
		std::cout<<"Create FileOperationsCoordinationService Module Singelton..."<<std::endl;
	}
	~FileOperationsCoordinationServiceCore (){
		std::cout<<"Destroy FileOperationsCoordinationService Module Singelton..."<<std::endl;
	}
	
	std::map<std::string, FileOperationsCoordinationService, ciLessLibC> ciInstanceMap;
public:
	void addNewModuleInstance(const std::string& name);
	int initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC> &ciConnectionsMap);
	int finiCiInstance(const std::string& ciInstanceName);
	std::string switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString);

 };
#endif /* FILEOPERATIONSCOORDINATIONSERVICECORE_H_ */
