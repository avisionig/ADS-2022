#include <bits/stdc++.h>
using namespace std;

struct Date{
    int day = 0, month = 0, year = 0;
};
bool compare(const Date &d1, const Date &d2)
{
    if (d1.year < d2.year)
        return true;
    if (d1.year == d2.year && d1.month < d2.month)
        return true;
    if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
        return true;
  
    return false;
} 

void swapp(Date* a, Date* b){
    Date t = *a;
    *a = *b;
    *b = t;
}
int part(Date arr[], int l, int r){
    Date pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++){
        if (compare(arr[j], pivot)){
            i++;
            swapp(&arr[i], &arr[j]);
        }
    } 
    swapp(&arr[i+1], &arr[r]);
    return (i + 1);
}
void quickSort(Date arr[], int l, int r){
    if (l < r){
        int p = part(arr, l , r);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}


int main(){
    int n; cin >> n;
    Date arr[n];
    Date a;
    string date;
    for(int i = 0; i < n; i++){
        int d, m, y;
        char c;
        cin >> d >> c >> m >> c >> y;
        Date a;


        a.day = d;
        a.month  = m;
        a.year = y;
        arr[i] = a;
    }
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        if (arr[i].day < 10 and arr[i].month < 10){
            cout << "0" << arr[i].day << "-" << "0" << arr[i].month << "-" << arr[i].year << endl;
        }
        else if (arr[i].day < 10){
            cout << "0" << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;
        }
        else if (arr[i].month < 10){
            cout << arr[i].day << "-" << "0" << arr[i].month << "-" << arr[i].year << endl;
        }
        else cout << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;
    }
    return 0;
}
