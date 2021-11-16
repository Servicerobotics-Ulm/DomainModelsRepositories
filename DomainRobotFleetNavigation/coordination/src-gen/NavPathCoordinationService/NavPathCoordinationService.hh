#ifndef NAVPATHCOORDINATIONSERVICE_H_
#define NAVPATHCOORDINATIONSERVICE_H_
#include "aceSmartSoft.hh"

// include communication objects
#include <DomainRobotFleetNavigation/CommNavPath.hh>
#include <DomainRobotFleetNavigation/CommNavPathACE.hh>
#include <DomainRobotFleetNavigation/CommShortestPathAnswer.hh>
#include <DomainRobotFleetNavigation/CommShortestPathAnswerACE.hh>
#include <DomainRobotFleetNavigation/CommShortestPathRequest.hh>
#include <DomainRobotFleetNavigation/CommShortestPathRequestACE.hh>


#include "NavPathCoordinationServiceQueryShortestPathQueryHandler.hh"
#include "NavPathCoordinationServiceSendPathSendHandler.hh"


class NavPathCoordinationService {
 	
public:
	NavPathCoordinationService ();
	~NavPathCoordinationService ();


	//variables, ports, handlers
	//param, state, wiring is dealt with the single master
	Smart::IQueryClientPattern<DomainRobotFleetNavigation::CommShortestPathRequest, DomainRobotFleetNavigation::CommShortestPathAnswer> *navPathCoordinationServicequeryShortestPathClient;
	NavPathCoordinationServiceQueryShortestPathQueryHandler *navPathCoordinationServicequeryShortestPathQueryHandler;
	SmartACE::SendClient<DomainRobotFleetNavigation::CommNavPath> *navPathCoordinationServicesendPathClient;
	NavPathCoordinationServiceSendPathSendHandler *navPathCoordinationServicesendPathSendHandler;
 };
#endif /* NAVPATHCOORDINATIONSERVICE_H_ */
