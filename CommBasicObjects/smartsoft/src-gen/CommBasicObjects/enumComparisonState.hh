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
#ifndef COMMBASICOBJECTS_COMPARISONSTATE_ENUM_H_
#define COMMBASICOBJECTS_COMPARISONSTATE_ENUM_H_

#include <CommBasicObjects/enumComparisonStateData.hh>

#include <string>
#include <iostream>
#include <locale>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace CommBasicObjects {
	
	class ComparisonState {
	private:
		CommBasicObjectsIDL::ComparisonState value;
		
	public:
		enum ENUM_ComparisonState {
			ENUM_VALUE_UNDEFINED = 0,
			UNKNOWN = 1,
			GREATER = 2,
			LOWER = 3,
			INBETWEEN = 4
		};
		
		// default constructor
		ComparisonState() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		ComparisonState(ENUM_ComparisonState e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type (which is typically int)
		ComparisonState(CommBasicObjectsIDL::ComparisonState e) {
			value = e;
		}
		
		//const CommBasicObjectsIDL::ComparisonState& get() const { return value; }
		
		// ENUM operator
		operator ENUM_ComparisonState() const {
			return static_cast<ENUM_ComparisonState>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_ComparisonState t) const {
			return this->value == t;
		}
		
		std::string to_string(const bool &use_fqn=true) const {
			std::string result = "";
			if(use_fqn == true) {
				result = "ComparisonState::";
			}
			switch (value) {
				case UNKNOWN:
					result += "UNKNOWN";
					break;
				case GREATER:
					result += "GREATER";
					break;
				case LOWER:
					result += "LOWER";
					break;
				case INBETWEEN:
					result += "INBETWEEN";
					break;
				default:
					result += "ENUM_VALUE_UNDEFINED";
					break;
			};
			return result;
		}
		
		static ComparisonState from_string(const std::string &value) {
			std::string input = value;
			std::locale l;
			for(auto &c: input) {
				// convert all characters to lower case (so string comparison works regardless of small/capital letters)
				c = std::tolower(c,l);
			}
			std::string base_name = "comparisonstate::";
			if(input.compare(0, base_name.length(), base_name) == 0) {
				// remove basename from comparing the actual enumeration
				input.erase(0,base_name.length());
			}
			if(input == "unknown"){
				return ComparisonState(UNKNOWN);
			}
			if(input == "greater"){
				return ComparisonState(GREATER);
			}
			if(input == "lower"){
				return ComparisonState(LOWER);
			}
			if(input == "inbetween"){
				return ComparisonState(INBETWEEN);
			}
			// default (if none of the preceding options match)
			return ComparisonState();
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
	
	inline std::ostream &operator<<(std::ostream &os, const ComparisonState &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif
