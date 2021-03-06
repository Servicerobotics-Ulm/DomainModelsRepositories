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
#include "CommNavigationObjects/CommCorridorNavigationNodeRequestCore.hh"

// serialization/deserialization operators
//#include "CommNavigationObjects/CommCorridorNavigationNodeRequestACE.hh"

// include the hash.idl containing the hash constant
#include "hash.hh"
#include <assert.h>
#include <cstring>
#include <iostream>

// SmartUtils used in from_xml method
#include "smartKnuthMorrisPratt.hh"

#ifdef ENABLE_HASH
	#include <boost/functional/hash.hpp>
#endif

namespace CommNavigationObjects 
{
	const char* CommCorridorNavigationNodeRequestCore::getCompiledHash()
	{
		return CommNavigationObjectsIDL::REPO_HASH;
	}
	
	void CommCorridorNavigationNodeRequestCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommNavigationObjects::CommCorridorNode(idl_CommCorridorNavigationNodeRequest.nodesList)
		CommNavigationObjects::CommCorridorNode::getAllHashValues(hashes);
	}
	
	void CommCorridorNavigationNodeRequestCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommCorridorNavigationNodeRequestCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommNavigationObjects::CommCorridorNode(idl_CommCorridorNavigationNodeRequest.nodesList)
		CommNavigationObjects::CommCorridorNode::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommCorridorNavigationNodeRequestCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		boost::hash_combine(seed, data.requestType);
		std::vector<CommNavigationObjectsIDL::CommCorridorNode>::const_iterator data_nodesListIt;
		for(data_nodesListIt=data.nodesList.begin(); data_nodesListIt!=data.nodesList.end(); data_nodesListIt++) {
			seed += CommNavigationObjects::CommCorridorNode::generateDataHash(*data_nodesListIt);
		}
		boost::hash_combine(seed, std::string(data.robotID.c_str()));
		
		return seed;
	}
	#endif
	
	// default constructor
	CommCorridorNavigationNodeRequestCore::CommCorridorNavigationNodeRequestCore()
	:	idl_CommCorridorNavigationNodeRequest()
	{  
		setRequestType(CommNavigationObjects::NavigationNodeRequestType());
		setNodesList(std::vector<CommNavigationObjects::CommCorridorNode>());
		setRobotID("");
	}
	
	CommCorridorNavigationNodeRequestCore::CommCorridorNavigationNodeRequestCore(const DATATYPE &data)
	:	idl_CommCorridorNavigationNodeRequest(data)
	{  }

	CommCorridorNavigationNodeRequestCore::~CommCorridorNavigationNodeRequestCore()
	{  }
	
	void CommCorridorNavigationNodeRequestCore::to_ostream(std::ostream &os) const
	{
	  os << "CommCorridorNavigationNodeRequest(";
	  getRequestType().to_ostream(os);
	  std::vector<CommNavigationObjects::CommCorridorNode>::const_iterator nodesListIt;
	  std::vector<CommNavigationObjects::CommCorridorNode> nodesListList = getNodesListCopy();
	  for(nodesListIt=nodesListList.begin(); nodesListIt!=nodesListList.end(); nodesListIt++) {
	  	nodesListIt->to_ostream(os);
	  }
	  os << getRobotID() << " ";
	  os << ") ";
	}
	
	// convert to xml stream
	void CommCorridorNavigationNodeRequestCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		os << indent << "<requestType>";
		getRequestType().to_xml(os, indent);
		os << indent << "</requestType>";
		std::vector<CommNavigationObjects::CommCorridorNode>::const_iterator nodesListIt;
		std::vector<CommNavigationObjects::CommCorridorNode> nodesListList = getNodesListCopy();
		counter = 0;
		os << indent << "<nodesListList n=\"" << nodesListList.size() << "\">";
		for(nodesListIt=nodesListList.begin(); nodesListIt!=nodesListList.end(); nodesListIt++) {
			os << indent << "<nodesList i=\"" << counter++ << "\">";
			nodesListIt->to_xml(os, indent);
			os << indent << "</nodesList>";
		}
		os << indent << "</nodesListList>";
		os << indent << "<robotID>" << getRobotID() << "</robotID>";
	}
	
	// restore from xml stream
	void CommCorridorNavigationNodeRequestCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_requestType("<requestType>");
		static const Smart::KnuthMorrisPratt kmp_nodesListList("<nodesListList n=\"");
		static const Smart::KnuthMorrisPratt kmp_nodesList("\">");
		static const Smart::KnuthMorrisPratt kmp_robotID("<robotID>");
		
		if(kmp_requestType.search(is)) {
			CommNavigationObjects::NavigationNodeRequestType requestTypeItem;
			requestTypeItem.from_xml(is);
			setRequestType(requestTypeItem);
		}
		if(kmp_nodesListList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			CommNavigationObjects::CommCorridorNode nodesListItem;
			std::vector<CommNavigationObjects::CommCorridorNode> nodesListList;
			kmp_nodesList.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_nodesList.search(is)) {
					nodesListItem.from_xml(is);
					nodesListList.push_back(nodesListItem);
				}
			}
			setNodesList(nodesListList);
		}
		if(kmp_robotID.search(is)) {
			std::string robotIDItem;
			is >> robotIDItem;
			setRobotID(robotIDItem);
		}
	}
	
	/*
	void CommCorridorNavigationNodeRequestCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		CommNavigationObjectsIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(CommNavigationObjectsIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommCorridorNavigationNodeRequestACE.hh)
		cdr << idl_CommCorridorNavigationNodeRequest;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommCorridorNavigationNodeRequest);
		cdr << data_hash;
		// std::cout << "CommCorridorNavigationNodeRequestCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommCorridorNavigationNodeRequestCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		CommNavigationObjectsIDL::HashList hashes;
		ACE_CDR::Long hashes_size;
		cdr >> hashes_size;
		for(int i=0; i<hashes_size; ++i) 
		{
			ACE_CString hash;
			cdr >> hash;
			hashes.push_back(hash.c_str());
		}
		checkAllHashValues(hashes);
		
		// Here the actual de-serialization takes place using the InputCDR serialization operator>>
		// (see CommCorridorNavigationNodeRequestACE.hh)
		cdr >> idl_CommCorridorNavigationNodeRequest;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommCorridorNavigationNodeRequest);
		assert(data_hash == own_hash);
		// std::cout << "CommCorridorNavigationNodeRequestCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommNavigationObjects */
