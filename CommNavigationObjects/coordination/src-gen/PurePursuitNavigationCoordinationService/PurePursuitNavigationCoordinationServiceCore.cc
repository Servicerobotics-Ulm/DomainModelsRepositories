#include "PurePursuitNavigationCoordinationServiceCore.hh"
#include <string>
#include <ace/OS.h>

#include <smartNumericCorrelationId.h>

 void PurePursuitNavigationCoordinationServiceCore::addNewModuleInstance(const std::string& name){
 	std::cout<<"addNewModuleInstance name:"<<name<<std::endl;
	PurePursuitNavigationCoordinationService mi;
	 ciInstanceMap.insert ( std::pair<std::string,PurePursuitNavigationCoordinationService>(name,mi));
 }
 
 int PurePursuitNavigationCoordinationServiceCore::initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC > &ciConnectionsMap){
 	std::map<std::string, PurePursuitNavigationCoordinationService, ciLessLibC>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
		std::cout<<__FUNCTION__<<" create ports and handlers..."<<std::endl;

	// create ports


	//component name: PurePursuitNavigationCoordinationService
	//EVENT CLIENT
	iter->second.purePursuitNavigationCoordinationServicegoalEventClient = new SmartACE::EventClient<CommNavigationObjects::CommCdlGoalEventParameter,CommNavigationObjects::CommCdlGoalEventResult>(component);
	iter->second.purePursuitNavigationCoordinationServicegoalEventEventHandlerCore = new PurePursuitNavigationCoordinationServiceGoalEventEventHandlerCore(iter->second.purePursuitNavigationCoordinationServicegoalEventClient, ciInstanceName);
	
	// connect ports
	std::cout<<__FUNCTION__<<" connect ports..."<<std::endl; 
	std::map< std::string, CiConnection, ciLessLibC>::const_iterator ci_inst_iter = ciConnectionsMap.find(ciInstanceName);
	if(ci_inst_iter != ciConnectionsMap.end()){
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("goalEvent");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.purePursuitNavigationCoordinationServicegoalEventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.purePursuitNavigationCoordinationServicegoalEventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
 
 int PurePursuitNavigationCoordinationServiceCore::finiCiInstance(const std::string& ciInstanceName){
 	std::map<std::string, PurePursuitNavigationCoordinationService>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
			delete iter->second.purePursuitNavigationCoordinationServicegoalEventEventHandlerCore;
			delete iter->second.purePursuitNavigationCoordinationServicegoalEventClient;
		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
}

std::string PurePursuitNavigationCoordinationServiceCore::switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode){
	std::map<std::string, PurePursuitNavigationCoordinationService>::const_iterator iter = ciInstanceMap.find(ciInstanceName);
	
	if(ciInstanceName == "NIL" && ciInstanceMap.size() == 1){
		std::cout<<"Fallback - no module-inst given, using the only existing module instance!"<<std::endl;
		iter = ciInstanceMap.begin();
	}
	
	if(iter != ciInstanceMap.end()){
		
		//std::cout<<"switchPurePursuitNavigationCoordinationService - compInstName: "<<componentInstanceName<<" parameter: "<<parameter<<" service: "<<service<<std::endl;
		
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
			if(ACE_OS::strcasecmp(service.c_str(), "goalEvent-activate") == 0 )
			{
				Smart::StatusCode status;
				Smart::EventIdPtr id = nullptr;
				
				CommNavigationObjects::CommCdlGoalEventParameter param;
				param = iter->second.purePursuitNavigationCoordinationServicegoalEventEventHandlerCore->activateEventParam(parameter);
					
				// CONTINOUS
				if( ACE_OS::strcasecmp(eventMode.c_str(), "CONTINUOUS") == 0 )
				{
					status = iter->second.purePursuitNavigationCoordinationServicegoalEventClient->activate(Smart::continuous, param, id);
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
					status = iter->second.purePursuitNavigationCoordinationServicegoalEventClient->activate(Smart::single, param, id);
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
			if(ACE_OS::strcasecmp(service.c_str(), "goalEvent-deactivate") == 0)
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
				
				status = iter->second.purePursuitNavigationCoordinationServicegoalEventClient->deactivate(id);
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
