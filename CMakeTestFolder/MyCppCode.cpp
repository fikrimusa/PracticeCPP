#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> msg {"Yes", "You", "Did", "It!"};

    for(const string& word : msg){
        cout << word << " ";
    }
    cout << endl;
}