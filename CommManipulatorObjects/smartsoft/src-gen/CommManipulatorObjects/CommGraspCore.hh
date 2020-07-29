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
#ifndef COMMMANIPULATOROBJECTS_COMMGRASP_CORE_H_
#define COMMMANIPULATOROBJECTS_COMMGRASP_CORE_H_

#include "CommManipulatorObjects/CommGraspData.hh"
#include "CommBasicObjects/CommPose3d.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommManipulatorObjects {
	
class CommGraspCore {
protected:
	// data structure
	CommManipulatorObjectsIDL::CommGrasp idl_CommGrasp;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommManipulatorObjectsIDL::CommGrasp DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommGraspCore();
	CommGraspCore(const DATATYPE &data);
	// default destructor
	virtual ~CommGraspCore();
	
	const DATATYPE& get() const { return idl_CommGrasp; }
	operator const DATATYPE&() const { return idl_CommGrasp; }
	DATATYPE& set() { return idl_CommGrasp; }

	static inline std::string identifier(void) { return "CommManipulatorObjects::CommGrasp"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Id
	inline std::string getId() const { return idl_CommGrasp.id; }
	inline CommGraspCore& setId(const std::string &id) { idl_CommGrasp.id = id; return *this; }
	
	// getter and setter for element Pose
	inline CommBasicObjects::CommPose3d getPose() const { return CommBasicObjects::CommPose3d(idl_CommGrasp.pose); }
	inline CommGraspCore& setPose(const CommBasicObjects::CommPose3d &pose) { idl_CommGrasp.pose = pose; return *this; }
	
	// getter and setter for element Quality
	inline double getQuality() const { return idl_CommGrasp.quality; }
	inline CommGraspCore& setQuality(const double &quality) { idl_CommGrasp.quality = quality; return *this; }
	
	// getter and setter for element Width
	inline double getWidth() const { return idl_CommGrasp.width; }
	inline CommGraspCore& setWidth(const double &width) { idl_CommGrasp.width = width; return *this; }
};

} /* namespace CommManipulatorObjects */
#endif /* COMMMANIPULATOROBJECTS_COMMGRASP_CORE_H_ */
