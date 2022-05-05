#include "Date.h"

Date::Date(){
	setDate(1901,1,1, 12, 2);
}

Date::Date(int y, int m, int d, int h, int duration){
	setDate(y,m,d, h, duration);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d, int h, int duration){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(duration);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}

void Date::setHour(int hour){
	this->hour = hour;
	if (hour > 23){this->hour = 23;}
	if (hour < 0){this->hour = 0;}
}

void Date::setDuration(int d){
	duration = d;

	if (d < 0){
		duration = 1;
	}
	else if (d > MAX_DURATION){
		duration = MAX_DURATION;
	}
}

//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
const string& Date::getMonthName(){return months[month-1];}


bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
			if (day == d.day){
				return this->hour < d.hour;
			}
			else {
				return day < d.day;
			}
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}
}

void Date::print(){
	cout << year << "/"<< month << "/"<< day << " @ " << hour<< ":00 for " << duration<< " hours."<<  endl;
}
bool Date::overlaps(Date& d){

  if (this->year == d.year && this->month == d.month && this->day == d.day){ // same day
    if (this->hour == d.hour){ // same hour
			return true;
    }
		else {
			if (this->hour < d.hour && hour + duration > d.hour){ // this hour overlaps d.hour
				return true;
			}
			else if (d.hour < hour && d.hour + d.duration > hour ){ // d.hour overlaps this hour
				return true;
			}
			return false;
		}
  }
  return false;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
