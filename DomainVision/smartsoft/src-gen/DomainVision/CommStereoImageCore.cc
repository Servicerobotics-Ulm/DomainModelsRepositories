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
#include "DomainVision/CommStereoImageCore.hh"

// serialization/deserialization operators
//#include "DomainVision/CommStereoImageACE.hh"

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

namespace DomainVision 
{
	const char* CommStereoImageCore::getCompiledHash()
	{
		return DomainVisionIDL::REPO_HASH;
	}
	
	void CommStereoImageCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for DomainVision::CommVideoImage(idl_CommStereoImage.left)
		DomainVision::CommVideoImage::getAllHashValues(hashes);
		// get hash value(s) for DomainVision::CommVideoImage(idl_CommStereoImage.right)
		DomainVision::CommVideoImage::getAllHashValues(hashes);
		// get hash value(s) for DomainVision::CommDisparityImage(idl_CommStereoImage.disparityMap)
		DomainVision::CommDisparityImage::getAllHashValues(hashes);
	}
	
	void CommStereoImageCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommStereoImageCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for DomainVision::CommVideoImage(idl_CommStereoImage.left)
		DomainVision::CommVideoImage::checkAllHashValues(hashes);
		// check hash value(s) for DomainVision::CommVideoImage(idl_CommStereoImage.right)
		DomainVision::CommVideoImage::checkAllHashValues(hashes);
		// check hash value(s) for DomainVision::CommDisparityImage(idl_CommStereoImage.disparityMap)
		DomainVision::CommDisparityImage::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommStereoImageCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		seed += DomainVision::CommVideoImage::generateDataHash(data.left);
		seed += DomainVision::CommVideoImage::generateDataHash(data.right);
		boost::hash_combine(seed, data.hasDispertyMap);
		seed += DomainVision::CommDisparityImage::generateDataHash(data.disparityMap);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommStereoImageCore::CommStereoImageCore()
	:	idl_CommStereoImage()
	{  
		setLeft(DomainVision::CommVideoImage());
		setRight(DomainVision::CommVideoImage());
		setHasDispertyMap(false);
		setDisparityMap(DomainVision::CommDisparityImage());
	}
	
	CommStereoImageCore::CommStereoImageCore(const DATATYPE &data)
	:	idl_CommStereoImage(data)
	{  }

	CommStereoImageCore::~CommStereoImageCore()
	{  }
	
	void CommStereoImageCore::to_ostream(std::ostream &os) const
	{
	  os << "CommStereoImage(";
	  getLeft().to_ostream(os);
	  getRight().to_ostream(os);
	  os << getHasDispertyMap() << " ";
	  getDisparityMap().to_ostream(os);
	  os << ") ";
	}
	
	// convert to xml stream
	void CommStereoImageCore::to_xml(std::ostream &os, const std::string &indent) const {
		os << indent << "<left>";
		getLeft().to_xml(os, indent);
		os << indent << "</left>";
		os << indent << "<right>";
		getRight().to_xml(os, indent);
		os << indent << "</right>";
		os << indent << "<hasDispertyMap>" << getHasDispertyMap() << "</hasDispertyMap>";
		os << indent << "<disparityMap>";
		getDisparityMap().to_xml(os, indent);
		os << indent << "</disparityMap>";
	}
	
	// restore from xml stream
	void CommStereoImageCore::from_xml(std::istream &is) {
		static const Smart::KnuthMorrisPratt kmp_left("<left>");
		static const Smart::KnuthMorrisPratt kmp_right("<right>");
		static const Smart::KnuthMorrisPratt kmp_hasDispertyMap("<hasDispertyMap>");
		static const Smart::KnuthMorrisPratt kmp_disparityMap("<disparityMap>");
		
		if(kmp_left.search(is)) {
			DomainVision::CommVideoImage leftItem;
			leftItem.from_xml(is);
			setLeft(leftItem);
		}
		if(kmp_right.search(is)) {
			DomainVision::CommVideoImage rightItem;
			rightItem.from_xml(is);
			setRight(rightItem);
		}
		if(kmp_hasDispertyMap.search(is)) {
			bool hasDispertyMapItem;
			is >> hasDispertyMapItem;
			setHasDispertyMap(hasDispertyMapItem);
		}
		if(kmp_disparityMap.search(is)) {
			DomainVision::CommDisparityImage disparityMapItem;
			disparityMapItem.from_xml(is);
			setDisparityMap(disparityMapItem);
		}
	}
	
	/*
	void CommStereoImageCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		DomainVisionIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(DomainVisionIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommStereoImageACE.hh)
		cdr << idl_CommStereoImage;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommStereoImage);
		cdr << data_hash;
		// std::cout << "CommStereoImageCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommStereoImageCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		DomainVisionIDL::HashList hashes;
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
		// (see CommStereoImageACE.hh)
		cdr >> idl_CommStereoImage;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommStereoImage);
		assert(data_hash == own_hash);
		// std::cout << "CommStereoImageCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace DomainVision */
