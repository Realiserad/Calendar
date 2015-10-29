#include <ctime>
#include <iostream>
#include "Gregorian.hpp"
#include "../Julian/Julian.hpp"
#include "../Date/Date.hpp"

namespace lab2 {
	Gregorian::Gregorian(int y, int m, int d) : Date(y,m,d, true);
	Gregorian::Gregorian() : Date() {
		// Get UNIX timestamp in ms
		time_t ms = time(0);
		// Convert to Gregorian calendar format
		struct tm *now = localtime(&ms);
		mYear = now->tm_year + 1900;
		mMonth = now->tm_mon + 1;   
		mDay = now->tm_mday;
	}
    Gregorian::Gregorian(const Date& d) {
		mYear = d.year();
		mMonth = d.month();
		mDay = d.day();
		if (!d.gregorian()) {
			convert_to_julian();
		}
    }
}
