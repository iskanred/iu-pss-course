#include "TimeStamp.h"

#include <sstream>
#include <iomanip>


TimeStamp::TimeStamp(time_t timeOfStamp) :
    timeOfStamp(timeOfStamp), second(), minute(), hour(),
    weekday(), monthDay(), month(), year()
{
    init();
}

TimeStamp::TimeStamp() :
        timeOfStamp(), second(), minute(), hour(),
        weekday(), monthDay(), month(), year()
{
    time(&timeOfStamp);
    init();
}

void TimeStamp::init() {
    tm *timeStamp = localtime(&timeOfStamp);

    second = timeStamp->tm_sec;
    minute = timeStamp->tm_min;
    hour = timeStamp->tm_hour;
    weekday = weekdays[timeStamp->tm_wday];
    monthDay = timeStamp->tm_mday;
    month = months[timeStamp->tm_mon];
    year = timeStamp->tm_year + 1900;
}


TimeStamp TimeStamp::operator+(const TimeDuration &timeDuration) const {
    time_t newTime = timeOfStamp + timeDuration.getTotalInSeconds();

    return TimeStamp(newTime);
}

TimeDuration TimeStamp::operator-(const TimeStamp &timeStamp) const {
    return TimeDuration(llabs(timeOfStamp - timeStamp.timeOfStamp));
}


bool TimeStamp::operator<(const TimeStamp &rhs) const {
    return timeOfStamp < rhs.timeOfStamp;
}

bool TimeStamp::operator>(const TimeStamp &rhs) const {
    return timeOfStamp > rhs.timeOfStamp;
}

bool TimeStamp::operator<=(const TimeStamp &rhs) const {
    return !(*this > rhs);
}

bool TimeStamp::operator>=(const TimeStamp &rhs) const {
    return !(*this < rhs);
}


std::string TimeStamp::toString() const {
    std::ostringstream sout;

    sout << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second << " "
        << weekday << " " << monthDay << " " << month << " " << year;

    return sout.str();
}


size_t TimeStamp::getSecond() const {
    return second;
}

size_t TimeStamp::getMinute() const {
    return minute;
}

size_t TimeStamp::getHour() const {
    return hour;
}

const std::string &TimeStamp::getWeekday() const {
    return weekday;
}

size_t TimeStamp::getMonthDay() const {
    return monthDay;
}

const std::string &TimeStamp::getMonth() const {
    return month;
}

size_t TimeStamp::getYear() const {
    return year;
}

time_t TimeStamp::getTimeOfStamp() const {
    return timeOfStamp;
}
