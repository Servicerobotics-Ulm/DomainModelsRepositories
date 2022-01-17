#ifndef BUNDLEDNAVIGATIONCOORDINATIONSERVICE_H_
#define BUNDLEDNAVIGATIONCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommBaseStateACE.hh>
#include <CommNavigationObjects/CommBundledNavigationEventParameter.hh>
#include <CommNavigationObjects/CommBundledNavigationEventParameterACE.hh>
#include <CommNavigationObjects/CommBundledNavigationEventResult.hh>
#include <CommNavigationObjects/CommBundledNavigationEventResultACE.hh>
#include <CommNavigationObjects/CommBundledNavigationEventState.hh>
#include <CommNavigationObjects/CommBundledNavigationEventStateACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>


#include "BundledNavigationCoordinationServiceBaseStateQueryHandler.hh"
#include "BundledNavigationCoordinationServiceGoalEventEventHandlerCore.hh"


class BundledNavigationCoordinationService {
 	
public:
	BundledNavigationCoordinationService ();
	~BundledNavigationCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IQueryClientPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState> *bundledNavigationCoordinationServicebaseStateClient;
	BundledNavigationCoordinationServiceBaseStateQueryHandler *bundledNavigationCoordinationServicebaseStateQueryHandler;
	Smart::IEventClientPattern<CommNavigationObjects::CommBundledNavigationEventParameter, CommNavigationObjects::CommBundledNavigationEventResult> *bundledNavigationCoordinationServicegoalEventClient;
	BundledNavigationCoordinationServiceGoalEventEventHandlerCore *bundledNavigationCoordinationServicegoalEventEventHandlerCore;
 };
#endif /* BUNDLEDNAVIGATIONCOORDINATIONSERVICE_H_ */
