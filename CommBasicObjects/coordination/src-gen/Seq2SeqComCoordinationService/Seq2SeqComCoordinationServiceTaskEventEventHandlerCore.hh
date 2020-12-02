#ifndef _SEQ2SEQCOMCOORDINATIONSERVICETASKEVENTEVENTHANDLERCORE_HH_
#define _SEQ2SEQCOMCOORDINATIONSERVICETASKEVENTEVENTHANDLERCORE_HH_
#include "aceSmartSoft.hh"
#include <string>

#include "CommBasicObjects/CommTaskMessage.hh"
#include "CommBasicObjects/CommTaskMessage.hh"
#include "Seq2SeqComCoordinationServiceTaskEventEventHandler.hh"

class Seq2SeqComCoordinationServiceTaskEventEventHandlerCore : public Smart::IEventHandler<CommBasicObjects::CommTaskMessage>
{
public:
	Seq2SeqComCoordinationServiceTaskEventEventHandlerCore(Smart::IEventClientPattern<CommBasicObjects::CommTaskMessage, CommBasicObjects::CommTaskMessage> *client, std::string moduleInstanceName);
	virtual void handleEvent(const Smart::EventIdPtr &id, const CommBasicObjects::CommTaskMessage &r) override;
	CommBasicObjects::CommTaskMessage activateEventParam(const std::string& parameterString);
private:
	Seq2SeqComCoordinationServiceTaskEventEventHandler userHandler;
	std::string ciInstanceName;
};

#endif
