//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------

#include "CommObjectRecognitionObjects/CommObjectRecognitionObjectProperties.hh"

using namespace CommObjectRecognitionObjects;

CommObjectRecognitionObjectProperties::CommObjectRecognitionObjectProperties()
:	CommObjectRecognitionObjectPropertiesCore()
{  }


/**
 * Constructor to set all values.
 * NOTE that you have to keep this constructor consistent with the model!
 * Use  at your own choice.
 *
 * The preferred way to set values for initialization is:
 *      CommRepository::MyCommObject obj;
 *      obj.setX(1).setY(2).setZ(3)...;
CommObjectRecognitionObjectProperties::CommObjectRecognitionObjectProperties(const unsigned int &object_id, const std::string &object_type, const CommBasicObjects::CommPose3d &pose, const CommBasicObjects::CommPosition3d &dimension, const std::vector<CommObjectRecognitionObjects::ObjectBelief> &beliefs, const CommObjectRecognitionObjects::TriMesh &mesh, const std::vector<CommObjectRecognitionObjects::Relation> &relations, const std::vector<CommBasicObjects::CommPose3d> &objectSurfacePoses, const bool &is_valid, const double &fill_level)
:	CommObjectRecognitionObjectPropertiesCore() // base constructor sets default values as defined in the model
{
	setIs_valid(is_valid);
	setObject_id(object_id);
	setObject_type(object_type);
	setPose(pose);
	setDimension(dimension);
	setBeliefs(beliefs);
	setMesh(mesh);
	setRelations(relations);
	setFill_level(fill_level);
	setObjectSurfacePoses(objectSurfacePoses);
}
 */

CommObjectRecognitionObjectProperties::CommObjectRecognitionObjectProperties(const CommObjectRecognitionObjectPropertiesCore &commObjectRecognitionObjectProperties)
:	CommObjectRecognitionObjectPropertiesCore(commObjectRecognitionObjectProperties)
{  }

CommObjectRecognitionObjectProperties::CommObjectRecognitionObjectProperties(const DATATYPE &commObjectRecognitionObjectProperties)
:	CommObjectRecognitionObjectPropertiesCore(commObjectRecognitionObjectProperties)
{  }

CommObjectRecognitionObjectProperties::~CommObjectRecognitionObjectProperties()
{  }
