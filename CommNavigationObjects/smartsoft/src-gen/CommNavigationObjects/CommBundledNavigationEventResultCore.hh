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
#ifndef COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTRESULT_CORE_H_
#define COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTRESULT_CORE_H_

#include "CommNavigationObjects/CommBundledNavigationEventResultData.hh"
#include "CommNavigationObjects/enumBundledNavigationGoalState.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommNavigationObjects {
	
class CommBundledNavigationEventResultCore {
protected:
	// data structure
	CommNavigationObjectsIDL::CommBundledNavigationEventResult idl_CommBundledNavigationEventResult;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommNavigationObjectsIDL::CommBundledNavigationEventResult DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommBundledNavigationEventResultCore();
	CommBundledNavigationEventResultCore(const DATATYPE &data);
	// default destructor
	virtual ~CommBundledNavigationEventResultCore();
	
	const DATATYPE& get() const { return idl_CommBundledNavigationEventResult; }
	operator const DATATYPE&() const { return idl_CommBundledNavigationEventResult; }
	DATATYPE& set() { return idl_CommBundledNavigationEventResult; }

	static inline std::string identifier(void) { return "CommNavigationObjects::CommBundledNavigationEventResult"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element LocationName
	inline std::string getLocationName() const { return idl_CommBundledNavigationEventResult.locationName; }
	inline CommBundledNavigationEventResultCore& setLocationName(const std::string &locationName) { idl_CommBundledNavigationEventResult.locationName = locationName; return *this; }
	
	// getter and setter for element GoalState
	inline CommNavigationObjects::BundledNavigationGoalState getGoalState() const { return CommNavigationObjects::BundledNavigationGoalState(idl_CommBundledNavigationEventResult.goalState); }
	inline CommBundledNavigationEventResultCore& setGoalState(const CommNavigationObjects::BundledNavigationGoalState &goalState) { idl_CommBundledNavigationEventResult.goalState = goalState; return *this; }
};

} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMBUNDLEDNAVIGATIONEVENTRESULT_CORE_H_ */
