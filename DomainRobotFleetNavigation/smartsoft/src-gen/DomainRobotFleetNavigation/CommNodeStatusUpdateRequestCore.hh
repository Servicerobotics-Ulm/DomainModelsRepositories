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
#ifndef DOMAINROBOTFLEETNAVIGATION_COMMNODESTATUSUPDATEREQUEST_CORE_H_
#define DOMAINROBOTFLEETNAVIGATION_COMMNODESTATUSUPDATEREQUEST_CORE_H_

#include "DomainRobotFleetNavigation/CommNodeStatusUpdateRequestData.hh"
#include "DomainRobotFleetNavigation/enumStatusUpdateType.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainRobotFleetNavigation {
	
class CommNodeStatusUpdateRequestCore {
protected:
	// data structure
	DomainRobotFleetNavigationIDL::CommNodeStatusUpdateRequest idl_CommNodeStatusUpdateRequest;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainRobotFleetNavigationIDL::CommNodeStatusUpdateRequest DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommNodeStatusUpdateRequestCore();
	CommNodeStatusUpdateRequestCore(const DATATYPE &data);
	// default destructor
	virtual ~CommNodeStatusUpdateRequestCore();
	
	const DATATYPE& get() const { return idl_CommNodeStatusUpdateRequest; }
	operator const DATATYPE&() const { return idl_CommNodeStatusUpdateRequest; }
	DATATYPE& set() { return idl_CommNodeStatusUpdateRequest; }

	static inline std::string identifier(void) { return "DomainRobotFleetNavigation::CommNodeStatusUpdateRequest"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Id
	inline int getId() const { return idl_CommNodeStatusUpdateRequest.id; }
	inline CommNodeStatusUpdateRequestCore& setId(const int &id) { idl_CommNodeStatusUpdateRequest.id = id; return *this; }
	
	// getter and setter for element Type
	inline DomainRobotFleetNavigation::StatusUpdateType getType() const { return DomainRobotFleetNavigation::StatusUpdateType(idl_CommNodeStatusUpdateRequest.type); }
	inline CommNodeStatusUpdateRequestCore& setType(const DomainRobotFleetNavigation::StatusUpdateType &type) { idl_CommNodeStatusUpdateRequest.type = type; return *this; }
};

} /* namespace DomainRobotFleetNavigation */
#endif /* DOMAINROBOTFLEETNAVIGATION_COMMNODESTATUSUPDATEREQUEST_CORE_H_ */