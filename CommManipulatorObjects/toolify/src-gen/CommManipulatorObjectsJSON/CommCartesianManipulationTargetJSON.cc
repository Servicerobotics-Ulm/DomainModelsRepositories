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

#include "CommCartesianManipulationTargetJSON.hh"

#include "CommBasicObjectsJSON/CommPose3dJSON.hh"
#include <CommManipulatorObjects/enumCartesianManipulationTargetReferenceFrame.hh>
#include <CommManipulatorObjects/enumBasicRobotMotionType.hh>
#include <CommManipulatorObjects/enumTargetVelocityTimeFlag.hh>

namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommCartesianManipulationTarget& obj, nlohmann::json& j)
{
	// tcp_pose: CommPose3d
	to_json(obj.tcp_pose, j["tcp_pose"]);
	// reference_frame: CartesianManipulationTargetReferenceFrame
	j["reference_frame"] = CommManipulatorObjects::CartesianManipulationTargetReferenceFrame(obj.reference_frame).to_string(false);
	// is_relative: Boolean
	j["is_relative"] = obj.is_relative;
	// motion_type: BasicRobotMotionType
	j["motion_type"] = CommManipulatorObjects::BasicRobotMotionType(obj.motion_type).to_string(false);
	// reach_type: TargetVelocityTimeFlag
	j["reach_type"] = CommManipulatorObjects::TargetVelocityTimeFlag(obj.reach_type).to_string(false);
	// velocity: Float
	j["velocity"] = obj.velocity;
	// acceleration: Float
	j["acceleration"] = obj.acceleration;
	// reach_time: Float
	j["reach_time"] = obj.reach_time;
	// blending_radius: Float
	j["blending_radius"] = obj.blending_radius;
	// motion_constraints: UInt8
	j["motion_constraints"] = obj.motion_constraints;
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommCartesianManipulationTarget& obj)
{
	// tcp_pose: CommPose3d
	if(j.contains("tcp_pose") && j["tcp_pose"].is_object()) {
		//from_json(j["tcp_pose"], obj.tcp_pose);
		obj.tcp_pose = j["tcp_pose"].get<CommBasicObjectsIDL::CommPose3d>();
	}
	// reference_frame: CartesianManipulationTargetReferenceFrame
	if(j.contains("reference_frame") && j["reference_frame"].is_string()) {
		obj.reference_frame = CommManipulatorObjects::CartesianManipulationTargetReferenceFrame::from_string(j["reference_frame"].get<std::string>());
	}
	// is_relative: Boolean
	if(j.contains("is_relative") && j["is_relative"].is_boolean()) {
		obj.is_relative = j["is_relative"].get<bool>();
	}
	// motion_type: BasicRobotMotionType
	if(j.contains("motion_type") && j["motion_type"].is_string()) {
		obj.motion_type = CommManipulatorObjects::BasicRobotMotionType::from_string(j["motion_type"].get<std::string>());
	}
	// reach_type: TargetVelocityTimeFlag
	if(j.contains("reach_type") && j["reach_type"].is_string()) {
		obj.reach_type = CommManipulatorObjects::TargetVelocityTimeFlag::from_string(j["reach_type"].get<std::string>());
	}
	// velocity: Float
	if(j.contains("velocity") && j["velocity"].is_number_float()) {
		obj.velocity = j["velocity"].get<float>();
	}
	// acceleration: Float
	if(j.contains("acceleration") && j["acceleration"].is_number_float()) {
		obj.acceleration = j["acceleration"].get<float>();
	}
	// reach_time: Float
	if(j.contains("reach_time") && j["reach_time"].is_number_float()) {
		obj.reach_time = j["reach_time"].get<float>();
	}
	// blending_radius: Float
	if(j.contains("blending_radius") && j["blending_radius"].is_number_float()) {
		obj.blending_radius = j["blending_radius"].get<float>();
	}
	// motion_constraints: UInt8
	if(j.contains("motion_constraints") && j["motion_constraints"].is_number_unsigned()) {
		obj.motion_constraints = j["motion_constraints"].get<unsigned char>();
	}
}

} // end namespace CommManipulatorObjectsIDL