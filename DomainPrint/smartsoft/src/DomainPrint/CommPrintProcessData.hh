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
#ifndef DOMAINPRINT_COMMPRINTPROCESSDATA_H_
#define DOMAINPRINT_COMMPRINTPROCESSDATA_H_

#include "DomainPrint/CommPrintProcessDataCore.hh"

namespace DomainPrint {
		
class CommPrintProcessData : public CommPrintProcessDataCore {
	public:
		// default constructors
		CommPrintProcessData();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommPrintProcessData(const std::vector<DomainPrint::CommKeyValue> &data, const std::string &templateID);
		
		CommPrintProcessData(const CommPrintProcessDataCore &commPrintProcessData);
		CommPrintProcessData(const DATATYPE &commPrintProcessData);
		virtual ~CommPrintProcessData();
		
		// use framework specific getter and setter methods from core (base) class
		using CommPrintProcessDataCore::get;
		using CommPrintProcessDataCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommPrintProcessData &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace DomainPrint */
#endif /* DOMAINPRINT_COMMPRINTPROCESSDATA_H_ */
