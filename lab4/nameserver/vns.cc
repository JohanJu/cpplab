#include "nameserverinterface.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
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

	}

	/*
	 * Find the IP address for the specified host name. Returns
	 * NON_EXISTING_ADDRESS if the host name wasn't in the name
	 * server.
	 */
	IPAddress lookup(const HostName& h) const {

		pair<HostName, IPAddress> pa = (*find_if(vns.begin(), vns.end(),
		[h](pair<HostName, IPAddress> p) { return p.first == h; }));
		if (pa != vns.end())
			return pa.second;
		cout << "no" << endl;
	}
};

int main() {
	VNS v;
	v.insert("hej", 1);
	v.insert("asd", 2);
	v.insert("qwe", 3);
	cout << v.lookup("qwe") << endl;
}