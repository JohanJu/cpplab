#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ifstream in("word");
	ifstream in("/usr/share/dict/words");
	ofstream out("triWord");
	string raw;
	
	while (in >> raw) {
		vector<string> tri;
		unsigned nbr = 0;
		string word = "";
		for (char c:raw)
		{
			word+=(char)tolower(c);
		}
		
		unsigned len = word.length();
		if (len > 2) {
			for (nbr = 0; nbr < len - 2; ++nbr)
			{
				tri.push_back(word.substr(nbr,3));
			}
			sort(tri.begin(), tri.end());
		}
		out << word << " " << nbr << " ";
		for(string s : tri){
			out << s << " ";
		}
		out << "\n";
	}
	in.close();
	out.close();
	return 0;
}