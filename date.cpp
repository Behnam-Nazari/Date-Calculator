#include <iostream>
using namespace std;

class Date{



public:

//=================================================//
    void get(){

        cout << "\n\n Enter the year:";
        cin >> y;
        cout << "\n\n Enter the month:";
        cin >> m;
        while (m > 12 || m < 1){
            cout << "\n\n Enter the month:";
            cin >> m;
        }
        cout << "\n\n Enter the day:";
        cin >> d;
        while (d > 31 || d < 1){
            cout << "\n\n Enter the day:";
            cin >> d;
        }
    }
//===============================================//
    void show1(){
    cout << y << "/";
    if (m>=10)
        cout << m << "/";
    else

        cout << "0" << m << "/";
    if (d>=10)
        cout << d;
    else
        cout << "0" << d;
    cout << "\n";
    }
// =============================================//
    void show2(){
        if (d>=10)
        cout << d << "-";
    else
        cout << "0" << d << "-";

    cout << monthName[m] << "-";
    cout << y;
    cout << "\n";
    }


// =============================================//


    void show3(){

    if (m == 1) {
        m = 13;
        y--;
    }
    if (m == 2) {
        m = 14;
        y--;
    }
    int q = d;
    int k = y % 100;
    int j = y / 100;
    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;

    cout <<days[h] << "," << d << "-" << monthName[m] << "-" <<y << "\n" ;



    }

    void sum(){
        int z;
        cout << "how many days to add? "; cin >> z;
    //================== YEAR==============
        int oldYear = y;
        int numLeap = 0;
        y += z/365;
        for (oldYear; oldYear < y; oldYear++ ){
            if ((oldYear % 4 ==0) && (oldYear %100 !=0) || (oldYear % 400 == 0)){
                numLeap++;

            }
        }
       cout << numLeap << "=numLeap";
        if ((y%4 == 0) && (y%100 !=0) || (y%400 == 0)){
        //========== MONTH =====================
            int mz=0;
            int remz = z%365;
            for (int i=m; remz > numOfDaysL[i]; i++ ){
                remz -= numOfDaysL[i];
                mz++;

            }
            m += mz;
            if (m > 12){
                y += m/12;
                m %= 12;
            }

        //===================== DAY=====================
            d +=remz;
            if (d> numOfDaysL[m]){
                d -= numOfDaysL[m];
                m++;
            }

        }
        else {



        //========== MONTH =====================
            int mz=0;
            int remz = z%365;
            for (int i=m; remz > numOfDays[i]; i++ ){
                remz -= numOfDays[i];
                mz++;

            }
            m += mz;
            if (m > 12){
                y += m/12;
                m %= 12;
            }
        //===================== DAY=====================
            d +=remz;
            if (d> numOfDays[m]){
                d -= numOfDays[m];
                m++;
            }

        }
         d -= numLeap;

}

private:
    int y,m,d;
    string monthName[13] = {"0", "Jan", "Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int numOfDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int numOfDaysL[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string days[7]= {"Sat","Sun","Mon","Tue","Wed","Thu","Fri"};
};

int main(){

Date d;
d.get();
d.show1();
d.show2();
d.show3();
d.sum();
d.show1();
d.show2();
d.show3();
return 0;
}
