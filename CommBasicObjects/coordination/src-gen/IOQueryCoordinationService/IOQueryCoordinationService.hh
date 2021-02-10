#ifndef IOQUERYCOORDINATIONSERVICE_H_
#define IOQUERYCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommIOValues.hh>
#include <CommBasicObjects/CommIOValuesACE.hh>


#include "IOQueryCoordinationServiceIoQueryQueryHandler.hh"


class IOQueryCoordinationService {
 	
public:
	IOQueryCoordinationService ();
	~IOQueryCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IQueryClientPattern<CommBasicObjects::CommIOValues, CommBasicObjects::CommIOValues> *iOQueryCoordinationServiceioQueryClient;
	IOQueryCoordinationServiceIoQueryQueryHandler *iOQueryCoordinationServiceioQueryQueryHandler;
 };
#endif /* IOQUERYCOORDINATIONSERVICE_H_ */
