#include "ExternalProgamCoordinationServiceCore.hh"
#include <string>
#include <ace/OS.h>

#include <smartNumericCorrelationId.h>

 void ExternalProgamCoordinationServiceCore::addNewModuleInstance(const std::string& name){
 	std::cout<<"addNewModuleInstance name:"<<name<<std::endl;
	ExternalProgamCoordinationService mi;
	 ciInstanceMap.insert ( std::pair<std::string,ExternalProgamCoordinationService>(name,mi));
 }
 
 int ExternalProgamCoordinationServiceCore::initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC > &ciConnectionsMap){
 	std::map<std::string, ExternalProgamCoordinationService, ciLessLibC>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
		std::cout<<__FUNCTION__<<" create ports and handlers..."<<std::endl;

	// create ports


	//component name: ExternalProgamCoordinationService
	//EVENT CLIENT
	iter->second.externalProgamCoordinationServiceprogramCallResultClient = new SmartACE::EventClient<DomainExternalSystems::CommExternalProgamEventParam,DomainExternalSystems::CommExternalProgramResponse>(component);
	iter->second.externalProgamCoordinationServiceprogramCallResultEventHandlerCore = new ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore(iter->second.externalProgamCoordinationServiceprogramCallResultClient, ciInstanceName);
	//QUERY CLIENT
	iter->second.externalProgamCoordinationServiceprogramListQueryClient = new SmartACE::QueryClient<CommBasicObjects::CommVoid,DomainExternalSystems::CommProgramList>(component);
	iter->second.externalProgamCoordinationServiceprogramListQueryQueryHandler = new ExternalProgamCoordinationServiceProgramListQueryQueryHandler();
	
	// connect ports
	std::cout<<__FUNCTION__<<" connect ports..."<<std::endl; 
	std::map< std::string, CiConnection, ciLessLibC>::const_iterator ci_inst_iter = ciConnectionsMap.find(ciInstanceName);
	if(ci_inst_iter != ciConnectionsMap.end()){
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("programCallResult");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.externalProgamCoordinationServiceprogramCallResultClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.externalProgamCoordinationServiceprogramCallResultClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("programListQuery");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.externalProgamCoordinationServiceprogramListQueryClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.externalProgamCoordinationServiceprogramListQueryClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
 
 int ExternalProgamCoordinationServiceCore::finiCiInstance(const std::string& ciInstanceName){
 	std::map<std::string, ExternalProgamCoordinationService>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
			delete iter->second.externalProgamCoordinationServiceprogramCallResultEventHandlerCore;
			delete iter->second.externalProgamCoordinationServiceprogramCallResultClient;
			delete iter->second.externalProgamCoordinationServiceprogramListQueryQueryHandler;
			delete iter->second.externalProgamCoordinationServiceprogramListQueryClient;
		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
}

std::string ExternalProgamCoordinationServiceCore::switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode){
	std::map<std::string, ExternalProgamCoordinationService>::const_iterator iter = ciInstanceMap.find(ciInstanceName);
	
	if(ciInstanceName == "NIL" && ciInstanceMap.size() == 1){
		std::cout<<"Fallback - no module-inst given, using the only existing module instance!"<<std::endl;
		iter = ciInstanceMap.begin();
	}
	
	if(iter != ciInstanceMap.end()){
		
		//std::cout<<"switchExternalProgamCoordinationService - compInstName: "<<componentInstanceName<<" parameter: "<<parameter<<" service: "<<service<<std::endl;
		
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
			if(ACE_OS::strcasecmp(service.c_str(), "programCallResult-activate") == 0 )
			{
				Smart::StatusCode status;
				Smart::EventIdPtr id = nullptr;
				
				DomainExternalSystems::CommExternalProgamEventParam param;
				param = iter->second.externalProgamCoordinationServiceprogramCallResultEventHandlerCore->activateEventParam(parameter);
					
				// CONTINOUS
				if( ACE_OS::strcasecmp(eventMode.c_str(), "CONTINUOUS") == 0 )
				{
					status = iter->second.externalProgamCoordinationServiceprogramCallResultClient->activate(Smart::continuous, param, id);
					outString.str("");
					switch(status)
					{
						case Smart::SMART_OK:
							outString << "(ok ("<<id<<"))";
							break;
						case Smart::SMART_DISCONNECTED:
							outString << "(error (smart disconnected))";
							break;
						case Smart::SMART_ERROR_COMMUNICATION:
							outString << "(error (smart communication error))";
							break;
						case Smart::SMART_ERROR:
							outString << "(error (unknown error))";
			       			break;
						default:
				            outString << "(error (unknown error))";
				            break;
					} // switch
				} // CONTINOUS
					
				// SINGLE
				else if( ACE_OS::strcasecmp(eventMode.c_str(), "SINGLE") == 0 )
				{
					status = iter->second.externalProgamCoordinationServiceprogramCallResultClient->activate(Smart::single, param, id);
					outString.str("");
					switch(status)
					{
						case Smart::SMART_OK:
							outString << "(ok ("<<id<<"))";
							break;
						case Smart::SMART_DISCONNECTED:
							outString << "(error (smart disconnected))";
							break;
						case Smart::SMART_ERROR_COMMUNICATION:
							outString << "(error (smart communication error))";
							break;
						case Smart::SMART_ERROR:
				            outString << "(error (unknown error))";
				            break;
						default:
				            outString << "(error (unknown error))";
				            break;
					} // switch
				}
			}
					
			// goal event deactivate
			if(ACE_OS::strcasecmp(service.c_str(), "programCallResult-deactivate") == 0)
			{
				Smart::StatusCode status;
				
				Smart::EventIdPtr id = NULL;
				
				try {
					// TODO: <alex> this seems to be quite a hack, as ID is not always an int and will not work with other middlewares as ACE
					id = std::make_shared<Smart::NumericCorrelationId>(std::stoi( parameter ));
				}
				catch (...) {
					std::cout<<"[FleetManagerCoordinationServiceCore] id int conversion error!"<<std::endl;
					outString << "(error (unknown error))";
					return outString.str();
				}
				
				status = iter->second.externalProgamCoordinationServiceprogramCallResultClient->deactivate(id);
				outString.str("");
				switch(status)
				{
				case Smart::SMART_OK:
					outString << "(ok ("<<id<<"))";
					break;
				case Smart::SMART_WRONGID:
					outString << "(error (smart wrongid))";
					break;
				case Smart::SMART_ERROR_COMMUNICATION:
					outString << "(error (smart communication error))";
					break;
				case Smart::SMART_ERROR:
					outString << "(error (unknown error))";
					break;
				default:
					outString << "(error (unknown error))";
					break;
				} // switch
					
			}
			if(ACE_OS::strcasecmp(service.c_str(), "programListQuery") == 0 )
			{
				CommBasicObjects::CommVoid request;
				DomainExternalSystems::CommProgramList answer;
				
				Smart::StatusCode status;
				request = iter->second.externalProgamCoordinationServiceprogramListQueryQueryHandler->handleRequest(parameter);
				
				status = iter->second.externalProgamCoordinationServiceprogramListQueryClient->query(request,answer);
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.externalProgamCoordinationServiceprogramListQueryQueryHandler->handleAnswer(answer);
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
	
		return outString.str();
		
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		std::ostringstream outString;
		outString << "(fatal error)";
		return outString.str();
	}
}
