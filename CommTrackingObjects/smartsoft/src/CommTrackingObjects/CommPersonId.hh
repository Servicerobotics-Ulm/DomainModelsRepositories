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
#ifndef COMMTRACKINGOBJECTS_COMMPERSONID_H_
#define COMMTRACKINGOBJECTS_COMMPERSONID_H_

#include "CommTrackingObjects/CommPersonIdCore.hh"

namespace CommTrackingObjects {
		
class CommPersonId : public CommPersonIdCore {
	public:
		// default constructors
		CommPersonId();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommPersonId(const unsigned int &id = 0);
		
		CommPersonId(const CommPersonIdCore &commPersonId);
		CommPersonId(const DATATYPE &commPersonId);
		virtual ~CommPersonId();
		
		// use framework specific getter and setter methods from core (base) class
		using CommPersonIdCore::get;
		using CommPersonIdCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommPersonId &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace CommTrackingObjects */
#endif /* COMMTRACKINGOBJECTS_COMMPERSONID_H_ */