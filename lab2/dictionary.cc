#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	ifstream in("small");
	string line, first, t;
	unsigned nbr;
	while(getline(in,line)){
		istringstream iss(line);
		iss >> first;
		iss >> nbr;
		nbr = first.length();
		if(nbr>=25)
			continue;
		vector<string> tri;
		while(iss >> t){
			tri.push_back(t);
		}
		words[nbr].push_back(Word(first,tri));
		raw.insert(first);		
	}
}

bool Dictionary::contains(const string& word) const {
	return raw.count(word);
}

// void Dictionary::add_trigram_suggestions(vector<string>& suggestions,const string& word){
// 	unsigned len = word.length();
// 	if (len > 2) {
// 		vector<string> tri;
// 		for (unsigned nbr = 0; nbr < len - 2; ++nbr)
// 		{
// 			tri.push_back(word.substr(nbr, 3));
// 		}
// 		sort(tri.begin(), tri.end());
// 		for (Word w : words[len])
// 		{
// 			if(w.get_matches(tri)){
// 				suggestions.push_back(w.get_word());
// 			}
// 		}
// 	}
// }

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	unsigned len = word.length();
	if (len > 2) {
		vector<string> tri;
		for (unsigned nbr = 0; nbr < len - 2; ++nbr)
		{
			tri.push_back(word.substr(nbr, 3));
		}
		sort(tri.begin(), tri.end());
		// for (string s : tri)
		// {
		// 	cout << s << " ";
		// }
		for (Word w : words[len])
		{
			unsigned u = w.get_matches(tri);
			if (u > 0 && u > len - 5) {
				suggestions.push_back(w.get_word());
			}
		}
		for (Word w : words[len + 1])
		{
			unsigned u = w.get_matches(tri);
			if (u > 0 && u > len - 4) {

				suggestions.push_back(w.get_word());
			}
		}
		if (len > 4) {
			for (Word w : words[len - 1])
			{
				unsigned u = w.get_matches(tri);
				if (u > 0 && u > len - 6) {
					suggestions.push_back(w.get_word());
				}
			}
		}
	}
	// for (string s : suggestions)
	// {
	// 	cout << s << endl;
	// }
	return suggestions;
}

int main()
{
	// cout << "dic" <<endl;
	Dictionary d;
	vector<string> v = d.get_suggestions("ariel");
	return 0;
}