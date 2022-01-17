#ifndef MAPPERCOORDINATIONSERVICE_H_
#define MAPPERCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommNavigationObjects/CommGridMap.hh>
#include <CommNavigationObjects/CommGridMapACE.hh>
#include <CommNavigationObjects/CommGridMapRequest.hh>
#include <CommNavigationObjects/CommGridMapRequestACE.hh>


#include "MapperCoordinationServiceLtmMapDataQueryHandler.hh"


class MapperCoordinationService {
 	
public:
	MapperCoordinationService ();
	~MapperCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IQueryClientPattern<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap> *mapperCoordinationServiceltmMapDataClient;
	MapperCoordinationServiceLtmMapDataQueryHandler *mapperCoordinationServiceltmMapDataQueryHandler;
 };
#endif /* MAPPERCOORDINATIONSERVICE_H_ */
