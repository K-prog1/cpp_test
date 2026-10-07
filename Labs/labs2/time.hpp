#ifndef TIME_HPP
#define TIME_HPP

class Time {
private:
    int hours_;
    int minutes_;
    int seconds_;

    void normalize();   
public:
    
    Time(int hours = 0, int minutes = 0, int seconds = 0);

    void info() const;                    // вывод в формате ЧЧ:ММ:СС

    void addSeconds(int sec);             // + заданное число секунд
    void subSeconds(int sec);             // - заданное число секунд
    void addTime(const Time& other);      // + другое время
    void subTime(const Time& other);      // - другое время

    int toSeconds() const;                // секунды от начала суток
};

#endif // TIME_HPP