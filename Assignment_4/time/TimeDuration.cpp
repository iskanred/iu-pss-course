#include "TimeDuration.h"


TimeDuration::TimeDuration(size_t seconds) {
    minutes = seconds / 60;
    TimeDuration::seconds = seconds % 60;

    hours = minutes / 60;
    minutes = minutes % 60;

    days = hours / 24;
    hours %= 24;
}


size_t TimeDuration::getTotalInSeconds() const {
    return seconds + minutes * 60 + hours * 60 * 60 + days * 24 * 60 * 60;
}

size_t TimeDuration::getTotalInMinutes() const {
    return minutes + hours * 60 + days * 24 * 60;
}

size_t TimeDuration::getTotalInHours() const {
    return hours + days * 24;
}

size_t TimeDuration::getTotalInDays() const {
    return days;
}


size_t TimeDuration::getSeconds() const {
    return seconds;
}

size_t TimeDuration::getMinutes() const {
    return minutes;
}

size_t TimeDuration::getHours() const {
    return hours;
}

size_t TimeDuration::getDays() const {
    return days;
}
