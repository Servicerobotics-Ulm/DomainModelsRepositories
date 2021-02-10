#include "IOQueryCoordinationServiceIoQueryQueryHandler.hh"
#include <sstream>

#include <string.h>

#ifndef LIST_SEPARATOR
#define LIST_SEPARATOR " ()\"\n"
#define LIST_STRING    100000
#endif

CommBasicObjects::CommIOValues IOQueryCoordinationServiceIoQueryQueryHandler::handleRequest(const std::string& inString){

	CommBasicObjects::CommIOValues request;
	//fill the request commObject with the data provided via the inString (from TCL)
	//e.g. request.setLisp(inString);

	//        std::string input(inString);
	//        std::string help;
	char *running;
	char *token;

	// copy string
	token = running = strdupa (inString.c_str());

	do
	{
		// extract trajectory flag -- angles or pose
		do
		{
			token = strsep (&running, LIST_SEPARATOR);
		} while ((token != NULL) && (strlen(token)==0));

		if(running != NULL){
			if( strcasecmp(token, "DIGITAL") == 0){
				unsigned int number;
				bool value;
				do
				{
					token = strsep (&running, LIST_SEPARATOR);
				} while ((token != NULL) && (strlen(token)==0));
				number = atoi(token);
				do
				{
					token = strsep (&running, LIST_SEPARATOR);
				} while ((token != NULL) && (strlen(token)==0));
				value = (strcasecmp(token,"0") == 1);
				std::cout<<"Push DIGITAL "<<number<<" "<<value<<std::endl;
				CommBasicObjects::CommDigitalOutputRequest tmp(number, value);
				//request.pushBackDigitalOutputValues(tmp);
				request.resizeDigitalOutputValues(request.getDigitalOutputValuesSize()+1);
				request.setDigitalOutputValuesElemAtPos(request.getDigitalOutputValuesSize()-1,tmp);
			} else if (strcasecmp(token, "ANALOG") == 0){
				unsigned int number;
				double value;
				do
				{
					token = strsep (&running, LIST_SEPARATOR);
				} while ((token != NULL) && (strlen(token)==0));
				number = atoi(token);
				do
				{
					token = strsep (&running, LIST_SEPARATOR);
				} while ((token != NULL) && (strlen(token)==0));
				std::cout<<"alue: "<<token<<std::endl;
				value =  atof(token);
				std::cout<<"Push ANALOG "<<number<<" "<<value<<std::endl;
				CommBasicObjects::CommAnalogOutputRequest tmp;
				tmp.setOutputNumber(number);
				tmp.setOutputValue(value);
				//request.pushBackAnalogOutputValues(tmp);
				request.resizeAnalogOutputValues(request.getAnalogOutputValuesSize()+1);
				request.setAnalogOutputValuesElemAtPos(request.getAnalogOutputValuesSize()-1,tmp);

			} else {
				std::cout<<__FILE__<<" "<<__FUNCTION__<<"ERROR PARSING LISP STRING: "<<token<<std::endl;
			}
		} else {
			std::cout<<"FOUND END"<<std::endl;
		}
	}
	while(running!=NULL);


	return request;
}

std::string IOQueryCoordinationServiceIoQueryQueryHandler::handleAnswer(const CommBasicObjects::CommIOValues& answer){

	std::ostringstream ss;

	ss << "((";
	for(unsigned int i=0;i<answer.getDigitalInputValuesSize();++i){
		ss << answer.getDigitalInputValuesElemAtPos(i) <<" ";
	}
	ss <<")(";
	for(unsigned int i=0;i<answer.getAnalogInputValuesSize();++i){
		ss << answer.getAnalogInputValuesElemAtPos(i) <<" ";
	}
	ss <<"))";

	return ss.str();
}
