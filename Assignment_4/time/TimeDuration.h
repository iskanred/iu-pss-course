#ifndef ASSIGNMENT_4_TIMEDURATION_H
#define ASSIGNMENT_4_TIMEDURATION_H

#include <ctime>


class TimeDuration {

    size_t seconds; // [0 ... 59]

    size_t minutes; // [0 ... 59]

    size_t hours; // [0 ... 24]

    size_t days; // [1 ... 31]


public:

    explicit TimeDuration(size_t seconds);

    [[nodiscard]] size_t getTotalInSeconds() const;

    [[nodiscard]] size_t getTotalInMinutes() const;

    [[nodiscard]] size_t getTotalInHours() const;

    [[nodiscard]] size_t getTotalInDays() const;


    [[nodiscard]] size_t getSeconds() const;

    [[nodiscard]] size_t getMinutes() const;

    [[nodiscard]] size_t getHours() const;

    [[nodiscard]] size_t getDays() const;
};


#endif //ASSIGNMENT_4_TIMEDURATION_H
