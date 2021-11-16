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
#ifndef DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHREQUEST_CORE_H_
#define DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHREQUEST_CORE_H_

#include "DomainRobotFleetNavigation/CommShortestPathRequestData.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainRobotFleetNavigation {
	
class CommShortestPathRequestCore {
protected:
	// data structure
	DomainRobotFleetNavigationIDL::CommShortestPathRequest idl_CommShortestPathRequest;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainRobotFleetNavigationIDL::CommShortestPathRequest DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommShortestPathRequestCore();
	CommShortestPathRequestCore(const DATATYPE &data);
	// default destructor
	virtual ~CommShortestPathRequestCore();
	
	const DATATYPE& get() const { return idl_CommShortestPathRequest; }
	operator const DATATYPE&() const { return idl_CommShortestPathRequest; }
	DATATYPE& set() { return idl_CommShortestPathRequest; }

	static inline std::string identifier(void) { return "DomainRobotFleetNavigation::CommShortestPathRequest"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element From
	inline int getFrom() const { return idl_CommShortestPathRequest.from; }
	inline CommShortestPathRequestCore& setFrom(const int &from) { idl_CommShortestPathRequest.from = from; return *this; }
	
	// getter and setter for element To
	inline int getTo() const { return idl_CommShortestPathRequest.to; }
	inline CommShortestPathRequestCore& setTo(const int &to) { idl_CommShortestPathRequest.to = to; return *this; }
};

} /* namespace DomainRobotFleetNavigation */
#endif /* DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHREQUEST_CORE_H_ */
