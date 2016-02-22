#include "nameserverinterface.h"
#include <unordered_map>
#include <utility>
#include <algorithm>

class UMNS: public NameServerInterface {

	unordered_map< HostName, IPAddress> mns;

public:

	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	void insert(const HostName& h, const IPAddress& i) {
		mns[h] = i;
	}

	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool remove(const HostName& h) {
		return mns.erase(h)>0;
	}

	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress lookup(const HostName& h) const {

		auto pa = mns.find(h);
		if (pa != mns.end())
			return pa->second;
		return NON_EXISTING_ADDRESS;
	}
};