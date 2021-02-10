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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEREQUEST_CORE_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEREQUEST_CORE_H_

#include "CommNavigationObjects/CommCorridorNavigationPoseRequestData.hh"
#include "CommNavigationObjects/enumNavigationNodeRequestType.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommNavigationObjects {
	
class CommCorridorNavigationPoseRequestCore {
protected:
	// data structure
	CommNavigationObjectsIDL::CommCorridorNavigationPoseRequest idl_CommCorridorNavigationPoseRequest;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommNavigationObjectsIDL::CommCorridorNavigationPoseRequest DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommCorridorNavigationPoseRequestCore();
	CommCorridorNavigationPoseRequestCore(const DATATYPE &data);
	// default destructor
	virtual ~CommCorridorNavigationPoseRequestCore();
	
	const DATATYPE& get() const { return idl_CommCorridorNavigationPoseRequest; }
	operator const DATATYPE&() const { return idl_CommCorridorNavigationPoseRequest; }
	DATATYPE& set() { return idl_CommCorridorNavigationPoseRequest; }

	static inline std::string identifier(void) { return "CommNavigationObjects::CommCorridorNavigationPoseRequest"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Requesttype
	inline CommNavigationObjects::NavigationNodeRequestType getRequesttype() const { return CommNavigationObjects::NavigationNodeRequestType(idl_CommCorridorNavigationPoseRequest.requesttype); }
	inline CommCorridorNavigationPoseRequestCore& setRequesttype(const CommNavigationObjects::NavigationNodeRequestType &requesttype) { idl_CommCorridorNavigationPoseRequest.requesttype = requesttype; return *this; }
	
	// getter and setter for element Pose
	inline unsigned int getPose() const { return idl_CommCorridorNavigationPoseRequest.pose; }
	inline CommCorridorNavigationPoseRequestCore& setPose(const unsigned int &pose) { idl_CommCorridorNavigationPoseRequest.pose = pose; return *this; }
	
	// getter and setter for element RobotID
	inline std::string getRobotID() const { return idl_CommCorridorNavigationPoseRequest.robotID; }
	inline CommCorridorNavigationPoseRequestCore& setRobotID(const std::string &robotID) { idl_CommCorridorNavigationPoseRequest.robotID = robotID; return *this; }
};

} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEREQUEST_CORE_H_ */
