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
#ifndef COMMOBJECTRECOGNITIONOBJECTS_PICKDETECTIONREQUEST_CORE_H_
#define COMMOBJECTRECOGNITIONOBJECTS_PICKDETECTIONREQUEST_CORE_H_

#include "CommObjectRecognitionObjects/PickDetectionRequestData.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommObjectRecognitionObjects {
	
class PickDetectionRequestCore {
protected:
	// data structure
	CommObjectRecognitionObjectsIDL::PickDetectionRequest idl_PickDetectionRequest;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommObjectRecognitionObjectsIDL::PickDetectionRequest DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	PickDetectionRequestCore();
	PickDetectionRequestCore(const DATATYPE &data);
	// default destructor
	virtual ~PickDetectionRequestCore();
	
	const DATATYPE& get() const { return idl_PickDetectionRequest; }
	operator const DATATYPE&() const { return idl_PickDetectionRequest; }
	DATATYPE& set() { return idl_PickDetectionRequest; }

	static inline std::string identifier(void) { return "CommObjectRecognitionObjects::PickDetectionRequest"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element WorkspaceID
	inline std::string getWorkspaceID() const { return idl_PickDetectionRequest.workspaceID; }
	inline PickDetectionRequestCore& setWorkspaceID(const std::string &workspaceID) { idl_PickDetectionRequest.workspaceID = workspaceID; return *this; }
	
	// getter and setter for element PickmodelID
	inline std::string getPickmodelID() const { return idl_PickDetectionRequest.pickmodelID; }
	inline PickDetectionRequestCore& setPickmodelID(const std::string &pickmodelID) { idl_PickDetectionRequest.pickmodelID = pickmodelID; return *this; }
};

} /* namespace CommObjectRecognitionObjects */
#endif /* COMMOBJECTRECOGNITIONOBJECTS_PICKDETECTIONREQUEST_CORE_H_ */
