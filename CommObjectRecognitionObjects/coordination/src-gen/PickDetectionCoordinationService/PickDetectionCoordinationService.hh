#ifndef PICKDETECTIONCOORDINATIONSERVICE_H_
#define PICKDETECTIONCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommManipulatorObjects/CommGrasp.hh>
#include <CommManipulatorObjects/CommGraspACE.hh>
#include <CommObjectRecognitionObjects/CommPickDetectionRequest.hh>
#include <CommObjectRecognitionObjects/CommPickDetectionRequestACE.hh>


#include "PickDetectionCoordinationServicePickqueryQueryHandler.hh"


class PickDetectionCoordinationService {
 	
public:
	PickDetectionCoordinationService ();
	~PickDetectionCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IQueryClientPattern<CommObjectRecognitionObjects::CommPickDetectionRequest, CommManipulatorObjects::CommGrasp> *pickDetectionCoordinationServicepickqueryClient;
	PickDetectionCoordinationServicePickqueryQueryHandler *pickDetectionCoordinationServicepickqueryQueryHandler;
 };
#endif /* PICKDETECTIONCOORDINATIONSERVICE_H_ */
