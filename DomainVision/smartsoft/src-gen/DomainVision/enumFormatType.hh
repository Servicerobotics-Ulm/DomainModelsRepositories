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
#ifndef DOMAINVISION_FORMATTYPE_ENUM_H_
#define DOMAINVISION_FORMATTYPE_ENUM_H_

#include <DomainVision/enumFormatTypeData.hh>

#include <string>
#include <iostream>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace DomainVision {
	
	class FormatType {
	private:
		DomainVisionIDL::FormatType value;
		
	public:
		enum ENUM_FormatType {
			ENUM_VALUE_UNDEFINED = 0,
			GREY = 1,
			RGB565 = 2,
			RGB555 = 3,
			RGB24 = 4,
			RGB32 = 5,
			YUV422 = 6,
			YUYV = 7,
			UYVY = 8,
			YUV420P = 9,
			YUV422P = 10,
			YUV411P = 11
		};
		
		// default constructor
		FormatType() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		FormatType(ENUM_FormatType e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type
		FormatType(DomainVisionIDL::FormatType e) {
			value = e;
		}
		
		//const DomainVisionIDL::FormatType& get() const { return value; }
		
		// ENUM operator
		operator ENUM_FormatType() const {
			return static_cast<ENUM_FormatType>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_FormatType t) const {
			return this->value == t;
		}
		
		std::string to_string() const {
			std::string result = "";
			switch (value) {
				case GREY:
					result = "FormatType::GREY";
					break;
				case RGB565:
					result = "FormatType::RGB565";
					break;
				case RGB555:
					result = "FormatType::RGB555";
					break;
				case RGB24:
					result = "FormatType::RGB24";
					break;
				case RGB32:
					result = "FormatType::RGB32";
					break;
				case YUV422:
					result = "FormatType::YUV422";
					break;
				case YUYV:
					result = "FormatType::YUYV";
					break;
				case UYVY:
					result = "FormatType::UYVY";
					break;
				case YUV420P:
					result = "FormatType::YUV420P";
					break;
				case YUV422P:
					result = "FormatType::YUV422P";
					break;
				case YUV411P:
					result = "FormatType::YUV411P";
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
	
	inline std::ostream &operator<<(std::ostream &os, const FormatType &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif