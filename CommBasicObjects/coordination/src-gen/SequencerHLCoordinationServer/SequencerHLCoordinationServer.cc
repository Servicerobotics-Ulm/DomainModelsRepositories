#include "SequencerHLCoordinationServer.hh"

SequencerHLCoordinationServer::SequencerHLCoordinationServer (){
		sequencerHLCoordinationServerhLCommandResponseClientSendHandler = NULL;
		sequencerHLCoordinationServerhLCommandResponseClientClient = NULL;
		sequencerHLCoordinationServerhLCommandServerClient = NULL;
		sequencerHLCoordinationServerhLCommandServerEventHandlerCore = NULL;
}
SequencerHLCoordinationServer::~SequencerHLCoordinationServer (){
	
}

