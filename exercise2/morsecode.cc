#include "morsecode.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

MorseCode::MorseCode() {
	ifstream in("morse.def");
	char ch;
	string code;
	while (in >> ch >> code) {
		table[ch - 'a'] = code;
	}
	in.close();
}


string MorseCode::encode(const string& text) const {
	stringstream ss;
	for (char ch : text) {
		if (ch >= 'a' && ch <= 'z') {
			ss << table[ch - 'a'] << ' ';
		}
	}
	
	return ss.str();
}

string MorseCode::decode(const string& code) const {
	stringstream ss;
	istringstream iss(code);
	string s;
	while (iss >> s) {
		char c = 0;
		while (c != 26 && table[c] != s) {
			++c;
		}
		c+='a';
		ss << c;
	}
	// return code;
	return ss.str();
}
