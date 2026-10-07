#include "Time.hpp"
#include <iostream>
#include <iomanip>

Time::Time(int hours, int minutes, int seconds)
    : hours_(hours), minutes_(minutes), seconds_(seconds)
{
    normalize();
}

void Time::normalize() {
    const int DAY = 24 * 3600;

    long long total = static_cast<long long>(hours_) * 3600
                    + static_cast<long long>(minutes_) * 60
                    + seconds_;

    total %= DAY;
    if (total < 0) total += DAY;

    hours_   = static_cast<int>(total / 3600);
    minutes_ = static_cast<int>((total % 3600) / 60);
    seconds_ = static_cast<int>(total % 60);
}

void Time::info() const {
    std::cout << std::setfill('0')
              << std::setw(2) << hours_   << ':'
              << std::setw(2) << minutes_ << ':'
              << std::setw(2) << seconds_ << std::endl;
}

int Time::toSeconds() const {
    return hours_ * 3600 + minutes_ * 60 + seconds_;
}

void Time::addSeconds(int sec) {
    seconds_ += sec;
    normalize();
}

void Time::subSeconds(int sec) {
    seconds_ -= sec;
    normalize();
}

void Time::addTime(const Time& other) {
    hours_   += other.hours_;
    minutes_ += other.minutes_;
    seconds_ += other.seconds_;
    normalize();
}

void Time::subTime(const Time& other) {
    hours_   -= other.hours_;
    minutes_ -= other.minutes_;
    seconds_ -= other.seconds_;
    normalize();
}