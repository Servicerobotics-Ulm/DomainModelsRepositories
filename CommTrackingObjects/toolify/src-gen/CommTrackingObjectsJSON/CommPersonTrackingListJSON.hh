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

#ifndef COMMPERSONTRACKINGLIST_JSON_TRANSFORMATION_H_
#define COMMPERSONTRACKINGLIST_JSON_TRANSFORMATION_H_

#include <nlohmann/json.hpp>

#include <CommTrackingObjects/CommPersonTrackingListData.hh>

namespace CommTrackingObjectsIDL {

	void to_json(const CommTrackingObjectsIDL::CommPersonTrackingList& obj, nlohmann::json& j);
	void from_json(const nlohmann::json& j, CommTrackingObjectsIDL::CommPersonTrackingList& obj);
	
} // end namespace CommTrackingObjectsIDL

#endif // COMMPERSONTRACKINGLIST_JSON_TRANSFORMATION_H_
