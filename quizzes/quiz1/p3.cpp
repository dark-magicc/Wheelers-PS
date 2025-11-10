
// Problem 3

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string,int> m;

    string s ="";
    cout << "Enter your string" << endl;
    getline(cin, s);
    s+= ' ';


    string tmp="";
    for (int i = 0; i< s.length();i++){
        // cout << s[i] << endl;
        if (s[i] == ' '){
            if(m.find(tmp) == m.end()){
                m[tmp] = 1;
            }
            else{
                m[tmp] ++;
            }
            tmp = "";
        }
        else{
            tmp += s[i];
        }
    }
    string most_freq_word = (m.begin())->first;
    int most_freq_num = (m.begin())->second;
    for (auto i : m){
        cout << "Key " << i.first << " and value is " << i.second << endl; 
        if (i.second> most_freq_num){
            most_freq_num = i.second;
            most_freq_word = i.first;
        }
    }
    cout << "Most freq word is " << most_freq_word << " (" << most_freq_num << " times" << endl;
    cout << "Total unique words is " << m.size() << endl;
    // Hint: you can use vector of strings instead of getline fun
    return 0;
}
