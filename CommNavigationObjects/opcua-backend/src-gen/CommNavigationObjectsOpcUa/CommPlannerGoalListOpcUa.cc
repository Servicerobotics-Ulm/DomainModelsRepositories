#include "CommPlannerGoalListOpcUa.hh"

#define SERONET_NO_DEPRECATED
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ComplexType.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementPrimitives.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/SelfDescriptionArray.hpp>
#include <SeRoNetSDK/SeRoNet/CommunicationObjects/Description/ElementArray.hpp>


namespace SeRoNet {
namespace CommunicationObjects {
namespace Description {
	
// serialization for CommNavigationObjectsIDL::CommPlannerGoalList
template <>
IDescription::shp_t SelfDescription(CommNavigationObjectsIDL::CommPlannerGoalList *obj, std::string name)
{
	auto ret = std::make_shared<SeRoNet::CommunicationObjects::Description::ComplexType>(name);
	// add id
	ret->add(
		SelfDescription(&(obj->id), "Id")
	);
	// add flag
	ret->add(
		SelfDescription(&(obj->flag), "Flag")
	);
	// add goalXvector
	ret->add(
		SelfDescription(&(obj->goalXvector), "GoalXvector")
	);
	// add goalYvector
	ret->add(
		SelfDescription(&(obj->goalYvector), "GoalYvector")
	);
	// add nodeObstacleVector
	ret->add(
		SelfDescription(&(obj->nodeObstacleVector), "NodeObstacleVector")
	);
	// add finalGoalX
	ret->add(
		SelfDescription(&(obj->finalGoalX), "FinalGoalX")
	);
	// add finalGoalY
	ret->add(
		SelfDescription(&(obj->finalGoalY), "FinalGoalY")
	);
	return ret;
} // end SelfDescription

} // end namespace Description
} // end namespace CommunicationObjects
} // end namespace SeRoNet
