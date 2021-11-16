#include "NavPathCoordinationServiceCore.hh"
#include <string>
#include <ace/OS.h>

#include <smartNumericCorrelationId.h>

 void NavPathCoordinationServiceCore::addNewModuleInstance(const std::string& name){
 	std::cout<<"addNewModuleInstance name:"<<name<<std::endl;
	NavPathCoordinationService mi;
	 ciInstanceMap.insert ( std::pair<std::string,NavPathCoordinationService>(name,mi));
 }
 
 int NavPathCoordinationServiceCore::initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC > &ciConnectionsMap){
 	std::map<std::string, NavPathCoordinationService, ciLessLibC>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
		std::cout<<__FUNCTION__<<" create ports and handlers..."<<std::endl;

	// create ports


	//component name: NavPathCoordinationService
	//QUERY CLIENT
	iter->second.navPathCoordinationServicequeryShortestPathClient = new SmartACE::QueryClient<DomainRobotFleetNavigation::CommShortestPathRequest,DomainRobotFleetNavigation::CommShortestPathAnswer>(component);
	iter->second.navPathCoordinationServicequeryShortestPathQueryHandler = new NavPathCoordinationServiceQueryShortestPathQueryHandler();
	//SEND CLIENT
	iter->second.navPathCoordinationServicesendPathClient = new SmartACE::SendClient<DomainRobotFleetNavigation::CommNavPath>(component);
	iter->second.navPathCoordinationServicesendPathSendHandler = new NavPathCoordinationServiceSendPathSendHandler();
	
	// connect ports
	std::cout<<__FUNCTION__<<" connect ports..."<<std::endl; 
	std::map< std::string, CiConnection, ciLessLibC>::const_iterator ci_inst_iter = ciConnectionsMap.find(ciInstanceName);
	if(ci_inst_iter != ciConnectionsMap.end()){
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("queryShortestPath");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.navPathCoordinationServicequeryShortestPathClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.navPathCoordinationServicequeryShortestPathClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("sendPath");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.navPathCoordinationServicesendPathClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.navPathCoordinationServicesendPathClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
	} else {
		std::cout<<"Was not able to find ci inst in ciComponent connection map!"<<std::endl;
	}

		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
 }
 
 int NavPathCoordinationServiceCore::finiCiInstance(const std::string& ciInstanceName){
 	std::map<std::string, NavPathCoordinationService>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
			delete iter->second.navPathCoordinationServicequeryShortestPathQueryHandler;
			delete iter->second.navPathCoordinationServicequeryShortestPathClient;
			delete iter->second.navPathCoordinationServicesendPathSendHandler;
			delete iter->second.navPathCoordinationServicesendPathClient;
		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
}

std::string NavPathCoordinationServiceCore::switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode){
	std::map<std::string, NavPathCoordinationService>::const_iterator iter = ciInstanceMap.find(ciInstanceName);
	
	if(ciInstanceName == "NIL" && ciInstanceMap.size() == 1){
		std::cout<<"Fallback - no module-inst given, using the only existing module instance!"<<std::endl;
		iter = ciInstanceMap.begin();
	}
	
	if(iter != ciInstanceMap.end()){
		
		//std::cout<<"switchNavPathCoordinationService - compInstName: "<<componentInstanceName<<" parameter: "<<parameter<<" service: "<<service<<std::endl;
		
		std::ostringstream outString;
		outString << "(error (unknown error))";
	
			
			// param
			if(ACE_OS::strcasecmp(service.c_str(), "param") == 0 )
			{
				outString.str(queryParam(componentInstanceName, parameter));
			}
			if(ACE_OS::strcasecmp(service.c_str(), "state") == 0 )
			{
				outString.str(setState(componentInstanceName, parameter));
			}
			if(ACE_OS::strcasecmp(service.c_str(), "getstate") == 0 )
			{
				outString.str(getState(componentInstanceName));
			}
			if(ACE_OS::strcasecmp(service.c_str(), "waitforlifecyclestate") == 0 )
			{
				outString.str(waitForLifeCycleState(componentInstanceName, parameter));
			}
			if(ACE_OS::strcasecmp(service.c_str(), "queryShortestPath") == 0 )
			{
				DomainRobotFleetNavigation::CommShortestPathRequest request;
				DomainRobotFleetNavigation::CommShortestPathAnswer answer;
				
				Smart::StatusCode status;
				request = iter->second.navPathCoordinationServicequeryShortestPathQueryHandler->handleRequest(parameter);
				
				status = iter->second.navPathCoordinationServicequeryShortestPathClient->query(request,answer);
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.navPathCoordinationServicequeryShortestPathQueryHandler->handleAnswer(answer);
						outString << "(ok "<<resString<<")";
						break;
				 	}
					case Smart::SMART_DISCONNECTED:
						outString << "(error (smart disconnected))";
						break;
					case Smart::SMART_ERROR_COMMUNICATION:
						outString << "(error (smart communication error))";
						break;
					case Smart::SMART_ERROR:
						outString << "(error (smart error))";
						break;
					default:
						outString << "(error (unknown error))";
						break;
				} // switch(status)
			}
			if(ACE_OS::strcasecmp(service.c_str(), "sendPath") == 0 )
			{
				DomainRobotFleetNavigation::CommNavPath com;
				
				Smart::StatusCode status;
				com = iter->second.navPathCoordinationServicesendPathSendHandler->handleSend(parameter);

				// everything is ok
				status = iter->second.navPathCoordinationServicesendPathClient->send(com);
				outString.str("");
				switch (status)
				{
						case Smart::SMART_OK:
								outString << "(ok ())";
								break;
						case Smart::SMART_DISCONNECTED:
								outString << "(error (smart disconnected))";
								break;
						case Smart::SMART_ERROR_COMMUNICATION:
								outString << "(error (smart communication error))";
								break;
						case Smart::SMART_ERROR:
								outString << "(error (smart error))";
								break;
						default:
								outString << "(error (unknown error))";
								break;
				}
			}
	
		return outString.str();
		
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		std::ostringstream outString;
		outString << "(fatal error)";
		return outString.str();
	}
}
