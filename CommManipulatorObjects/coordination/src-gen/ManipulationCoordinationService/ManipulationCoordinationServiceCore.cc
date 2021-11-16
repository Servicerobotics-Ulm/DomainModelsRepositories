#include "ManipulationCoordinationServiceCore.hh"
#include <string>
#include <ace/OS.h>

#include <smartNumericCorrelationId.h>

 void ManipulationCoordinationServiceCore::addNewModuleInstance(const std::string& name){
 	std::cout<<"addNewModuleInstance name:"<<name<<std::endl;
	ManipulationCoordinationService mi;
	 ciInstanceMap.insert ( std::pair<std::string,ManipulationCoordinationService>(name,mi));
 }
 
 int ManipulationCoordinationServiceCore::initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC > &ciConnectionsMap){
 	std::map<std::string, ManipulationCoordinationService, ciLessLibC>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
		std::cout<<__FUNCTION__<<" create ports and handlers..."<<std::endl;

	// create ports


	//component name: ManipulationCoordinationService
	//EVENT CLIENT
	iter->second.manipulationCoordinationServiceioeventClient = new SmartACE::EventClient<CommBasicObjects::CommDigitalInputEventParameter,CommBasicObjects::CommDigitalInputEventResult>(component);
	iter->second.manipulationCoordinationServiceioeventEventHandlerCore = new ManipulationCoordinationServiceIoeventEventHandlerCore(iter->second.manipulationCoordinationServiceioeventClient, ciInstanceName);
	//QUERY CLIENT
	iter->second.manipulationCoordinationServiceioqueryClient = new SmartACE::QueryClient<CommBasicObjects::CommIOValues,CommBasicObjects::CommIOValues>(component);
	iter->second.manipulationCoordinationServiceioqueryQueryHandler = new ManipulationCoordinationServiceIoqueryQueryHandler();
	//EVENT CLIENT
	iter->second.manipulationCoordinationServicemanipulatoreventClient = new SmartACE::EventClient<CommManipulatorObjects::CommManipulatorEventParameter,CommManipulatorObjects::CommManipulatorEventResult>(component);
	iter->second.manipulationCoordinationServicemanipulatoreventEventHandlerCore = new ManipulationCoordinationServiceManipulatoreventEventHandlerCore(iter->second.manipulationCoordinationServicemanipulatoreventClient, ciInstanceName);
	//QUERY CLIENT
	iter->second.manipulationCoordinationServicemanipulatorprogramsClient = new SmartACE::QueryClient<CommBasicObjects::CommVoid,CommManipulatorObjects::CommMobileManipulatorPrograms>(component);
	iter->second.manipulationCoordinationServicemanipulatorprogramsQueryHandler = new ManipulationCoordinationServiceManipulatorprogramsQueryHandler();
	//QUERY CLIENT
	iter->second.manipulationCoordinationServicemanipulatorstateClient = new SmartACE::QueryClient<CommBasicObjects::CommVoid,CommManipulatorObjects::CommMobileManipulatorState>(component);
	iter->second.manipulationCoordinationServicemanipulatorstateQueryHandler = new ManipulationCoordinationServiceManipulatorstateQueryHandler();
	//SEND CLIENT
	iter->second.manipulationCoordinationServicetrajectoryClient = new SmartACE::SendClient<CommManipulatorObjects::CommManipulationTrajectory>(component);
	iter->second.manipulationCoordinationServicetrajectorySendHandler = new ManipulationCoordinationServiceTrajectorySendHandler();
	
	// connect ports
	std::cout<<__FUNCTION__<<" connect ports..."<<std::endl; 
	std::map< std::string, CiConnection, ciLessLibC>::const_iterator ci_inst_iter = ciConnectionsMap.find(ciInstanceName);
	if(ci_inst_iter != ciConnectionsMap.end()){
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("ioevent");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.manipulationCoordinationServiceioeventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulationCoordinationServiceioeventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("ioquery");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.manipulationCoordinationServiceioqueryClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulationCoordinationServiceioqueryClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("manipulatorevent");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.manipulationCoordinationServicemanipulatoreventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulationCoordinationServicemanipulatoreventClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
				status = iter->second.manipulationCoordinationServicemanipulatorprogramsClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulationCoordinationServicemanipulatorprogramsClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
				status = iter->second.manipulationCoordinationServicemanipulatorstateClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulationCoordinationServicemanipulatorstateClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("trajectory");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.manipulationCoordinationServicetrajectoryClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.manipulationCoordinationServicetrajectoryClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
 
 int ManipulationCoordinationServiceCore::finiCiInstance(const std::string& ciInstanceName){
 	std::map<std::string, ManipulationCoordinationService>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
			delete iter->second.manipulationCoordinationServiceioeventEventHandlerCore;
			delete iter->second.manipulationCoordinationServiceioeventClient;
			delete iter->second.manipulationCoordinationServiceioqueryQueryHandler;
			delete iter->second.manipulationCoordinationServiceioqueryClient;
			delete iter->second.manipulationCoordinationServicemanipulatoreventEventHandlerCore;
			delete iter->second.manipulationCoordinationServicemanipulatoreventClient;
			delete iter->second.manipulationCoordinationServicemanipulatorprogramsQueryHandler;
			delete iter->second.manipulationCoordinationServicemanipulatorprogramsClient;
			delete iter->second.manipulationCoordinationServicemanipulatorstateQueryHandler;
			delete iter->second.manipulationCoordinationServicemanipulatorstateClient;
			delete iter->second.manipulationCoordinationServicetrajectorySendHandler;
			delete iter->second.manipulationCoordinationServicetrajectoryClient;
		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
}

std::string ManipulationCoordinationServiceCore::switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode){
	std::map<std::string, ManipulationCoordinationService>::const_iterator iter = ciInstanceMap.find(ciInstanceName);
	
	if(ciInstanceName == "NIL" && ciInstanceMap.size() == 1){
		std::cout<<"Fallback - no module-inst given, using the only existing module instance!"<<std::endl;
		iter = ciInstanceMap.begin();
	}
	
	if(iter != ciInstanceMap.end()){
		
		//std::cout<<"switchManipulationCoordinationService - compInstName: "<<componentInstanceName<<" parameter: "<<parameter<<" service: "<<service<<std::endl;
		
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
			if(ACE_OS::strcasecmp(service.c_str(), "ioevent-activate") == 0 )
			{
				Smart::StatusCode status;
				Smart::EventIdPtr id = nullptr;
				
				CommBasicObjects::CommDigitalInputEventParameter param;
				param = iter->second.manipulationCoordinationServiceioeventEventHandlerCore->activateEventParam(parameter);
					
				// CONTINOUS
				if( ACE_OS::strcasecmp(eventMode.c_str(), "CONTINUOUS") == 0 )
				{
					status = iter->second.manipulationCoordinationServiceioeventClient->activate(Smart::continuous, param, id);
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
					status = iter->second.manipulationCoordinationServiceioeventClient->activate(Smart::single, param, id);
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
			if(ACE_OS::strcasecmp(service.c_str(), "ioevent-deactivate") == 0)
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
				
				status = iter->second.manipulationCoordinationServiceioeventClient->deactivate(id);
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
			if(ACE_OS::strcasecmp(service.c_str(), "ioquery") == 0 )
			{
				CommBasicObjects::CommIOValues request;
				CommBasicObjects::CommIOValues answer;
				
				Smart::StatusCode status;
				request = iter->second.manipulationCoordinationServiceioqueryQueryHandler->handleRequest(parameter);
				
				status = iter->second.manipulationCoordinationServiceioqueryClient->query(request,answer);
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.manipulationCoordinationServiceioqueryQueryHandler->handleAnswer(answer);
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
			if(ACE_OS::strcasecmp(service.c_str(), "manipulatorevent-activate") == 0 )
			{
				Smart::StatusCode status;
				Smart::EventIdPtr id = nullptr;
				
				CommManipulatorObjects::CommManipulatorEventParameter param;
				param = iter->second.manipulationCoordinationServicemanipulatoreventEventHandlerCore->activateEventParam(parameter);
					
				// CONTINOUS
				if( ACE_OS::strcasecmp(eventMode.c_str(), "CONTINUOUS") == 0 )
				{
					status = iter->second.manipulationCoordinationServicemanipulatoreventClient->activate(Smart::continuous, param, id);
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
					status = iter->second.manipulationCoordinationServicemanipulatoreventClient->activate(Smart::single, param, id);
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
			if(ACE_OS::strcasecmp(service.c_str(), "manipulatorevent-deactivate") == 0)
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
				
				status = iter->second.manipulationCoordinationServicemanipulatoreventClient->deactivate(id);
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
			if(ACE_OS::strcasecmp(service.c_str(), "manipulatorprograms") == 0 )
			{
				CommBasicObjects::CommVoid request;
				CommManipulatorObjects::CommMobileManipulatorPrograms answer;
				
				Smart::StatusCode status;
				request = iter->second.manipulationCoordinationServicemanipulatorprogramsQueryHandler->handleRequest(parameter);
				
				status = iter->second.manipulationCoordinationServicemanipulatorprogramsClient->query(request,answer);
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.manipulationCoordinationServicemanipulatorprogramsQueryHandler->handleAnswer(answer);
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
			if(ACE_OS::strcasecmp(service.c_str(), "manipulatorstate") == 0 )
			{
				CommBasicObjects::CommVoid request;
				CommManipulatorObjects::CommMobileManipulatorState answer;
				
				Smart::StatusCode status;
				request = iter->second.manipulationCoordinationServicemanipulatorstateQueryHandler->handleRequest(parameter);
				
				status = iter->second.manipulationCoordinationServicemanipulatorstateClient->query(request,answer);
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.manipulationCoordinationServicemanipulatorstateQueryHandler->handleAnswer(answer);
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
			if(ACE_OS::strcasecmp(service.c_str(), "trajectory") == 0 )
			{
				CommManipulatorObjects::CommManipulationTrajectory com;
				
				Smart::StatusCode status;
				com = iter->second.manipulationCoordinationServicetrajectorySendHandler->handleSend(parameter);

				// everything is ok
				status = iter->second.manipulationCoordinationServicetrajectoryClient->send(com);
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
