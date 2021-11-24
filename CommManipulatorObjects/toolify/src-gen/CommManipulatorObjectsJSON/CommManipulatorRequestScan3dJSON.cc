//-----------------------------------------------------------------------------------
// Code generated by the Toolify Robotics GmbH extension for the SmartMDSD Toolchain 
// 
// Toolify Robotics GmbH
// Weinbergweg 216
// 89075 Ulm 
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//-----------------------------------------------------------------------------------

#include "CommManipulatorRequestScan3dJSON.hh"


namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommManipulatorRequestScan3d& obj, nlohmann::json& j)
{
	// begin_joint_angles: Double[]
	j["begin_joint_angles"] = obj.begin_joint_angles;
	// end_joint_angles: Double[]
	j["end_joint_angles"] = obj.end_joint_angles;
	// laser_begin_angle: Double
	j["laser_begin_angle"] = obj.laser_begin_angle;
	// laser_end_angle: Double
	j["laser_end_angle"] = obj.laser_end_angle;
	// number_of_steps: UInt16
	j["number_of_steps"] = obj.number_of_steps;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommManipulatorRequestScan3d& obj)
{
	// begin_joint_angles: Double[]
	if(j.contains("begin_joint_angles") && j["begin_joint_angles"].is_array()) {
		obj.begin_joint_angles = j["begin_joint_angles"].get<std::vector<double>>();
	}
	// end_joint_angles: Double[]
	if(j.contains("end_joint_angles") && j["end_joint_angles"].is_array()) {
		obj.end_joint_angles = j["end_joint_angles"].get<std::vector<double>>();
	}
	// laser_begin_angle: Double
	if(j.contains("laser_begin_angle") && j["laser_begin_angle"].is_number_float()) {
		obj.laser_begin_angle = j["laser_begin_angle"].get<double>();
	}
	// laser_end_angle: Double
	if(j.contains("laser_end_angle") && j["laser_end_angle"].is_number_float()) {
		obj.laser_end_angle = j["laser_end_angle"].get<double>();
	}
	// number_of_steps: UInt16
	if(j.contains("number_of_steps") && j["number_of_steps"].is_number_unsigned()) {
		obj.number_of_steps = j["number_of_steps"].get<unsigned short>();
	}
}

} // end namespace CommManipulatorObjectsIDL