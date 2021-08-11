#include "LabelPrinterCoordinationServiceCore.hh"
#include <string>
#include <ace/OS.h>

#include <smartNumericCorrelationId.h>

 void LabelPrinterCoordinationServiceCore::addNewModuleInstance(const std::string& name){
 	std::cout<<"addNewModuleInstance name:"<<name<<std::endl;
	LabelPrinterCoordinationService mi;
	 ciInstanceMap.insert ( std::pair<std::string,LabelPrinterCoordinationService>(name,mi));
 }
 
 int LabelPrinterCoordinationServiceCore::initCiInstance(SmartACE::SmartComponent * component, const std::string& ciInstanceName, const std::map< std::string, CiConnection, ciLessLibC > &ciConnectionsMap){
 	std::map<std::string, LabelPrinterCoordinationService, ciLessLibC>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
		std::cout<<__FUNCTION__<<" create ports and handlers..."<<std::endl;

	// create ports


	//component name: LabelPrinterCoordinationService
	//QUERY CLIENT
	iter->second.labelPrinterCoordinationServicedataClient = new SmartACE::QueryClient<DomainPrint::CommPrintProcessData,DomainPrint::CommPrintResponse>(component);
	iter->second.labelPrinterCoordinationServicedataQueryHandler = new LabelPrinterCoordinationServiceDataQueryHandler();
	//QUERY CLIENT
	iter->second.labelPrinterCoordinationServicefullPrintJobClient = new SmartACE::QueryClient<DomainPrint::CommPrintRequest,DomainPrint::CommPrintResponse>(component);
	iter->second.labelPrinterCoordinationServicefullPrintJobQueryHandler = new LabelPrinterCoordinationServiceFullPrintJobQueryHandler();
	//SEND CLIENT
	iter->second.labelPrinterCoordinationServicetriggerClient = new SmartACE::SendClient<CommBasicObjects::CommVoid>(component);
	iter->second.labelPrinterCoordinationServicetriggerSendHandler = new LabelPrinterCoordinationServiceTriggerSendHandler();
	
	// connect ports
	std::cout<<__FUNCTION__<<" connect ports..."<<std::endl; 
	std::map< std::string, CiConnection, ciLessLibC>::const_iterator ci_inst_iter = ciConnectionsMap.find(ciInstanceName);
	if(ci_inst_iter != ciConnectionsMap.end()){
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("data");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.labelPrinterCoordinationServicedataClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.labelPrinterCoordinationServicedataClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("fullPrintJob");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.labelPrinterCoordinationServicefullPrintJobClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.labelPrinterCoordinationServicefullPrintJobClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				}
				std::cout << "connected.\n";
			} else {
				std::cout<<"ERROR SERVICE NOT FOUND IN MAP!"<<std::endl;
				return 1;
			}
		}
		{
			std::map<std::string, std::string>::const_iterator service_iter = ci_inst_iter->second.serviceNameMap.find("trigger");
			if(service_iter != ci_inst_iter->second.serviceNameMap.end()){
				std::string serviceName(service_iter->second);
		
				Smart::StatusCode status;
		
				std::cout << "connecting to: " << ci_inst_iter->second.componentInstanceName << "; " << serviceName << std::endl;
				status = iter->second.labelPrinterCoordinationServicetriggerClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
				while(status != Smart::SMART_OK)
				{
					ACE_OS::sleep(ACE_Time_Value(0,500000));
					status = iter->second.labelPrinterCoordinationServicetriggerClient->connect(ci_inst_iter->second.componentInstanceName, serviceName);
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
 
 int LabelPrinterCoordinationServiceCore::finiCiInstance(const std::string& ciInstanceName){
 	std::map<std::string, LabelPrinterCoordinationService>::iterator iter = ciInstanceMap.find(ciInstanceName);
	if(iter != ciInstanceMap.end()){
			delete iter->second.labelPrinterCoordinationServicedataQueryHandler;
			delete iter->second.labelPrinterCoordinationServicedataClient;
			delete iter->second.labelPrinterCoordinationServicefullPrintJobQueryHandler;
			delete iter->second.labelPrinterCoordinationServicefullPrintJobClient;
			delete iter->second.labelPrinterCoordinationServicetriggerSendHandler;
			delete iter->second.labelPrinterCoordinationServicetriggerClient;
		return 0;
	} else {
		std::cout<<"ERROR WAS NOT ABLE TO FIND CI INSTANCE IN MAP --> this should not have happend!"<<std::endl;
		return -1;
	}
}

std::string LabelPrinterCoordinationServiceCore::switchCi(const std::string& ciInstanceName, const std::string& componentName, const std::string& componentInstanceName, const std::string& service, const std::string& parameter, const std::string& eventMode){
	std::map<std::string, LabelPrinterCoordinationService>::const_iterator iter = ciInstanceMap.find(ciInstanceName);
	
	if(ciInstanceName == "NIL" && ciInstanceMap.size() == 1){
		std::cout<<"Fallback - no module-inst given, using the only existing module instance!"<<std::endl;
		iter = ciInstanceMap.begin();
	}
	
	if(iter != ciInstanceMap.end()){
		
		//std::cout<<"switchLabelPrinterCoordinationService - compInstName: "<<componentInstanceName<<" parameter: "<<parameter<<" service: "<<service<<std::endl;
		
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
			if(ACE_OS::strcasecmp(service.c_str(), "data") == 0 )
			{
				DomainPrint::CommPrintProcessData request;
				DomainPrint::CommPrintResponse answer;
				
				Smart::StatusCode status;
				request = iter->second.labelPrinterCoordinationServicedataQueryHandler->handleRequest(parameter);
				
				status = iter->second.labelPrinterCoordinationServicedataClient->query(request,answer);
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.labelPrinterCoordinationServicedataQueryHandler->handleAnswer(answer);
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
			if(ACE_OS::strcasecmp(service.c_str(), "fullPrintJob") == 0 )
			{
				DomainPrint::CommPrintRequest request;
				DomainPrint::CommPrintResponse answer;
				
				Smart::StatusCode status;
				request = iter->second.labelPrinterCoordinationServicefullPrintJobQueryHandler->handleRequest(parameter);
				
				status = iter->second.labelPrinterCoordinationServicefullPrintJobClient->query(request,answer);
				outString.str("");
				switch (status)
				{
					case Smart::SMART_OK:
					{
						std::string resString = iter->second.labelPrinterCoordinationServicefullPrintJobQueryHandler->handleAnswer(answer);
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
			if(ACE_OS::strcasecmp(service.c_str(), "trigger") == 0 )
			{
				CommBasicObjects::CommVoid com;
				
				Smart::StatusCode status;
				com = iter->second.labelPrinterCoordinationServicetriggerSendHandler->handleSend(parameter);

				// everything is ok
				status = iter->second.labelPrinterCoordinationServicetriggerClient->send(com);
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
