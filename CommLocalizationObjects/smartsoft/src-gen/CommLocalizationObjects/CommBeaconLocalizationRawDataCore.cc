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
#include "CommLocalizationObjects/CommBeaconLocalizationRawDataCore.hh"

// serialization/deserialization operators
//#include "CommLocalizationObjects/CommBeaconLocalizationRawDataACE.hh"

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

namespace CommLocalizationObjects 
{
	const char* CommBeaconLocalizationRawDataCore::getCompiledHash()
	{
		return CommLocalizationObjectsIDL::REPO_HASH;
	}
	
	void CommBeaconLocalizationRawDataCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommLocalizationObjects::CommBeaconMeasurement(idl_CommBeaconLocalizationRawData.measurements)
		CommLocalizationObjects::CommBeaconMeasurement::getAllHashValues(hashes);
	}
	
	void CommBeaconLocalizationRawDataCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommBeaconLocalizationRawDataCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommLocalizationObjects::CommBeaconMeasurement(idl_CommBeaconLocalizationRawData.measurements)
		CommLocalizationObjects::CommBeaconMeasurement::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommBeaconLocalizationRawDataCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		std::vector<CommLocalizationObjectsIDL::CommBeaconMeasurement>::const_iterator data_measurementsIt;
		for(data_measurementsIt=data.measurements.begin(); data_measurementsIt!=data.measurements.end(); data_measurementsIt++) {
			seed += CommLocalizationObjects::CommBeaconMeasurement::generateDataHash(*data_measurementsIt);
		}
		
		return seed;
	}
	#endif
	
	// default constructor
	CommBeaconLocalizationRawDataCore::CommBeaconLocalizationRawDataCore()
	:	idl_CommBeaconLocalizationRawData()
	{  
		setMeasurements(std::vector<CommLocalizationObjects::CommBeaconMeasurement>());
	}
	
	CommBeaconLocalizationRawDataCore::CommBeaconLocalizationRawDataCore(const DATATYPE &data)
	:	idl_CommBeaconLocalizationRawData(data)
	{  }

	CommBeaconLocalizationRawDataCore::~CommBeaconLocalizationRawDataCore()
	{  }
	
	void CommBeaconLocalizationRawDataCore::to_ostream(std::ostream &os) const
	{
	  os << "CommBeaconLocalizationRawData(";
	  std::vector<CommLocalizationObjects::CommBeaconMeasurement>::const_iterator measurementsIt;
	  std::vector<CommLocalizationObjects::CommBeaconMeasurement> measurementsList = getMeasurementsCopy();
	  for(measurementsIt=measurementsList.begin(); measurementsIt!=measurementsList.end(); measurementsIt++) {
	  	measurementsIt->to_ostream(os);
	  }
	  os << ") ";
	}
	
	// convert to xml stream
	void CommBeaconLocalizationRawDataCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		std::vector<CommLocalizationObjects::CommBeaconMeasurement>::const_iterator measurementsIt;
		std::vector<CommLocalizationObjects::CommBeaconMeasurement> measurementsList = getMeasurementsCopy();
		counter = 0;
		os << indent << "<measurementsList n=\"" << measurementsList.size() << "\">";
		for(measurementsIt=measurementsList.begin(); measurementsIt!=measurementsList.end(); measurementsIt++) {
			os << indent << "<measurements i=\"" << counter++ << "\">";
			measurementsIt->to_xml(os, indent);
			os << indent << "</measurements>";
		}
		os << indent << "</measurementsList>";
	}
	
	// restore from xml stream
	void CommBeaconLocalizationRawDataCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_measurementsList("<measurementsList n=\"");
		static const Smart::KnuthMorrisPratt kmp_measurements("\">");
		
		if(kmp_measurementsList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			CommLocalizationObjects::CommBeaconMeasurement measurementsItem;
			std::vector<CommLocalizationObjects::CommBeaconMeasurement> measurementsList;
			kmp_measurements.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_measurements.search(is)) {
					measurementsItem.from_xml(is);
					measurementsList.push_back(measurementsItem);
				}
			}
			setMeasurements(measurementsList);
		}
	}
	
	/*
	void CommBeaconLocalizationRawDataCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		CommLocalizationObjectsIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(CommLocalizationObjectsIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommBeaconLocalizationRawDataACE.hh)
		cdr << idl_CommBeaconLocalizationRawData;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommBeaconLocalizationRawData);
		cdr << data_hash;
		// std::cout << "CommBeaconLocalizationRawDataCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommBeaconLocalizationRawDataCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		CommLocalizationObjectsIDL::HashList hashes;
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
		// (see CommBeaconLocalizationRawDataACE.hh)
		cdr >> idl_CommBeaconLocalizationRawData;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommBeaconLocalizationRawData);
		assert(data_hash == own_hash);
		// std::cout << "CommBeaconLocalizationRawDataCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommLocalizationObjects */