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
#ifndef COMMBASICOBJECTS_FILEMOVEREVENTTYPE_ENUM_H_
#define COMMBASICOBJECTS_FILEMOVEREVENTTYPE_ENUM_H_

#include <CommBasicObjects/enumFileMoverEventTypeData.hh>

#include <string>
#include <iostream>
#include <locale>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace CommBasicObjects {
	
	class FileMoverEventType {
	private:
		CommBasicObjectsIDL::FileMoverEventType value;
		
	public:
		enum ENUM_FileMoverEventType {
			ENUM_VALUE_UNDEFINED = 0,
			TYPE_FILE_UNKNOWN = 1,
			TYPE_FILE_SUCCESS = 2,
			TYPE_FILE_ERROR = 3
		};
		
		// default constructor
		FileMoverEventType() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		FileMoverEventType(ENUM_FileMoverEventType e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type (which is typically int)
		FileMoverEventType(CommBasicObjectsIDL::FileMoverEventType e) {
			value = e;
		}
		
		//const CommBasicObjectsIDL::FileMoverEventType& get() const { return value; }
		
		// ENUM operator
		operator ENUM_FileMoverEventType() const {
			return static_cast<ENUM_FileMoverEventType>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_FileMoverEventType t) const {
			return this->value == t;
		}
		
		std::string to_string(const bool &use_fqn=true) const {
			std::string result = "";
			if(use_fqn == true) {
				result = "FileMoverEventType::";
			}
			switch (value) {
				case TYPE_FILE_UNKNOWN:
					result += "TYPE_FILE_UNKNOWN";
					break;
				case TYPE_FILE_SUCCESS:
					result += "TYPE_FILE_SUCCESS";
					break;
				case TYPE_FILE_ERROR:
					result += "TYPE_FILE_ERROR";
					break;
				default:
					result += "ENUM_VALUE_UNDEFINED";
					break;
			};
			return result;
		}
		
		static FileMoverEventType from_string(const std::string &value) {
			std::string input = value;
			std::locale l;
			for(auto &c: input) {
				// convert all characters to lower case (so string comparison works regardless of small/capital letters)
				c = std::tolower(c,l);
			}
			std::string base_name = "filemovereventtype::";
			if(input.compare(0, base_name.length(), base_name) == 0) {
				// remove basename from comparing the actual enumeration
				input.erase(0,base_name.length());
			}
			if(input == "type_file_unknown"){
				return FileMoverEventType(TYPE_FILE_UNKNOWN);
			}
			if(input == "type_file_success"){
				return FileMoverEventType(TYPE_FILE_SUCCESS);
			}
			if(input == "type_file_error"){
				return FileMoverEventType(TYPE_FILE_ERROR);
			}
			// default (if none of the preceding options match)
			return FileMoverEventType();
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
	
	inline std::ostream &operator<<(std::ostream &os, const FileMoverEventType &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif
