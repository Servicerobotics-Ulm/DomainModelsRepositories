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
#include "DomainExternalSystems/CommExternalProgramResponseCore.hh"

// serialization/deserialization operators
//#include "DomainExternalSystems/CommExternalProgramResponseACE.hh"

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

namespace DomainExternalSystems 
{
	const char* CommExternalProgramResponseCore::getCompiledHash()
	{
		return DomainExternalSystemsIDL::REPO_HASH;
	}
	
	void CommExternalProgramResponseCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for DomainExternalSystems::CommExternalProgramArgument(idl_CommExternalProgramResponse.resultArgs)
		DomainExternalSystems::CommExternalProgramArgument::getAllHashValues(hashes);
	}
	
	void CommExternalProgramResponseCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommExternalProgramResponseCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for DomainExternalSystems::CommExternalProgramArgument(idl_CommExternalProgramResponse.resultArgs)
		DomainExternalSystems::CommExternalProgramArgument::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommExternalProgramResponseCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		boost::hash_combine(seed, data.status);
		boost::hash_combine(seed, data.result);
		std::vector<DomainExternalSystemsIDL::CommExternalProgramArgument>::const_iterator data_resultArgsIt;
		for(data_resultArgsIt=data.resultArgs.begin(); data_resultArgsIt!=data.resultArgs.end(); data_resultArgsIt++) {
			seed += DomainExternalSystems::CommExternalProgramArgument::generateDataHash(*data_resultArgsIt);
		}
		
		return seed;
	}
	#endif
	
	// default constructor
	CommExternalProgramResponseCore::CommExternalProgramResponseCore()
	:	idl_CommExternalProgramResponse()
	{  
		setStatus(DomainExternalSystems::ExternalProgramStatus());
		setResult(DomainExternalSystems::ExternalProgramResult());
		setResultArgs(std::vector<DomainExternalSystems::CommExternalProgramArgument>());
	}
	
	CommExternalProgramResponseCore::CommExternalProgramResponseCore(const DATATYPE &data)
	:	idl_CommExternalProgramResponse(data)
	{  }

	CommExternalProgramResponseCore::~CommExternalProgramResponseCore()
	{  }
	
	void CommExternalProgramResponseCore::to_ostream(std::ostream &os) const
	{
	  os << "CommExternalProgramResponse(";
	  getStatus().to_ostream(os);
	  getResult().to_ostream(os);
	  std::vector<DomainExternalSystems::CommExternalProgramArgument>::const_iterator resultArgsIt;
	  std::vector<DomainExternalSystems::CommExternalProgramArgument> resultArgsList = getResultArgsCopy();
	  for(resultArgsIt=resultArgsList.begin(); resultArgsIt!=resultArgsList.end(); resultArgsIt++) {
	  	resultArgsIt->to_ostream(os);
	  }
	  os << ") ";
	}
	
	// convert to xml stream
	void CommExternalProgramResponseCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		os << indent << "<status>";
		getStatus().to_xml(os, indent);
		os << indent << "</status>";
		os << indent << "<result>";
		getResult().to_xml(os, indent);
		os << indent << "</result>";
		std::vector<DomainExternalSystems::CommExternalProgramArgument>::const_iterator resultArgsIt;
		std::vector<DomainExternalSystems::CommExternalProgramArgument> resultArgsList = getResultArgsCopy();
		counter = 0;
		os << indent << "<resultArgsList n=\"" << resultArgsList.size() << "\">";
		for(resultArgsIt=resultArgsList.begin(); resultArgsIt!=resultArgsList.end(); resultArgsIt++) {
			os << indent << "<resultArgs i=\"" << counter++ << "\">";
			resultArgsIt->to_xml(os, indent);
			os << indent << "</resultArgs>";
		}
		os << indent << "</resultArgsList>";
	}
	
	// restore from xml stream
	void CommExternalProgramResponseCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_status("<status>");
		static const Smart::KnuthMorrisPratt kmp_result("<result>");
		static const Smart::KnuthMorrisPratt kmp_resultArgsList("<resultArgsList n=\"");
		static const Smart::KnuthMorrisPratt kmp_resultArgs("\">");
		
		if(kmp_status.search(is)) {
			DomainExternalSystems::ExternalProgramStatus statusItem;
			statusItem.from_xml(is);
			setStatus(statusItem);
		}
		if(kmp_result.search(is)) {
			DomainExternalSystems::ExternalProgramResult resultItem;
			resultItem.from_xml(is);
			setResult(resultItem);
		}
		if(kmp_resultArgsList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			DomainExternalSystems::CommExternalProgramArgument resultArgsItem;
			std::vector<DomainExternalSystems::CommExternalProgramArgument> resultArgsList;
			kmp_resultArgs.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_resultArgs.search(is)) {
					resultArgsItem.from_xml(is);
					resultArgsList.push_back(resultArgsItem);
				}
			}
			setResultArgs(resultArgsList);
		}
	}
	
	/*
	void CommExternalProgramResponseCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		DomainExternalSystemsIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(DomainExternalSystemsIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommExternalProgramResponseACE.hh)
		cdr << idl_CommExternalProgramResponse;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommExternalProgramResponse);
		cdr << data_hash;
		// std::cout << "CommExternalProgramResponseCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommExternalProgramResponseCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		DomainExternalSystemsIDL::HashList hashes;
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
		// (see CommExternalProgramResponseACE.hh)
		cdr >> idl_CommExternalProgramResponse;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommExternalProgramResponse);
		assert(data_hash == own_hash);
		// std::cout << "CommExternalProgramResponseCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace DomainExternalSystems */
