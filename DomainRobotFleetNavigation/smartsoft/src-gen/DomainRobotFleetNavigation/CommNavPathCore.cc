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
#include "DomainRobotFleetNavigation/CommNavPathCore.hh"

// serialization/deserialization operators
//#include "DomainRobotFleetNavigation/CommNavPathACE.hh"

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

namespace DomainRobotFleetNavigation 
{
	const char* CommNavPathCore::getCompiledHash()
	{
		return DomainRobotFleetNavigationIDL::REPO_HASH;
	}
	
	void CommNavPathCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for DomainRobotFleetNavigation::CommPath(idl_CommNavPath.path)
		DomainRobotFleetNavigation::CommPath::getAllHashValues(hashes);
	}
	
	void CommNavPathCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommNavPathCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for DomainRobotFleetNavigation::CommPath(idl_CommNavPath.path)
		DomainRobotFleetNavigation::CommPath::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommNavPathCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		std::vector<DomainRobotFleetNavigationIDL::CommPath>::const_iterator data_pathIt;
		for(data_pathIt=data.path.begin(); data_pathIt!=data.path.end(); data_pathIt++) {
			seed += DomainRobotFleetNavigation::CommPath::generateDataHash(*data_pathIt);
		}
		
		return seed;
	}
	#endif
	
	// default constructor
	CommNavPathCore::CommNavPathCore()
	:	idl_CommNavPath()
	{  
		setPath(std::vector<DomainRobotFleetNavigation::CommPath>());
	}
	
	CommNavPathCore::CommNavPathCore(const DATATYPE &data)
	:	idl_CommNavPath(data)
	{  }

	CommNavPathCore::~CommNavPathCore()
	{  }
	
	void CommNavPathCore::to_ostream(std::ostream &os) const
	{
	  os << "CommNavPath(";
	  std::vector<DomainRobotFleetNavigation::CommPath>::const_iterator pathIt;
	  std::vector<DomainRobotFleetNavigation::CommPath> pathList = getPathCopy();
	  for(pathIt=pathList.begin(); pathIt!=pathList.end(); pathIt++) {
	  	pathIt->to_ostream(os);
	  }
	  os << ") ";
	}
	
	// convert to xml stream
	void CommNavPathCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		std::vector<DomainRobotFleetNavigation::CommPath>::const_iterator pathIt;
		std::vector<DomainRobotFleetNavigation::CommPath> pathList = getPathCopy();
		counter = 0;
		os << indent << "<pathList n=\"" << pathList.size() << "\">";
		for(pathIt=pathList.begin(); pathIt!=pathList.end(); pathIt++) {
			os << indent << "<path i=\"" << counter++ << "\">";
			pathIt->to_xml(os, indent);
			os << indent << "</path>";
		}
		os << indent << "</pathList>";
	}
	
	// restore from xml stream
	void CommNavPathCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_pathList("<pathList n=\"");
		static const Smart::KnuthMorrisPratt kmp_path("\">");
		
		if(kmp_pathList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			DomainRobotFleetNavigation::CommPath pathItem;
			std::vector<DomainRobotFleetNavigation::CommPath> pathList;
			kmp_path.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_path.search(is)) {
					pathItem.from_xml(is);
					pathList.push_back(pathItem);
				}
			}
			setPath(pathList);
		}
	}
	
	/*
	void CommNavPathCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		DomainRobotFleetNavigationIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(DomainRobotFleetNavigationIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommNavPathACE.hh)
		cdr << idl_CommNavPath;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommNavPath);
		cdr << data_hash;
		// std::cout << "CommNavPathCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommNavPathCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		DomainRobotFleetNavigationIDL::HashList hashes;
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
		// (see CommNavPathACE.hh)
		cdr >> idl_CommNavPath;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommNavPath);
		assert(data_hash == own_hash);
		// std::cout << "CommNavPathCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace DomainRobotFleetNavigation */