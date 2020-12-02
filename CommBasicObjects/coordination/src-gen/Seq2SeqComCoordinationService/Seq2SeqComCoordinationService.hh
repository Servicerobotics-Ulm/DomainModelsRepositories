#ifndef SEQ2SEQCOMCOORDINATIONSERVICE_H_
#define SEQ2SEQCOMCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommTaskEventState.hh>
#include <CommBasicObjects/CommTaskEventStateACE.hh>
#include <CommBasicObjects/CommTaskMessage.hh>
#include <CommBasicObjects/CommTaskMessageACE.hh>


#include "Seq2SeqComCoordinationServiceTaskEventEventHandlerCore.hh"


class Seq2SeqComCoordinationService {
 	
public:
	Seq2SeqComCoordinationService ();
	~Seq2SeqComCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommBasicObjects::CommTaskMessage, CommBasicObjects::CommTaskMessage> *seq2SeqComCoordinationServicetaskEventClient;
	Seq2SeqComCoordinationServiceTaskEventEventHandlerCore *seq2SeqComCoordinationServicetaskEventEventHandlerCore;
 };
#endif /* SEQ2SEQCOMCOORDINATIONSERVICE_H_ */
