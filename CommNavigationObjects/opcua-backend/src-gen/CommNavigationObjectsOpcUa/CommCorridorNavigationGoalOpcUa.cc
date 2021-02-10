#include "CommCorridorNavigationGoalOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>

#include "CommNavigationObjectsOpcUa/CommNavigationPathsOpcUa.hh"

namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommNavigationObjectsIDL::CommCorridorNavigationGoal
template <>
IDescription::shp_t SelfDescription(CommNavigationObjectsIDL::CommCorridorNavigationGoal *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add goalID
	ret->add(
		SelfDescription(&(obj->goalID), "GoalID")
	);
	// add paths
	ret->add(
		SelfDescription(&(obj->paths), "Paths")
	);
	// add goalX
	ret->add(
		SelfDescription(&(obj->goalX), "GoalX")
	);
	// add goalY
	ret->add(
		SelfDescription(&(obj->goalY), "GoalY")
	);
	// add goal_id
	ret->add(
		SelfDescription(&(obj->goal_id), "Goal_id")
	);
	// add startX
	ret->add(
		SelfDescription(&(obj->startX), "StartX")
	);
	// add startY
	ret->add(
		SelfDescription(&(obj->startY), "StartY")
	);
	// add start_id
	ret->add(
		SelfDescription(&(obj->start_id), "Start_id")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
