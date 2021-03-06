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
#include "DomainPrint/CommPrintProcessDataACE.hh"
#include <ace/SString.h>
#include "DomainPrint/enumApplicationModeTypeEnumData.hh"
#include "DomainPrint/CommKeyValueACE.hh"

// serialization operator for element CommPrintProcessData
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrintIDL::CommPrintProcessData &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element data
	good_bit = good_bit && cdr << ACE_Utils::truncate_cast<ACE_CDR::ULong>(data.data.size());
	std::vector<DomainPrintIDL::CommKeyValue>::const_iterator data_dataIt;
	for(data_dataIt=data.data.begin(); data_dataIt!=data.data.end(); data_dataIt++) {
		good_bit = good_bit && cdr << *data_dataIt;
	}
	// serialize list-element templateID
	good_bit = good_bit && cdr << ACE_CString(data.templateID.c_str());
	// serialize list-element applicationMode
	good_bit = good_bit && cdr.write_long(data.applicationMode);
	
	return good_bit;
}

// de-serialization operator for element CommPrintProcessData
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrintIDL::CommPrintProcessData &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize list-type element data
	ACE_CDR::ULong data_dataNbr;
	good_bit = good_bit && cdr >> data_dataNbr;
	data.data.clear();
	DomainPrintIDL::CommKeyValue data_dataItem;
	for(ACE_CDR::ULong i=0; i<data_dataNbr; ++i) {
		good_bit = good_bit && cdr >> data_dataItem;
		data.data.push_back(data_dataItem);
	}
	// deserialize string-type element templateID
	ACE_CString data_templateID_str;
	good_bit = good_bit && cdr >> data_templateID_str;
	data.templateID = data_templateID_str.c_str();
	// deserialize type element applicationMode
	good_bit = good_bit && cdr.read_long(data.applicationMode);
	
	return good_bit;
}

// serialization operator for CommunicationObject CommPrintProcessData
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainPrint::CommPrintProcessData &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject CommPrintProcessData
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainPrint::CommPrintProcessData &obj)
{
	return cdr >> obj.set();
}
