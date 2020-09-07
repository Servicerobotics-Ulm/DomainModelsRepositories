#include "ManipulatorCoordinationServiceCore.hh"
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

#include <smartNumericCorrelationId.h>

 void ManipulatorCoordinationServiceCore::addNewModuleInstance(const std::string& name){
 	std::cout<<"addNewModuleInstance name:"<<name<<std::endl;
	ManipulatorCoordinationService mi;
	 ciInstanceMap.insert ( std::pair<std::string,ManipulatorCoordinationService>(name,mi));
 }
 
 int ManipulatorCoordinationServiceCore::initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC > &ciConnectionsMap){
 	std::map<std::string, ManipulatorCoordinationService, ciLessLibC>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
		std::cout<<__FUNCTION__<<" create ports and handlers..."<<std::endl;

	// create ports


	//component name: ManipulatorCoordinationService
	//EVENT CLIENT
	iter->second.manipulatorCoordinationServicemanipulatoreventClient = new SmartACE::EventClient<CommManipulatorObjects::CommManipulatorEventParameter,CommManipulatorObjects::CommManipulatorEventResult>(component);
	iter->second.manipulatorCoordinationServicemanipulatoreventEventHandlerCore = new ManipulatorCoordinationServiceManipulatoreventEventHandlerCore(iter->second.manipulatorCoordinationServicemanipulatoreventClient, ciInstanceName);
	//QUERY CLIENT
	iter->second.manipulatorCoordinationServicemanipulatorprogramsClient = new SmartACE::QueryClient<CommBasicObjects::CommVoid,CommManipulatorObjects::CommMobileManipulatorPrograms>(component);
	iter->second.manipulatorCoordinationServicemanipulatorprogramsQueryHandler = new ManipulatorCoordinationServiceManipulatorprogramsQueryHandler();
	//QUERY CLIENT
	iter->second.manipulatorCoordinationServicemanipulatorstateClient = new SmartACE::QueryClient<CommBasicObjects::CommVoid,CommManipulatorObjects::CommMobileManipulatorState>(component);
	iter->second.manipulatorCoordinationServicemanipulatorstateQueryHandler = new ManipulatorCoordinationServiceManipulatorstateQueryHandler();
	
	// connect ports
	std::cout<<__FUNCTION__<<" connect ports..."<<std::endl; 
	std::map< std::string, CiConnection, ciLessLibC>::const_iterator ci_inst_iter = ciConnectionsMap.find(ciInstanceName);
	if(ci_inst_iter != ciConnectionsMap.end()){
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("manipulatorevent");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.manipulatorCoordinationServicemanipulatoreventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulatorCoordinationServicemanipulatoreventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("manipulatorprograms");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.manipulatorCoordinationServicemanipulatorprogramsClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulatorCoordinationServicemanipulatorprogramsClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("manipulatorstate");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.manipulatorCoordinationServicemanipulatorstateClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulatorCoordinationServicemanipulatorstateClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
 
 int ManipulatorCoordinationServiceCore::finiCiInstance(const std::string& ciInstanceName){
 	std::map<std::string, ManipulatorCoordinationService>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
			delete iter->second.manipulatorCoordinationServicemanipulatoreventEventHandlerCore;
			delete iter->second.manipulatorCoordinationServicemanipulatoreventClient;
			delete iter->second.manipulatorCoordinationServicemanipulatorprogramsQueryHandler;
			delete iter->second.manipulatorCoordinationServicemanipulatorprogramsClient;
			delete iter->second.manipulatorCoordinationServicemanipulatorstateQueryHandler;
			delete iter->second.manipulatorCoordinationServicemanipulatorstateClient;
		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
}

std::string ManipulatorCoordinationServiceCore::switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString){
	std::map<std::string, ManipulatorCoordinationService>::const_iterator iter = ciInstanceMap.find(ciInstanceName);
	
	if(ciInstanceName == "NIL" && ciInstanceMap.size() == 1){
		std::cout<<"Fallback - no module-inst given, using the only existing module instance!"<<std::endl;
		iter = ciInstanceMap.begin();
	}
	
	if(iter != ciInstanceMap.end()){
		
		std::cout<<"switchManipulatorCoordinationService - compInstName: "<<componentInstanceName<<" inString: "<<inString<<" service: "<<service<<std::endl;
		
		std::ostringstream outString;
		outString << "(error (unknown error))";
	
			
			// param
			if(strcasecmp(service.c_str(), "param") == 0 )
			{
				outString.str(queryParam(componentInstanceName, inString));
			}
			if(strcasecmp(service.c_str(), "state") == 0 )
			{
				outString.str(setState(componentInstanceName, inString));
			}
			if(strcasecmp(service.c_str(), "manipulatorevent-activate") == 0 )
			{
				Smart::StatusCode status;
				Smart::EventIdPtr id = nullptr;
				char *input  = (char *)NULL;
				char *pointer = (char *)NULL;
				char *param1  = (char *)NULL;
				
				pointer = input = strdup(inString.c_str());
				do
				{
					param1 = strsep(&input," ()\"\n");
				} while ((param1 != NULL) && (strlen(param1)==0));
					
				CommManipulatorObjects::CommManipulatorEventParameter param;
				param = iter->second.manipulatorCoordinationServicemanipulatoreventEventHandlerCore->activateEventParam(input);
					
				// CONTINOUS
				if( strcasecmp(param1, "CONTINUOUS") == 0 )
				{
					status = iter->second.manipulatorCoordinationServicemanipulatoreventClient->activate(Smart::continuous, param, id);
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
				else if( strcasecmp(param1, "SINGLE") == 0 )
				{
					status = iter->second.manipulatorCoordinationServicemanipulatoreventClient->activate(Smart::single, param, id);
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
			if(strcasecmp(service.c_str(), "manipulatorevent-deactivate") == 0)
			{
				Smart::StatusCode status;
				char *input  = (char *)NULL;
				char *pointer = (char *)NULL;
				char *param1  = (char *)NULL;
					
				pointer = input = strdup(inString.c_str());
				do
				{
					param1 = strsep(&input," ()\"\n");
				} while ((param1 != NULL) && (strlen(param1)==0));
					
				std::string str(param1);
				// remove " "
				str = str.substr(1, str.length()-2);
				// TODO: <alex> this seems to be quite a hack, as ID is not always an int and will not work with other middlewares as ACE
				Smart::EventIdPtr id = std::make_shared<Smart::NumericCorrelationId>(atoi( param1 ));
					
				status = iter->second.manipulatorCoordinationServicemanipulatoreventClient->deactivate(id);
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
			if(strcasecmp(service.c_str(), "manipulatorprograms") == 0 )
			{
				CommBasicObjects::CommVoid request;
				CommManipulatorObjects::CommMobileManipulatorPrograms answer;
				
				Smart::StatusCode status;
				request = iter->second.manipulatorCoordinationServicemanipulatorprogramsQueryHandler->handleRequest(inString);
				
				std::cout << "vor status = manipulatorprogramsClient->query(request,answer);\n";
				status = iter->second.manipulatorCoordinationServicemanipulatorprogramsClient->query(request,answer);
				std::cout << "nach status = manipulatorprogramsClient->query(request,answer);\n";
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.manipulatorCoordinationServicemanipulatorprogramsQueryHandler->handleAnswer(answer);
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
			if(strcasecmp(service.c_str(), "manipulatorstate") == 0 )
			{
				CommBasicObjects::CommVoid request;
				CommManipulatorObjects::CommMobileManipulatorState answer;
				
				Smart::StatusCode status;
				request = iter->second.manipulatorCoordinationServicemanipulatorstateQueryHandler->handleRequest(inString);
				
				std::cout << "vor status = manipulatorstateClient->query(request,answer);\n";
				status = iter->second.manipulatorCoordinationServicemanipulatorstateClient->query(request,answer);
				std::cout << "nach status = manipulatorstateClient->query(request,answer);\n";
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.manipulatorCoordinationServicemanipulatorstateQueryHandler->handleAnswer(answer);
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
