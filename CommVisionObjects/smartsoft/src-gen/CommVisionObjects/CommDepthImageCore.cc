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
#include "CommVisionObjects/CommDepthImageCore.hh"

// serialization/deserialization operators
//#include "CommVisionObjects/CommDepthImageACE.hh"

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

namespace CommVisionObjects 
{
	const char* CommDepthImageCore::getCompiledHash()
	{
		return CommVisionObjectsIDL::REPO_HASH;
	}
	
	void CommDepthImageCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
	}
	
	void CommDepthImageCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommDepthImageCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
	}
	
	#ifdef ENABLE_HASH
	size_t CommDepthImageCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		boost::hash_combine(seed, data.width);
		boost::hash_combine(seed, data.height);
		boost::hash_combine(seed, data.format);
		boost::hash_combine(seed, data.pixel_size);
		boost::hash_combine(seed, data.min_distcance);
		boost::hash_combine(seed, data.max_distcance);
		std::vector<ACE_CDR::Octet>::const_iterator data_dataIt;
		for(data_dataIt=data.data.begin(); data_dataIt!=data.data.end(); data_dataIt++) {
			boost::hash_combine(seed, *data_dataIt);
		}
		std::vector<ACE_CDR::Double>::const_iterator data_intrinsic_mIt;
		for(data_intrinsic_mIt=data.intrinsic_m.begin(); data_intrinsic_mIt!=data.intrinsic_m.end(); data_intrinsic_mIt++) {
			boost::hash_combine(seed, *data_intrinsic_mIt);
		}
		std::vector<ACE_CDR::Double>::const_iterator data_extrinsic_mIt;
		for(data_extrinsic_mIt=data.extrinsic_m.begin(); data_extrinsic_mIt!=data.extrinsic_m.end(); data_extrinsic_mIt++) {
			boost::hash_combine(seed, *data_extrinsic_mIt);
		}
		std::vector<ACE_CDR::Double>::const_iterator data_stereo_mIt;
		for(data_stereo_mIt=data.stereo_m.begin(); data_stereo_mIt!=data.stereo_m.end(); data_stereo_mIt++) {
			boost::hash_combine(seed, *data_stereo_mIt);
		}
		std::vector<ACE_CDR::Double>::const_iterator data_distortion_mIt;
		for(data_distortion_mIt=data.distortion_m.begin(); data_distortion_mIt!=data.distortion_m.end(); data_distortion_mIt++) {
			boost::hash_combine(seed, *data_distortion_mIt);
		}
		boost::hash_combine(seed, data.distortion_model);
		boost::hash_combine(seed, data.seq_count);
		boost::hash_combine(seed, data.is_valid);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommDepthImageCore::CommDepthImageCore()
	:	idl_CommDepthImage()
	{  
		setWidth(0);
		setHeight(0);
		setFormat(CommVisionObjects::DepthFormatType());
		setPixel_size(0);
		setMin_distcance(0.0);
		setMax_distcance(0.0);
		setData(std::vector<unsigned char>());
		setIntrinsic_m(std::vector<double>());
		setExtrinsic_m(std::vector<double>());
		setStereo_m(std::vector<double>());
		setDistortion_m(std::vector<double>());
		setDistortion_model(CommVisionObjects::ImageDistortionModel());
		setSeq_count(0);
		setIs_valid(false);
	}
	
	CommDepthImageCore::CommDepthImageCore(const DATATYPE &data)
	:	idl_CommDepthImage(data)
	{  }

	CommDepthImageCore::~CommDepthImageCore()
	{  }
	
	void CommDepthImageCore::to_ostream(std::ostream &os) const
	{
	  os << "CommDepthImage(";
	  os << getWidth() << " ";
	  os << getHeight() << " ";
	  getFormat().to_ostream(os);
	  os << getPixel_size() << " ";
	  os << getMin_distcance() << " ";
	  os << getMax_distcance() << " ";
	  std::vector<unsigned char>::const_iterator dataIt;
	  std::vector<unsigned char> dataList = getDataCopy();
	  for(dataIt=dataList.begin(); dataIt!=dataList.end(); dataIt++) {
	  	os << *dataIt << " ";
	  }
	  std::vector<double>::const_iterator intrinsic_mIt;
	  std::vector<double> intrinsic_mList = getIntrinsic_mCopy();
	  for(intrinsic_mIt=intrinsic_mList.begin(); intrinsic_mIt!=intrinsic_mList.end(); intrinsic_mIt++) {
	  	os << *intrinsic_mIt << " ";
	  }
	  std::vector<double>::const_iterator extrinsic_mIt;
	  std::vector<double> extrinsic_mList = getExtrinsic_mCopy();
	  for(extrinsic_mIt=extrinsic_mList.begin(); extrinsic_mIt!=extrinsic_mList.end(); extrinsic_mIt++) {
	  	os << *extrinsic_mIt << " ";
	  }
	  std::vector<double>::const_iterator stereo_mIt;
	  std::vector<double> stereo_mList = getStereo_mCopy();
	  for(stereo_mIt=stereo_mList.begin(); stereo_mIt!=stereo_mList.end(); stereo_mIt++) {
	  	os << *stereo_mIt << " ";
	  }
	  std::vector<double>::const_iterator distortion_mIt;
	  std::vector<double> distortion_mList = getDistortion_mCopy();
	  for(distortion_mIt=distortion_mList.begin(); distortion_mIt!=distortion_mList.end(); distortion_mIt++) {
	  	os << *distortion_mIt << " ";
	  }
	  getDistortion_model().to_ostream(os);
	  os << getSeq_count() << " ";
	  os << getIs_valid() << " ";
	  os << ") ";
	}
	
	// convert to xml stream
	void CommDepthImageCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		os << indent << "<width>" << getWidth() << "</width>";
		os << indent << "<height>" << getHeight() << "</height>";
		os << indent << "<format>";
		getFormat().to_xml(os, indent);
		os << indent << "</format>";
		os << indent << "<pixel_size>" << getPixel_size() << "</pixel_size>";
		os << indent << "<min_distcance>" << getMin_distcance() << "</min_distcance>";
		os << indent << "<max_distcance>" << getMax_distcance() << "</max_distcance>";
		std::vector<unsigned char>::const_iterator dataIt;
		std::vector<unsigned char> dataList = getDataCopy();
		counter = 0;
		os << indent << "<dataList n=\"" << dataList.size() << "\">";
		for(dataIt=dataList.begin(); dataIt!=dataList.end(); dataIt++) {
			os << indent << "<data i=\"" << counter++ << "\">" << *dataIt << "</data>";
		}
		os << indent << "</dataList>";
		std::vector<double>::const_iterator intrinsic_mIt;
		std::vector<double> intrinsic_mList = getIntrinsic_mCopy();
		counter = 0;
		os << indent << "<intrinsic_mList n=\"" << intrinsic_mList.size() << "\">";
		for(intrinsic_mIt=intrinsic_mList.begin(); intrinsic_mIt!=intrinsic_mList.end(); intrinsic_mIt++) {
			os << indent << "<intrinsic_m i=\"" << counter++ << "\">" << *intrinsic_mIt << "</intrinsic_m>";
		}
		os << indent << "</intrinsic_mList>";
		std::vector<double>::const_iterator extrinsic_mIt;
		std::vector<double> extrinsic_mList = getExtrinsic_mCopy();
		counter = 0;
		os << indent << "<extrinsic_mList n=\"" << extrinsic_mList.size() << "\">";
		for(extrinsic_mIt=extrinsic_mList.begin(); extrinsic_mIt!=extrinsic_mList.end(); extrinsic_mIt++) {
			os << indent << "<extrinsic_m i=\"" << counter++ << "\">" << *extrinsic_mIt << "</extrinsic_m>";
		}
		os << indent << "</extrinsic_mList>";
		std::vector<double>::const_iterator stereo_mIt;
		std::vector<double> stereo_mList = getStereo_mCopy();
		counter = 0;
		os << indent << "<stereo_mList n=\"" << stereo_mList.size() << "\">";
		for(stereo_mIt=stereo_mList.begin(); stereo_mIt!=stereo_mList.end(); stereo_mIt++) {
			os << indent << "<stereo_m i=\"" << counter++ << "\">" << *stereo_mIt << "</stereo_m>";
		}
		os << indent << "</stereo_mList>";
		std::vector<double>::const_iterator distortion_mIt;
		std::vector<double> distortion_mList = getDistortion_mCopy();
		counter = 0;
		os << indent << "<distortion_mList n=\"" << distortion_mList.size() << "\">";
		for(distortion_mIt=distortion_mList.begin(); distortion_mIt!=distortion_mList.end(); distortion_mIt++) {
			os << indent << "<distortion_m i=\"" << counter++ << "\">" << *distortion_mIt << "</distortion_m>";
		}
		os << indent << "</distortion_mList>";
		os << indent << "<distortion_model>";
		getDistortion_model().to_xml(os, indent);
		os << indent << "</distortion_model>";
		os << indent << "<seq_count>" << getSeq_count() << "</seq_count>";
		os << indent << "<is_valid>" << getIs_valid() << "</is_valid>";
	}
	
	// restore from xml stream
	void CommDepthImageCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_width("<width>");
		static const Smart::KnuthMorrisPratt kmp_height("<height>");
		static const Smart::KnuthMorrisPratt kmp_format("<format>");
		static const Smart::KnuthMorrisPratt kmp_pixel_size("<pixel_size>");
		static const Smart::KnuthMorrisPratt kmp_min_distcance("<min_distcance>");
		static const Smart::KnuthMorrisPratt kmp_max_distcance("<max_distcance>");
		static const Smart::KnuthMorrisPratt kmp_dataList("<dataList n=\"");
		static const Smart::KnuthMorrisPratt kmp_data("\">");
		static const Smart::KnuthMorrisPratt kmp_intrinsic_mList("<intrinsic_mList n=\"");
		static const Smart::KnuthMorrisPratt kmp_intrinsic_m("\">");
		static const Smart::KnuthMorrisPratt kmp_extrinsic_mList("<extrinsic_mList n=\"");
		static const Smart::KnuthMorrisPratt kmp_extrinsic_m("\">");
		static const Smart::KnuthMorrisPratt kmp_stereo_mList("<stereo_mList n=\"");
		static const Smart::KnuthMorrisPratt kmp_stereo_m("\">");
		static const Smart::KnuthMorrisPratt kmp_distortion_mList("<distortion_mList n=\"");
		static const Smart::KnuthMorrisPratt kmp_distortion_m("\">");
		static const Smart::KnuthMorrisPratt kmp_distortion_model("<distortion_model>");
		static const Smart::KnuthMorrisPratt kmp_seq_count("<seq_count>");
		static const Smart::KnuthMorrisPratt kmp_is_valid("<is_valid>");
		
		if(kmp_width.search(is)) {
			unsigned int widthItem;
			is >> widthItem;
			setWidth(widthItem);
		}
		if(kmp_height.search(is)) {
			unsigned int heightItem;
			is >> heightItem;
			setHeight(heightItem);
		}
		if(kmp_format.search(is)) {
			CommVisionObjects::DepthFormatType formatItem;
			formatItem.from_xml(is);
			setFormat(formatItem);
		}
		if(kmp_pixel_size.search(is)) {
			unsigned int pixel_sizeItem;
			is >> pixel_sizeItem;
			setPixel_size(pixel_sizeItem);
		}
		if(kmp_min_distcance.search(is)) {
			double min_distcanceItem;
			is >> min_distcanceItem;
			setMin_distcance(min_distcanceItem);
		}
		if(kmp_max_distcance.search(is)) {
			double max_distcanceItem;
			is >> max_distcanceItem;
			setMax_distcance(max_distcanceItem);
		}
		if(kmp_dataList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			unsigned char dataItem;
			std::vector<unsigned char> dataList;
			kmp_data.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_data.search(is)) {
					is >> dataItem;
					dataList.push_back(dataItem);
				}
			}
			setData(dataList);
		}
		if(kmp_intrinsic_mList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			double intrinsic_mItem;
			std::vector<double> intrinsic_mList;
			kmp_intrinsic_m.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_intrinsic_m.search(is)) {
					is >> intrinsic_mItem;
					intrinsic_mList.push_back(intrinsic_mItem);
				}
			}
			setIntrinsic_m(intrinsic_mList);
		}
		if(kmp_extrinsic_mList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			double extrinsic_mItem;
			std::vector<double> extrinsic_mList;
			kmp_extrinsic_m.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_extrinsic_m.search(is)) {
					is >> extrinsic_mItem;
					extrinsic_mList.push_back(extrinsic_mItem);
				}
			}
			setExtrinsic_m(extrinsic_mList);
		}
		if(kmp_stereo_mList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			double stereo_mItem;
			std::vector<double> stereo_mList;
			kmp_stereo_m.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_stereo_m.search(is)) {
					is >> stereo_mItem;
					stereo_mList.push_back(stereo_mItem);
				}
			}
			setStereo_m(stereo_mList);
		}
		if(kmp_distortion_mList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			double distortion_mItem;
			std::vector<double> distortion_mList;
			kmp_distortion_m.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_distortion_m.search(is)) {
					is >> distortion_mItem;
					distortion_mList.push_back(distortion_mItem);
				}
			}
			setDistortion_m(distortion_mList);
		}
		if(kmp_distortion_model.search(is)) {
			CommVisionObjects::ImageDistortionModel distortion_modelItem;
			distortion_modelItem.from_xml(is);
			setDistortion_model(distortion_modelItem);
		}
		if(kmp_seq_count.search(is)) {
			unsigned int seq_countItem;
			is >> seq_countItem;
			setSeq_count(seq_countItem);
		}
		if(kmp_is_valid.search(is)) {
			bool is_validItem;
			is >> is_validItem;
			setIs_valid(is_validItem);
		}
	}
	
	/*
	void CommDepthImageCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		CommVisionObjectsIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(CommVisionObjectsIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommDepthImageACE.hh)
		cdr << idl_CommDepthImage;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommDepthImage);
		cdr << data_hash;
		// std::cout << "CommDepthImageCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommDepthImageCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		CommVisionObjectsIDL::HashList hashes;
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
		// (see CommDepthImageACE.hh)
		cdr >> idl_CommDepthImage;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommDepthImage);
		assert(data_hash == own_hash);
		// std::cout << "CommDepthImageCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommVisionObjects */
