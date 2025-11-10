// Problem 4

#include <iostream>
#include <vector>
using namespace std;

void add_grade(vector<int> &v,int grade){
    v.push_back(grade);
    int sum=0;
    cout << "Vector elements after addition {" ;
    for(int i : v){
        cout << i << " ,";
        sum+= i;
    }
    cout << "}" << endl;
    cout << "New avg is " << (float)sum/v.size();
    return;
}
void remove_grade(vector<int> &v, int grade){
    bool found = false;
    for(auto i = v.begin(); i!= v.end(); i++){
        if (*i == grade){
            v.erase(i);
            found =true;
            break;
        }
    }
    if (found){
        int sum=0;
        cout << "Vector elements after removal {" ;
        for(int i : v){
            cout << i << " ,";
            sum+= i;
        }
        cout << "}" << endl;
        cout << "New avg is " << (float)sum/v.size() << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    
}

int main() {
    vector<int> v;
    int choice =0;
    do{
        cout<< "Enter a choice" << endl;
        cout<< "1- add grades" << endl;
        cout<< "2- remove a grade" << endl;
        cout<< "3- exit" << endl;
        cin  >> choice;
        if (choice == 1){
            cout<< "Enter a grade" << endl;
            int grade;
            cin >> grade;
            add_grade(v, grade);
        }
        else if( choice ==2){
            cout<< "Enter a grade to remove" << endl;
            int grade;
            cin >> grade;
            remove_grade(v, grade);
        }
    }
    while(choice !=3);
    return 0;
}