#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	tri = t;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned nbr= 0;
	unsigned i = 0;
	for (string s : t){
		while(i<tri.size())
		{
			int c = s.compare(tri[i]);
			if(c==0){
				++nbr;
				// break;
			}
			else if(c<0)
				break;
			++i;
		}
	}
	return nbr;
}

// int main(){

// 	// anderson 6 and der ers nde rso son
// 	vector<string> tri{"ari", "iel", "rie"};
// 	vector<string> comp{"ari", "iel", "rie"};
// 	Word w("ariel",tri);
// 	string s = "ariel";
// 	cout << w.get_matches(comp)<< endl;
// }
