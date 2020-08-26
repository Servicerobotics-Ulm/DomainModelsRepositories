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
#ifndef COMMOBJECTRECOGNITIONOBJECTS_COMMIMAGEOBJECTRECOGNITIONRESULT_CORE_H_
#define COMMOBJECTRECOGNITIONOBJECTS_COMMIMAGEOBJECTRECOGNITIONRESULT_CORE_H_

#include "CommObjectRecognitionObjects/CommImageObjectRecognitionResultData.hh"
#include "CommObjectRecognitionObjects/CommObjectBelief.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommObjectRecognitionObjects {
	
class CommImageObjectRecognitionResultCore {
protected:
	// data structure
	CommObjectRecognitionObjectsIDL::CommImageObjectRecognitionResult idl_CommImageObjectRecognitionResult;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommObjectRecognitionObjectsIDL::CommImageObjectRecognitionResult DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommImageObjectRecognitionResultCore();
	CommImageObjectRecognitionResultCore(const DATATYPE &data);
	// default destructor
	virtual ~CommImageObjectRecognitionResultCore();
	
	const DATATYPE& get() const { return idl_CommImageObjectRecognitionResult; }
	operator const DATATYPE&() const { return idl_CommImageObjectRecognitionResult; }
	DATATYPE& set() { return idl_CommImageObjectRecognitionResult; }

	static inline std::string identifier(void) { return "CommObjectRecognitionObjects::CommImageObjectRecognitionResult"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Xmin
	inline unsigned int getXmin() const { return idl_CommImageObjectRecognitionResult.xmin; }
	inline CommImageObjectRecognitionResultCore& setXmin(const unsigned int &xmin) { idl_CommImageObjectRecognitionResult.xmin = xmin; return *this; }
	
	// getter and setter for element Ymin
	inline unsigned int getYmin() const { return idl_CommImageObjectRecognitionResult.ymin; }
	inline CommImageObjectRecognitionResultCore& setYmin(const unsigned int &ymin) { idl_CommImageObjectRecognitionResult.ymin = ymin; return *this; }
	
	// getter and setter for element Xmax
	inline unsigned int getXmax() const { return idl_CommImageObjectRecognitionResult.xmax; }
	inline CommImageObjectRecognitionResultCore& setXmax(const unsigned int &xmax) { idl_CommImageObjectRecognitionResult.xmax = xmax; return *this; }
	
	// getter and setter for element Ymax
	inline unsigned int getYmax() const { return idl_CommImageObjectRecognitionResult.ymax; }
	inline CommImageObjectRecognitionResultCore& setYmax(const unsigned int &ymax) { idl_CommImageObjectRecognitionResult.ymax = ymax; return *this; }
	
	// getter and setter for element Belief
	inline CommObjectRecognitionObjects::CommObjectBelief getBelief() const { return CommObjectRecognitionObjects::CommObjectBelief(idl_CommImageObjectRecognitionResult.belief); }
	inline CommImageObjectRecognitionResultCore& setBelief(const CommObjectRecognitionObjects::CommObjectBelief &belief) { idl_CommImageObjectRecognitionResult.belief = belief; return *this; }
	
	// getter and setter for element ObjectId
	inline unsigned int getObjectId() const { return idl_CommImageObjectRecognitionResult.objectId; }
	inline CommImageObjectRecognitionResultCore& setObjectId(const unsigned int &objectId) { idl_CommImageObjectRecognitionResult.objectId = objectId; return *this; }
};

} /* namespace CommObjectRecognitionObjects */
#endif /* COMMOBJECTRECOGNITIONOBJECTS_COMMIMAGEOBJECTRECOGNITIONRESULT_CORE_H_ */