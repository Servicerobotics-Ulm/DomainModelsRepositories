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
#ifndef DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHANSWER_CORE_H_
#define DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHANSWER_CORE_H_

#include "DomainRobotFleetNavigation/CommShortestPathAnswerData.hh"
#include "DomainRobotFleetNavigation/CommNode.hh"

#include <iostream>
#include <string>
#include <list>

namespace DomainRobotFleetNavigation {
	
class CommShortestPathAnswerCore {
protected:
	// data structure
	DomainRobotFleetNavigationIDL::CommShortestPathAnswer idl_CommShortestPathAnswer;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef DomainRobotFleetNavigationIDL::CommShortestPathAnswer DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommShortestPathAnswerCore();
	CommShortestPathAnswerCore(const DATATYPE &data);
	// default destructor
	virtual ~CommShortestPathAnswerCore();
	
	const DATATYPE& get() const { return idl_CommShortestPathAnswer; }
	operator const DATATYPE&() const { return idl_CommShortestPathAnswer; }
	DATATYPE& set() { return idl_CommShortestPathAnswer; }

	static inline std::string identifier(void) { return "DomainRobotFleetNavigation::CommShortestPathAnswer"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Path
	/**
	 * Getter methods for element idl_CommShortestPathAnswer.path of type vector<DomainRobotFleetNavigation::CommNode>
	 */
	inline std::vector<DomainRobotFleetNavigation::CommNode> getPathCopy() const { 
		return std::vector<DomainRobotFleetNavigation::CommNode>(idl_CommShortestPathAnswer.path.begin(), idl_CommShortestPathAnswer.path.end());
	}
	inline DomainRobotFleetNavigation::CommNode getPathElemAtPos(const size_t &pos) const {
		return DomainRobotFleetNavigation::CommNode(idl_CommShortestPathAnswer.path[pos]);
	}
	inline size_t getPathSize() const { return idl_CommShortestPathAnswer.path.size(); }
	inline bool isPathEmpty() const { return idl_CommShortestPathAnswer.path.empty(); }
	/**
	 * Setter methods for idl_CommShortestPathAnswer.path of type vector<DomainRobotFleetNavigation::CommNode>
	 */
	inline CommShortestPathAnswerCore& setPath(const std::vector<DomainRobotFleetNavigation::CommNode> &path) { 
		idl_CommShortestPathAnswer.path.assign(path.begin(), path.end());
		return *this;
	}
	inline bool setPathElemAtPos(const size_t &pos, const DomainRobotFleetNavigation::CommNode &elem) {
		if(pos < idl_CommShortestPathAnswer.path.size()) {
			idl_CommShortestPathAnswer.path[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertPathVectorAtPos(const size_t &pos, const std::vector<DomainRobotFleetNavigation::CommNode> &data) {
		if(pos < idl_CommShortestPathAnswer.path.size()) {
			idl_CommShortestPathAnswer.path.insert(idl_CommShortestPathAnswer.path.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizePath(const size_t &size) { idl_CommShortestPathAnswer.path.resize(size); }
	inline bool erasePathElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommShortestPathAnswer.path.size() ) {
			idl_CommShortestPathAnswer.path.erase(idl_CommShortestPathAnswer.path.begin()+pos, idl_CommShortestPathAnswer.path.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearPath() { idl_CommShortestPathAnswer.path.clear(); }
};

} /* namespace DomainRobotFleetNavigation */
#endif /* DOMAINROBOTFLEETNAVIGATION_COMMSHORTESTPATHANSWER_CORE_H_ */