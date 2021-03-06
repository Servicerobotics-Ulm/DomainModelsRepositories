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
#include "CommNavigationObjects/CommCorridorNetworkLayoutCore.hh"

// serialization/deserialization operators
//#include "CommNavigationObjects/CommCorridorNetworkLayoutACE.hh"

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
	const char* CommCorridorNetworkLayoutCore::getCompiledHash()
	{
		return CommNavigationObjectsIDL::REPO_HASH;
	}
	
	void CommCorridorNetworkLayoutCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommNavigationObjects::CommCorridorNetworkStatus(idl_CommCorridorNetworkLayout.networkStatus)
		CommNavigationObjects::CommCorridorNetworkStatus::getAllHashValues(hashes);
		// get hash value(s) for CommBasicObjects::CommDataFile(idl_CommCorridorNetworkLayout.layoutFile)
		CommBasicObjects::CommDataFile::getAllHashValues(hashes);
	}
	
	void CommCorridorNetworkLayoutCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommCorridorNetworkLayoutCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommNavigationObjects::CommCorridorNetworkStatus(idl_CommCorridorNetworkLayout.networkStatus)
		CommNavigationObjects::CommCorridorNetworkStatus::checkAllHashValues(hashes);
		// check hash value(s) for CommBasicObjects::CommDataFile(idl_CommCorridorNetworkLayout.layoutFile)
		CommBasicObjects::CommDataFile::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommCorridorNetworkLayoutCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		seed += CommNavigationObjects::CommCorridorNetworkStatus::generateDataHash(data.networkStatus);
		seed += CommBasicObjects::CommDataFile::generateDataHash(data.layoutFile);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommCorridorNetworkLayoutCore::CommCorridorNetworkLayoutCore()
	:	idl_CommCorridorNetworkLayout()
	{  
		setNetworkStatus(CommNavigationObjects::CommCorridorNetworkStatus());
		setLayoutFile(CommBasicObjects::CommDataFile());
	}
	
	CommCorridorNetworkLayoutCore::CommCorridorNetworkLayoutCore(const DATATYPE &data)
	:	idl_CommCorridorNetworkLayout(data)
	{  }

	CommCorridorNetworkLayoutCore::~CommCorridorNetworkLayoutCore()
	{  }
	
	void CommCorridorNetworkLayoutCore::to_ostream(std::ostream &os) const
	{
	  os << "CommCorridorNetworkLayout(";
	  getNetworkStatus().to_ostream(os);
	  getLayoutFile().to_ostream(os);
	  os << ") ";
	}
	
	// convert to xml stream
	void CommCorridorNetworkLayoutCore::to_xml(std::ostream &os, const std::string &indent) const {
		os << indent << "<networkStatus>";
		getNetworkStatus().to_xml(os, indent);
		os << indent << "</networkStatus>";
		os << indent << "<layoutFile>";
		getLayoutFile().to_xml(os, indent);
		os << indent << "</layoutFile>";
	}
	
	// restore from xml stream
	void CommCorridorNetworkLayoutCore::from_xml(std::istream &is) {
		static const Smart::KnuthMorrisPratt kmp_networkStatus("<networkStatus>");
		static const Smart::KnuthMorrisPratt kmp_layoutFile("<layoutFile>");
		
		if(kmp_networkStatus.search(is)) {
			CommNavigationObjects::CommCorridorNetworkStatus networkStatusItem;
			networkStatusItem.from_xml(is);
			setNetworkStatus(networkStatusItem);
		}
		if(kmp_layoutFile.search(is)) {
			CommBasicObjects::CommDataFile layoutFileItem;
			layoutFileItem.from_xml(is);
			setLayoutFile(layoutFileItem);
		}
	}
	
	/*
	void CommCorridorNetworkLayoutCore::get(ACE_Message_Block *&msg) const
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
		// (see CommCorridorNetworkLayoutACE.hh)
		cdr << idl_CommCorridorNetworkLayout;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommCorridorNetworkLayout);
		cdr << data_hash;
		// std::cout << "CommCorridorNetworkLayoutCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommCorridorNetworkLayoutCore::set(const ACE_Message_Block *msg)
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
		// (see CommCorridorNetworkLayoutACE.hh)
		cdr >> idl_CommCorridorNetworkLayout;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommCorridorNetworkLayout);
		assert(data_hash == own_hash);
		// std::cout << "CommCorridorNetworkLayoutCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommNavigationObjects */
