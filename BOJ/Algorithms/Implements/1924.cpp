#include <iostream>

using namespace std;

int main(){
    int month, date;
    cin >> month , date;

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};
    int total = date;
    for(int i = 0; i < month-1; i++){
        total += days[i];
    }
    total = total % 7;
    if(total == 0){
        cout << "SUN";
    }
    else if(total == 1){
        cout << "MON";
    }       
    else if(total == 2){
        cout << "TUE";
    }   
    else if(total == 3){
        cout << "WED";
    }  
    else if(total == 4){
        cout << "THU";
    }   
    else if(total == 5){
        cout << "FRI";
    }
    else{
        cout << "SAT";
    }
}