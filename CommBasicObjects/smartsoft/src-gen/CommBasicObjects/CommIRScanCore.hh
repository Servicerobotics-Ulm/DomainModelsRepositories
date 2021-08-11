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
#ifndef COMMBASICOBJECTS_COMMIRSCAN_CORE_H_
#define COMMBASICOBJECTS_COMMIRSCAN_CORE_H_

#include "CommBasicObjects/CommIRScanData.hh"
#include "CommBasicObjects/CommTimeStamp.hh"
#include "CommBasicObjects/CommPose3d.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommBasicObjects {
	
class CommIRScanCore {
protected:
	// data structure
	CommBasicObjectsIDL::CommIRScan idl_CommIRScan;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommBasicObjectsIDL::CommIRScan DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommIRScanCore();
	CommIRScanCore(const DATATYPE &data);
	// default destructor
	virtual ~CommIRScanCore();
	
	const DATATYPE& get() const { return idl_CommIRScan; }
	operator const DATATYPE&() const { return idl_CommIRScan; }
	DATATYPE& set() { return idl_CommIRScan; }

	static inline std::string identifier(void) { return "CommBasicObjects::CommIRScan"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Distance_min
	inline double getDistance_min() const { return idl_CommIRScan.distance_min; }
	inline CommIRScanCore& setDistance_min(const double &distance_min) { idl_CommIRScan.distance_min = distance_min; return *this; }
	
	// getter and setter for element Distance_max
	inline double getDistance_max() const { return idl_CommIRScan.distance_max; }
	inline CommIRScanCore& setDistance_max(const double &distance_max) { idl_CommIRScan.distance_max = distance_max; return *this; }
	
	// getter and setter for element Poses3D
	/**
	 * Getter methods for element idl_CommIRScan.poses3D of type vector<CommBasicObjects::CommPose3d>
	 */
	inline std::vector<CommBasicObjects::CommPose3d> getPoses3DCopy() const { 
		return std::vector<CommBasicObjects::CommPose3d>(idl_CommIRScan.poses3D.begin(), idl_CommIRScan.poses3D.end());
	}
	inline CommBasicObjects::CommPose3d getPoses3DElemAtPos(const size_t &pos) const {
		return CommBasicObjects::CommPose3d(idl_CommIRScan.poses3D[pos]);
	}
	inline size_t getPoses3DSize() const { return idl_CommIRScan.poses3D.size(); }
	inline bool isPoses3DEmpty() const { return idl_CommIRScan.poses3D.empty(); }
	/**
	 * Setter methods for idl_CommIRScan.poses3D of type vector<CommBasicObjects::CommPose3d>
	 */
	inline CommIRScanCore& setPoses3D(const std::vector<CommBasicObjects::CommPose3d> &poses3D) { 
		idl_CommIRScan.poses3D.assign(poses3D.begin(), poses3D.end());
		return *this;
	}
	inline bool setPoses3DElemAtPos(const size_t &pos, const CommBasicObjects::CommPose3d &elem) {
		if(pos < idl_CommIRScan.poses3D.size()) {
			idl_CommIRScan.poses3D[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertPoses3DVectorAtPos(const size_t &pos, const std::vector<CommBasicObjects::CommPose3d> &data) {
		if(pos < idl_CommIRScan.poses3D.size()) {
			idl_CommIRScan.poses3D.insert(idl_CommIRScan.poses3D.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizePoses3D(const size_t &size) { idl_CommIRScan.poses3D.resize(size); }
	inline bool erasePoses3DElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommIRScan.poses3D.size() ) {
			idl_CommIRScan.poses3D.erase(idl_CommIRScan.poses3D.begin()+pos, idl_CommIRScan.poses3D.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearPoses3D() { idl_CommIRScan.poses3D.clear(); }
	
	// getter and setter for element Distances
	/**
	 * Getter methods for idl_CommIRScan.distances of type vector<double>
	 */
	inline std::vector<double>& getDistancesRef() { return idl_CommIRScan.distances; }
	inline std::vector<double> getDistancesCopy() const {
		return std::vector<double>(idl_CommIRScan.distances.begin(), idl_CommIRScan.distances.end());
	}
	inline double getDistancesElemAtPos(const size_t &pos) const { return idl_CommIRScan.distances[pos]; }
	inline size_t getDistancesSize() const { return idl_CommIRScan.distances.size(); }
	inline bool isDistancesEmpty() const { return idl_CommIRScan.distances.empty(); }
	/**
	 * Setter methods for idl_CommIRScan.distances of type vector<double>
	 */
	inline CommIRScanCore& setDistances(const std::vector<double> &distances) { idl_CommIRScan.distances = distances; return *this; }
	inline bool setDistancesElemAtPos(const size_t &pos, const double &elem) {
		if(pos < idl_CommIRScan.distances.size()) {
			idl_CommIRScan.distances[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertDistancesVectorAtPos(const size_t &pos, const std::vector<double> &data) {
		if(pos <= idl_CommIRScan.distances.size()) {
			idl_CommIRScan.distances.insert(idl_CommIRScan.distances.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeDistances(const size_t &size) { idl_CommIRScan.distances.resize(size); }
	inline bool eraseDistancesElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommIRScan.distances.size() ) {
			idl_CommIRScan.distances.erase(idl_CommIRScan.distances.begin()+pos, idl_CommIRScan.distances.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearDistances() { idl_CommIRScan.distances.clear(); }
	
	// getter and setter for element TimeStamp
	inline CommBasicObjects::CommTimeStamp getTimeStamp() const { return CommBasicObjects::CommTimeStamp(idl_CommIRScan.timeStamp); }
	inline CommIRScanCore& setTimeStamp(const CommBasicObjects::CommTimeStamp &timeStamp) { idl_CommIRScan.timeStamp = timeStamp; return *this; }
	
	// getter and setter for element Raw_readings
	/**
	 * Getter methods for idl_CommIRScan.raw_readings of type vector<double>
	 */
	inline std::vector<double>& getRaw_readingsRef() { return idl_CommIRScan.raw_readings; }
	inline std::vector<double> getRaw_readingsCopy() const {
		return std::vector<double>(idl_CommIRScan.raw_readings.begin(), idl_CommIRScan.raw_readings.end());
	}
	inline double getRaw_readingsElemAtPos(const size_t &pos) const { return idl_CommIRScan.raw_readings[pos]; }
	inline size_t getRaw_readingsSize() const { return idl_CommIRScan.raw_readings.size(); }
	inline bool isRaw_readingsEmpty() const { return idl_CommIRScan.raw_readings.empty(); }
	/**
	 * Setter methods for idl_CommIRScan.raw_readings of type vector<double>
	 */
	inline CommIRScanCore& setRaw_readings(const std::vector<double> &raw_readings) { idl_CommIRScan.raw_readings = raw_readings; return *this; }
	inline bool setRaw_readingsElemAtPos(const size_t &pos, const double &elem) {
		if(pos < idl_CommIRScan.raw_readings.size()) {
			idl_CommIRScan.raw_readings[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertRaw_readingsVectorAtPos(const size_t &pos, const std::vector<double> &data) {
		if(pos <= idl_CommIRScan.raw_readings.size()) {
			idl_CommIRScan.raw_readings.insert(idl_CommIRScan.raw_readings.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeRaw_readings(const size_t &size) { idl_CommIRScan.raw_readings.resize(size); }
	inline bool eraseRaw_readingsElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommIRScan.raw_readings.size() ) {
			idl_CommIRScan.raw_readings.erase(idl_CommIRScan.raw_readings.begin()+pos, idl_CommIRScan.raw_readings.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearRaw_readings() { idl_CommIRScan.raw_readings.clear(); }
};

} /* namespace CommBasicObjects */
#endif /* COMMBASICOBJECTS_COMMIRSCAN_CORE_H_ */
