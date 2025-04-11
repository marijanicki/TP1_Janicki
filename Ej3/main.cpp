#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Ej2/Iarmas.hpp"

using namespace std;

int main(){
    srand(time(NULL));
    for(int i = 0; i<=10; i++){
        int random_num = 0+ rand() % (2-0+1) ;
        cout<<random_num<<endl;
    }
    cout<<endl;
    for(int i = 0; i<=10; i++){
        int random_num2 = 3 + rand() % (7-3+1) ;
        cout<<random_num2<<endl;
    }
}