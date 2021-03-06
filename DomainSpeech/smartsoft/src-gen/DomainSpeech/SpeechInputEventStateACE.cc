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
#include "DomainSpeech/SpeechInputEventStateACE.hh"
#include <ace/SString.h>

// serialization operator for element SpeechInputEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainSpeechIDL::SpeechInputEventState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element topic
	good_bit = good_bit && cdr << ACE_CString(data.topic.c_str());
	// serialize list-element text
	good_bit = good_bit && cdr << ACE_CString(data.text.c_str());
	// serialize list-element semantic
	good_bit = good_bit && cdr << ACE_CString(data.semantic.c_str());
	// serialize list-element confidence
	good_bit = good_bit && cdr.write_double(data.confidence);
	
	return good_bit;
}

// de-serialization operator for element SpeechInputEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainSpeechIDL::SpeechInputEventState &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize string-type element topic
	ACE_CString data_topic_str;
	good_bit = good_bit && cdr >> data_topic_str;
	data.topic = data_topic_str.c_str();
	// deserialize string-type element text
	ACE_CString data_text_str;
	good_bit = good_bit && cdr >> data_text_str;
	data.text = data_text_str.c_str();
	// deserialize string-type element semantic
	ACE_CString data_semantic_str;
	good_bit = good_bit && cdr >> data_semantic_str;
	data.semantic = data_semantic_str.c_str();
	// deserialize type element confidence
	good_bit = good_bit && cdr.read_double(data.confidence);
	
	return good_bit;
}

// serialization operator for CommunicationObject SpeechInputEventState
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DomainSpeech::SpeechInputEventState &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject SpeechInputEventState
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DomainSpeech::SpeechInputEventState &obj)
{
	return cdr >> obj.set();
}
