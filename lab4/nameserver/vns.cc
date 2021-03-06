#include "nameserverinterface.h"
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class VNS: public NameServerInterface {

	vector<pair< HostName, IPAddress>> vns;

public:

	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	void insert(const HostName& h, const IPAddress& i) {
		vns.push_back(pair<HostName, IPAddress>(h, i));
	}

	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool remove(const HostName& h) {
		auto pa = find_if(vns.begin(), vns.end(),
		[h](pair<HostName, IPAddress> p) { return p.first == h; });
		if (pa != vns.end()){
			vns.erase(pa);
			return true;
		}
		return false;
	}

	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress lookup(const HostName& h) const {

		auto pa = find_if(vns.begin(), vns.end(),
		[h](pair<HostName, IPAddress> p) { return p.first == h; });
		if (pa != vns.end())
			return pa->second;
		return NON_EXISTING_ADDRESS;
	}
};

// int main() {
// 	hash<string> hash_fn;
// 	// cout << sizeof(hash_fn("aasdaasdasdsd")) << endl;

// }