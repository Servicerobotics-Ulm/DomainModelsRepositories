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
#ifndef DOMAINPRINT_COMMPRINTDATA_H_
#define DOMAINPRINT_COMMPRINTDATA_H_

#include "DomainPrint/CommPrintDataCore.hh"

namespace DomainPrint {
		
class CommPrintData : public CommPrintDataCore {
	public:
		// default constructors
		CommPrintData();
		
		/**
		 * Constructor to set all values.
		 * NOTE that you have to keep this constructor consistent with the model!
		 * Use  at your own choice.
		 *
		 * The preferred way to set values for initialization is:
		 *      CommRepository::MyCommObject obj;
		 *      obj.setX(1).setY(2).setZ(3)...;
		 */
		// CommPrintData(const std::string &data, const DomainPrint::PrintDataEnum &format = DomainPrint::PrintDataEnum());
		
		CommPrintData(const CommPrintDataCore &commPrintData);
		CommPrintData(const DATATYPE &commPrintData);
		virtual ~CommPrintData();
		
		// use framework specific getter and setter methods from core (base) class
		using CommPrintDataCore::get;
		using CommPrintDataCore::set;
		
		//
		// feel free to add customized methods here
		//
};

inline std::ostream &operator<<(std::ostream &os, const CommPrintData &co)
{
	co.to_ostream(os);
	return os;
}
	
} /* namespace DomainPrint */
#endif /* DOMAINPRINT_COMMPRINTDATA_H_ */
