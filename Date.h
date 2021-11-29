#ifndef CSCI261_DATE_H
#define CSCI261_DATE_H


class Date
{
public:
    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

    Date();

    Date(int, int, int);

private:

    constexpr static const int MONTH_DAYS[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    void setDefault();

    void validate();

    int _year{};
    int _month{};
    int _day{};
};

#endif //CSCI261_DATE_H