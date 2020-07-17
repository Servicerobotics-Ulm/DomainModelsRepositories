#ifndef _SEQUENCERHLCOORDINATIONSERVERHLCOMMANDSERVEREVENTHANDLERCORE_HH_
#define _SEQUENCERHLCOORDINATIONSERVERHLCOMMANDSERVEREVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommBasicObjects/CommSkillMsg.hh"
#include "CommBasicObjects/CommSkillMsg.hh"
#include "SequencerHLCoordinationServerHLCommandServerEventHandler.hh"

class SequencerHLCoordinationServerHLCommandServerEventHandlerCore : public Smart::IEventHandler<CommBasicObjects::CommSkillMsg>
{
public:
	SequencerHLCoordinationServerHLCommandServerEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommSkillMsg, CommBasicObjects::CommSkillMsg> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommSkillMsg &r) override;
	CommBasicObjects::CommSkillMsg activateEventParam(const std::string& parameterString);
private:
	SequencerHLCoordinationServerHLCommandServerEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
