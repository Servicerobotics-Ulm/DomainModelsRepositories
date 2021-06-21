#include "LabelPrinterCoordinationServiceFullPrintJobQueryHandler.hh"
  
DomainPrint::CommPrintRequest LabelPrinterCoordinationServiceFullPrintJobQueryHandler::handleRequest(const std::string& inString){

	DomainPrint::CommPrintRequest request;
	//fill the request commObject with the data provided via the inString (from TCL)
	//e.g. request.setLisp(inString);

	return request;
}

std::string LabelPrinterCoordinationServiceFullPrintJobQueryHandler::handleAnswer(const DomainPrint::CommPrintResponse& answer){
	
	std::string outString;
	//fill the outString (to TCL) with the data provided via the answer commObject
	//e.g. 
	//std::ostringstream ss;
	//ss << "("<< std::setprecision( 2 ) << answer_data<<")";
	//outString = ss.str();
	return outString;
}
