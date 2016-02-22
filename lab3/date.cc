#include <ctime>  // time and localtime
#include "date.h"
#include <regex>

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if (day == daysPerMonth[month-1]) {
		day = 1;
		if (month == 12) {
			month = 1;
			++year;
		} else {
			++month;
		}
	}else{
		++day;
	}
}

ostream& operator<<(ostream &o,const Date &d){
	o << d.getYear() << "-";
	if(d.getMonth()<10)
		o << "0"; 
	o << d.getMonth() << "-";
	if(d.getDay()<10)
		o << "0"; 
	o << d.getDay();



	// o << d.getYear() << "-" << d.getMonth() << "-" << d.getDay();
	return o;
}
istream& operator>>(istream &i, Date &d) {
	string s;
	i >> s;
	regex e("[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]");



	if(!regex_match (s,e)){
		i.setstate(ios_base::failbit);
		return i;
	}
	// d.year = stoi(s.substr(0,4));
	// d.month = stoi(s.substr(5,2));
	// d.day = stoi(s.substr(8,2));
	d = Date(stoi(s.substr(0,4)),stoi(s.substr(5,2)),stoi(s.substr(8,2)));
	return i;
}

