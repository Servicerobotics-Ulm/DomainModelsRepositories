#ifndef _RUNTIMEINTERFACE_HH
#define _RUNTIMEINTERFACE_HH

#include <map>
#include <string>
#include <string.h>

extern 	std::string queryParam(const std::string& server, const std::string& param);
extern 	std::string setState(const std::string& server, const std::string& state);
extern	std::string getState(const std::string& server);
extern 	std::string waitForLifeCycleState(const std::string& server, const std::string& state);
extern  int appedEvent(const std::string& event);

typedef struct
{
	std::string ciTypeName;
	std::string componentInstanceName;
	std::map< std::string,std::string >serviceNameMap;

}CiConnection;

struct ciLessLibC : public std::binary_function<std::string, std::string, bool> {
    bool operator()(const std::string &lhs, const std::string &rhs) const {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0 ;
    }
};

#endif
