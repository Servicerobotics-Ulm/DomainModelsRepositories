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
#ifndef DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMSTARTRESPONSE_CORE_H_
#define DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMSTARTRESPONSE_CORE_H_

#include "DomainExternalSystems/CommExternalProgramStartResponseData.hh"
#include "DomainExternalSystems/enumExternalProgramResult.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainExternalSystems {
	
class CommExternalProgramStartResponseCore {
protected:
	// data structure
	DomainExternalSystemsIDL::CommExternalProgramStartResponse idl_CommExternalProgramStartResponse;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainExternalSystemsIDL::CommExternalProgramStartResponse DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommExternalProgramStartResponseCore();
	CommExternalProgramStartResponseCore(const DATATYPE &data);
	// default destructor
	virtual ~CommExternalProgramStartResponseCore();
	
	const DATATYPE& get() const { return idl_CommExternalProgramStartResponse; }
	operator const DATATYPE&() const { return idl_CommExternalProgramStartResponse; }
	DATATYPE& set() { return idl_CommExternalProgramStartResponse; }

	static inline std::string identifier(void) { return "DomainExternalSystems::CommExternalProgramStartResponse"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Result
	inline DomainExternalSystems::ExternalProgramResult getResult() const { return DomainExternalSystems::ExternalProgramResult(idl_CommExternalProgramStartResponse.result); }
	inline CommExternalProgramStartResponseCore& setResult(const DomainExternalSystems::ExternalProgramResult &result) { idl_CommExternalProgramStartResponse.result = result; return *this; }
};

} /* namespace DomainExternalSystems */
#endif /* DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMSTARTRESPONSE_CORE_H_ */