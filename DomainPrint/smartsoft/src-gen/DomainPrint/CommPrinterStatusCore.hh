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
#ifndef DOMAINPRINT_COMMPRINTERSTATUS_CORE_H_
#define DOMAINPRINT_COMMPRINTERSTATUS_CORE_H_

#include "DomainPrint/CommPrinterStatusData.hh"
#include "DomainPrint/enumPrinterStatusEnum.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainPrint {
	
class CommPrinterStatusCore {
protected:
	// data structure
	DomainPrintIDL::CommPrinterStatus idl_CommPrinterStatus;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainPrintIDL::CommPrinterStatus DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommPrinterStatusCore();
	CommPrinterStatusCore(const DATATYPE &data);
	// default destructor
	virtual ~CommPrinterStatusCore();
	
	const DATATYPE& get() const { return idl_CommPrinterStatus; }
	operator const DATATYPE&() const { return idl_CommPrinterStatus; }
	DATATYPE& set() { return idl_CommPrinterStatus; }

	static inline std::string identifier(void) { return "DomainPrint::CommPrinterStatus"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Status
	inline DomainPrint::PrinterStatusEnum getStatus() const { return DomainPrint::PrinterStatusEnum(idl_CommPrinterStatus.status); }
	inline CommPrinterStatusCore& setStatus(const DomainPrint::PrinterStatusEnum &status) { idl_CommPrinterStatus.status = status; return *this; }
	
	// getter and setter for element StatusRIBWARN
	inline bool getStatusRIBWARN() const { return idl_CommPrinterStatus.statusRIBWARN; }
	inline CommPrinterStatusCore& setStatusRIBWARN(const bool &statusRIBWARN) { idl_CommPrinterStatus.statusRIBWARN = statusRIBWARN; return *this; }
	
	// getter and setter for element StatusLBLWARN
	inline bool getStatusLBLWARN() const { return idl_CommPrinterStatus.statusLBLWARN; }
	inline CommPrinterStatusCore& setStatusLBLWARN(const bool &statusLBLWARN) { idl_CommPrinterStatus.statusLBLWARN = statusLBLWARN; return *this; }
};

} /* namespace DomainPrint */
#endif /* DOMAINPRINT_COMMPRINTERSTATUS_CORE_H_ */
