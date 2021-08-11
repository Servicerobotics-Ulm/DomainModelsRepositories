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
#ifndef COMMBASICOBJECTS_COMMPOSE3DWITHCOVARIANCE_CORE_H_
#define COMMBASICOBJECTS_COMMPOSE3DWITHCOVARIANCE_CORE_H_

#include "CommBasicObjects/CommPose3dWithCovarianceData.hh"
#include "CommBasicObjects/CommPose3d.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommBasicObjects {
	
class CommPose3dWithCovarianceCore {
protected:
	// data structure
	CommBasicObjectsIDL::CommPose3dWithCovariance idl_CommPose3dWithCovariance;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommBasicObjectsIDL::CommPose3dWithCovariance DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommPose3dWithCovarianceCore();
	CommPose3dWithCovarianceCore(const DATATYPE &data);
	// default destructor
	virtual ~CommPose3dWithCovarianceCore();
	
	const DATATYPE& get() const { return idl_CommPose3dWithCovariance; }
	operator const DATATYPE&() const { return idl_CommPose3dWithCovariance; }
	DATATYPE& set() { return idl_CommPose3dWithCovariance; }

	static inline std::string identifier(void) { return "CommBasicObjects::CommPose3dWithCovariance"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Pose
	inline CommBasicObjects::CommPose3d getPose() const { return CommBasicObjects::CommPose3d(idl_CommPose3dWithCovariance.pose); }
	inline CommPose3dWithCovarianceCore& setPose(const CommBasicObjects::CommPose3d &pose) { idl_CommPose3dWithCovariance.pose = pose; return *this; }
	
	// getter and setter for element CovMatrix
	/**
	 * Getter methods for idl_CommPose3dWithCovariance.covMatrix of type vector<double>
	 */
	inline std::vector<double>& getCovMatrixRef() { return idl_CommPose3dWithCovariance.covMatrix; }
	inline std::vector<double> getCovMatrixCopy() const {
		return std::vector<double>(idl_CommPose3dWithCovariance.covMatrix.begin(), idl_CommPose3dWithCovariance.covMatrix.end());
	}
	inline double getCovMatrixElemAtPos(const size_t &pos) const { return idl_CommPose3dWithCovariance.covMatrix[pos]; }
	inline size_t getCovMatrixSize() const { return idl_CommPose3dWithCovariance.covMatrix.size(); }
	inline bool isCovMatrixEmpty() const { return idl_CommPose3dWithCovariance.covMatrix.empty(); }
	/**
	 * Setter methods for idl_CommPose3dWithCovariance.covMatrix of type vector<double>
	 */
	inline CommPose3dWithCovarianceCore& setCovMatrix(const std::vector<double> &covMatrix) { idl_CommPose3dWithCovariance.covMatrix = covMatrix; return *this; }
	inline bool setCovMatrixElemAtPos(const size_t &pos, const double &elem) {
		if(pos < idl_CommPose3dWithCovariance.covMatrix.size()) {
			idl_CommPose3dWithCovariance.covMatrix[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertCovMatrixVectorAtPos(const size_t &pos, const std::vector<double> &data) {
		if(pos <= idl_CommPose3dWithCovariance.covMatrix.size()) {
			idl_CommPose3dWithCovariance.covMatrix.insert(idl_CommPose3dWithCovariance.covMatrix.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeCovMatrix(const size_t &size) { idl_CommPose3dWithCovariance.covMatrix.resize(size); }
	inline bool eraseCovMatrixElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommPose3dWithCovariance.covMatrix.size() ) {
			idl_CommPose3dWithCovariance.covMatrix.erase(idl_CommPose3dWithCovariance.covMatrix.begin()+pos, idl_CommPose3dWithCovariance.covMatrix.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearCovMatrix() { idl_CommPose3dWithCovariance.covMatrix.clear(); }
};

} /* namespace CommBasicObjects */
#endif /* COMMBASICOBJECTS_COMMPOSE3DWITHCOVARIANCE_CORE_H_ */
