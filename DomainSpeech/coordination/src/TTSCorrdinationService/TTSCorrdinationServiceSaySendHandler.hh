#ifndef _TTSCORRDINATIONSERVICESAYSENDHANDLER_HH_
#define _TTSCORRDINATIONSERVICESAYSENDHANDLER_HH_

#include "DomainSpeech/CommSpeechOutputMessage.hh"
#include <string>

class TTSCorrdinationServiceSaySendHandler
{
public:

	TTSCorrdinationServiceSaySendHandler(){

	}

	DomainSpeech::CommSpeechOutputMessage handleSend(std::string inString);
};

#endif
