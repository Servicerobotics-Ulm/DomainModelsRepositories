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
#ifndef COMMMANIPULATOROBJECTS_CARTESIANMANIPULATIONTARGETREFERENCEFRAME_ENUM_H_
#define COMMMANIPULATOROBJECTS_CARTESIANMANIPULATIONTARGETREFERENCEFRAME_ENUM_H_

#include <CommManipulatorObjects/enumCartesianManipulationTargetReferenceFrameData.hh>

#include <string>
#include <iostream>
#include <locale>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace CommManipulatorObjects {
	
	class CartesianManipulationTargetReferenceFrame {
	private:
		CommManipulatorObjectsIDL::CartesianManipulationTargetReferenceFrame value;
		
	public:
		enum ENUM_CartesianManipulationTargetReferenceFrame {
			ENUM_VALUE_UNDEFINED = 0,
			MANIPULATOR = 1,
			MOBILE_BASE = 2
		};
		
		// default constructor
		CartesianManipulationTargetReferenceFrame() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		CartesianManipulationTargetReferenceFrame(ENUM_CartesianManipulationTargetReferenceFrame e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type (which is typically int)
		CartesianManipulationTargetReferenceFrame(CommManipulatorObjectsIDL::CartesianManipulationTargetReferenceFrame e) {
			value = e;
		}
		
		//const CommManipulatorObjectsIDL::CartesianManipulationTargetReferenceFrame& get() const { return value; }
		
		// ENUM operator
		operator ENUM_CartesianManipulationTargetReferenceFrame() const {
			return static_cast<ENUM_CartesianManipulationTargetReferenceFrame>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_CartesianManipulationTargetReferenceFrame t) const {
			return this->value == t;
		}
		
		std::string to_string(const bool &use_fqn=true) const {
			std::string result = "";
			if(use_fqn == true) {
				result = "CartesianManipulationTargetReferenceFrame::";
			}
			switch (value) {
				case MANIPULATOR:
					result += "MANIPULATOR";
					break;
				case MOBILE_BASE:
					result += "MOBILE_BASE";
					break;
				default:
					result += "ENUM_VALUE_UNDEFINED";
					break;
			};
			return result;
		}
		
		static CartesianManipulationTargetReferenceFrame from_string(const std::string &value) {
			std::string input = value;
			std::locale l;
			for(auto &c: input) {
				// convert all characters to lower case (so string comparison works regardless of small/capital letters)
				c = std::tolower(c,l);
			}
			std::string base_name = "cartesianmanipulationtargetreferenceframe::";
			if(input.compare(0, base_name.length(), base_name) == 0) {
				// remove basename from comparing the actual enumeration
				input.erase(0,base_name.length());
			}
			if(input == "manipulator"){
				return CartesianManipulationTargetReferenceFrame(MANIPULATOR);
			}
			if(input == "mobile_base"){
				return CartesianManipulationTargetReferenceFrame(MOBILE_BASE);
			}
			// default (if none of the preceding options match)
			return CartesianManipulationTargetReferenceFrame();
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
	
	inline std::ostream &operator<<(std::ostream &os, const CartesianManipulationTargetReferenceFrame &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif