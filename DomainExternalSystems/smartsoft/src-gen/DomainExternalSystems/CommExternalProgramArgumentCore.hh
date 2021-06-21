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
#ifndef DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMARGUMENT_CORE_H_
#define DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMARGUMENT_CORE_H_

#include "DomainExternalSystems/CommExternalProgramArgumentData.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainExternalSystems {
	
class CommExternalProgramArgumentCore {
protected:
	// data structure
	DomainExternalSystemsIDL::CommExternalProgramArgument idl_CommExternalProgramArgument;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainExternalSystemsIDL::CommExternalProgramArgument DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommExternalProgramArgumentCore();
	CommExternalProgramArgumentCore(const DATATYPE &data);
	// default destructor
	virtual ~CommExternalProgramArgumentCore();
	
	const DATATYPE& get() const { return idl_CommExternalProgramArgument; }
	operator const DATATYPE&() const { return idl_CommExternalProgramArgument; }
	DATATYPE& set() { return idl_CommExternalProgramArgument; }

	static inline std::string identifier(void) { return "DomainExternalSystems::CommExternalProgramArgument"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Name
	inline std::string getName() const { return idl_CommExternalProgramArgument.name; }
	inline CommExternalProgramArgumentCore& setName(const std::string &name) { idl_CommExternalProgramArgument.name = name; return *this; }
	
	// getter and setter for element Type
	inline std::string getType() const { return idl_CommExternalProgramArgument.type; }
	inline CommExternalProgramArgumentCore& setType(const std::string &type) { idl_CommExternalProgramArgument.type = type; return *this; }
	
	// getter and setter for element Value
	inline std::string getValue() const { return idl_CommExternalProgramArgument.value; }
	inline CommExternalProgramArgumentCore& setValue(const std::string &value) { idl_CommExternalProgramArgument.value = value; return *this; }
};

} /* namespace DomainExternalSystems */
#endif /* DOMAINEXTERNALSYSTEMS_COMMEXTERNALPROGRAMARGUMENT_CORE_H_ */
