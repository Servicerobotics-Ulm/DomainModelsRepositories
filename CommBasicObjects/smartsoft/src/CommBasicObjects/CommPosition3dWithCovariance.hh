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
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#ifndef COMMBASICOBJECTS_COMMPOSITION3DWITHCOVARIANCE_H_
#define COMMBASICOBJECTS_COMMPOSITION3DWITHCOVARIANCE_H_

#include "CommBasicObjects/CommPosition3dWithCovarianceCore.hh"

namespace CommBasicObjects {
		
class CommPosition3dWithCovariance : public CommPosition3dWithCovarianceCore {
	public:
		// default constructors
		CommPosition3dWithCovariance();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommPosition3dWithCovariance(const CommBasicObjects::CommPosition3d &position, const std::vector<double> &covMatrix);
		
		CommPosition3dWithCovariance(const CommPosition3dWithCovarianceCore &commPosition3dWithCovariance);
		CommPosition3dWithCovariance(const DATATYPE &commPosition3dWithCovariance);
		virtual ~CommPosition3dWithCovariance();
		
		// use framework specific getter and setter methods from core (base) class
		using CommPosition3dWithCovarianceCore::get;
		using CommPosition3dWithCovarianceCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommPosition3dWithCovariance &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommBasicObjects */
#endif /* COMMBASICOBJECTS_COMMPOSITION3DWITHCOVARIANCE_H_ */
