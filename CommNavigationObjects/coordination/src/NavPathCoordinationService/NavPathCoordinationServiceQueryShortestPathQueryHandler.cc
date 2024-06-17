#include "NavPathCoordinationServiceQueryShortestPathQueryHandler.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
CommNavigationObjects::CommShortestPathRequest NavPathCoordinationServiceQueryShortestPathQueryHandler::handleRequest(const std::string& inString){

	CommNavigationObjects::CommShortestPathRequest request;
	//fill the request commObject with the data provided via the inString (from TCL)
	//e.g. request.setLisp(inString);

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

std::string NavPathCoordinationServiceQueryShortestPathQueryHandler::handleAnswer(const CommNavigationObjects::CommShortestPathAnswer& answer){
	
	std::string outString;
	//fill the outString (to TCL) with the data provided via the answer commObject
	//e.g. 
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}
