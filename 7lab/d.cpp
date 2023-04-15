#include <bits/stdc++.h>
using namespace std;

struct Student {
    string f_name, l_name;
    double gpa;
    Student(){
      this->f_name = "";
        this->l_name = "";
        this->gpa = 0;
    }
    Student(string f_name,string l_name, double gpa){
        this->f_name = f_name;
        this->l_name = l_name;
        this->gpa = gpa;
    }
    bool compare_stud(Student s2){
    if (this -> gpa > s2.gpa ){
        return true;
    }
    else if (this -> gpa == s2.gpa and this -> l_name > s2.l_name){
        return true;
    }
    else if (this -> gpa == s2.gpa and this -> l_name == s2.l_name and this -> f_name > s2.f_name){
        return true;
    }
    return false;
}
};


void merge(Student arr[], int l, int m, int r) {
  
  int n1 = m - l + 1;
  int n2 = r - m;

  Student a[n1];
  Student b[n2];

  for (int i = 0; i < n1; i++)
    a[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    b[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (b[j].compare_stud(a[i])) {
      arr[k] = a[i];
      i++;
    } else {
      arr[k] = b[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = a[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = b[j];
    j++;
    k++;
  }
}


void mergeSort(Student arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main(){
    unordered_map <string, float> grades;
    
    grades.insert(pair<string, float>("A+", 4.00));
    grades.insert(pair<string, float>("A", 3.75));
    grades.insert(pair<string, float>("B+", 3.50));
    grades.insert(pair<string, float>("B", 3.00));
    grades.insert(pair<string, float>("C+", 2.50));
    grades.insert(pair<string, float>("C", 2.00));
    grades.insert(pair<string, float>("D+", 1.50));
    grades.insert(pair<string, float>("D", 1.00));
    grades.insert(pair<string, float>("F", 0.00));
    
    int n, m; cin >> n;
    Student studs[n];
    string f_n, l_n;
    for (int i = 0; i < n; i++){
        cin >> l_n >> f_n >> m;
        int cred = 0;
        int sum_cred = 0;
        string gpas;
        double sum = 0;
        for ( int j = 0; j < m; j++){
            cin >> gpas >> cred;
            sum += (grades[gpas] * cred);
            sum_cred += cred;
        }
        studs[i] = Student(f_n, l_n, sum/sum_cred);
    }
     
    mergeSort(studs, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << studs[i].l_name << " " << studs[i].f_name << " " << fixed <<setprecision(3) <<studs[i].gpa << endl;
    }
    return 0;


}