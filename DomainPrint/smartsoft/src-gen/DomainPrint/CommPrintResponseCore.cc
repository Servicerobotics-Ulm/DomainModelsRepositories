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
#include "DomainPrint/CommPrintResponseCore.hh"

// serialization/deserialization operators
//#include "DomainPrint/CommPrintResponseACE.hh"

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
	const char* CommPrintResponseCore::getCompiledHash()
	{
		return DomainPrintIDL::REPO_HASH;
	}
	
	void CommPrintResponseCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
	}
	
	void CommPrintResponseCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommPrintResponseCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
	}
	
	#ifdef ENABLE_HASH
	size_t CommPrintResponseCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		boost::hash_combine(seed, std::string(data.resultValue.c_str()));
		boost::hash_combine(seed, data.result);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommPrintResponseCore::CommPrintResponseCore()
	:	idl_CommPrintResponse()
	{  
		setResultValue("");
		setResult(DomainPrint::PrintResponseResultEnum());
	}
	
	CommPrintResponseCore::CommPrintResponseCore(const DATATYPE &data)
	:	idl_CommPrintResponse(data)
	{  }

	CommPrintResponseCore::~CommPrintResponseCore()
	{  }
	
	void CommPrintResponseCore::to_ostream(std::ostream &os) const
	{
	  os << "CommPrintResponse(";
	  os << getResultValue() << " ";
	  getResult().to_ostream(os);
	  os << ") ";
	}
	
	// convert to xml stream
	void CommPrintResponseCore::to_xml(std::ostream &os, const std::string &indent) const {
		os << indent << "<resultValue>" << getResultValue() << "</resultValue>";
		os << indent << "<result>";
		getResult().to_xml(os, indent);
		os << indent << "</result>";
	}
	
	// restore from xml stream
	void CommPrintResponseCore::from_xml(std::istream &is) {
		static const Smart::KnuthMorrisPratt kmp_resultValue("<resultValue>");
		static const Smart::KnuthMorrisPratt kmp_result("<result>");
		
		if(kmp_resultValue.search(is)) {
			std::string resultValueItem;
			is >> resultValueItem;
			setResultValue(resultValueItem);
		}
		if(kmp_result.search(is)) {
			DomainPrint::PrintResponseResultEnum resultItem;
			resultItem.from_xml(is);
			setResult(resultItem);
		}
	}
	
	/*
	void CommPrintResponseCore::get(ACE_Message_Block *&msg) const
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
		// (see CommPrintResponseACE.hh)
		cdr << idl_CommPrintResponse;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommPrintResponse);
		cdr << data_hash;
		// std::cout << "CommPrintResponseCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommPrintResponseCore::set(const ACE_Message_Block *msg)
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
		// (see CommPrintResponseACE.hh)
		cdr >> idl_CommPrintResponse;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommPrintResponse);
		assert(data_hash == own_hash);
		// std::cout << "CommPrintResponseCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace DomainPrint */
