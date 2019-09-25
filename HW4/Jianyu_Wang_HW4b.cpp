#include <time.h>
#include <iostream>



class JulianDate {
private:
	static int EPOCH;
    int _mon, _day, _year, _hour, _min, _sec;
	// this representation would make difference VERY UGLY
	// diff between Jan. 1 2001 12:03:04  and Feb 26 2028 11:19:02
	double jday; // number of days since epoch
public:
    JulianDate (int mon,int day,int year,int hour,int min,int second):_mon(mon),_day(day),_year(year),_hour(hour),_min(min),_sec(second){};
    JulianDate(){
        time_t t=time(NULL);
        _sec=;

    }

    JulianDate operator-(const Date &date){
        int num=0;
        Date bigDate,smallDate;
        int value=compare(date);
        if(value==1){
            bigDate=*this;
            smallDate=date;
        }else if(value==-1){   
            bigDate=date;		
            smallDate=*this;	
        }else return 0; 	
        int yearGap=bigDate.m_year-smallDate.m_year;

        if(yearGap>=2){		
            for(int i=smallDate.m_year+1;i<=bigDate.m_year-1;i++){			
                if(isLeapYear(i)) num+=366;			
                else num+=365;		
            }		
            num+=bigDate.getDaysofYear();		
            num+=smallDate.getRemainingDaysofYear();	
        }
        else if(bigDate.m_year-smallDate.m_year==1){	
            num+=bigDate.getDaysofYear();		
            num+=smallDate.getRemainingDaysofYear();	
        }
        else{		
            num+=bigDate.getDaysofYear();		
            num-=smallDate.getDaysofYear();	
        }

        if(value==1) return num;	
        else return -num;
    }
    
    JulianDate operator+(int days){	
        int year=_year,month;	
        int remainings=getRemainingDaysofYear();	
        if(days>remainings){		
            days-=remainings;		
            year++;		
            int num=isLeapYear(year)?366:365;		
            while(days>num){ // 找到相应的年份			
                days-=num;			
                year++;			
                num=isLeapYear(year)?366:365;		
                }		
            }	
            int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};	
            if(isLeapYear(year)) months[1]=29;	
            month=m_month;	
            if(days-(months[m_month-1]-_day)>0){		
                days-=months[m_month-1]-_day;		
                int i=m_month;		
                for(;i<12;i++){// 找到相应的月份			
                if(days-months[i]<0) break;			
                days-=months[i];		
            }		
            month=i+1;	
        }	
        int day=_day;	
        return Date(year,month,day);
    }

};

/*
	how many days in a year? 365
	leap year: if year MOD 4 == 0 LEAP EXCEPT
	           if year MOD 100 == 0 NOT LEAP YEAR Except
						 if year MOD 400 == 0 LEAP

Leap years:
 NO 1900 
 YES 1904
 YES 1908
 YES 2000
 NO 2100
 YES 2400

    days since EPOCH = 365 * (year - 2000) + years/4 - ....

2018 - 2000 = 18
seconds in a day = 24*60*60 = 86400
hh:mm:ss     
00:00:00  0.0
12:00:00  0.5
 */

int JulianDate EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0


int main() {

	JulianDate newyear(2018, 1, 1, 0,0,0);

	JulianDate valentine(2018, 2, 14, 12,0,0); // 0.5

	JulianDate today; // get it from the system time: time(nullptr)

	                  // localtime



	double days = valentine - newyear;

	JulianDate due = today + 7;

	cout << due << '\n';



	cout << "\nyear: " << newyear.getYear()

			 << "\nmonth: " << newyear.getMonth()

			 << "\nday: " << newyear.getDay()

			 << "\nhour: " << newyear.getHour()

			 << "\nmin: " << newyear.getMin()

			 << "\nsec: " << newyear.getSec() << '\n';

	JulianDate d1(2019, 1, 1, 0,0,0);

	for (int i = 0; i < 100; i++)

		cout << d1 + i;



}