#include "DateTime.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using std::string;

DateTime::DateTime() {
    year = 0;
    month = 0;
    day = 0;
    hour = 0;
    min = 0;
    sec = 0;
}

DateTime::DateTime(int y, int M, int d, int h, int m, int s) {
    year = y;
    month = M;
    day = d;
    hour = h;
    min = m; 
    sec = s;
}

int DateTime::getYear() { return year; }
int DateTime::getMonth() { return month; }
int DateTime::getDay() { return day; }
int DateTime::getHour() { return hour; }
int DateTime::getMin() { return min; }
int DateTime::getSec() { return sec; }

void DateTime::setYear(int y) { this->year = y; }
void DateTime::setMonth(int M) { this->month = M; }
void DateTime::setDay(int d) { this->day = d; }
void DateTime::setHour(int h) { this->hour = h; }
void DateTime::setMin(int m) { this->min = m; }
void DateTime::setSec(int s) { this->sec = s; }

void DateTime::parseString(string str) {
    int yearEndIndex = str.find('-');
    this->year = convertToInt(4, 0, yearEndIndex, str);

    int monthEndIndex = str.find('-', yearEndIndex + 1);
    this->month = convertToInt(2, yearEndIndex + 1, monthEndIndex, str);
    
    int dayEndIndex = str.find('T');
    this->day = convertToInt(2, monthEndIndex + 1, dayEndIndex, str);
   
    int hourEndIndex = str.find(':');
    this->hour = convertToInt(2, dayEndIndex + 1, hourEndIndex, str);

    int minEndIndex = str.find(':', hourEndIndex + 1);
    int tempMin = convertToInt(2, hourEndIndex + 1, minEndIndex, str);
    this->min = tempMin;

    int secEndIndex = str.find('Z');
    this->sec = convertToInt(2, minEndIndex + 1, secEndIndex, str);
}

std::ostream& operator<<(std::ostream & os, DateTime& dt) {
    os << dt.getMonth() << '/' << dt.getDay() << '/' << dt.getYear() <<
            "  " << dt.getHour() << ':' << dt.getMin() << ':' << dt.getSec();
    return os;
}

std::string DateTime::toString() {
    std::stringstream sstm;
    sstm << getYear() << '-' << std::setfill('0')<<std::setw(2) << getMonth() << '-' << getDay() << 'T' << 
            getHour() << ':' << getMin() << ':' << getSec() << 'Z';
    return sstm.str();
}

int DateTime::convertToInt(int size, int start, int end, string original) {
    //TODO: Fix the extra character(s) bug before sending this into the deliverable
    char dataString[size];
    int i = 0;
    for (int j = start; j < end; j++) {
        dataString[i] = original[j];
        i++;
    }
    //std::cout << dataString << std::endl;
    int out;
    string format = "%" + std::to_string(size) + "d";
    sscanf(dataString, format.c_str(), &out);
    return out;
}