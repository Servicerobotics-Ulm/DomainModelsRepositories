#ifndef SEQUENCERHLCOORDINATIONSERVER_H_
#define SEQUENCERHLCOORDINATIONSERVER_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommSkillMsg.hh>
#include <CommBasicObjects/CommSkillMsgACE.hh>


#include "SequencerHLCoordinationServerHLCommandResponseClientSendHandler.hh"
#include "SequencerHLCoordinationServerHLCommandServerEventHandlerCore.hh"


class SequencerHLCoordinationServer {
 	
public:
	SequencerHLCoordinationServer ();
	~SequencerHLCoordinationServer ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	SmartACE::SendClient<CommBasicObjects::CommSkillMsg> *sequencerHLCoordinationServerhLCommandResponseClientClient;
	SequencerHLCoordinationServerHLCommandResponseClientSendHandler *sequencerHLCoordinationServerhLCommandResponseClientSendHandler;
	Smart::IEventClientPattern<CommBasicObjects::CommSkillMsg, CommBasicObjects::CommSkillMsg> *sequencerHLCoordinationServerhLCommandServerClient;
	SequencerHLCoordinationServerHLCommandServerEventHandlerCore *sequencerHLCoordinationServerhLCommandServerEventHandlerCore;
 };
#endif /* SEQUENCERHLCOORDINATIONSERVER_H_ */
