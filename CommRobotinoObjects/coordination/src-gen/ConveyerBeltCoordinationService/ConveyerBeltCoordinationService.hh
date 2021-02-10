#ifndef CONVEYERBELTCOORDINATIONSERVICE_H_
#define CONVEYERBELTCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommRobotinoObjects/CommRobotinoConveyerBeltEventParameter.hh>
#include <CommRobotinoObjects/CommRobotinoConveyerBeltEventParameterACE.hh>
#include <CommRobotinoObjects/CommRobotinoConveyerBeltEventResult.hh>
#include <CommRobotinoObjects/CommRobotinoConveyerBeltEventResultACE.hh>
#include <CommRobotinoObjects/RobotinoConveyerBeltEventState.hh>
#include <CommRobotinoObjects/RobotinoConveyerBeltEventStateACE.hh>


#include "ConveyerBeltCoordinationServiceLoadeventEventHandlerCore.hh"


class ConveyerBeltCoordinationService {
 	
public:
	ConveyerBeltCoordinationService ();
	~ConveyerBeltCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<CommRobotinoObjects::CommRobotinoConveyerBeltEventParameter, CommRobotinoObjects::CommRobotinoConveyerBeltEventResult> *conveyerBeltCoordinationServiceloadeventClient;
	ConveyerBeltCoordinationServiceLoadeventEventHandlerCore *conveyerBeltCoordinationServiceloadeventEventHandlerCore;
 };
#endif /* CONVEYERBELTCOORDINATIONSERVICE_H_ */
