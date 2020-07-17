#ifndef _SEQUENCERHLCOORDINATIONSERVERHLCOMMANDSERVEREVENTHANDLER_HH_
#define _SEQUENCERHLCOORDINATIONSERVERHLCOMMANDSERVEREVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommBasicObjects/CommSkillMsg.hh"
#include "CommBasicObjects/CommSkillMsg.hh"

class SequencerHLCoordinationServerHLCommandServerEventHandler
{
public:
	std::string handleEvent(const CommBasicObjects::CommSkillMsg &r) throw();
	CommBasicObjects::CommSkillMsg activateEventParam(const std::string& parameterString);
};

#endif
