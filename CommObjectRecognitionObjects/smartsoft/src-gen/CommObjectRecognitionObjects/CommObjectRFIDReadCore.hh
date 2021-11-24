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
#ifndef COMMOBJECTRECOGNITIONOBJECTS_COMMOBJECTRFIDREAD_CORE_H_
#define COMMOBJECTRECOGNITIONOBJECTS_COMMOBJECTRFIDREAD_CORE_H_

#include "CommObjectRecognitionObjects/CommObjectRFIDReadData.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommObjectRecognitionObjects {
	
class CommObjectRFIDReadCore {
protected:
	// data structure
	CommObjectRecognitionObjectsIDL::CommObjectRFIDRead idl_CommObjectRFIDRead;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommObjectRecognitionObjectsIDL::CommObjectRFIDRead DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommObjectRFIDReadCore();
	CommObjectRFIDReadCore(const DATATYPE &data);
	// default destructor
	virtual ~CommObjectRFIDReadCore();
	
	const DATATYPE& get() const { return idl_CommObjectRFIDRead; }
	operator const DATATYPE&() const { return idl_CommObjectRFIDRead; }
	DATATYPE& set() { return idl_CommObjectRFIDRead; }

	static inline std::string identifier(void) { return "CommObjectRecognitionObjects::CommObjectRFIDRead"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element TagId
	inline std::string getTagId() const { return idl_CommObjectRFIDRead.tagId; }
	inline CommObjectRFIDReadCore& setTagId(const std::string &tagId) { idl_CommObjectRFIDRead.tagId = tagId; return *this; }
	
	// getter and setter for element Rssi
	inline int getRssi() const { return idl_CommObjectRFIDRead.rssi; }
	inline CommObjectRFIDReadCore& setRssi(const int &rssi) { idl_CommObjectRFIDRead.rssi = rssi; return *this; }
};

} /* namespace CommObjectRecognitionObjects */
#endif /* COMMOBJECTRECOGNITIONOBJECTS_COMMOBJECTRFIDREAD_CORE_H_ */