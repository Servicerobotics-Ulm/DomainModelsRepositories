#include "CdlCoordinationServiceCore.hh"
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

#include <smartNumericCorrelationId.h>

 void CdlCoordinationServiceCore::addNewModuleInstance(const std::string& name){
 	std::cout<<"addNewModuleInstance name:"<<name<<std::endl;
	CdlCoordinationService mi;
	 ciInstanceMap.insert ( std::pair<std::string,CdlCoordinationService>(name,mi));
 }
 
 int CdlCoordinationServiceCore::initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC > &ciConnectionsMap){
 	std::map<std::string, CdlCoordinationService, ciLessLibC>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
		std::cout<<__FUNCTION__<<" create ports and handlers..."<<std::endl;

	// create ports


	//component name: CdlCoordinationService
	//EVENT CLIENT
	iter->second.cdlCoordinationServiceblockedEventClient = new SmartACE::EventClient<CommNavigationObjects::CommCdlRobotBlockedEventParameter,CommNavigationObjects::CommCdlRobotBlockedEventResult>(component);
	iter->second.cdlCoordinationServiceblockedEventEventHandlerCore = new CdlCoordinationServiceBlockedEventEventHandlerCore(iter->second.cdlCoordinationServiceblockedEventClient, ciInstanceName);
	//EVENT CLIENT
	iter->second.cdlCoordinationServicegoalEventClient = new SmartACE::EventClient<CommNavigationObjects::CommCdlGoalEventParameter,CommNavigationObjects::CommCdlGoalEventResult>(component);
	iter->second.cdlCoordinationServicegoalEventEventHandlerCore = new CdlCoordinationServiceGoalEventEventHandlerCore(iter->second.cdlCoordinationServicegoalEventClient, ciInstanceName);
	
	// connect ports
	std::cout<<__FUNCTION__<<" connect ports..."<<std::endl; 
	std::map< std::string, CiConnection, ciLessLibC>::const_iterator ci_inst_iter = ciConnectionsMap.find(ciInstanceName);
	if(ci_inst_iter != ciConnectionsMap.end()){
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("blockedEvent");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.cdlCoordinationServiceblockedEventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.cdlCoordinationServiceblockedEventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("goalEvent");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.cdlCoordinationServicegoalEventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.cdlCoordinationServicegoalEventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
 
 int CdlCoordinationServiceCore::finiCiInstance(const std::string& ciInstanceName){
 	std::map<std::string, CdlCoordinationService>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
			delete iter->second.cdlCoordinationServiceblockedEventEventHandlerCore;
			delete iter->second.cdlCoordinationServiceblockedEventClient;
			delete iter->second.cdlCoordinationServicegoalEventEventHandlerCore;
			delete iter->second.cdlCoordinationServicegoalEventClient;
		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
}

std::string CdlCoordinationServiceCore::switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& inString){
	std::map<std::string, CdlCoordinationService>::const_iterator iter = ciInstanceMap.find(ciInstanceName);
	
	if(ciInstanceName == "NIL" && ciInstanceMap.size() == 1){
		std::cout<<"Fallback - no module-inst given, using the only existing module instance!"<<std::endl;
		iter = ciInstanceMap.begin();
	}
	
	if(iter != ciInstanceMap.end()){
		
		//std::cout<<"switchCdlCoordinationService - compInstName: "<<componentInstanceName<<" inString: "<<inString<<" service: "<<service<<std::endl;
		
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
			if(strcasecmp(service.c_str(), "getstate") == 0 )
			{
				outString.str(getState(componentInstanceName));
			}
			if(strcasecmp(service.c_str(), "waitforlifecyclestate") == 0 )
			{
				outString.str(waitForLifeCycleState(componentInstanceName, inString));
			}
			if(strcasecmp(service.c_str(), "blockedEvent-activate") == 0 )
			{
				Smart::StatusCode status;
				Smart::EventIdPtr id = nullptr;
				char *input  = (char *)NULL;
				char *pointer = (char *)NULL;
				char *param1  = (char *)NULL;
				char *eventParam  = (char *)NULL;
				
				pointer = input = strdup(inString.c_str());
				do
				{
					param1 = strsep(&input," ()\"\n");
				} while ((param1 != NULL) && (strlen(param1)==0));
				
				do
				{
					eventParam = strsep(&input," ()\"\n");
				} while ((eventParam != NULL) && (strlen(eventParam)==0));
				
				CommNavigationObjects::CommCdlRobotBlockedEventParameter param;
				param = iter->second.cdlCoordinationServiceblockedEventEventHandlerCore->activateEventParam(eventParam);
					
				// CONTINOUS
				if( strcasecmp(param1, "CONTINUOUS") == 0 )
				{
					status = iter->second.cdlCoordinationServiceblockedEventClient->activate(Smart::continuous, param, id);
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
					status = iter->second.cdlCoordinationServiceblockedEventClient->activate(Smart::single, param, id);
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
			if(strcasecmp(service.c_str(), "blockedEvent-deactivate") == 0)
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
					
				status = iter->second.cdlCoordinationServiceblockedEventClient->deactivate(id);
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
			if(strcasecmp(service.c_str(), "goalEvent-activate") == 0 )
			{
				Smart::StatusCode status;
				Smart::EventIdPtr id = nullptr;
				char *input  = (char *)NULL;
				char *pointer = (char *)NULL;
				char *param1  = (char *)NULL;
				char *eventParam  = (char *)NULL;
				
				pointer = input = strdup(inString.c_str());
				do
				{
					param1 = strsep(&input," ()\"\n");
				} while ((param1 != NULL) && (strlen(param1)==0));
				
				do
				{
					eventParam = strsep(&input," ()\"\n");
				} while ((eventParam != NULL) && (strlen(eventParam)==0));
				
				CommNavigationObjects::CommCdlGoalEventParameter param;
				param = iter->second.cdlCoordinationServicegoalEventEventHandlerCore->activateEventParam(eventParam);
					
				// CONTINOUS
				if( strcasecmp(param1, "CONTINUOUS") == 0 )
				{
					status = iter->second.cdlCoordinationServicegoalEventClient->activate(Smart::continuous, param, id);
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
					status = iter->second.cdlCoordinationServicegoalEventClient->activate(Smart::single, param, id);
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
			if(strcasecmp(service.c_str(), "goalEvent-deactivate") == 0)
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
					
				status = iter->second.cdlCoordinationServicegoalEventClient->deactivate(id);
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
	
		return outString.str();
		
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		std::ostringstream outString;
		outString << "(fatal error)";
		return outString.str();
	}
}
