#ifndef EXTERNALPROGAMCOORDINATIONSERVICE_H_
#define EXTERNALPROGAMCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <DomainExternalSystems/CommExternalProgamEventParam.hh>
#include <DomainExternalSystems/CommExternalProgamEventParamACE.hh>
#include <DomainExternalSystems/CommExternalProgramResponse.hh>
#include <DomainExternalSystems/CommExternalProgramResponseACE.hh>
#include <DomainExternalSystems/CommProgramList.hh>
#include <DomainExternalSystems/CommProgramListACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>


#include "ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore.hh"
#include "ExternalProgamCoordinationServiceProgramListQueryQueryHandler.hh"


class ExternalProgamCoordinationService {
 	
public:
	ExternalProgamCoordinationService ();
	~ExternalProgamCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IEventClientPattern<DomainExternalSystems::CommExternalProgamEventParam, DomainExternalSystems::CommExternalProgramResponse> *externalProgamCoordinationServiceprogramCallResultClient;
	ExternalProgamCoordinationServiceProgramCallResultEventHandlerCore *externalProgamCoordinationServiceprogramCallResultEventHandlerCore;
	Smart::IQueryClientPattern<CommBasicObjects::CommVoid, DomainExternalSystems::CommProgramList> *externalProgamCoordinationServiceprogramListQueryClient;
	ExternalProgamCoordinationServiceProgramListQueryQueryHandler *externalProgamCoordinationServiceprogramListQueryQueryHandler;
 };
#endif /* EXTERNALPROGAMCOORDINATIONSERVICE_H_ */
