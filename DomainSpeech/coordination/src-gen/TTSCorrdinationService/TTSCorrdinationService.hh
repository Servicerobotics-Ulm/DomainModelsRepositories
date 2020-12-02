#ifndef TTSCORRDINATIONSERVICE_H_
#define TTSCORRDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommPropertySet.hh>
#include <CommBasicObjects/CommPropertySetACE.hh>
#include <DomainSpeech/CommSpeechOutputMessage.hh>
#include <DomainSpeech/CommSpeechOutputMessageACE.hh>


#include "TTSCorrdinationServiceSaySendHandler.hh"
#include "TTSCorrdinationServiceSayWaitQueryHandler.hh"


class TTSCorrdinationService {
 	
public:
	TTSCorrdinationService ();
	~TTSCorrdinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	SmartACE::SendClient<DomainSpeech::CommSpeechOutputMessage> *tTSCorrdinationServicesayClient;
	TTSCorrdinationServiceSaySendHandler *tTSCorrdinationServicesaySendHandler;
	Smart::IQueryClientPattern<DomainSpeech::CommSpeechOutputMessage, CommBasicObjects::CommPropertySet> *tTSCorrdinationServicesayWaitClient;
	TTSCorrdinationServiceSayWaitQueryHandler *tTSCorrdinationServicesayWaitQueryHandler;
 };
#endif /* TTSCORRDINATIONSERVICE_H_ */
