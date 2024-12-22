#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


int main(){
    string grade[] = {"A", "B+", "B", "C+", "C", "D+", "D", "F", "W"};
    cout << "Press Enter 3 times to reveal your future.\n";
    for (int i = 0; i < 3; i++){
        cin.get();
    }
    srand(time(0));

    int randomgrade = rand() % 9;
    cout << "You will get " << grade[randomgrade] <<" in this 261102.";

    return 0;

}
