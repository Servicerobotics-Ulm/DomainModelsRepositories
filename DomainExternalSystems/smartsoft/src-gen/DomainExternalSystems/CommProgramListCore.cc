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
#include "DomainExternalSystems/CommProgramListCore.hh"

// serialization/deserialization operators
//#include "DomainExternalSystems/CommProgramListACE.hh"

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
	const char* CommProgramListCore::getCompiledHash()
	{
		return DomainExternalSystemsIDL::REPO_HASH;
	}
	
	void CommProgramListCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for DomainExternalSystems::CommExternalProgram(idl_CommProgramList.programs)
		DomainExternalSystems::CommExternalProgram::getAllHashValues(hashes);
	}
	
	void CommProgramListCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommProgramListCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for DomainExternalSystems::CommExternalProgram(idl_CommProgramList.programs)
		DomainExternalSystems::CommExternalProgram::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommProgramListCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		std::vector<DomainExternalSystemsIDL::CommExternalProgram>::const_iterator data_programsIt;
		for(data_programsIt=data.programs.begin(); data_programsIt!=data.programs.end(); data_programsIt++) {
			seed += DomainExternalSystems::CommExternalProgram::generateDataHash(*data_programsIt);
		}
		boost::hash_combine(seed, data.isValid);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommProgramListCore::CommProgramListCore()
	:	idl_CommProgramList()
	{  
		setPrograms(std::vector<DomainExternalSystems::CommExternalProgram>());
		setIsValid(false);
	}
	
	CommProgramListCore::CommProgramListCore(const DATATYPE &data)
	:	idl_CommProgramList(data)
	{  }

	CommProgramListCore::~CommProgramListCore()
	{  }
	
	void CommProgramListCore::to_ostream(std::ostream &os) const
	{
	  os << "CommProgramList(";
	  std::vector<DomainExternalSystems::CommExternalProgram>::const_iterator programsIt;
	  std::vector<DomainExternalSystems::CommExternalProgram> programsList = getProgramsCopy();
	  for(programsIt=programsList.begin(); programsIt!=programsList.end(); programsIt++) {
	  	programsIt->to_ostream(os);
	  }
	  os << getIsValid() << " ";
	  os << ") ";
	}
	
	// convert to xml stream
	void CommProgramListCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		std::vector<DomainExternalSystems::CommExternalProgram>::const_iterator programsIt;
		std::vector<DomainExternalSystems::CommExternalProgram> programsList = getProgramsCopy();
		counter = 0;
		os << indent << "<programsList n=\"" << programsList.size() << "\">";
		for(programsIt=programsList.begin(); programsIt!=programsList.end(); programsIt++) {
			os << indent << "<programs i=\"" << counter++ << "\">";
			programsIt->to_xml(os, indent);
			os << indent << "</programs>";
		}
		os << indent << "</programsList>";
		os << indent << "<isValid>" << getIsValid() << "</isValid>";
	}
	
	// restore from xml stream
	void CommProgramListCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_programsList("<programsList n=\"");
		static const Smart::KnuthMorrisPratt kmp_programs("\">");
		static const Smart::KnuthMorrisPratt kmp_isValid("<isValid>");
		
		if(kmp_programsList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			DomainExternalSystems::CommExternalProgram programsItem;
			std::vector<DomainExternalSystems::CommExternalProgram> programsList;
			kmp_programs.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_programs.search(is)) {
					programsItem.from_xml(is);
					programsList.push_back(programsItem);
				}
			}
			setPrograms(programsList);
		}
		if(kmp_isValid.search(is)) {
			bool isValidItem;
			is >> isValidItem;
			setIsValid(isValidItem);
		}
	}
	
	/*
	void CommProgramListCore::get(ACE_Message_Block *&msg) const
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
		// (see CommProgramListACE.hh)
		cdr << idl_CommProgramList;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommProgramList);
		cdr << data_hash;
		// std::cout << "CommProgramListCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommProgramListCore::set(const ACE_Message_Block *msg)
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
		// (see CommProgramListACE.hh)
		cdr >> idl_CommProgramList;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommProgramList);
		assert(data_hash == own_hash);
		// std::cout << "CommProgramListCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace DomainExternalSystems */
