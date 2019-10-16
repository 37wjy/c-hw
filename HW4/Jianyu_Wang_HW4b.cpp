#include <time.h>
#include <iostream>

using namespace std;

class JulianDate {
private:
	static int EPOCH;
    int _year,_mon, _day,  _hour, _min, _sec;
	// this representation would make difference VERY UGLY
	// diff between Jan. 1 2001 12:03:04  and Feb 26 2028 11:19:02
	double jday; // number of days since epoch
public:
    JulianDate (int year,int mon,int day,int hour,int min,int second):_mon(mon),_day(day),_year(year),_hour(hour),_min(min),_sec(second){
        jday= 365 * (_year - 2000) + _year/4+(_year-2000)/400-(_year-2000)/100;
        int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};	
        if(isLeapYear(year)) months[1]=29;
        for(int i=0;i<mon-1;i++)
            jday+=months[i];
        jday+=day;};

    JulianDate (int year){_year=year; _mon=1;_day=1;_hour=0;_min=0;_sec=0;jday= 365 * (_year - 2000) + _year/4+(_year-2000)/400-(_year-2000)/100;}
    JulianDate(){
        time_t rawtime=time(NULL);
        tm *ct = localtime(&rawtime);
        _sec=ct->tm_sec;
        _min=ct->tm_min;
        _hour=ct->tm_hour;
        _day=ct->tm_mday;
        _mon=ct->tm_mon+1;
        _year=ct->tm_year+1900;
        jday= 365 * (_year - 2000) + _year/4+(_year-2000)/400-(_year-2000)/100;
    }

    bool isLeapYear(int year){
        if(year%100==0){
            if(year%400==0)return true;
            else return false;
        }
        else if (year%4==0)
        {
            return true;
        }
        else{
            return false;
        }
    }

    int daysOfYear(){
        return isLeapYear(_year)?366:365;
    }

    int remainingDaysOfYear(){
        return isLeapYear(_year)?366:365-_day;
    }

    int* toArr()const{
        int a[6]={_year,_mon, _day,  _hour, _min, _sec};
        return a;
    }

    int compare(const JulianDate &date){
        int64_t a=toSec();
        int64_t b=date.toSec();
        if(a>b)return 1;
        if(a<b)return -1;
        return 0;
    }

    int64_t toSec()const{
        return ((_year*365+_mon*31+_day)*60+_min)*60+_sec;
    }

    JulianDate operator=(int year){return JulianDate(year);}

    double operator-(const JulianDate &date){
        return jday-date.jday+(_hour-date._hour)/24.0+(_min-date._min)/24.0/60.0+(_sec-date._sec)/24.0/60.0/60.0;
    }
    
    JulianDate operator+(int days){	
        int year=_year,month=_mon,day=_day;	
        int remainings=remainingDaysOfYear();

        if(days>remainings){		
            days-=remainings;		
            year++;		
            int num=isLeapYear(year)?366:365;		
            while(days>num){		
                days-=num;			
                year++;			
                num=isLeapYear(year)?366:365;		
                }		
            }	

            int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};	
            if(isLeapYear(year)) months[1]=29;
            days+=_day;
            if(days-(months[_mon-1])>0){		
                days-=months[_mon-1];		
                int i=_mon;		
                for(;i<12;i++){			
                    if(days-months[i]<=0) break;			
                    days-=months[i];			
                }		
                month=i+1;
            }	
        	
        return JulianDate(year,month,days,_hour,_min,_sec);
    }

    friend ostream& operator<<(ostream& os,const JulianDate& dt){
        string a[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Sep","Oct","Nov","Dec"};
        os<<dt._year<<"/"<<dt._mon<<"/"<<dt._day<<" "<<dt._hour<<":"<<dt._min<<":"<<dt._sec<<endl;
        return os; 
    }

    int getYear(){return _year;}
    int getMonth(){return _mon;}
    int getDay(){return _day;}
    int getHour(){return _hour;}
    int getMin(){return _min;}
    int getSec(){return _sec;}
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

int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

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