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
#ifndef COMMROBOTINOOBJECTS_COMMPATHFREEAREA_CORE_H_
#define COMMROBOTINOOBJECTS_COMMPATHFREEAREA_CORE_H_

#include "CommRobotinoObjects/CommPathFreeAreaData.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommRobotinoObjects {
	
class CommPathFreeAreaCore {
protected:
	// data structure
	CommRobotinoObjectsIDL::CommPathFreeArea idl_CommPathFreeArea;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommRobotinoObjectsIDL::CommPathFreeArea DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommPathFreeAreaCore();
	CommPathFreeAreaCore(const DATATYPE &data);
	// default destructor
	virtual ~CommPathFreeAreaCore();
	
	const DATATYPE& get() const { return idl_CommPathFreeArea; }
	operator const DATATYPE&() const { return idl_CommPathFreeArea; }
	DATATYPE& set() { return idl_CommPathFreeArea; }

	static inline std::string identifier(void) { return "CommRobotinoObjects::CommPathFreeArea"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element AreaID
	inline int getAreaID() const { return idl_CommPathFreeArea.areaID; }
	inline CommPathFreeAreaCore& setAreaID(const int &areaID) { idl_CommPathFreeArea.areaID = areaID; return *this; }
	
	// getter and setter for element MaxOccupancy
	inline int getMaxOccupancy() const { return idl_CommPathFreeArea.maxOccupancy; }
	inline CommPathFreeAreaCore& setMaxOccupancy(const int &maxOccupancy) { idl_CommPathFreeArea.maxOccupancy = maxOccupancy; return *this; }
	
	// getter and setter for element RobotIDs
	/**
	 * Getter methods for idl_CommPathFreeArea.robotIDs of type vector<int>
	 */
	inline std::vector<int>& getRobotIDsRef() { return idl_CommPathFreeArea.robotIDs; }
	inline std::vector<int> getRobotIDsCopy() const {
		return std::vector<int>(idl_CommPathFreeArea.robotIDs.begin(), idl_CommPathFreeArea.robotIDs.end());
	}
	inline int getRobotIDsElemAtPos(const size_t &pos) const { return idl_CommPathFreeArea.robotIDs[pos]; }
	inline size_t getRobotIDsSize() const { return idl_CommPathFreeArea.robotIDs.size(); }
	inline bool isRobotIDsEmpty() const { return idl_CommPathFreeArea.robotIDs.empty(); }
	/**
	 * Setter methods for idl_CommPathFreeArea.robotIDs of type vector<int>
	 */
	inline CommPathFreeAreaCore& setRobotIDs(const std::vector<int> &robotIDs) { idl_CommPathFreeArea.robotIDs = robotIDs; return *this; }
	inline bool setRobotIDsElemAtPos(const size_t &pos, const int &elem) {
		if(pos < idl_CommPathFreeArea.robotIDs.size()) {
			idl_CommPathFreeArea.robotIDs[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertRobotIDsVectorAtPos(const size_t &pos, const std::vector<int> &data) {
		if(pos < idl_CommPathFreeArea.robotIDs.size()) {
			idl_CommPathFreeArea.robotIDs.insert(idl_CommPathFreeArea.robotIDs.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeRobotIDs(const size_t &size) { idl_CommPathFreeArea.robotIDs.resize(size); }
	inline bool eraseRobotIDsElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommPathFreeArea.robotIDs.size() ) {
			idl_CommPathFreeArea.robotIDs.erase(idl_CommPathFreeArea.robotIDs.begin()+pos, idl_CommPathFreeArea.robotIDs.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearRobotIDs() { idl_CommPathFreeArea.robotIDs.clear(); }
	
	// getter and setter for element NodeXvector
	/**
	 * Getter methods for idl_CommPathFreeArea.nodeXvector of type vector<double>
	 */
	inline std::vector<double>& getNodeXvectorRef() { return idl_CommPathFreeArea.nodeXvector; }
	inline std::vector<double> getNodeXvectorCopy() const {
		return std::vector<double>(idl_CommPathFreeArea.nodeXvector.begin(), idl_CommPathFreeArea.nodeXvector.end());
	}
	inline double getNodeXvectorElemAtPos(const size_t &pos) const { return idl_CommPathFreeArea.nodeXvector[pos]; }
	inline size_t getNodeXvectorSize() const { return idl_CommPathFreeArea.nodeXvector.size(); }
	inline bool isNodeXvectorEmpty() const { return idl_CommPathFreeArea.nodeXvector.empty(); }
	/**
	 * Setter methods for idl_CommPathFreeArea.nodeXvector of type vector<double>
	 */
	inline CommPathFreeAreaCore& setNodeXvector(const std::vector<double> &nodeXvector) { idl_CommPathFreeArea.nodeXvector = nodeXvector; return *this; }
	inline bool setNodeXvectorElemAtPos(const size_t &pos, const double &elem) {
		if(pos < idl_CommPathFreeArea.nodeXvector.size()) {
			idl_CommPathFreeArea.nodeXvector[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertNodeXvectorVectorAtPos(const size_t &pos, const std::vector<double> &data) {
		if(pos < idl_CommPathFreeArea.nodeXvector.size()) {
			idl_CommPathFreeArea.nodeXvector.insert(idl_CommPathFreeArea.nodeXvector.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeNodeXvector(const size_t &size) { idl_CommPathFreeArea.nodeXvector.resize(size); }
	inline bool eraseNodeXvectorElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommPathFreeArea.nodeXvector.size() ) {
			idl_CommPathFreeArea.nodeXvector.erase(idl_CommPathFreeArea.nodeXvector.begin()+pos, idl_CommPathFreeArea.nodeXvector.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearNodeXvector() { idl_CommPathFreeArea.nodeXvector.clear(); }
	
	// getter and setter for element NodeYvector
	/**
	 * Getter methods for idl_CommPathFreeArea.nodeYvector of type vector<double>
	 */
	inline std::vector<double>& getNodeYvectorRef() { return idl_CommPathFreeArea.nodeYvector; }
	inline std::vector<double> getNodeYvectorCopy() const {
		return std::vector<double>(idl_CommPathFreeArea.nodeYvector.begin(), idl_CommPathFreeArea.nodeYvector.end());
	}
	inline double getNodeYvectorElemAtPos(const size_t &pos) const { return idl_CommPathFreeArea.nodeYvector[pos]; }
	inline size_t getNodeYvectorSize() const { return idl_CommPathFreeArea.nodeYvector.size(); }
	inline bool isNodeYvectorEmpty() const { return idl_CommPathFreeArea.nodeYvector.empty(); }
	/**
	 * Setter methods for idl_CommPathFreeArea.nodeYvector of type vector<double>
	 */
	inline CommPathFreeAreaCore& setNodeYvector(const std::vector<double> &nodeYvector) { idl_CommPathFreeArea.nodeYvector = nodeYvector; return *this; }
	inline bool setNodeYvectorElemAtPos(const size_t &pos, const double &elem) {
		if(pos < idl_CommPathFreeArea.nodeYvector.size()) {
			idl_CommPathFreeArea.nodeYvector[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertNodeYvectorVectorAtPos(const size_t &pos, const std::vector<double> &data) {
		if(pos < idl_CommPathFreeArea.nodeYvector.size()) {
			idl_CommPathFreeArea.nodeYvector.insert(idl_CommPathFreeArea.nodeYvector.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeNodeYvector(const size_t &size) { idl_CommPathFreeArea.nodeYvector.resize(size); }
	inline bool eraseNodeYvectorElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommPathFreeArea.nodeYvector.size() ) {
			idl_CommPathFreeArea.nodeYvector.erase(idl_CommPathFreeArea.nodeYvector.begin()+pos, idl_CommPathFreeArea.nodeYvector.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearNodeYvector() { idl_CommPathFreeArea.nodeYvector.clear(); }
};

} /* namespace CommRobotinoObjects */
#endif /* COMMROBOTINOOBJECTS_COMMPATHFREEAREA_CORE_H_ */
