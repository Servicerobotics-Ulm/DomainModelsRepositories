#ifndef _SEQUENCERHLCOORDINATIONSERVERHLCOMMANDRESPONSECLIENTSENDHANDLER_HH_
#define _SEQUENCERHLCOORDINATIONSERVERHLCOMMANDRESPONSECLIENTSENDHANDLER_HH_

#include "CommBasicObjects/CommSkillMsg.hh"
#include <string>

class SequencerHLCoordinationServerHLCommandResponseClientSendHandler
{
public:

	SequencerHLCoordinationServerHLCommandResponseClientSendHandler(){

	}

	CommBasicObjects::CommSkillMsg handleSend(std::string inString);
};

#endif
