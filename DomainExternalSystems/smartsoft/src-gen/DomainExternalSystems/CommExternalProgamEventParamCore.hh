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
#ifndef DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGAMEVENTPARAM_CORE_H_
#define DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGAMEVENTPARAM_CORE_H_

#include "DomainExternalSystems/CommExternalProgamEventParamData.hh"
#include "DomainExternalSystems/enumExternalProgramStatus.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainExternalSystems {
	
class CommExternalProgamEventParamCore {
protected:
	// data structure
	DomainExternalSystemsIDL::CommExternalProgamEventParam idl_CommExternalProgamEventParam;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainExternalSystemsIDL::CommExternalProgamEventParam DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommExternalProgamEventParamCore();
	CommExternalProgamEventParamCore(const DATATYPE &data);
	// default destructor
	virtual ~CommExternalProgamEventParamCore();
	
	const DATATYPE& get() const { return idl_CommExternalProgamEventParam; }
	operator const DATATYPE&() const { return idl_CommExternalProgamEventParam; }
	DATATYPE& set() { return idl_CommExternalProgamEventParam; }

	static inline std::string identifier(void) { return "DomainExternalSystems::CommExternalProgamEventParam"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Status
	inline DomainExternalSystems::ExternalProgramStatus getStatus() const { return DomainExternalSystems::ExternalProgramStatus(idl_CommExternalProgamEventParam.status); }
	inline CommExternalProgamEventParamCore& setStatus(const DomainExternalSystems::ExternalProgramStatus &status) { idl_CommExternalProgamEventParam.status = status; return *this; }
};

} /* namespace DomainExternalSystems */
#endif /* DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGAMEVENTPARAM_CORE_H_ */
