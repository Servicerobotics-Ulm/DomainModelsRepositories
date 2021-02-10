#include "CorridorNavigationClientCoordinationServiceClosestnodequeryQueryHandler.hh"

#include <string.h>
#include <iomanip>
#include <sstream>

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING    100000
#endif

CommNavigationObjects::CommClosestNodeRequest CorridorNavigationClientCoordinationServiceClosestnodequeryQueryHandler::handleRequest(const std::string& inString){

	CommNavigationObjects::CommClosestNodeRequest request;

	char *running;
	char *token;

	// copy string
	running = strdupa (inString.c_str());

	CommBasicObjects::CommPosition3d startPosition;

	// extract x
	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));
	startPosition.set_x(atof(token),1);

	// extract y
	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));
	startPosition.set_y(atof(token),1);

	request.setPosition(startPosition);

	std::cout<<__FILE__<<":: request: "<<request<<std::endl;

	return request;
}

std::string CorridorNavigationClientCoordinationServiceClosestnodequeryQueryHandler::handleAnswer(const CommNavigationObjects::CommClosestNodeAnswer& answer){

	std::cout<<__FILE__<<":: response: "<<answer<<std::endl;

	std::string outString;

	std::stringstream tmp;

	if(answer.getValid()==true){
		CommBasicObjects::CommPosition3d position = answer.getPosition();
		//ok id dist x y
		tmp <<"( T "<<answer.getNode_id()<<" "<<std::setprecision(3)<< answer.getDistance()<<" "<<position.get_x(1)<<" "<<position.get_y(1)<<")";
	} else {
		tmp <<"( NIL )";
	}

	outString = tmp.str();

	return outString;
}
