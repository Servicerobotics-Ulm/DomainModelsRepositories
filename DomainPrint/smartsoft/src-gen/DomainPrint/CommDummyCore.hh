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
#ifndef DOMAINPRINT_COMMDUMMY_CORE_H_
#define DOMAINPRINT_COMMDUMMY_CORE_H_

#include "DomainPrint/CommDummyData.hh"
#include "CommBasicObjects/CommVoid.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainPrint {
	
class CommDummyCore {
protected:
	// data structure
	DomainPrintIDL::CommDummy idl_CommDummy;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainPrintIDL::CommDummy DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommDummyCore();
	CommDummyCore(const DATATYPE &data);
	// default destructor
	virtual ~CommDummyCore();
	
	const DATATYPE& get() const { return idl_CommDummy; }
	operator const DATATYPE&() const { return idl_CommDummy; }
	DATATYPE& set() { return idl_CommDummy; }

	static inline std::string identifier(void) { return "DomainPrint::CommDummy"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Dummy
	inline CommBasicObjects::CommVoid getDummy() const { return CommBasicObjects::CommVoid(idl_CommDummy.dummy); }
	inline CommDummyCore& setDummy(const CommBasicObjects::CommVoid &dummy) { idl_CommDummy.dummy = dummy; return *this; }
};

} /* namespace DomainPrint */
#endif /* DOMAINPRINT_COMMDUMMY_CORE_H_ */
