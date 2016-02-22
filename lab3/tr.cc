#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

class TR {
private:
	string s;
public:
	TR() {
		getline(cin, s, '\0');
	}
	void rmTag() {
		auto start = s.find("<");
		while (start != string::npos) {
			auto end = s.find(">");
			if (end == string::npos) {
				cerr << "no rend" << endl;
			}
			s.erase(start, end - start + 1);
			start = s.find("<");
		}
	}
	void trans() {
		// regex e("&[a-z]+");
		// smatch m;
		unsigned i;
		for ( i = 0; i < s.size(); ++i)
		{
			if (s[i] == '&' && s[i + 1] != ' ') {
				unsigned char replace = 0;
				switch (s[i + 1]) {
				case 'l':
					replace = '<';
					break;
				case 'g':
					replace = '>';
					break;
				case 'n':
					// replace = 160;
					replace = 32;
					break;
				case 'a':
					replace = '&';
					break;

				}
				unsigned j = i;
				while (j<s.size()&&s[j] != ';' ) {
					++j;
				}
				s.insert(i, string(1, replace));
				s.erase(i + 1, j - i + 1);
			}
		}
	}




	void print() {
		cout << endl;
		rmTag();
		trans();
		cout << s << endl;
	}

};

int main() {
	// ifstream in("test.html");
	TR tr;
	tr.print();
}