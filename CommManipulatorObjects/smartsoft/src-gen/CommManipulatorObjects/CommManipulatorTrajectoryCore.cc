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
#include "CommManipulatorObjects/CommManipulatorTrajectoryCore.hh"

// serialization/deserialization operators
//#include "CommManipulatorObjects/CommManipulatorTrajectoryACE.hh"

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

namespace CommManipulatorObjects 
{
	const char* CommManipulatorTrajectoryCore::getCompiledHash()
	{
		return CommManipulatorObjectsIDL::REPO_HASH;
	}
	
	void CommManipulatorTrajectoryCore::getAllHashValues(std::list<std::string> &hashes)
	{
		// get own hash value
		hashes.push_back(getCompiledHash());
		// get hash value(s) for CommManipulatorObjects::CommJointValues(idl_CommManipulatorTrajectory.joint_angles)
		CommManipulatorObjects::CommJointValues::getAllHashValues(hashes);
		// get hash value(s) for CommBasicObjects::CommPose3d(idl_CommManipulatorTrajectory.pose_tcp)
		CommBasicObjects::CommPose3d::getAllHashValues(hashes);
		// get hash value(s) for CommManipulatorObjects::CommGripperTrajectory(idl_CommManipulatorTrajectory.gripper_angles)
		CommManipulatorObjects::CommGripperTrajectory::getAllHashValues(hashes);
	}
	
	void CommManipulatorTrajectoryCore::checkAllHashValues(std::list<std::string> &hashes)
	{
		// check own hash value
		if (strcmp(getCompiledHash(), hashes.front().c_str()) != 0)
		{
			std::cerr << "###################################################" << std::endl;
			std::cerr << "WARNING: HASHES OF COMMUNICATION OBJECTS MISSMATCH!" << std::endl;
			std::cerr << "CommManipulatorTrajectoryCore hash" << std::endl;
			std::cerr << "Expected: " << getCompiledHash() << std::endl;
			std::cerr << "Received: " << hashes.front() << std::endl;
			std::cerr << "###################################################" << std::endl;
		}
		assert(strcmp(getCompiledHash(), hashes.front().c_str()) == 0);
		hashes.pop_front();
		
		// check hash value(s) for CommManipulatorObjects::CommJointValues(idl_CommManipulatorTrajectory.joint_angles)
		CommManipulatorObjects::CommJointValues::checkAllHashValues(hashes);
		// check hash value(s) for CommBasicObjects::CommPose3d(idl_CommManipulatorTrajectory.pose_tcp)
		CommBasicObjects::CommPose3d::checkAllHashValues(hashes);
		// check hash value(s) for CommManipulatorObjects::CommGripperTrajectory(idl_CommManipulatorTrajectory.gripper_angles)
		CommManipulatorObjects::CommGripperTrajectory::checkAllHashValues(hashes);
	}
	
	#ifdef ENABLE_HASH
	size_t CommManipulatorTrajectoryCore::generateDataHash(const DATATYPE &data)
	{
		size_t seed = 0;
		
		std::vector<CommManipulatorObjectsIDL::CommJointValues>::const_iterator data_joint_anglesIt;
		for(data_joint_anglesIt=data.joint_angles.begin(); data_joint_anglesIt!=data.joint_angles.end(); data_joint_anglesIt++) {
			seed += CommManipulatorObjects::CommJointValues::generateDataHash(*data_joint_anglesIt);
		}
		seed += CommBasicObjects::CommPose3d::generateDataHash(data.pose_tcp);
		seed += CommManipulatorObjects::CommGripperTrajectory::generateDataHash(data.gripper_angles);
		boost::hash_combine(seed, data.flag);
		
		return seed;
	}
	#endif
	
	// default constructor
	CommManipulatorTrajectoryCore::CommManipulatorTrajectoryCore()
	:	idl_CommManipulatorTrajectory()
	{  
		setJoint_angles(std::vector<CommManipulatorObjects::CommJointValues>());
		setPose_tcp(CommBasicObjects::CommPose3d());
		setGripper_angles(CommManipulatorObjects::CommGripperTrajectory());
		setFlag(CommManipulatorObjects::ManipulatorTrajectoryFlag());
	}
	
	CommManipulatorTrajectoryCore::CommManipulatorTrajectoryCore(const DATATYPE &data)
	:	idl_CommManipulatorTrajectory(data)
	{  }

	CommManipulatorTrajectoryCore::~CommManipulatorTrajectoryCore()
	{  }
	
	void CommManipulatorTrajectoryCore::to_ostream(std::ostream &os) const
	{
	  os << "CommManipulatorTrajectory(";
	  std::vector<CommManipulatorObjects::CommJointValues>::const_iterator joint_anglesIt;
	  std::vector<CommManipulatorObjects::CommJointValues> joint_anglesList = getJoint_anglesCopy();
	  for(joint_anglesIt=joint_anglesList.begin(); joint_anglesIt!=joint_anglesList.end(); joint_anglesIt++) {
	  	joint_anglesIt->to_ostream(os);
	  }
	  getPose_tcp().to_ostream(os);
	  getGripper_angles().to_ostream(os);
	  getFlag().to_ostream(os);
	  os << ") ";
	}
	
	// convert to xml stream
	void CommManipulatorTrajectoryCore::to_xml(std::ostream &os, const std::string &indent) const {
		size_t counter = 0;
		
		std::vector<CommManipulatorObjects::CommJointValues>::const_iterator joint_anglesIt;
		std::vector<CommManipulatorObjects::CommJointValues> joint_anglesList = getJoint_anglesCopy();
		counter = 0;
		os << indent << "<joint_anglesList n=\"" << joint_anglesList.size() << "\">";
		for(joint_anglesIt=joint_anglesList.begin(); joint_anglesIt!=joint_anglesList.end(); joint_anglesIt++) {
			os << indent << "<joint_angles i=\"" << counter++ << "\">";
			joint_anglesIt->to_xml(os, indent);
			os << indent << "</joint_angles>";
		}
		os << indent << "</joint_anglesList>";
		os << indent << "<pose_tcp>";
		getPose_tcp().to_xml(os, indent);
		os << indent << "</pose_tcp>";
		os << indent << "<gripper_angles>";
		getGripper_angles().to_xml(os, indent);
		os << indent << "</gripper_angles>";
		os << indent << "<flag>";
		getFlag().to_xml(os, indent);
		os << indent << "</flag>";
	}
	
	// restore from xml stream
	void CommManipulatorTrajectoryCore::from_xml(std::istream &is) {
		size_t counter = 0;
		
		static const Smart::KnuthMorrisPratt kmp_joint_anglesList("<joint_anglesList n=\"");
		static const Smart::KnuthMorrisPratt kmp_joint_angles("\">");
		static const Smart::KnuthMorrisPratt kmp_pose_tcp("<pose_tcp>");
		static const Smart::KnuthMorrisPratt kmp_gripper_angles("<gripper_angles>");
		static const Smart::KnuthMorrisPratt kmp_flag("<flag>");
		
		if(kmp_joint_anglesList.search(is)) {
			size_t numberElements;
			is >> numberElements;
			CommManipulatorObjects::CommJointValues joint_anglesItem;
			std::vector<CommManipulatorObjects::CommJointValues> joint_anglesList;
			kmp_joint_angles.search(is);
			for(counter=0; counter<numberElements; counter++) {
				if(kmp_joint_angles.search(is)) {
					joint_anglesItem.from_xml(is);
					joint_anglesList.push_back(joint_anglesItem);
				}
			}
			setJoint_angles(joint_anglesList);
		}
		if(kmp_pose_tcp.search(is)) {
			CommBasicObjects::CommPose3d pose_tcpItem;
			pose_tcpItem.from_xml(is);
			setPose_tcp(pose_tcpItem);
		}
		if(kmp_gripper_angles.search(is)) {
			CommManipulatorObjects::CommGripperTrajectory gripper_anglesItem;
			gripper_anglesItem.from_xml(is);
			setGripper_angles(gripper_anglesItem);
		}
		if(kmp_flag.search(is)) {
			CommManipulatorObjects::ManipulatorTrajectoryFlag flagItem;
			flagItem.from_xml(is);
			setFlag(flagItem);
		}
	}
	
	/*
	void CommManipulatorTrajectoryCore::get(ACE_Message_Block *&msg) const
	{
		// start with a default internal buffer size(will automatically grow if needed)
		ACE_OutputCDR cdr(ACE_DEFAULT_CDR_BUFSIZE);
		
		CommManipulatorObjectsIDL::HashList hashes;
		getAllHashValues(hashes);
		cdr << static_cast<ACE_CDR::Long>(hashes.size());
		for(CommManipulatorObjectsIDL::HashList::const_iterator it=hashes.begin(); it!=hashes.end(); it++)
		{
			cdr << ACE_CString(it->c_str());
		}
		
		// Here the actual serialization takes place using the OutputCDR serialization operator<<
		// (see CommManipulatorTrajectoryACE.hh)
		cdr << idl_CommManipulatorTrajectory;
		
	#ifdef ENABLE_HASH
		ACE_CDR::ULong data_hash = generateDataHash(idl_CommManipulatorTrajectory);
		cdr << data_hash;
		// std::cout << "CommManipulatorTrajectoryCore: current data hash: " << data_hash << std::endl;
	#endif
		
		// return a shallow copy of the serialized message 
		// (no data is actually copied, only the internal reference counter is incremented)
		// in order to prevent memory leaks the caller of this get(msg) method must
		// manually free the memory by calling the release() method of the message block msg
		msg = cdr.begin()->duplicate();
	}
	
	void CommManipulatorTrajectoryCore::set(const ACE_Message_Block *msg)
	{
		ACE_InputCDR cdr(msg);
	
		CommManipulatorObjectsIDL::HashList hashes;
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
		// (see CommManipulatorTrajectoryACE.hh)
		cdr >> idl_CommManipulatorTrajectory;
		
	#ifdef ENABLE_HASH
		ACE_CDR::Long data_hash;
		cdr >> data_hash;
		ACE_CDR::Long own_hash = generateDataHash(idl_CommManipulatorTrajectory);
		assert(data_hash == own_hash);
		// std::cout << "CommManipulatorTrajectoryCore: own data hash: " << own_hash << "; received data hash: " << data_hash << std::endl;
	#endif
	}
	*/
} /* namespace CommManipulatorObjects */
