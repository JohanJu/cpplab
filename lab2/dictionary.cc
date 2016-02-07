#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	ifstream in("triWord");
	string line, first;
	while(getline(in,line)){
		istringstream iss(line);
		iss >> first;
		words.insert(first);		
	}
	// for (string s : words)
	// 		cout << s << "\n";
}

bool Dictionary::contains(const string& word) const {
	return (words.find(word) != words.end());
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}

// int main()
// {
// 	Dictionary d;
// 	return 0;
// }