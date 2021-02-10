#include "CorridorNavigationClientCoordinationServiceNavtimequeryQueryHandler.hh"
  
#include <string.h>
#include <sstream>

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING    100000
#endif

CommNavigationObjects::CommNavigationTimeRequest CorridorNavigationClientCoordinationServiceNavtimequeryQueryHandler::handleRequest(const std::string& inString){

	CommNavigationObjects::CommNavigationTimeRequest request;
	//fill the request commObject with the data provided via the inString (from TCL)
	//e.g. request.setLisp(inString);

	char *running;
	char *token;

	// copy string
	running = strdupa (inString.c_str());

	// extract start
	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));
	request.setStartPose( atoi(token) );

	// extract goal
	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));
	request.setGoalPose( atoi(token) );

	std::cout<<__FILE__<<":: request: "<<request<<std::endl;

	return request;
}

std::string CorridorNavigationClientCoordinationServiceNavtimequeryQueryHandler::handleAnswer(const CommNavigationObjects::CommNavigationTimeResponse& answer){
	
	std::cout<<__FILE__<<":: response: "<<answer<<std::endl;
	std::string outString;

	CommBasicObjects::CommTimeStamp duration = answer.getEstimatedDuration();
	unsigned long time_seconds = duration.get_seconds();

	std::stringstream tmp;
	tmp << time_seconds;
	outString = tmp.str();

	return outString;
}
