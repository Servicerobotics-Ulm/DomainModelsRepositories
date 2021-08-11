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
#ifndef COMMBASICOBJECTS_COMMDATAFILE_CORE_H_
#define COMMBASICOBJECTS_COMMDATAFILE_CORE_H_

#include "CommBasicObjects/CommDataFileData.hh"
#include "CommBasicObjects/CommTimeStamp.hh"

#include <iostream>
#include <string>
#include <list>

namespace CommBasicObjects {
	
class CommDataFileCore {
protected:
	// data structure
	CommBasicObjectsIDL::CommDataFile idl_CommDataFile;
	
public:
	// give a publicly accessible type-name for the template parameter IDL
	typedef CommBasicObjectsIDL::CommDataFile DATATYPE;
	
	#ifdef ENABLE_HASH
		static size_t generateDataHash(const DATATYPE &);
	#endif
	
	static const char* getCompiledHash();
	static void getAllHashValues(std::list<std::string> &hashes);
	static void checkAllHashValues(std::list<std::string> &hashes);
	
	// default constructors
	CommDataFileCore();
	CommDataFileCore(const DATATYPE &data);
	// default destructor
	virtual ~CommDataFileCore();
	
	const DATATYPE& get() const { return idl_CommDataFile; }
	operator const DATATYPE&() const { return idl_CommDataFile; }
	DATATYPE& set() { return idl_CommDataFile; }

	static inline std::string identifier(void) { return "CommBasicObjects::CommDataFile"; }
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const;
	
	// convert to xml stream
	void to_xml(std::ostream &os, const std::string &indent = "") const;
	
	// restore from xml stream
	void from_xml(std::istream &is);
	
	// User Interface
	
	// getter and setter for element Filename
	inline std::string getFilename() const { return idl_CommDataFile.filename; }
	inline CommDataFileCore& setFilename(const std::string &filename) { idl_CommDataFile.filename = filename; return *this; }
	
	// getter and setter for element Filesize
	inline unsigned int getFilesize() const { return idl_CommDataFile.filesize; }
	inline CommDataFileCore& setFilesize(const unsigned int &filesize) { idl_CommDataFile.filesize = filesize; return *this; }
	
	// getter and setter for element Timestamp
	inline CommBasicObjects::CommTimeStamp getTimestamp() const { return CommBasicObjects::CommTimeStamp(idl_CommDataFile.timestamp); }
	inline CommDataFileCore& setTimestamp(const CommBasicObjects::CommTimeStamp &timestamp) { idl_CommDataFile.timestamp = timestamp; return *this; }
	
	// getter and setter for element Data
	/**
	 * Getter methods for idl_CommDataFile.data of type vector<char>
	 */
	inline std::vector<char>& getDataRef() { return idl_CommDataFile.data; }
	inline std::vector<char> getDataCopy() const {
		return std::vector<char>(idl_CommDataFile.data.begin(), idl_CommDataFile.data.end());
	}
	inline char getDataElemAtPos(const size_t &pos) const { return idl_CommDataFile.data[pos]; }
	inline size_t getDataSize() const { return idl_CommDataFile.data.size(); }
	inline bool isDataEmpty() const { return idl_CommDataFile.data.empty(); }
	/**
	 * Setter methods for idl_CommDataFile.data of type vector<char>
	 */
	inline CommDataFileCore& setData(const std::vector<char> &data) { idl_CommDataFile.data = data; return *this; }
	inline bool setDataElemAtPos(const size_t &pos, const char &elem) {
		if(pos < idl_CommDataFile.data.size()) {
			idl_CommDataFile.data[pos] = elem;
			return true;
		}
		return false;
	}
	inline bool insertDataVectorAtPos(const size_t &pos, const std::vector<char> &data) {
		if(pos <= idl_CommDataFile.data.size()) {
			idl_CommDataFile.data.insert(idl_CommDataFile.data.begin()+pos, data.begin(), data.end());
			return true;
		}
		return false;
	}
	inline void resizeData(const size_t &size) { idl_CommDataFile.data.resize(size); }
	inline bool eraseDataElemsAtPos(const size_t &pos, const size_t &nbr_elems) {
		if( (pos+nbr_elems) <= idl_CommDataFile.data.size() ) {
			idl_CommDataFile.data.erase(idl_CommDataFile.data.begin()+pos, idl_CommDataFile.data.begin()+pos+nbr_elems);
			return true;
		}
		return false;
	}
	inline void clearData() { idl_CommDataFile.data.clear(); }
	
	// getter and setter for element Valid
	inline bool getValid() const { return idl_CommDataFile.valid; }
	inline CommDataFileCore& setValid(const bool &valid) { idl_CommDataFile.valid = valid; return *this; }
};

} /* namespace CommBasicObjects */
#endif /* COMMBASICOBJECTS_COMMDATAFILE_CORE_H_ */
