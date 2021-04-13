#ifndef ASSIGNMENT_4_TIMESTAMP_H
#define ASSIGNMENT_4_TIMESTAMP_H

#include <ctime>
#include <string>

#include "TimeDuration.h"


class TimeStamp {

    static const inline std::string weekdays[7] {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };

    static const inline std::string months[12] {
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"
    };


    time_t timeOfStamp; // seconds from 1st Jan 1970

    size_t second; // [0 ... 59]

    size_t minute; // [0 ... 59]

    size_t hour; // [0 ... 24]

    std::string weekday; // [Monday ... Sunday]

    size_t monthDay; // [1 ... 31]

    std::string month; // [January ... December]

    size_t year; // [2021 ... ]


    explicit TimeStamp(time_t timeOfStamp);

    void init();

public:
    TimeStamp();


    TimeStamp operator+(const TimeDuration &timeDuration) const;

    TimeDuration operator-(const TimeStamp &timeStamp) const;


    bool operator<(const TimeStamp &rhs) const;

    bool operator>(const TimeStamp &rhs) const;

    bool operator<=(const TimeStamp &rhs) const;

    bool operator>=(const TimeStamp &rhs) const;


    [[nodiscard]] std::string toString() const;


    [[nodiscard]] size_t getSecond() const;

    [[nodiscard]] size_t getMinute() const;

    [[nodiscard]] size_t getHour() const;

    [[nodiscard]] const std::string &getWeekday() const;

    [[nodiscard]] size_t getMonthDay() const;

    [[nodiscard]] const std::string &getMonth() const;

    [[nodiscard]] size_t getYear() const;
};


#endif //ASSIGNMENT_4_TIMESTAMP_H
