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
#ifndef COMMMANIPULATOROBJECTS_MANIPULATOREVENTSTATE_CORE_H_
#define COMMMANIPULATOROBJECTS_MANIPULATOREVENTSTATE_CORE_H_

#include "CommManipulatorObjects/ManipulatorEventStateData.hh"
#include "CommManipulatorObjects/enumManipulatorEvent.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommManipulatorObjects {
	
class ManipulatorEventStateCore {
protected:
	// data structure
	CommManipulatorObjectsIDL::ManipulatorEventState idl_ManipulatorEventState;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommManipulatorObjectsIDL::ManipulatorEventState DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	ManipulatorEventStateCore();
	ManipulatorEventStateCore(const DATATYPE &data);
	// default destructor
	virtual ~ManipulatorEventStateCore();
	
	const DATATYPE& get() const { return idl_ManipulatorEventState; }
	operator const DATATYPE&() const { return idl_ManipulatorEventState; }
	DATATYPE& set() { return idl_ManipulatorEventState; }

	static inline std::string identifier(void) { return "CommManipulatorObjects::ManipulatorEventState"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Event
	inline CommManipulatorObjects::ManipulatorEvent getEvent() const { return CommManipulatorObjects::ManipulatorEvent(idl_ManipulatorEventState.event); }
	inline ManipulatorEventStateCore& setEvent(const CommManipulatorObjects::ManipulatorEvent &event) { idl_ManipulatorEventState.event = event; return *this; }
};

} /* namespace CommManipulatorObjects */
#endif /* COMMMANIPULATOROBJECTS_MANIPULATOREVENTSTATE_CORE_H_ */
