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
#ifndef COMMNAVIGATIONOBJECTS_NODE_TYPE_ENUM_H_
#define COMMNAVIGATIONOBJECTS_NODE_TYPE_ENUM_H_

#include <CommNavigationObjects/enumNODE_TYPEData.hh>

#include <string>
#include <iostream>
#include <locale>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace CommNavigationObjects {
	
	class NODE_TYPE {
	private:
		CommNavigationObjectsIDL::NODE_TYPE value;
		
	public:
		enum ENUM_NODE_TYPE {
			ENUM_VALUE_UNDEFINED = 0,
			NORMAL = 1,
			CROSS = 2,
			WAIT = 3,
			NEWCROSS = 4
		};
		
		// default constructor
		NODE_TYPE() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		NODE_TYPE(ENUM_NODE_TYPE e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type (which is typically int)
		NODE_TYPE(CommNavigationObjectsIDL::NODE_TYPE e) {
			value = e;
		}
		
		//const CommNavigationObjectsIDL::NODE_TYPE& get() const { return value; }
		
		// ENUM operator
		operator ENUM_NODE_TYPE() const {
			return static_cast<ENUM_NODE_TYPE>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_NODE_TYPE t) const {
			return this->value == t;
		}
		
		std::string to_string(const bool &use_fqn=true) const {
			std::string result = "";
			if(use_fqn == true) {
				result = "NODE_TYPE::";
			}
			switch (value) {
				case NORMAL:
					result += "NORMAL";
					break;
				case CROSS:
					result += "CROSS";
					break;
				case WAIT:
					result += "WAIT";
					break;
				case NEWCROSS:
					result += "NEWCROSS";
					break;
				default:
					result += "ENUM_VALUE_UNDEFINED";
					break;
			};
			return result;
		}
		
		static NODE_TYPE from_string(const std::string &value) {
			std::string input = value;
			std::locale l;
			for(auto &c: input) {
				// convert all characters to lower case (so string comparison works regardless of small/capital letters)
				c = std::tolower(c,l);
			}
			std::string base_name = "node_type::";
			if(input.compare(0, base_name.length(), base_name) == 0) {
				// remove basename from comparing the actual enumeration
				input.erase(0,base_name.length());
			}
			if(input == "normal"){
				return NODE_TYPE(NORMAL);
			}
			if(input == "cross"){
				return NODE_TYPE(CROSS);
			}
			if(input == "wait"){
				return NODE_TYPE(WAIT);
			}
			if(input == "newcross"){
				return NODE_TYPE(NEWCROSS);
			}
			// default (if none of the preceding options match)
			return NODE_TYPE();
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
	
	inline std::ostream &operator<<(std::ostream &os, const NODE_TYPE &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif
