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
#ifndef COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_CORE_H_
#define COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_CORE_H_

#include "CommNavigationObjects/CommCorridorNavigationNodeAnswerData.hh"
#include "CommNavigationObjects/CommCorridorNode.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommNavigationObjects {
	
class CommCorridorNavigationNodeAnswerCore {
protected:
	// data structure
	CommNavigationObjectsIDL::CommCorridorNavigationNodeAnswer idl_CommCorridorNavigationNodeAnswer;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommNavigationObjectsIDL::CommCorridorNavigationNodeAnswer DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommCorridorNavigationNodeAnswerCore();
	CommCorridorNavigationNodeAnswerCore(const DATATYPE &data);
	// default destructor
	virtual ~CommCorridorNavigationNodeAnswerCore();
	
	const DATATYPE& get() const { return idl_CommCorridorNavigationNodeAnswer; }
	operator const DATATYPE&() const { return idl_CommCorridorNavigationNodeAnswer; }
	DATATYPE& set() { return idl_CommCorridorNavigationNodeAnswer; }

	static inline std::string identifier(void) { return "CommNavigationObjects::CommCorridorNavigationNodeAnswer"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element NodesList
	/**
	 * Getter methods for element idl_CommCorridorNavigationNodeAnswer.nodesList of type vector<CommNavigationObjects::CommCorridorNode>
	 */
	inline std::vector<CommNavigationObjects::CommCorridorNode> getNodesListCopy() const { 
		return std::vector<CommNavigationObjects::CommCorridorNode>(idl_CommCorridorNavigationNodeAnswer.nodesList.begin(), idl_CommCorridorNavigationNodeAnswer.nodesList.end());
	}
	inline CommNavigationObjects::CommCorridorNode getNodesListElemAtPos(const size_t &pos) const {
		return CommNavigationObjects::CommCorridorNode(idl_CommCorridorNavigationNodeAnswer.nodesList[pos]);
	}
	inline size_t getNodesListSize() const { return idl_CommCorridorNavigationNodeAnswer.nodesList.size(); }
	inline bool isNodesListEmpty() const { return idl_CommCorridorNavigationNodeAnswer.nodesList.empty(); }
	/**
	 * Setter methods for idl_CommCorridorNavigationNodeAnswer.nodesList of type vector<CommNavigationObjects::CommCorridorNode>
	 */
	inline CommCorridorNavigationNodeAnswerCore& setNodesList(const std::vector<CommNavigationObjects::CommCorridorNode> &nodesList) { 
		idl_CommCorridorNavigationNodeAnswer.nodesList.assign(nodesList.begin(), nodesList.end());
		return *this;
	}
	inline bool setNodesListElemAtPos(const size_t &pos, const CommNavigationObjects::CommCorridorNode &elem) {
		if(pos < idl_CommCorridorNavigationNodeAnswer.nodesList.size()) {
			idl_CommCorridorNavigationNodeAnswer.nodesList[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertNodesListVectorAtPos(const size_t &pos, const std::vector<CommNavigationObjects::CommCorridorNode> &data) {
		if(pos < idl_CommCorridorNavigationNodeAnswer.nodesList.size()) {
			idl_CommCorridorNavigationNodeAnswer.nodesList.insert(idl_CommCorridorNavigationNodeAnswer.nodesList.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeNodesList(const size_t &size) { idl_CommCorridorNavigationNodeAnswer.nodesList.resize(size); }
	inline bool eraseNodesListElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommCorridorNavigationNodeAnswer.nodesList.size() ) {
			idl_CommCorridorNavigationNodeAnswer.nodesList.erase(idl_CommCorridorNavigationNodeAnswer.nodesList.begin()+pos, idl_CommCorridorNavigationNodeAnswer.nodesList.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearNodesList() { idl_CommCorridorNavigationNodeAnswer.nodesList.clear(); }
	
	// getter and setter for element Success
	inline bool getSuccess() const { return idl_CommCorridorNavigationNodeAnswer.success; }
	inline CommCorridorNavigationNodeAnswerCore& setSuccess(const bool &success) { idl_CommCorridorNavigationNodeAnswer.success = success; return *this; }
};

} /* namespace CommNavigationObjects */
#endif /* COMMNAVIGATIONOBJECTS_COMMCORRIDORNAVIGATIONNODEANSWER_CORE_H_ */
