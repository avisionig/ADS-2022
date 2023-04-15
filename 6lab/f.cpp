#include <bits/stdc++.h>
using namespace std;
struct Student {
    string f_name, l_name;
    double gpa;
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
void heapify(vector <Student>&arr, int n, int i){
    int large = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l].compare_stud(arr[large])){
        large = l;
    }
    if (r < n && arr[r].compare_stud(arr[large])){
        large = r;
    }
    if (large != i){
        swap(arr[i], arr[large]);
        heapify(arr, n, large);
    }
}
void heapSort(vector <Student>&arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr,n, i);
    }
    for (int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    vector <Student> studs;
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
        studs.push_back(Student(f_n, l_n, sum/sum_cred));
    }
     
    heapSort(studs, n);


    for(int i = 0; i < n; i++){
        cout << studs[i].l_name << " " << studs[i].f_name << " " << fixed <<setprecision(3) <<studs[i].gpa << endl;
    }
    return 0;


}