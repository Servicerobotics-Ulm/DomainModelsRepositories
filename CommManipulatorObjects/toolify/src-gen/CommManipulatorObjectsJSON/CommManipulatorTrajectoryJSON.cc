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

#include "CommManipulatorTrajectoryJSON.hh"

#include "CommManipulatorObjectsJSON/CommJointValuesJSON.hh"
#include "CommBasicObjectsJSON/CommPose3dJSON.hh"
#include "CommManipulatorObjectsJSON/CommGripperTrajectoryJSON.hh"
#include <CommManipulatorObjects/enumManipulatorTrajectoryFlag.hh>

namespace CommManipulatorObjectsIDL {

void to_json(const CommManipulatorObjectsIDL::CommManipulatorTrajectory& obj, nlohmann::json& j)
{
	// joint_angles: CommJointValues[]
	for(size_t idx=0; idx < obj.joint_angles.size(); idx++) {
		nlohmann::json array_element;
		to_json(obj.joint_angles.at(idx), array_element);
		j["joint_angles"].emplace_back(array_element);
	}
	// pose_tcp: CommPose3d
	to_json(obj.pose_tcp, j["pose_tcp"]);
	// gripper_angles: CommGripperTrajectory
	to_json(obj.gripper_angles, j["gripper_angles"]);
	// flag: ManipulatorTrajectoryFlag
	j["flag"] = CommManipulatorObjects::ManipulatorTrajectoryFlag(obj.flag).to_string(false);
}

/**
 * this transformation handles missing values and checks for correct types:
 * - missing primitive type values (including simple arrays) are set to zero values
 * - missing object type values are skipped entirely
 * - types are checked before performing the type-cast operation
 */
void from_json(const nlohmann::json& j, CommManipulatorObjectsIDL::CommManipulatorTrajectory& obj)
{
	// joint_angles: CommJointValues[]
	if(j.contains("joint_angles") && j["joint_angles"].is_array()) {
		auto jjoint_angles = j["joint_angles"];
		obj.joint_angles.resize(jjoint_angles.size());
		for(size_t idx=0; idx < jjoint_angles.size(); idx++) {
			// convert the json array values individually
			if(jjoint_angles.at(idx).is_object()) {
				// from_json(jjoint_angles.at(idx), obj.joint_angles.at(idx));
				obj.joint_angles[idx] = jjoint_angles[idx].get<CommManipulatorObjectsIDL::CommJointValues>();
			}
		}
	}
	// pose_tcp: CommPose3d
	if(j.contains("pose_tcp") && j["pose_tcp"].is_object()) {
		//from_json(j["pose_tcp"], obj.pose_tcp);
		obj.pose_tcp = j["pose_tcp"].get<CommBasicObjectsIDL::CommPose3d>();
	}
	// gripper_angles: CommGripperTrajectory
	if(j.contains("gripper_angles") && j["gripper_angles"].is_object()) {
		//from_json(j["gripper_angles"], obj.gripper_angles);
		obj.gripper_angles = j["gripper_angles"].get<CommManipulatorObjectsIDL::CommGripperTrajectory>();
	}
	// flag: ManipulatorTrajectoryFlag
	if(j.contains("flag") && j["flag"].is_string()) {
		obj.flag = CommManipulatorObjects::ManipulatorTrajectoryFlag::from_string(j["flag"].get<std::string>());
	}
}

} // end namespace CommManipulatorObjectsIDL