#include <iostream>
using namespace std;
class Time
{
public:
    void set_time();
    void show_time();
private:
    int hour;
    int minute;
    int sec;
};
class Date
{
public:
    void set_date();
    void show_date();
private:
    int year;
    int month;
    int day;
};
class Clock:public Time,public Date
{
public:
    void set_Clock();
    void show_Clock();
};
/******begin*******/
void Time::set_time()
{
	cin>>hour>>minute>>sec;
}
void Date::set_date()
{
	cin>>year>>month>>day;
}
void Time::show_time()
{
	cout<<Time::hour<<':'<<Time::minute<<':'<<Time::sec<<'\n';
}
void Date::show_date()
{
	cout<<Date::year<<'/'<<Date::month<<'/'<<Date::day<<'\n';
}
void Clock::set_Clock()
{
	set_time();
	set_date();
}
void Clock::show_Clock()
{
	show_time();
	show_date();
}
/*******end********/
int main()
{
    Clock c;
    c.set_Clock();
    c.show_Clock();
    return 0;
}