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
#ifndef DOMAINVISION_DEPTHFORMATTYPE_ENUM_H_
#define DOMAINVISION_DEPTHFORMATTYPE_ENUM_H_

#include <DomainVision/enumDepthFormatTypeData.hh>

#include <string>
#include <iostream>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace DomainVision {
	
	class DepthFormatType {
	private:
		DomainVisionIDL::DepthFormatType value;
		
	public:
		enum ENUM_DepthFormatType {
			ENUM_VALUE_UNDEFINED = 0,
			UINT8 = 1,
			UINT16 = 2,
			FLOAT = 3,
			DOUBLE = 4
		};
		
		// default constructor
		DepthFormatType() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		DepthFormatType(ENUM_DepthFormatType e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type
		DepthFormatType(DomainVisionIDL::DepthFormatType e) {
			value = e;
		}
		
		//const DomainVisionIDL::DepthFormatType& get() const { return value; }
		
		// ENUM operator
		operator ENUM_DepthFormatType() const {
			return static_cast<ENUM_DepthFormatType>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_DepthFormatType t) const {
			return this->value == t;
		}
		
		std::string to_string() const {
			std::string result = "";
			switch (value) {
				case UINT8:
					result = "DepthFormatType::UINT8";
					break;
				case UINT16:
					result = "DepthFormatType::UINT16";
					break;
				case FLOAT:
					result = "DepthFormatType::FLOAT";
					break;
				case DOUBLE:
					result = "DepthFormatType::DOUBLE";
					break;
				default:
					result = "ENUM_VALUE_UNDEFINED";
					break;
			};
			return result;
		}
		
		// helper method to easily implement output stream
		void to_ostream(std::ostream &os = std::cout) const {
			os << to_string();
		}
		
		// convert to xml stream
		void to_xml(std::ostream &os, const std::string &indent = "") const {
			os << indent << "<value>" << value << "</value>";
		}
		
		// restore from xml stream
		void from_xml(std::istream &is) {
			static const Smart::KnuthMorrisPratt kmp_value("<value>");
			if(kmp_value.search(is)) {
				is >> value;
			}
		}
	
	};
	
	inline std::ostream &operator<<(std::ostream &os, const DepthFormatType &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif
