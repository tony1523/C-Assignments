 /***********************************************************************
*  Assignment    : 3                                                   *
*  Name          : Anthony Sanogo                                      *
*  Student ID    : 002-27-9811                                         *
*  Date          : 2020-11-05                                          *
   Program to print the calendar for a particular year
*  inputs: month, year, and weekday for the 1st of the month
*  output: the years's calendar, and a statement giving the weekday
*  for the last day of the year
************************************************************************/

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
int last;

string month_name (int month){

    string mth;
  switch (month){
    case 1: mth = "January"; break;
    case 2: mth = "February"; break;
    case 3: mth = "March"; break;
    case 4: mth = "April"; break;
    case 5: mth = "May"; break;
    case 6: mth = "June"; break;
    case 7: mth = "July"; break;
    case 8: mth = "August"; break;
    case 9: mth = "September"; break;
    case 10: mth = "October"; break;
    case 11: mth = "November"; break;
    case 12: mth = "December"; break;
    }

return mth;
}

int find_max_days (int month, int year){

  int max_days;
  switch (month){       // find the number of days in that particular month
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: max_days = 31; break;
    case 4: case 6: case 9: case 11: max_days = 30; break;
    case 2: if (year % 4 != 0 || year%100==0 && year%400!=0)
               max_days = 28;
            else max_days = 29; break;
    default: break;
  }
  return max_days;
}

string day_of_week (int pos){

     string weekday ;
    switch (pos){
     case 1: weekday = "Sunday"; break;
     case 2: weekday = "Monday"; break;
     case 3: weekday = "Tuesday"; break;
     case 4: weekday = "Wednesday"; break;
     case 5: weekday = "Thursday"; break;
     case 6: weekday = "Friday"; break;
     case 7: weekday = "Saturday"; break;
     }
return weekday;
}
void draw_month (int first, int month, int year){



  // print a heading
        cout<< "\n\n  ------------ "<<month_name(month) <<" -------------\n";



        cout << " Sun Mon Tue Wed Thu Fri Sat\n";
         int pos = first;        // used to place the number in the correct column
         int day = 1;
        cout << setw (first*4) << day; // position the "1" under the right day of the week
         for (day = 2; day <= find_max_days(month,year); day++){   // loop to print all the days
            if (pos == 7){              // go to a new line at the end of the week
            cout << endl;
             pos = 1;}

            else{
              pos++;
            }
            cout << setw(4) << day;
            if (pos ==7){
             last=1;
            }
            else{
             last=pos+1;
            }

                     }


if (month==12){
   cout <<"\n\npos=" <<pos  << " The year ends on a "<< day_of_week(pos)<<endl;
}


}


int main(){


  cout << "which year? ";
  int year;             // needed to decide whether it's a leap year (for February)
  cin >> year;
  cout << "enter the day of the week for the 1st of the month (1=Sun, 2=Mon etc) ";
  int first;
  cin >> first;


 cout << "\n   Calendar for the year " << year <<endl;

for (int month = 1; month <= 12; month++)
    {
        if(month==1){
        draw_month(first,month,year);
        }
        else{
         draw_month(last,month,year);
        }

    }


return 0;
}
