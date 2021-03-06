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
#include "CommNavigationObjects/CommCorridorNavigationGoalCore.hh"

// serialization/deserialization operators
//#include "CommNavigationObjects/CommCorridorNavigationGoalACE.hh"

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
	const char* CommCorridorNavigationGoalCore::getCompiledHash()
	{
		return CommNavigationObjectsIDL::REPO_HASH;
	}
	
	void CommCorridorNavigationGoalCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommNavigationObjects::CommNavigationPaths(idl_CommCorridorNavigationGoal.paths)
		CommNavigationObjects::CommNavigationPaths::getAllHashValues(hashes);
	}
	
	void CommCorridorNavigationGoalCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommCorridorNavigationGoalCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommNavigationObjects::CommNavigationPaths(idl_CommCorridorNavigationGoal.paths)
		CommNavigationObjects::CommNavigationPaths::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommCorridorNavigationGoalCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		boost::hash_combine(seed, data.goalID);
		seed += CommNavigationObjects::CommNavigationPaths::generateDataHash(data.paths);
		boost::hash_combine(seed, data.goalX);
		boost::hash_combine(seed, data.goalY);
		boost::hash_combine(seed, data.goal_id);
		boost::hash_combine(seed, data.startX);
		boost::hash_combine(seed, data.startY);
		boost::hash_combine(seed, data.start_id);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommCorridorNavigationGoalCore::CommCorridorNavigationGoalCore()
	:	idl_CommCorridorNavigationGoal()
	{  
		setGoalID(0);
		setPaths(CommNavigationObjects::CommNavigationPaths());
		setGoalX(0.0);
		setGoalY(0.0);
		setGoal_id(0);
		setStartX(0.0);
		setStartY(0.0);
		setStart_id(0);
	}
	
	CommCorridorNavigationGoalCore::CommCorridorNavigationGoalCore(const DATATYPE &data)
	:	idl_CommCorridorNavigationGoal(data)
	{  }

	CommCorridorNavigationGoalCore::~CommCorridorNavigationGoalCore()
	{  }
	
	void CommCorridorNavigationGoalCore::to_ostream(std::ostream &os) const
	{
	  os << "CommCorridorNavigationGoal(";
	  os << getGoalID() << " ";
	  getPaths().to_ostream(os);
	  os << getGoalX() << " ";
	  os << getGoalY() << " ";
	  os << getGoal_id() << " ";
	  os << getStartX() << " ";
	  os << getStartY() << " ";
	  os << getStart_id() << " ";
	  os << ") ";
	}
	
	// convert to xml stream
	void CommCorridorNavigationGoalCore::to_xml(std::ostream &os, const std::string &indent) const {
		os << indent << "<goalID>" << getGoalID() << "</goalID>";
		os << indent << "<paths>";
		getPaths().to_xml(os, indent);
		os << indent << "</paths>";
		os << indent << "<goalX>" << getGoalX() << "</goalX>";
		os << indent << "<goalY>" << getGoalY() << "</goalY>";
		os << indent << "<goal_id>" << getGoal_id() << "</goal_id>";
		os << indent << "<startX>" << getStartX() << "</startX>";
		os << indent << "<startY>" << getStartY() << "</startY>";
		os << indent << "<start_id>" << getStart_id() << "</start_id>";
	}
	
	// restore from xml stream
	void CommCorridorNavigationGoalCore::from_xml(std::istream &is) {
		static const Smart::KnuthMorrisPratt kmp_goalID("<goalID>");
		static const Smart::KnuthMorrisPratt kmp_paths("<paths>");
		static const Smart::KnuthMorrisPratt kmp_goalX("<goalX>");
		static const Smart::KnuthMorrisPratt kmp_goalY("<goalY>");
		static const Smart::KnuthMorrisPratt kmp_goal_id("<goal_id>");
		static const Smart::KnuthMorrisPratt kmp_startX("<startX>");
		static const Smart::KnuthMorrisPratt kmp_startY("<startY>");
		static const Smart::KnuthMorrisPratt kmp_start_id("<start_id>");
		
		if(kmp_goalID.search(is)) {
			int goalIDItem;
			is >> goalIDItem;
			setGoalID(goalIDItem);
		}
		if(kmp_paths.search(is)) {
			CommNavigationObjects::CommNavigationPaths pathsItem;
			pathsItem.from_xml(is);
			setPaths(pathsItem);
		}
		if(kmp_goalX.search(is)) {
			double goalXItem;
			is >> goalXItem;
			setGoalX(goalXItem);
		}
		if(kmp_goalY.search(is)) {
			double goalYItem;
			is >> goalYItem;
			setGoalY(goalYItem);
		}
		if(kmp_goal_id.search(is)) {
			int goal_idItem;
			is >> goal_idItem;
			setGoal_id(goal_idItem);
		}
		if(kmp_startX.search(is)) {
			double startXItem;
			is >> startXItem;
			setStartX(startXItem);
		}
		if(kmp_startY.search(is)) {
			double startYItem;
			is >> startYItem;
			setStartY(startYItem);
		}
		if(kmp_start_id.search(is)) {
			int start_idItem;
			is >> start_idItem;
			setStart_id(start_idItem);
		}
	}
	
	/*
	void CommCorridorNavigationGoalCore::get(ACE_Message_Block *&msg) const
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
		// (see CommCorridorNavigationGoalACE.hh)
		cdr << idl_CommCorridorNavigationGoal;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommCorridorNavigationGoal);
		cdr << data_hash;
		// std::cout << "CommCorridorNavigationGoalCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommCorridorNavigationGoalCore::set(const ACE_Message_Block *msg)
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
		// (see CommCorridorNavigationGoalACE.hh)
		cdr >> idl_CommCorridorNavigationGoal;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommCorridorNavigationGoal);
		assert(data_hash == own_hash);
		// std::cout << "CommCorridorNavigationGoalCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommNavigationObjects */
