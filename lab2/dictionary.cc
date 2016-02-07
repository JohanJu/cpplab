#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "dictionary.h"

using namespace std;

struct Pair{
	int cost;
	string word;
	bool operator<(Pair& p){
		return cost<p.cost;
	}
};

Dictionary::Dictionary() {
	ifstream in("triWord");
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

void Dictionary::add_trigram_suggestions(vector<string>& suggestions,const string& word) const{
	unsigned len = word.length();
	if (len > 2) {
		vector<string> tri;
		for (unsigned nbr = 0; nbr < len - 2; ++nbr)
		{
			tri.push_back(word.substr(nbr, 3));
		}
		sort(tri.begin(), tri.end());
		for (Word w : words[len])
		{
			unsigned u = w.get_matches(tri);
			if (u > 0) {
				suggestions.push_back(w.get_word());
			}
		}
		for (Word w : words[len + 1])
		{
			unsigned u = w.get_matches(tri);
			if (u > 0) {

				suggestions.push_back(w.get_word());
			}
		}
		if (len > 4) {
			for (Word w : words[len - 1])
			{
				unsigned u = w.get_matches(tri);
				if (u > 0) {
					suggestions.push_back(w.get_word());
				}
			}
		}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions,const string& word) const {
	vector<Pair> ranked;
	int d[26][26];
	for (int i = 0; i < 26; ++i)
	{
		d[i][0] = i;
		d[0][i] = i;
	}
	for(string s : suggestions){
		for (unsigned i = 1; i <= word.length(); ++i)
		{
			for (unsigned j = 1; j <= s.length(); ++j)
			{
				int a,b,c;
				a = word[i]==s[j]?d[i-1][j-1]:d[i-1][j-1]+1;
				b = d[i-1][j]+1;
				c = d[i][j - 1] + 1;
				d[i][j] = a < b ? (a < c ? a : c) : (b < c ? b : c);
			}
		}
		int cost = d[word.length()][s.length()];
		ranked.push_back(Pair{cost, s});
	}
	sort(ranked.begin(), ranked.end());
	suggestions.resize(0);
	int max = 5>ranked.size()?ranked.size():5;
	for (int i = 0; i < max; ++i)
	{
		suggestions.push_back(ranked[i].word);
	}
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	Dictionary::add_trigram_suggestions(suggestions,word);
	Dictionary::rank_suggestions(suggestions,word);
	return suggestions;
}

// int main()
// {
// 	// int a = 7,b =6 ,c=4,d;
// 	// d = a<b?(a<c?a:c):(b<c?b:c);
// 	// cout << d <<endl;

// 	// Pair a{1,"a"}, b{5,"b"}, c{2,"c"};
// 	// vector<Pair> v;
// 	// v.push_back(a);
// 	// v.push_back(b);
// 	// v.push_back(c);
// 	// sort(v.begin(),v.end());
// 	// for(Pair& p:v){
// 	// 	cout << p.word<< endl;
// 	// }

// 	Dictionary d;
// 	vector<string> v = d.get_suggestions("ariel");
// 	return 0;
// }