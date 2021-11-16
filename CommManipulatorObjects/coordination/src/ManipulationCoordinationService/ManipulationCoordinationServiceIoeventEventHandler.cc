#include "ManipulationCoordinationServiceIoeventEventHandler.hh"


#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

std::string ManipulationCoordinationServiceIoeventEventHandler::handleEvent(const CommBasicObjects::CommDigitalInputEventResult &r) throw() {
	std::string outString;

	std::stringstream result_string;
	result_string << "( ";
	unsigned int number = r.getDigitalInputValuesSize();
	for(int i = 0; i< number; i++)
	{
		result_string << r.getDigitalInputValuesElemAtPos(i) << " ";
	}
	result_string << ")";
	std::cout << "ManipulatorCoordinationServiceIoeventEventHandler: outString = " <<result_string.str() <<std::endl;
	return result_string.str();
}

CommBasicObjects::CommDigitalInputEventParameter ManipulationCoordinationServiceIoeventEventHandler::activateEventParam(const std::string& parameterString){

	std::cout << "IO event activation request with string: " <<parameterString <<std::endl;
	CommBasicObjects::CommDigitalInputEventParameter param;
	//convert std::string to LISP string
	static char outString[LISP_STRING];
	char *running;
	char *token;
	// copy string
	token = running = strdupa (parameterString.c_str());

	// extract trajectory flag -- angles or pose
	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));


	/////////////////////////////////////////////////////////////////////
	// SINGLE
	//if( strcasecmp(token, "SINGLE") == 0 )
	{
		unsigned int number;
		bool value;
		do
		{
			token = strsep (&running, LISP_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));
		number = atoi(token);
		do
		{
			token = strsep (&running, LISP_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));
		value = (strcasecmp(token, "T")==0);

		std::cout << "token =" <<token <<std::endl;
		std::cout << "Number =" <<number <<": Value ="<<value<<std::endl;

		param.setDigitalInputValue(value);
		param.setDigitalInputValuesNumber(number);
		std::cout << "IO event activated with Number : " <<number << " value : " << value <<std::endl;

	}
	return param;
}
