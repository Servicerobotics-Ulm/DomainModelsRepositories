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
#ifndef COMMNAVIGATIONOBJECTS_NAVIGATIONNODEREQUESTTYPE_ENUM_H_
#define COMMNAVIGATIONOBJECTS_NAVIGATIONNODEREQUESTTYPE_ENUM_H_

#include <CommNavigationObjects/enumNavigationNodeRequestTypeData.hh>

#include <string>
#include <iostream>
#include <locale>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace CommNavigationObjects {
	
	class NavigationNodeRequestType {
	private:
		CommNavigationObjectsIDL::NavigationNodeRequestType value;
		
	public:
		enum ENUM_NavigationNodeRequestType {
			ENUM_VALUE_UNDEFINED = 0,
			FREENODE = 1,
			ACQUIRENODE = 2,
			FREEALLNODES = 3,
			FREEALLNODESBUT = 4
		};
		
		// default constructor
		NavigationNodeRequestType() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		NavigationNodeRequestType(ENUM_NavigationNodeRequestType e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type (which is typically int)
		NavigationNodeRequestType(CommNavigationObjectsIDL::NavigationNodeRequestType e) {
			value = e;
		}
		
		//const CommNavigationObjectsIDL::NavigationNodeRequestType& get() const { return value; }
		
		// ENUM operator
		operator ENUM_NavigationNodeRequestType() const {
			return static_cast<ENUM_NavigationNodeRequestType>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_NavigationNodeRequestType t) const {
			return this->value == t;
		}
		
		std::string to_string(const bool &use_fqn=true) const {
			std::string result = "";
			if(use_fqn == true) {
				result = "NavigationNodeRequestType::";
			}
			switch (value) {
				case FREENODE:
					result += "FREENODE";
					break;
				case ACQUIRENODE:
					result += "ACQUIRENODE";
					break;
				case FREEALLNODES:
					result += "FREEALLNODES";
					break;
				case FREEALLNODESBUT:
					result += "FREEALLNODESBUT";
					break;
				default:
					result += "ENUM_VALUE_UNDEFINED";
					break;
			};
			return result;
		}
		
		static NavigationNodeRequestType from_string(const std::string &value) {
			std::string input = value;
			std::locale l;
			for(auto &c: input) {
				// convert all characters to lower case (so string comparison works regardless of small/capital letters)
				c = std::tolower(c,l);
			}
			std::string base_name = "navigationnoderequesttype::";
			if(input.compare(0, base_name.length(), base_name) == 0) {
				// remove basename from comparing the actual enumeration
				input.erase(0,base_name.length());
			}
			if(input == "freenode"){
				return NavigationNodeRequestType(FREENODE);
			}
			if(input == "acquirenode"){
				return NavigationNodeRequestType(ACQUIRENODE);
			}
			if(input == "freeallnodes"){
				return NavigationNodeRequestType(FREEALLNODES);
			}
			if(input == "freeallnodesbut"){
				return NavigationNodeRequestType(FREEALLNODESBUT);
			}
			// default (if none of the preceding options match)
			return NavigationNodeRequestType();
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
	
	inline std::ostream &operator<<(std::ostream &os, const NavigationNodeRequestType &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif
