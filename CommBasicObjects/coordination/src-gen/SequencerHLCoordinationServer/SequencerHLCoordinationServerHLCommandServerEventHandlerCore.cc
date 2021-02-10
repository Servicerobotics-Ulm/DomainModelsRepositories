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
	std::string resultString;
	resultString = userHandler.handleEvent(r);
	
	///////////////////////////////////////////
	/////////// ESCAPE " in user data
	std::string toSearch = "\"";
	std::string replaceStr = "\\\"";
	// Get the first occurrence
    size_t pos = resultString.find(toSearch);
    // Repeat till end is reached
    while( pos != std::string::npos)
    {
        // Replace this occurrence of Sub String
    	resultString.replace(pos, toSearch.size(), replaceStr);
        // Get the next occurrence from the current position
        pos =resultString.find(toSearch, pos + replaceStr.size());
    }
    ///////////////////////////////////////////
	
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
