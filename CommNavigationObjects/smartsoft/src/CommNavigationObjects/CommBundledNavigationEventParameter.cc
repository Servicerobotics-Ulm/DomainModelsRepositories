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

#include "CommNavigationObjects/CommBundledNavigationEventParameter.hh"

using namespace CommNavigationObjects;

CommBundledNavigationEventParameter::CommBundledNavigationEventParameter()
:	CommBundledNavigationEventParameterCore()
{  }


/**
 * Constructor to set all values.
 * NOTE that you have to keep this constructor consistent with the model!
 * Use  at your own choice.
 *
 * The preferred way to set values for initialization is:
 *      CommRepository::MyCommObject obj;
 *      obj.setX(1).setY(2).setZ(3)...;
CommBundledNavigationEventParameter::CommBundledNavigationEventParameter(const std::string &locationName, const CommNavigationObjects::BundledNavigationGoalState &previousState)
:	CommBundledNavigationEventParameterCore() // base constructor sets default values as defined in the model
{
	setLocationName(locationName);
	setPreviousState(previousState);
}
 */

CommBundledNavigationEventParameter::CommBundledNavigationEventParameter(const CommBundledNavigationEventParameterCore &commBundledNavigationEventParameter)
:	CommBundledNavigationEventParameterCore(commBundledNavigationEventParameter)
{  }

CommBundledNavigationEventParameter::CommBundledNavigationEventParameter(const DATATYPE &commBundledNavigationEventParameter)
:	CommBundledNavigationEventParameterCore(commBundledNavigationEventParameter)
{  }

CommBundledNavigationEventParameter::~CommBundledNavigationEventParameter()
{  }