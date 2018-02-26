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
#ifndef COMMNAVIGATIONOBJECTS_COMMCDLGOALEVENTRESULT_CORE_H_
#define COMMNAVIGATIONOBJECTS_COMMCDLGOALEVENTRESULT_CORE_H_

#include "CommNavigationObjects/CommCdlGoalEventResultData.hh"
#include "CommNavigationObjects/enumCdlGoalEventType.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommNavigationObjects {
	
class CommCdlGoalEventResultCore {
protected:
	// data structure
	CommNavigationObjectsIDL::CommCdlGoalEventResult idl_CommCdlGoalEventResult;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommNavigationObjectsIDL::CommCdlGoalEventResult DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommCdlGoalEventResultCore();
	CommCdlGoalEventResultCore(const DATATYPE &data);
	// default destructor
	virtual ~CommCdlGoalEventResultCore();
	
	const DATATYPE& get() const { return idl_CommCdlGoalEventResult; }
	operator const DATATYPE&() const { return idl_CommCdlGoalEventResult; }
	DATATYPE& set() { return idl_CommCdlGoalEventResult; }

	static inline std::string identifier(void) { return "CommNavigationObjects::CommCdlGoalEventResult"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element State
	inline CommNavigationObjects::CdlGoalEventType getState() const { return CommNavigationObjects::CdlGoalEventType(idl_CommCdlGoalEventResult.state); }
	inline CommCdlGoalEventResultCore& setState(const CommNavigationObjects::CdlGoalEventType &state) { idl_CommCdlGoalEventResult.state = state; return *this; }
};

} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMCDLGOALEVENTRESULT_CORE_H_ */