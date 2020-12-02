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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEREQUESTEVENTSTATE_CORE_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEREQUESTEVENTSTATE_CORE_H_

#include "CommNavigationObjects/CommCorridorNavigationPoseRequestEventStateData.hh"
#include "CommNavigationObjects/enumNodeRequestAnserType.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommNavigationObjects {
	
class CommCorridorNavigationPoseRequestEventStateCore {
protected:
	// data structure
	CommNavigationObjectsIDL::CommCorridorNavigationPoseRequestEventState idl_CommCorridorNavigationPoseRequestEventState;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommNavigationObjectsIDL::CommCorridorNavigationPoseRequestEventState DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommCorridorNavigationPoseRequestEventStateCore();
	CommCorridorNavigationPoseRequestEventStateCore(const DATATYPE &data);
	// default destructor
	virtual ~CommCorridorNavigationPoseRequestEventStateCore();
	
	const DATATYPE& get() const { return idl_CommCorridorNavigationPoseRequestEventState; }
	operator const DATATYPE&() const { return idl_CommCorridorNavigationPoseRequestEventState; }
	DATATYPE& set() { return idl_CommCorridorNavigationPoseRequestEventState; }

	static inline std::string identifier(void) { return "CommNavigationObjects::CommCorridorNavigationPoseRequestEventState"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element NewState
	inline CommNavigationObjects::NodeRequestAnserType getNewState() const { return CommNavigationObjects::NodeRequestAnserType(idl_CommCorridorNavigationPoseRequestEventState.newState); }
	inline CommCorridorNavigationPoseRequestEventStateCore& setNewState(const CommNavigationObjects::NodeRequestAnserType &newState) { idl_CommCorridorNavigationPoseRequestEventState.newState = newState; return *this; }
};

} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONPOSEREQUESTEVENTSTATE_CORE_H_ */
