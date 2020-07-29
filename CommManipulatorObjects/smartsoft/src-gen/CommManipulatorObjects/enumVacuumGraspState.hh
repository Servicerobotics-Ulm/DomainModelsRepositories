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
#ifndef COMMMANIPULATOROBJECTS_VACUUMGRASPSTATE_ENUM_H_
#define COMMMANIPULATOROBJECTS_VACUUMGRASPSTATE_ENUM_H_

#include <CommManipulatorObjects/enumVacuumGraspStateData.hh>

#include <string>
#include <iostream>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

namespace CommManipulatorObjects {
	
	class VacuumGraspState {
	private:
		CommManipulatorObjectsIDL::VacuumGraspState value;
		
	public:
		enum ENUM_VacuumGraspState {
			ENUM_VALUE_UNDEFINED = 0,
			VACUUM_REACHED = 1,
			VACUUM_NOT_REACHED = 2,
			VACUUM_OK = 3,
			VACUUM_LOST = 4,
			VACUUM_UNKNOWN = 5
		};
		
		// default constructor
		VacuumGraspState() { 
			value = ENUM_VALUE_UNDEFINED;
		}
		
		// copy constructor for enum type
		VacuumGraspState(ENUM_VacuumGraspState e) {
			value = static_cast<int>(e);
		}
		
		// copy constructor for IDL type
		VacuumGraspState(CommManipulatorObjectsIDL::VacuumGraspState e) {
			value = e;
		}
		
		//const CommManipulatorObjectsIDL::VacuumGraspState& get() const { return value; }
		
		// ENUM operator
		operator ENUM_VacuumGraspState() const {
			return static_cast<ENUM_VacuumGraspState>(value);
		}
		
		// compare operator
		bool operator == (const ENUM_VacuumGraspState t) const {
			return this->value == t;
		}
		
		std::string to_string() const {
			std::string result = "";
			switch (value) {
				case VACUUM_REACHED:
					result = "VacuumGraspState::VACUUM_REACHED";
					break;
				case VACUUM_NOT_REACHED:
					result = "VacuumGraspState::VACUUM_NOT_REACHED";
					break;
				case VACUUM_OK:
					result = "VacuumGraspState::VACUUM_OK";
					break;
				case VACUUM_LOST:
					result = "VacuumGraspState::VACUUM_LOST";
					break;
				case VACUUM_UNKNOWN:
					result = "VacuumGraspState::VACUUM_UNKNOWN";
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
	
	inline std::ostream &operator<<(std::ostream &os, const VacuumGraspState &e)
	{
		e.to_ostream(os);
		return os;
	}
};

#endif