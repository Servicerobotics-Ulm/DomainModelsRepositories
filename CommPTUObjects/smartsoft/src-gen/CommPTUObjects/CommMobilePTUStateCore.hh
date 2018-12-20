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
#ifndef COMMPTUOBJECTS_COMMMOBILEPTUSTATE_CORE_H_
#define COMMPTUOBJECTS_COMMMOBILEPTUSTATE_CORE_H_

#include "CommPTUObjects/CommMobilePTUStateData.hh"
#include "CommBasicObjects/CommBaseState.hh"
#include "CommPTUObjects/CommPTUState.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommPTUObjects {
	
class CommMobilePTUStateCore {
protected:
	// data structure
	CommPTUObjectsIDL::CommMobilePTUState idl_CommMobilePTUState;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommPTUObjectsIDL::CommMobilePTUState DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommMobilePTUStateCore();
	CommMobilePTUStateCore(const DATATYPE &data);
	// default destructor
	virtual ~CommMobilePTUStateCore();
	
	const DATATYPE& get() const { return idl_CommMobilePTUState; }
	operator const DATATYPE&() const { return idl_CommMobilePTUState; }
	DATATYPE& set() { return idl_CommMobilePTUState; }

	static inline std::string identifier(void) { return "CommPTUObjects::CommMobilePTUState"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Ptu_state
	inline CommPTUObjects::CommPTUState getPtu_state() const { return CommPTUObjects::CommPTUState(idl_CommMobilePTUState.ptu_state); }
	inline CommMobilePTUStateCore& setPtu_state(const CommPTUObjects::CommPTUState &ptu_state) { idl_CommMobilePTUState.ptu_state = ptu_state; return *this; }
	
	// getter and setter for element Base_state
	inline CommBasicObjects::CommBaseState getBase_state() const { return CommBasicObjects::CommBaseState(idl_CommMobilePTUState.base_state); }
	inline CommMobilePTUStateCore& setBase_state(const CommBasicObjects::CommBaseState &base_state) { idl_CommMobilePTUState.base_state = base_state; return *this; }
};

} /* namespace CommPTUObjects */
#endif /* COMMPTUOBJECTS_COMMMOBILEPTUSTATE_CORE_H_ */
