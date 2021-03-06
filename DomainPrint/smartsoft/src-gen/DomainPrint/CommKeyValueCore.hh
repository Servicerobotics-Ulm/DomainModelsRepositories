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
#ifndef DOMAINPRINT_COMMKEYVALUE_CORE_H_
#define DOMAINPRINT_COMMKEYVALUE_CORE_H_

#include "DomainPrint/CommKeyValueData.hh"
#include "DomainPrint/enumKeyValueDataTypeEnum.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainPrint {
	
class CommKeyValueCore {
protected:
	// data structure
	DomainPrintIDL::CommKeyValue idl_CommKeyValue;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainPrintIDL::CommKeyValue DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommKeyValueCore();
	CommKeyValueCore(const DATATYPE &data);
	// default destructor
	virtual ~CommKeyValueCore();
	
	const DATATYPE& get() const { return idl_CommKeyValue; }
	operator const DATATYPE&() const { return idl_CommKeyValue; }
	DATATYPE& set() { return idl_CommKeyValue; }

	static inline std::string identifier(void) { return "DomainPrint::CommKeyValue"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Key
	inline std::string getKey() const { return idl_CommKeyValue.key; }
	inline CommKeyValueCore& setKey(const std::string &key) { idl_CommKeyValue.key = key; return *this; }
	
	// getter and setter for element Value
	inline std::string getValue() const { return idl_CommKeyValue.value; }
	inline CommKeyValueCore& setValue(const std::string &value) { idl_CommKeyValue.value = value; return *this; }
	
	// getter and setter for element Type
	inline DomainPrint::KeyValueDataTypeEnum getType() const { return DomainPrint::KeyValueDataTypeEnum(idl_CommKeyValue.type); }
	inline CommKeyValueCore& setType(const DomainPrint::KeyValueDataTypeEnum &type) { idl_CommKeyValue.type = type; return *this; }
};

} /* namespace DomainPrint */
#endif /* DOMAINPRINT_COMMKEYVALUE_CORE_H_ */
