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
#include "CommBasicObjects/CommPosition3dWithCovarianceCore.hh"

// serialization/deserialization operators
//#include "CommBasicObjects/CommPosition3dWithCovarianceACE.hh"

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
	const char* CommPosition3dWithCovarianceCore::getCompiledHash()
	{
		return CommBasicObjectsIDL::REPO_HASH;
	}
	
	void CommPosition3dWithCovarianceCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommBasicObjects::CommPosition3d(idl_CommPosition3dWithCovariance.position)
		CommBasicObjects::CommPosition3d::getAllHashValues(hashes);
	}
	
	void CommPosition3dWithCovarianceCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommPosition3dWithCovarianceCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommBasicObjects::CommPosition3d(idl_CommPosition3dWithCovariance.position)
		CommBasicObjects::CommPosition3d::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommPosition3dWithCovarianceCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		seed += CommBasicObjects::CommPosition3d::generateDataHash(data.position);
		std::vector<ACE_CDR::Double>::const_iterator data_covMatrixIt;
		for(data_covMatrixIt=data.covMatrix.begin(); data_covMatrixIt!=data.covMatrix.end(); data_covMatrixIt++) {
			boost::hash_combine(seed, *data_covMatrixIt);
		}
		
		return seed;
	}
	#endif
	
	// default constructor
	CommPosition3dWithCovarianceCore::CommPosition3dWithCovarianceCore()
	:	idl_CommPosition3dWithCovariance()
	{  
		setPosition(CommBasicObjects::CommPosition3d());
		setCovMatrix(std::vector<double>());
	}
	
	CommPosition3dWithCovarianceCore::CommPosition3dWithCovarianceCore(const DATATYPE &data)
	:	idl_CommPosition3dWithCovariance(data)
	{  }

	CommPosition3dWithCovarianceCore::~CommPosition3dWithCovarianceCore()
	{  }
	
	void CommPosition3dWithCovarianceCore::to_ostream(std::ostream &os) const
	{
	  os << "CommPosition3dWithCovariance(";
	  getPosition().to_ostream(os);
	  std::vector<double>::const_iterator covMatrixIt;
	  std::vector<double> covMatrixList = getCovMatrixCopy();
	  for(covMatrixIt=covMatrixList.begin(); covMatrixIt!=covMatrixList.end(); covMatrixIt++) {
	  	os << *covMatrixIt << " ";
	  }
	  os << ") ";
	}
	
	// convert to xml stream
	void CommPosition3dWithCovarianceCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		os << indent << "<position>";
		getPosition().to_xml(os, indent);
		os << indent << "</position>";
		std::vector<double>::const_iterator covMatrixIt;
		std::vector<double> covMatrixList = getCovMatrixCopy();
		counter = 0;
		os << indent << "<covMatrixList n=\"" << covMatrixList.size() << "\">";
		for(covMatrixIt=covMatrixList.begin(); covMatrixIt!=covMatrixList.end(); covMatrixIt++) {
			os << indent << "<covMatrix i=\"" << counter++ << "\">" << *covMatrixIt << "</covMatrix>";
		}
		os << indent << "</covMatrixList>";
	}
	
	// restore from xml stream
	void CommPosition3dWithCovarianceCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_position("<position>");
		static const Smart::KnuthMorrisPratt kmp_covMatrixList("<covMatrixList n=\"");
		static const Smart::KnuthMorrisPratt kmp_covMatrix("\">");
		
		if(kmp_position.search(is)) {
			CommBasicObjects::CommPosition3d positionItem;
			positionItem.from_xml(is);
			setPosition(positionItem);
		}
		if(kmp_covMatrixList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			double covMatrixItem;
			std::vector<double> covMatrixList;
			kmp_covMatrix.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_covMatrix.search(is)) {
					is >> covMatrixItem;
					covMatrixList.push_back(covMatrixItem);
				}
			}
			setCovMatrix(covMatrixList);
		}
	}
	
	/*
	void CommPosition3dWithCovarianceCore::get(ACE_Message_Block *&msg) const
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
		// (see CommPosition3dWithCovarianceACE.hh)
		cdr << idl_CommPosition3dWithCovariance;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommPosition3dWithCovariance);
		cdr << data_hash;
		// std::cout << "CommPosition3dWithCovarianceCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommPosition3dWithCovarianceCore::set(const ACE_Message_Block *msg)
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
		// (see CommPosition3dWithCovarianceACE.hh)
		cdr >> idl_CommPosition3dWithCovariance;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommPosition3dWithCovariance);
		assert(data_hash == own_hash);
		// std::cout << "CommPosition3dWithCovarianceCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommBasicObjects */
