#include "ManipulationCoordinationServiceManipulatorstateQueryHandler.hh"


#include <iomanip>

CommBasicObjects::CommVoid ManipulationCoordinationServiceManipulatorstateQueryHandler::handleRequest(const std::string& inString){
	CommBasicObjects::CommVoid request;
//	// parse the inString into an nlohmann::json object
//	nlohmann::json data = nlohmann::json::parse(inString);
//	// convert the parsed nlohmann::json object into the request communication object
//	CommBasicObjectsIDL::from_json(data, request.set());
//	// return the coverted result object
	return request;
}

std::string ManipulationCoordinationServiceManipulatorstateQueryHandler::handleAnswer(const CommManipulatorObjects::CommMobileManipulatorState& answer){

	std::ostringstream outString;

	if(answer.is_valid() && answer.get_manipulator_state().is_valid()) {

		double x,y,z,yaw,pitch,roll;
		answer.get_manipulator_state().get_pose_TCP_robot(x, y, z, yaw, pitch, roll, 1.0);

		outString << std::setprecision(5);
		outString << "((angles ";
		for (int i = 0; i < answer.get_manipulator_state().get_joint_count(); ++i) {
			outString << answer.get_manipulator_state().get_joint_angle(i) << " ";
		}
		outString << ")";

		outString << "(pose " << x << " " << y << " " << z << " " << yaw << " "
				<< pitch << " " << roll << "))";
	}
	else {
		outString << "((no valid answer))";
	}

	return outString.str();


//	nlohmann::json data;
//	CommManipulatorObjectsIDL::to_json(answer.get(), data);
//	return data.dump();
}
