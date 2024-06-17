#include "NavPathCoordinationServiceSendPathSendHandler.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
CommNavigationObjects::CommNavPath NavPathCoordinationServiceSendPathSendHandler::handleSend(std::string inString){

	// (2 (1 1 2.5 (2 (1 2.0 3.0 1) (1 2.0 3.0 1))) (2 1 2.5 (2 (1 2.0 3.0 1) (1 2.0 3.0 1))))

	std::cout << "timo navpath inString: " << inString << std::endl;

	CommNavigationObjects::CommNavPath sendCommObject;

	static char outString[LISP_STRING];
	char *running;
	char *token;

	token = running = strdupa (inString.c_str());

	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));

	CommNavigationObjects::CommPath path;
	std::vector<CommNavigationObjects::CommPath> paths;

	std::cout << "path length: " << token << std::endl;
	int pathlength = atoi(token);

	for (int i = 0; i < pathlength; i++) {
		do
		{
			token = strsep (&running, LISP_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));
		std::cout << "path id: " << token << std::endl;
		path.setId(atoi(token));

		do
		{
			token = strsep (&running, LISP_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));
		std::cout << "path direction: " << token << std::endl;
		path.setDirection(atoi(token));

		do
		{
			token = strsep (&running, LISP_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));
		std::cout << "path width: " << token << std::endl;
		path.setWidth(atof(token));

		do
		{
			token = strsep (&running, LISP_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));

		CommNavigationObjects::CommNode node;
		std::vector<CommNavigationObjects::CommNode> nodes;

		std::cout << "node length: " << token << std::endl;
		int nodelength = atoi(token);
		for (int j = 0; j < nodelength; j++) {
			do
			{
				token = strsep (&running, LISP_SEPARATOR);
			} while ((token != NULL) && (strlen(token)==0));
			std::cout << "node id: " << token << std::endl;
			node.setId(atoi(token));

			do
			{
				token = strsep (&running, LISP_SEPARATOR);
			} while ((token != NULL) && (strlen(token)==0));
			std::cout << "node x: " << token << std::endl;
			node.setX(atof(token));

			do
			{
				token = strsep (&running, LISP_SEPARATOR);
			} while ((token != NULL) && (strlen(token)==0));
			std::cout << "node y: " << token << std::endl;
			node.setY(atof(token));

			do
			{
				token = strsep (&running, LISP_SEPARATOR);
			} while ((token != NULL) && (strlen(token)==0));
			std::cout << "node reserved: " << token << std::endl;
			node.setReserved(atoi(token));
			nodes.push_back(node);
		}
		path.setNode(nodes);
		paths.push_back(path);
	}

	sendCommObject.setPath(paths);

	return sendCommObject;
}

