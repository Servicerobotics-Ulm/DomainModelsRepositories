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
#ifndef COMMLOCALIZATIONOBJECTS_COMMLOCALIZATIONZONERESULT_CORE_H_
#define COMMLOCALIZATIONOBJECTS_COMMLOCALIZATIONZONERESULT_CORE_H_

#include "CommLocalizationObjects/CommLocalizationZoneResultData.hh"
#include "CommBasicObjects/CommTimeStamp.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommLocalizationObjects {
	
class CommLocalizationZoneResultCore {
protected:
	// data structure
	CommLocalizationObjectsIDL::CommLocalizationZoneResult idl_CommLocalizationZoneResult;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommLocalizationObjectsIDL::CommLocalizationZoneResult DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommLocalizationZoneResultCore();
	CommLocalizationZoneResultCore(const DATATYPE &data);
	// default destructor
	virtual ~CommLocalizationZoneResultCore();
	
	const DATATYPE& get() const { return idl_CommLocalizationZoneResult; }
	operator const DATATYPE&() const { return idl_CommLocalizationZoneResult; }
	DATATYPE& set() { return idl_CommLocalizationZoneResult; }

	static inline std::string identifier(void) { return "CommLocalizationObjects::CommLocalizationZoneResult"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element CurrentZone
	inline int getCurrentZone() const { return idl_CommLocalizationZoneResult.currentZone; }
	inline CommLocalizationZoneResultCore& setCurrentZone(const int &currentZone) { idl_CommLocalizationZoneResult.currentZone = currentZone; return *this; }
	
	// getter and setter for element Timestamp
	inline CommBasicObjects::CommTimeStamp getTimestamp() const { return CommBasicObjects::CommTimeStamp(idl_CommLocalizationZoneResult.timestamp); }
	inline CommLocalizationZoneResultCore& setTimestamp(const CommBasicObjects::CommTimeStamp &timestamp) { idl_CommLocalizationZoneResult.timestamp = timestamp; return *this; }
};

} /* namespace CommLocalizationObjects */
#endif /* COMMLOCALIZATIONOBJECTS_COMMLOCALIZATIONZONERESULT_CORE_H_ */