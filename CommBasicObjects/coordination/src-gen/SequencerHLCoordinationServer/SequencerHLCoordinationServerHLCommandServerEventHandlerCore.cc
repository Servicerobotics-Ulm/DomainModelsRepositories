#include "SequencerHLCoordinationServerHLCommandServerEventHandlerCore.hh"
#include "runTimeInterface.hh"
#include <cstdio>
#include <iostream>

SequencerHLCoordinationServerHLCommandServerEventHandlerCore::SequencerHLCoordinationServerHLCommandServerEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommSkillMsg, CommBasicObjects::CommSkillMsg> *client, std::string ciInstanceName)
: Smart::IEventHandler<CommBasicObjects::CommSkillMsg>(client)
{
	this->ciInstanceName = ciInstanceName;
}
		
void SequencerHLCoordinationServerHLCommandServerEventHandlerCore::handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommSkillMsg &r) {
	std::cout<<"Event CORE Called!"<<std::endl;
	std::string resultString;
	resultString = userHandler.handleEvent(r);
	
	std::ostringstream eventResult;
	eventResult<< "(";
	eventResult<< "( coordination-interfaces-type . \"SequencerHLCoordinationServer\")";
	eventResult<< "( coordination-interface-instance . \""<<this->ciInstanceName<<"\")";
	eventResult<< "( service-name . \"HLCommandServer\")";
	eventResult<< "( id . "<<id<<")";
	eventResult<< "( data . \""<<resultString<<"\")";
	eventResult<< ")";
//	eventResult<<"((\"SequencerHLCoordinationServer\" "<<this->ciInstanceName<<" \"HLCommandServer\" "<<id<<") "<<resultString<<")";
	int result = appedEvent(eventResult.str());
}

CommBasicObjects::CommSkillMsg SequencerHLCoordinationServerHLCommandServerEventHandlerCore::activateEventParam(const std::string& parameterString){
	std::cout<<"Activate Event Parameter string: "<<parameterString<<std::endl;
	return userHandler.activateEventParam(parameterString);
}
