#include "editor.h"
#include <iostream>
#include <string>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char r = text[pos];
	char l = '?';
	switch(r){
		case ')':
		l = '(';
		break;

		case ']':
		l = '[';
		break;

		case '}':
		l = '{';
		break;
	}
	cout << l << ' ' << r << endl; 
	int lpos = pos;
	int nbr = 1;
	while(nbr){
		--lpos;
		if(text[lpos]==r)
			++nbr;
		else if(text[lpos]==l)
			--nbr;
		if(lpos == 0){
			--lpos;
			break;
		}
		
	}

	return lpos;
}
