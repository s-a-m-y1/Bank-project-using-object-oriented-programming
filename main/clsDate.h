
#include "clsString.h"
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<ctime>
#pragma once
using namespace std;
class clsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;
public:
    clsDate(short Day, short Month, short  Year)//htis is constroctor is 3 prmitarrs 
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;

    }
    clsDate(string Date)//htis is constroctor from string date to filter date 
    {
        vector<string>VFileter;
        VFileter = clsString::Split(Date, "/");
        _Day = stod(VFileter[0]);
        _Month = stod(VFileter[1]);
        _Year = stod(VFileter[2]);


    }

    static string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm now; 

        
        localtime_s(&now, &t);

        short Day, Month, Year, Hour, Minute, Second;

        Year = now.tm_year + 1900;
        Month = now.tm_mon + 1;
        Day = now.tm_mday;

      
        Hour = now.tm_hour % 12;
        if (Hour == 0) Hour = 12;

        Minute = now.tm_min;
        Second = now.tm_sec;

        return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
    }



    clsDate()//this is constroctor From Local time The mathien
    {
        time_t now = time(0);
        struct tm localTime;
        localtime_s(&localTime, &now);
        _Day = localTime.tm_mday;
        _Month = localTime.tm_mon + 1;
        _Year = localTime.tm_year + 1900;
    }

    void SetDay( short Day)
    {
        _Day = Day;
    }
    short GetDay()
    {
        return _Day;
    }
    void SetMonth( short Month)
    {
        _Month = Month;
    }
    short GetMonth()
    {
        return _Month;
    }
    void SetYear( short Year)
    {
        _Year = Year;
    }
    short GetYear()
    {
        return _Year;
    }
    clsDate( short dateofdaysorder,  short Year)
    {
        clsDate Date = GetDateFromDayOrderInYear(dateofdaysorder, Year);
        _Day = Date._Day;
        _Month = Date._Month;
        _Year = Date._Year;
    }
    void print()

    {
        //cout DATE tO STRIGN   fd

    }


    static bool IsLeapYear( int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    }

    bool IsLeapYear()const
    {
        return IsLeapYear(this->_Year);

    }

    static short NumberOfDaysInMonth(const short month, const short year)
    {
        if (month < 1 || month > 12) return 0;

        static short daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        if (month == 2 && IsLeapYear(year)) return 29;

        return daysInMonth[month - 1];
    }
    short NumberOfDaysInMonth()const
    {
        return NumberOfDaysInMonth(this->_Month, this->_Year);
    }

    static short NumberOfHoursInMonth(short Month, short Year)
    {
        return NumberOfDaysInMonth(Month, Year) * 24;
    }

    short NumberOfHoursInMonth() const
    {
        return NumberOfHoursInMonth(this->_Month, this->_Year);
    }

    static int NumberOfMinutesInMonth(short Month, short Year)
    {
        return NumberOfHoursInMonth(Month, Year) * 60;
    }

    int NumberOfMinutesInMonth() const
    {
        return NumberOfMinutesInMonth(this->_Month, this->_Year);
    }

    static int NumberOfSecondsInMonth(short Month, short Year)
    {
        return NumberOfMinutesInMonth(Month, Year) * 60;
    }

    int NumberOfSecondsInMonth() const
    {
        return NumberOfSecondsInMonth(this->_Month, this->_Year);
    }

    static short DayOfWeekOrder(const short DAY, const short Month, const short Yaer)
    {

        short a, y, m;
        a = (14 - Month) / 12;
        y = Yaer - a;
        m = Month + (12 * a) - 2;
        // Gregorian:
        //0:sun, 1:Mon, 2:Tue...etc
        return (DAY + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
            / 12)) % 7;
    }


    short DayOfWeekOrder()const
    {
        return DayOfWeekOrder(this->_Day, this->_Month, this->_Year);
        //return (DAY + (Year - ((14 - Month) / 12)) + ((Year - ((14 - Month) / 12)) / 4) - ((Year - ((14 - Month) / 12)) / 100) + ((Year - ((14 - Month) / 12)) / 400) + ((31 * (Month + (12 * ((14 - Month) / 12)) - 2)) / 12)) % 7;
    }
    static string DayName(const short dayOrder)
    {
        static string arrDayNames[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
        return   (dayOrder < 0 || dayOrder>6) ? "Invaled Number " : arrDayNames[dayOrder];
    }

    string DayName()const
    {
        return DayName(DayOfWeekOrder(this->_Day, this->_Month, this->_Year));
    }

    static string Monthshortname(short NumberofMonth)
    {

        static  string Arrnamemonthofmnonth[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
        return (NumberofMonth < 1 || NumberofMonth>12) ? "Invaled Number " : Arrnamemonthofmnonth[NumberofMonth - 1];
    }
    string Monthshortname()const
    {

        return Monthshortname(this->_Month);
    }


    static void PrintClanderDate(short Month, short year)
    {
        int curant = DayOfWeekOrder(1, Month, year);
        int dayOfmonth = NumberOfDaysInMonth(Month, year);

        // تلوين أو تنسيق العنوان
        printf("\n  _______________ %s _______________\n\n", Monthshortname(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int i;
        // طباعة الفراغات قبل بداية أول يوم في الشهر
        for (i = 0; i < curant; i++)
            printf("     "); // 5 مسافات لتناسب التنسيق التالى

        for (int y = 1; y <= dayOfmonth; y++)
        {
            printf("%5d", y);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n  ___________________________________\n");
    }

    static void PrintCalenderOfMonthInfullYear(short Year)
    {
        printf("\n==================================================\n");
        printf("\n                Calnder - %d\n            \n", Year);
        printf("\n==================================================\n");
        for (short i = 1; i <= 12; i++)
        {
            PrintClanderDate(i, Year);
        }
        return;
    }

    void PrintClanderDate()const
    {
        PrintClanderDate(this->_Month, this->_Year);
    }

    void PrintCalenderOfMonthInfullYear()const
    {
        PrintCalenderOfMonthInfullYear(this->_Year);
    }
    static short NumberOfDaysFromTheBeginingOfTheYear(short day, short month, short year)//In short, the cycle function calculates the total number of days in a year minus one month, and then returns the total number of days to the current number of days.
    {
        int totalDays = 0;
        for (short i = 1; i <= month - 1; i++)
        {
            totalDays = NumberOfDaysInMonth(i, year);
        }
        return totalDays + day;
    }

    short NumberOfDaysFromTheBeginingOfTheYear()const
    {
        return NumberOfDaysFromTheBeginingOfTheYear(this->_Day, this->_Month, this->_Year);
    }
    static clsDate GetDateFromDayOrderInYear(short dateofdaysorder, short year)//!////////////////////
    {
        clsDate date;
        short Ramingdays = dateofdaysorder;
        short Daymmonth = 0;
        date._Day = 1;
        date._Year = year;
        while (true)
        {
            Daymmonth = NumberOfDaysInMonth(date._Month, year);
            if (Ramingdays > Daymmonth)
            {
                Ramingdays -= Daymmonth;
                date._Month++;
            }
            else
            {
                date._Day = Ramingdays;
                break;
            }
        }
        return date;

    }



    static clsDate DateAddDays(short days, clsDate date)
    {
        int Rimaingdays = days + NumberOfDaysFromTheBeginingOfTheYear(date._Day, date._Month, date._Year);
        short dayinmonth = 0;
        date._Month = 1;
        while (true)
        {
            dayinmonth = NumberOfDaysInMonth(date._Month, date._Year);
            if (Rimaingdays > dayinmonth)
            {
                Rimaingdays -= dayinmonth;
                date._Month++;
            }
            if (date._Month > 12)
            {
                date._Month = 1;
                date._Year++;

            }
            else
                date._Day = Rimaingdays;
            break;
        }
        return date;
    }

    void DateAddDays(short days)
    {
        *this = DateAddDays(days, *this);
    }


    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        if (Date1._Year != Date2._Year)return Date1._Year < Date2._Year;
        if (Date1._Month != Date2._Month)return Date1._Month < Date2._Month;
        return (Date1._Day < Date2._Day);
    }
    bool IsDate1BeforeDate2(clsDate Date)

    {
        return  IsDate1BeforeDate2(*this, Date);
    }

    static bool IsDate1EqualDate2(clsDate  Date1, clsDate Date2)
    {
        return(Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day);
    }


    static bool IsLastDayInMonth(clsDate date)
    {
        return(date._Month == 12);
    }
    bool IsLastDayInMonth()const
    {
        return IsLastDayInMonth(*this);
    }

    static bool IsLastMonthInYear(clsDate date)
    {
        return (date._Day == NumberOfDaysInMonth(date._Month, date._Year));
    }
    bool IsLastMonthInYear()const
    {
        return IsLastMonthInYear(*this);
    }
    static clsDate IncreaseDateByOneDay(clsDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date))
            {
                Date._Month = 1;
                Date._Day = 1;
                Date._Year++;
            }
            else
            {
                Date._Day = 1;
                Date._Month++;
            }
        }
        else
        {
            Date._Day++;
        }
        return Date;
    }

    void IncreaseDateByOneDay()
    {
        *this = IncreaseDateByOneDay(*this);
    }

    static  int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days : Days;
    }

    int GetDifferenceInDays(clsDate date)const
    {
        return GetDifferenceInDays(*this, date);
    }

    static void SwapDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate Swaping;
        Date1 = Swaping;
        Date1 = Date2;
        Date2 = Swaping;

    }

    void SwapDates(clsDate& Date)
    {
        SwapDates(*this, Date);
    }

    // static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    // {
    // int Days = 0;
    // short SawpFlagValue = 1;
    // if (!IsDate1BeforeDate2(Date1, Date2))
    // {
    // //Swap Dates
    // SwapDates(Date1, Date2);
    // SawpFlagValue = -1;
    // }
    // while (IsDate1BeforeDate2(Date1, Date2))
    // {
    // Days++;
    // Date1 = IncreaseDateByOneDay(Date1);
    // }
    // return IncludeEndDay ? ++Days * SawpFlagValue : Days *
    // SawpFlagValue;

    // }

    // int GetDifferenceInDays(clsDate date)const
    // {
    //  return GetDifferenceInDays(*this , date);
    // }

    static clsDate IncreaseDateByOneWeek(clsDate date)
    {
        for (int i = 1; i <= 7; i++)
        {
            date = IncreaseDateByOneDay(date);
        }
        return date;
    }

    void IncreaseDateByOneWeek()
    {
        *this = IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeeks(short XWeeks)
    {
        *this = IncreaseDateByXWeeks(XWeeks, *this);
    }

    static clsDate IncreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 12)
        {
            Date._Month = 1;
            Date._Year++;
        }
        else
        {
            Date._Month++;
        }
        short NumberOfDaysInCurrentMonth =
            NumberOfDaysInMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void  IncreaseDateByOneMonth()
    {
        *this = IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXDays(short Days, clsDate Date)
    {
        for (short i = 1; i <= Days; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    void IncreaseDateByXDays(short Days)
    {
        *this = IncreaseDateByXDays(Days, *this);
    }
    /////////////////
    static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
    {
        for (short i = 1; i <= Months; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }
    void IncreaseDateByXMonths(short Months)
    {
        *this = IncreaseDateByXMonths(Months, *this);
    }

    clsDate IncreaseDateByOneYear(clsDate Date)
    {
        Date._Year++;
        return Date;
    }
    void IncreaseDateByOneYear()
    {
        *this = IncreaseDateByOneYear(*this);
    }
    clsDate IncreaseDateByXYears(short Years, clsDate Date)
    {
        for (short i = 1; i <= Years; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    void IncreaseDateByXYears(short Years)
    {
        *this = IncreaseDateByXYears(Years, *this);
    }
    clsDate IncreaseDateByXYearsFaster(short Years, clsDate Date)
    {
        Date._Year += Years;
        return Date;
    }
    void IncreaseDateByXYearsFaster(short Years)
    {
        *this = IncreaseDateByXYearsFaster(Years, *this);
    }
    clsDate IncreaseDateByOneDecade(clsDate Date)
    {
        //Period of 10 years
        Date._Year += 10;
        return Date;
    }
    void IncreaseDateByOneDecade()
    {
        *this = IncreaseDateByOneDecade(*this);
    }
    clsDate IncreaseDateByXDecades(short Decade, clsDate Date)
    {
        for (short i = 1; i <= Decade * 10; i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    void IncreaseDateByXDecades(short Decade)
    {
        *this = IncreaseDateByXDecades(Decade, *this);
    }
    clsDate IncreaseDateByXDecadesFaster(short Decade, clsDate Date)
    {
        Date._Year += Decade * 10;
        return Date;
    }
    void IncreaseDateByXDecadesFaster(short Decade)
    {
        *this = IncreaseDateByXDecadesFaster(Decade, *this);
    }
    clsDate IncreaseDateByOneCentury(clsDate Date)
    {
        //Period of 100 years
        Date._Year += 100;
        return Date;
    }
    void IncreaseDateByOneCentury()
    {
        *this = IncreaseDateByOneCentury(*this);
    }

    clsDate IncreaseDateByOneMillennium(clsDate Date)
    {
        //Period of 1000 years
        Date._Year += 1000;
        return Date;
    }
    void IncreaseDateByOneMillennium()
    {
        *this = IncreaseDateByOneMillennium(*this);
    }

    clsDate DecreaseDateByOneDay(clsDate Date)
    {
        if (Date._Day == 1)
        {
            if (Date._Month == 1)
            {
                Date._Month = 12;
                Date._Day = 31;
                Date._Year--;
            }
            else
            {
                Date._Month--;
                Date._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
            }
        }
        else
        {
            Date._Day--;
        }
        return Date;
    }

    void DecreaseDateByOneDay()
    {
        *this = DecreaseDateByOneDay(*this);
    }
    clsDate DecreaseDateByOneWeek(clsDate Date)
    {
        for (int i = 1; i <= 7; i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    void DecreaseDateByOneWeek()
    {
        *this = DecreaseDateByOneWeek(*this);
    }

    clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
    {
        for (short i = 1; i <= Weeks; i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }
    void DecreaseDateByXWeeks(short Weeks)
    {
        *this = DecreaseDateByXWeeks(Weeks, *this);
    }
    clsDate DecreaseDateByOneMonth(clsDate Date)
    {
        if (Date._Month == 1)
        {
            Date._Month = 12;
            Date._Year--;
        }
        else
            Date._Month--;

        short NumberOfDaysInCurrentMonth =
            NumberOfDaysInMonth(Date._Month, Date._Year);
        if (Date._Day > NumberOfDaysInCurrentMonth)
        {
            Date._Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    void DecreaseDateByOneMonth()
    {
        *this = DecreaseDateByOneMonth(*this);
    }


    static bool IsWeekEnd(clsDate date)
    {
        //Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
        //  0       1         2          3            4        5         6
        short Indexday = DayOfWeekOrder(date._Day, date._Month, date._Year);
        return (Indexday > 4);
    }
    bool IsWeekEnd()const
    {

        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {

        return !IsWeekEnd(Date);
    }
    bool IsBusinessDay()const
    {
        return IsBusinessDay(*this);
    }

    static short DaysUntilTheEndOfWeek(clsDate Date)
    {
        return 6 - DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
    }

    short DaysUntilTheEndOfWeek()const
    {
        return DaysUntilTheEndOfWeek(*this);
    }

    static short DaysUntilTheEndOfMonth(clsDate Date1)///test 
    {
        clsDate EndOfMontDate;
        EndOfMontDate._Day = NumberOfDaysInMonth(Date1._Day,
            Date1._Year);
        EndOfMontDate._Month = Date1._Month;
        EndOfMontDate._Year = Date1._Year;
        return GetDifferenceInDays(Date1, EndOfMontDate, true);
    }

    short DaysUntilTheEndOfMonth()const
    {
        return DaysUntilTheEndOfMonth(*this);
    }

    static short DaysUntilTheEndOfYear(clsDate Date1)
    {
        clsDate EndOfYearDate;
        EndOfYearDate._Day = 31;
        EndOfYearDate._Month = 12;
        EndOfYearDate._Year = Date1._Year;
        return GetDifferenceInDays(Date1, EndOfYearDate, true);
    }

    short DaysUntilTheEndOfYear()const
    {
        return DaysUntilTheEndOfYear(*this);
    }

    static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)///test
    {

        short WeekEndCounter = 0;

        //in case the data  is weekend keep adding one day util you reach business day
        //we get rid of all weekends before the first business day
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        //here we increase the vacation dates to add all weekends to it.

        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {

            if (IsWeekEnd(DateFrom))
                WeekEndCounter++;

            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        //in case the return date is week end keep adding one day util you reach business day
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }

        return DateFrom;
    }

    void CalculateVacationReturnDate(short VacationDays)
    {
        *this = CalculateVacationReturnDate(*this, VacationDays);
    }

    static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) &&
            !IsDate1EqualDate2(Date1, Date2));
    }
    bool IsDate1AfterDate2(clsDate Date)const
    {
        return IsDate1AfterDate2(*this, Date);
    }
    enum enDateCompare { Before = -1, Equal = 0, After = 1 };
    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;
        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;
        /* if (IsDate1AfterDate2(Date1,Date2))
        return enDateCompare::After;*/
        //this is faster
        return enDateCompare::After;
    }

    static bool IsValidDate(clsDate Date)
    {
        if (Date._Day < 1 || Date._Day>31)
            return false;
        if (Date._Month < 1 || Date._Month>12)
            return false;
        if (Date._Month == 2)
        {
            if (IsLeapYear(Date._Day))
            {
                if (Date._Day > 29)
                    return false;
            }
            else
            {
                if (Date._Day > 28)
                    return false;
            }
        }
        short DaysInMonth = NumberOfDaysInMonth(Date._Month,
            Date._Year);
        if (Date._Day > DaysInMonth)
            return false;
        return true;
    }
    bool IsValidDate()const
    {
        return IsValidDate(*this);
    }


    string DateToString()
    {
        clsDate Date = *this;
        return to_string(Date._Day) + "/" + to_string(Date._Month) +
            "/" + to_string(Date._Year);
    }

    // string FormateDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
    // {
    // string FormattedDateString = "";
    // FormattedDateString = (DateToString(Date), "dd",to_string(Date._Day));
    // FormattedDateString = ReplaceWordInString(FormattedDateString,"mm", to_string(Date._Month));
    // FormattedDateString = ReplaceWordInString(FormattedDateString,"yyyy", to_string(Date._Year));
    // return FormattedDateString;
    // }

};