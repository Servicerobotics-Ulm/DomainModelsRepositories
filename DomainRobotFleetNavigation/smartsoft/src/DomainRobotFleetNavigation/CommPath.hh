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
#ifndef DOMAINROBOTFLEETNAVIGATION_COMMPATH_H_
#define DOMAINROBOTFLEETNAVIGATION_COMMPATH_H_

#include "DomainRobotFleetNavigation/CommPathCore.hh"

namespace DomainRobotFleetNavigation {
		
class CommPath : public CommPathCore {
	public:
		// default constructors
		CommPath();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommPath(const int &id, const int &direction, const double &width, const std::vector<DomainRobotFleetNavigation::CommNode> &node);
		
		CommPath(const CommPathCore &commPath);
		CommPath(const DATATYPE &commPath);
		virtual ~CommPath();
		
		// use framework specific getter and setter methods from core (base) class
		using CommPathCore::get;
		using CommPathCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommPath &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace DomainRobotFleetNavigation */
#endif /* DOMAINROBOTFLEETNAVIGATION_COMMPATH_H_ */