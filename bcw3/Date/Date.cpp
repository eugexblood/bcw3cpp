#include "Date.h"

void Date::validate(int day, int month, int year) {
    if ( year < 1 ) {
        throw InvalidDate("Year value should be >0.");
    }
    if ( month < 1 || month > 12 ) {
        throw InvalidDate("Month value should be from 1 to 12.");
    }
    if ( day < 1 ) {
        throw InvalidDate("Day value shouldn't be <1.");
    }
    if ( month == 2 ) {
        if ( year % 4 == 0 ) {
            if ( day > 29 ) {
                throw InvalidDate("It is 29 days in February this year.");
            }
        } else {
            if ( day > 28 ) {
                throw InvalidDate("It is 28 days in February this year.");
            }
        }
    }
    if ( month == 1 || month == 4 || month == 6 || month == 9 || month == 11 ) {
        if ( day > 30 ) {
            throw InvalidDate("It is only 30 days in this month.");
        }
    } else {
        if ( day > 31 ) {
            throw InvalidDate("It is 31 days in this month.");
        }
    }
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    validate(day, month, year);
}

Date::~Date() {}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.getDay() << "." << date.getMonth() << "." << date.getYear();
    return out;
}
