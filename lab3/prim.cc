#include <iostream>
#include <string>

using namespace std;

int main() {
	unsigned n = 200;
	string p(n, 'p');
	
	for (unsigned i = 2; i < n; ++i)
	{
		for (unsigned j = i*2; j < n; j += i) {
			p[j] = 'c';
		}
	}
	for (unsigned i = 0; i < n; ++i)
	{
		if(p[i]=='p')
			cout << i << " ";
	}
	cout << endl;

	n = 100000;
	p= string(n, 'p');
	
	for (unsigned i = 2; i < n; ++i)
	{
		for (unsigned j = i*2; j < n; j += i) {
			p[j] = 'c';
		}
	}
	for (unsigned i = n-1; i > 0; --i)
	{
		if(p[i]=='p'){
			cout << i << endl;
			break;
		}
	}
}