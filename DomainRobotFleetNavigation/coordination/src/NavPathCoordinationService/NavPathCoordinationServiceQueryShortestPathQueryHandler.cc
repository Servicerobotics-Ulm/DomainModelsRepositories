#include "NavPathCoordinationServiceQueryShortestPathQueryHandler.hh"

#include "DomainRobotFleetNavigationJSON/CommShortestPathRequestJSON.hh"
#include "DomainRobotFleetNavigationJSON/CommShortestPathAnswerJSON.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DomainRobotFleetNavigation::CommShortestPathRequest NavPathCoordinationServiceQueryShortestPathQueryHandler::handleRequest(const std::string& inString){
	DomainRobotFleetNavigation::CommShortestPathRequest request;
	// parse the inString into an nlohmann::json object
	nlohmann::json data = nlohmann::json::parse(inString);
	// convert the parsed nlohmann::json object into the request communication object
	DomainRobotFleetNavigationIDL::from_json(data, request.set());
	// return the coverted result object

	std::cout << "RECEIVED: " << inString << std::endl;

	static char outString[LISP_STRING];
	char *running;
	char *token;

	token = running = strdupa (inString.c_str());

	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));

	request.setFrom(atoi(token));

	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));

	request.setTo(atoi(token));

	std::cout << "from: " << request.getFrom() << " & to: " << request.getTo() << std::endl;


	return request;
}

std::string NavPathCoordinationServiceQueryShortestPathQueryHandler::handleAnswer(const DomainRobotFleetNavigation::CommShortestPathAnswer& answer){
	nlohmann::json data;
	DomainRobotFleetNavigationIDL::to_json(answer.get(), data);
	return data.dump();
}
