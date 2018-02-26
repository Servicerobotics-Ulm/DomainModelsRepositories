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
#include "CommBasicObjects/CommDataFileCore.hh"

// serialization/deserialization operators
//#include "CommBasicObjects/CommDataFileACE.hh"

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

namespace CommBasicObjects 
{
	const char* CommDataFileCore::getCompiledHash()
	{
		return CommBasicObjectsIDL::REPO_HASH;
	}
	
	void CommDataFileCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommBasicObjects::CommTimeStamp(idl_CommDataFile.timestamp)
		CommBasicObjects::CommTimeStamp::getAllHashValues(hashes);
	}
	
	void CommDataFileCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommDataFileCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommBasicObjects::CommTimeStamp(idl_CommDataFile.timestamp)
		CommBasicObjects::CommTimeStamp::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommDataFileCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		boost::hash_combine(seed, std::string(data.filename.c_str()));
		boost::hash_combine(seed, data.filesize);
		seed += CommBasicObjects::CommTimeStamp::generateDataHash(data.timestamp);
		std::vector<ACE_CDR::Char>::const_iterator data_dataIt;
		for(data_dataIt=data.data.begin(); data_dataIt!=data.data.end(); data_dataIt++) {
			boost::hash_combine(seed, *data_dataIt);
		}
		boost::hash_combine(seed, data.valid);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommDataFileCore::CommDataFileCore()
	:	idl_CommDataFile()
	{  
		setFilename("");
		setFilesize(0);
		setTimestamp(CommBasicObjects::CommTimeStamp());
		setData(std::vector<char>());
		setValid(false);
	}
	
	CommDataFileCore::CommDataFileCore(const DATATYPE &data)
	:	idl_CommDataFile(data)
	{  }

	CommDataFileCore::~CommDataFileCore()
	{  }
	
	void CommDataFileCore::to_ostream(std::ostream &os) const
	{
	  os << "CommDataFile(";
	  os << getFilename() << " ";
	  os << getFilesize() << " ";
	  getTimestamp().to_ostream(os);
	  std::vector<char>::const_iterator dataIt;
	  std::vector<char> dataList = getDataCopy();
	  for(dataIt=dataList.begin(); dataIt!=dataList.end(); dataIt++) {
	  	os << *dataIt << " ";
	  }
	  os << getValid() << " ";
	  os << ") ";
	}
	
	// convert to xml stream
	void CommDataFileCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		os << indent << "<filename>" << getFilename() << "</filename>";
		os << indent << "<filesize>" << getFilesize() << "</filesize>";
		os << indent << "<timestamp>";
		getTimestamp().to_xml(os, indent);
		os << indent << "</timestamp>";
		std::vector<char>::const_iterator dataIt;
		std::vector<char> dataList = getDataCopy();
		counter = 0;
		os << indent << "<dataList n=\"" << dataList.size() << "\">";
		for(dataIt=dataList.begin(); dataIt!=dataList.end(); dataIt++) {
			os << indent << "<data i=\"" << counter++ << "\">" << *dataIt << "</data>";
		}
		os << indent << "</dataList>";
		os << indent << "<valid>" << getValid() << "</valid>";
	}
	
	// restore from xml stream
	void CommDataFileCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_filename("<filename>");
		static const Smart::KnuthMorrisPratt kmp_filesize("<filesize>");
		static const Smart::KnuthMorrisPratt kmp_timestamp("<timestamp>");
		static const Smart::KnuthMorrisPratt kmp_dataList("<dataList n=\"");
		static const Smart::KnuthMorrisPratt kmp_data("\">");
		static const Smart::KnuthMorrisPratt kmp_valid("<valid>");
		
		if(kmp_filename.search(is)) {
			std::string filenameItem;
			is >> filenameItem;
			setFilename(filenameItem);
		}
		if(kmp_filesize.search(is)) {
			unsigned int filesizeItem;
			is >> filesizeItem;
			setFilesize(filesizeItem);
		}
		if(kmp_timestamp.search(is)) {
			CommBasicObjects::CommTimeStamp timestampItem;
			timestampItem.from_xml(is);
			setTimestamp(timestampItem);
		}
		if(kmp_dataList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			char dataItem;
			std::vector<char> dataList;
			kmp_data.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_data.search(is)) {
					is >> dataItem;
					dataList.push_back(dataItem);
				}
			}
			setData(dataList);
		}
		if(kmp_valid.search(is)) {
			bool validItem;
			is >> validItem;
			setValid(validItem);
		}
	}
	
	/*
	void CommDataFileCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		CommBasicObjectsIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(CommBasicObjectsIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommDataFileACE.hh)
		cdr << idl_CommDataFile;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommDataFile);
		cdr << data_hash;
		// std::cout << "CommDataFileCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommDataFileCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		CommBasicObjectsIDL::HashList hashes;
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
		// (see CommDataFileACE.hh)
		cdr >> idl_CommDataFile;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommDataFile);
		assert(data_hash == own_hash);
		// std::cout << "CommDataFileCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommBasicObjects */