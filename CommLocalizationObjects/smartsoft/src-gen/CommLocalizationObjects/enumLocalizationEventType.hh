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
#ifndef COMMLOCALIZATIONOBJECTS_LOCALIZATIONEVENTTYPE_ENUM_H_
#define COMMLOCALIZATIONOBJECTS_LOCALIZATIONEVENTTYPE_ENUM_H_

#include <CommLocalizationObjects/enumLocalizationEventTypeData.hh>

#include <string>
#include <iostream>
#include <locale>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace CommLocalizationObjects {
	
	class LocalizationEventType {
	private:
		CommLocalizationObjectsIDL::LocalizationEventType value;
		
	public:
		enum ENUM_LocalizationEventType {
			ENUM_VALUE_UNDEFINED = 0,
			LOCALIZATION_UNKNOWN = 1,
			LOCALIZATION_LOST = 2,
			LOCALIZATION_OK = 3
		};
		
		// default constructor
		LocalizationEventType() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		LocalizationEventType(ENUM_LocalizationEventType e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type (which is typically int)
		LocalizationEventType(CommLocalizationObjectsIDL::LocalizationEventType e) {
			value = e;
		}
		
		//const CommLocalizationObjectsIDL::LocalizationEventType& get() const { return value; }
		
		// ENUM operator
		operator ENUM_LocalizationEventType() const {
			return static_cast<ENUM_LocalizationEventType>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_LocalizationEventType t) const {
			return this->value == t;
		}
		
		std::string to_string(const bool &use_fqn=true) const {
			std::string result = "";
			if(use_fqn == true) {
				result = "LocalizationEventType::";
			}
			switch (value) {
				case LOCALIZATION_UNKNOWN:
					result += "LOCALIZATION_UNKNOWN";
					break;
				case LOCALIZATION_LOST:
					result += "LOCALIZATION_LOST";
					break;
				case LOCALIZATION_OK:
					result += "LOCALIZATION_OK";
					break;
				default:
					result += "ENUM_VALUE_UNDEFINED";
					break;
			};
			return result;
		}
		
		static LocalizationEventType from_string(const std::string &value) {
			std::string input = value;
			std::locale l;
			for(auto &c: input) {
				// convert all characters to lower case (so string comparison works regardless of small/capital letters)
				c = std::tolower(c,l);
			}
			std::string base_name = "localizationeventtype::";
			if(input.compare(0, base_name.length(), base_name) == 0) {
				// remove basename from comparing the actual enumeration
				input.erase(0,base_name.length());
			}
			if(input == "localization_unknown"){
				return LocalizationEventType(LOCALIZATION_UNKNOWN);
			}
			if(input == "localization_lost"){
				return LocalizationEventType(LOCALIZATION_LOST);
			}
			if(input == "localization_ok"){
				return LocalizationEventType(LOCALIZATION_OK);
			}
			// default (if none of the preceding options match)
			return LocalizationEventType();
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
	
	inline std::ostream &operator<<(std::ostream &os, const LocalizationEventType &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif
