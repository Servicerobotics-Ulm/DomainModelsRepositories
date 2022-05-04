#include "NavPathCoordinationServiceQueryClosestFreeNodeQueryHandler.hh"

#include "CommBasicObjectsJSON/CommPosition3dJSON.hh"
#include "DomainRobotFleetNavigationJSON/CommNodeJSON.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iomanip>

CommBasicObjects::CommPosition3d NavPathCoordinationServiceQueryClosestFreeNodeQueryHandler::handleRequest(const std::string& inString){
	CommBasicObjects::CommPosition3d request;
	// parse the inString into an nlohmann::json object
	//nlohmann::json data = nlohmann::json::parse(inString);
	// convert the parsed nlohmann::json object into the request communication object
	//CommBasicObjectsIDL::from_json(data, request.set());
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

	request.setX(atoi(token));

	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));

	request.setY(atoi(token));

	return request;
}

std::string NavPathCoordinationServiceQueryClosestFreeNodeQueryHandler::handleAnswer(const DomainRobotFleetNavigation::CommNode& answer){
	//nlohmann::json data;
	//DomainRobotFleetNavigationIDL::to_json(answer.get(), data);
	//return data.dump();
	//return std::to_string(answer.getId());

	std::ostringstream outString;
	int id = answer.getId();
	double x = answer.getX();
	double y = answer.getY();
	outString << "("<<id<<" "<<(int)x<<" "<<(int)y<<")";

	return outString.str();
}
