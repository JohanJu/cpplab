#include "nameserverinterface.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

class HNS: public NameServerInterface {

	vector<vector<pair<HostName, IPAddress>>> out;
	// vector<map<HostName,IPAddress>> out;
	int nbr;
public:
	inline  int ha(const string& s) const {
		hash<string> hash;
		return hash(s) % nbr;
		// return hash(s&0x3fff;
	}

	HNS(int nr) {
		// nr = 0x3fff;
		nbr = nr;
		for (int i = 0; i < nr; ++i)
		{
			out.push_back(vector<pair<HostName, IPAddress>>());
			// out.push_back(map<HostName,IPAddress>());

		}
	}
	/*
	 * Insert a name/address pair. Does not check if the name
	 * or address already exists.
	 */
	void insert(const HostName& h, const IPAddress& i) {
		out[ha(h)].push_back(pair<HostName, IPAddress>(h, i));
		// (out[ha(h)]).[h] = i;
	}

	/*
	 * Remove the pair with the specified host name. Returns true
	 * if the host name existed and the pair was removed, false
	 * otherwise.
	 */
	bool remove(const HostName& h) {

		vector<pair<HostName, IPAddress>>& in = out[ha(h)];
		auto pa = find_if(in.begin(), in.end(),
		[h](pair<HostName, IPAddress> p) { return p.first == h; });
		if (pa != in.end()) {
			in.erase(pa);
			return true;
		}
		return false;
		// return out[ha(h)].erase(h)>0;
	}

	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress lookup(const HostName& h) const {

		const vector<pair<HostName, IPAddress>>& in = out[ha(h)];
		auto pa = find_if(in.begin(), in.end(),
		[h](pair<HostName, IPAddress> p) { return p.first == h; });
		if (pa != in.end()){
			return pa->second;
		}
		return NON_EXISTING_ADDRESS;
		// auto m = out[ha(h)];
		// auto pa = m.find(h);
		// if (pa != m.end())
		// 	return pa->second;
		// return NON_EXISTING_ADDRESS;
	}
};