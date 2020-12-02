#ifndef _TTSCORRDINATIONSERVICESAYWAITQUERYHANDLER_HH_
#define _TTSCORRDINATIONSERVICESAYWAITQUERYHANDLER_HH_

#include "DomainSpeech/CommSpeechOutputMessage.hh"
#include "CommBasicObjects/CommPropertySet.hh"
#include <string>

class TTSCorrdinationServiceSayWaitQueryHandler
{
public:

	TTSCorrdinationServiceSayWaitQueryHandler(){

	}

	DomainSpeech::CommSpeechOutputMessage handleRequest(const std::string& inString);

	std::string handleAnswer(const CommBasicObjects::CommPropertySet& answer);
};

#endif
