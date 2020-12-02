#ifndef _SEQ2SEQCOMCOORDINATIONSERVICETASKEVENTEVENTHANDLER_HH_
#define _SEQ2SEQCOMCOORDINATIONSERVICETASKEVENTEVENTHANDLER_HH_
#include "aceSmartSoft.hh"
#include <string>
#include <iostream>


#include "CommBasicObjects/CommTaskMessage.hh"
#include "CommBasicObjects/CommTaskMessage.hh"

class Seq2SeqComCoordinationServiceTaskEventEventHandler
{
public:
	std::string handleEvent(const CommBasicObjects::CommTaskMessage &r) throw();
	CommBasicObjects::CommTaskMessage activateEventParam(const std::string& parameterString);
};

#endif
