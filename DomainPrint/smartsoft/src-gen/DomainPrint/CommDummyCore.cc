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
#include "DomainPrint/CommDummyCore.hh"

// serialization/deserialization operators
//#include "DomainPrint/CommDummyACE.hh"

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

namespace DomainPrint 
{
	const char* CommDummyCore::getCompiledHash()
	{
		return DomainPrintIDL::REPO_HASH;
	}
	
	void CommDummyCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommBasicObjects::CommVoid(idl_CommDummy.dummy)
		CommBasicObjects::CommVoid::getAllHashValues(hashes);
	}
	
	void CommDummyCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommDummyCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommBasicObjects::CommVoid(idl_CommDummy.dummy)
		CommBasicObjects::CommVoid::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommDummyCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		seed += CommBasicObjects::CommVoid::generateDataHash(data.dummy);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommDummyCore::CommDummyCore()
	:	idl_CommDummy()
	{  
		setDummy(CommBasicObjects::CommVoid());
	}
	
	CommDummyCore::CommDummyCore(const DATATYPE &data)
	:	idl_CommDummy(data)
	{  }

	CommDummyCore::~CommDummyCore()
	{  }
	
	void CommDummyCore::to_ostream(std::ostream &os) const
	{
	  os << "CommDummy(";
	  getDummy().to_ostream(os);
	  os << ") ";
	}
	
	// convert to xml stream
	void CommDummyCore::to_xml(std::ostream &os, const std::string &indent) const {
		os << indent << "<dummy>";
		getDummy().to_xml(os, indent);
		os << indent << "</dummy>";
	}
	
	// restore from xml stream
	void CommDummyCore::from_xml(std::istream &is) {
		static const Smart::KnuthMorrisPratt kmp_dummy("<dummy>");
		
		if(kmp_dummy.search(is)) {
			CommBasicObjects::CommVoid dummyItem;
			dummyItem.from_xml(is);
			setDummy(dummyItem);
		}
	}
	
	/*
	void CommDummyCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		DomainPrintIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(DomainPrintIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommDummyACE.hh)
		cdr << idl_CommDummy;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommDummy);
		cdr << data_hash;
		// std::cout << "CommDummyCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommDummyCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		DomainPrintIDL::HashList hashes;
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
		// (see CommDummyACE.hh)
		cdr >> idl_CommDummy;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommDummy);
		assert(data_hash == own_hash);
		// std::cout << "CommDummyCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace DomainPrint */