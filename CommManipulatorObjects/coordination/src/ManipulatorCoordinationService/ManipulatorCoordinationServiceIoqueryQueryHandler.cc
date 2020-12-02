#include "ManipulatorCoordinationServiceIoqueryQueryHandler.hh"

#ifndef LISP_SEPARATOR
#define LISP_SEPARATOR " ()\"\n"
#define LISP_STRING 100000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
CommBasicObjects::CommIOValues ManipulatorCoordinationServiceIoqueryQueryHandler::handleRequest(const std::string& inString){

	CommBasicObjects::CommIOValues request;

	//convert std::string to LISP string
	static char outString[LISP_STRING];
	char *running;
	char *token;
	// copy string
	token = running = strdupa (inString.c_str());

	// extract trajectory flag -- angles or pose
	do
	{
		token = strsep (&running, LISP_SEPARATOR);
	} while ((token != NULL) && (strlen(token)==0));


	/////////////////////////////////////////////////////////////////////
	// DIGITAL
	if( strcasecmp(token, "DIGITAL") == 0 )
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
		value = (strcasecmp(token, "0")==1);

		std::cout << "Number =" <<number <<": Value ="<<value<<std::endl;

		CommBasicObjects::CommDigitalOutputRequest digital_req;
		digital_req.setOutputNumber(number);
		digital_req.setOutputValue(value);
		request.resizeDigitalOutputValues(request.getDigitalOutputValuesSize() + 1);
		request.setDigitalOutputValuesElemAtPos(request.getDigitalOutputValuesSize() - 1, digital_req);
	} else if(strcasecmp(token, "ANALOG") == 0 ){
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
		value = (strcasecmp(token, "0")==1);

		std::cout << "Number =" <<number <<": Value ="<<value<<std::endl;

		CommBasicObjects::CommAnalogOutputRequest analog_req;
		analog_req.setOutputNumber(number);
		analog_req.setOutputValue(value);
		request.resizeAnalogOutputValues(request.getAnalogOutputValuesSize() + 1);
		request.setAnalogOutputValuesElemAtPos(request.getAnalogOutputValuesSize() - 1, analog_req);
	}

	return request;
}

std::string ManipulatorCoordinationServiceIoqueryQueryHandler::handleAnswer(const CommBasicObjects::CommIOValues& answer){
	
	std::string outString;
	//fill the outString (to TCL) with the data provided via the answer commObject
	//e.g. 
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}
