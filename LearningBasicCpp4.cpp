#include <iostream>
using namespace std;
class Complex {
private:
    float x , y , z;

public:
    Complex(){
        cout<<"Input 1st complex number :" ;
        cin>> x ;
        cout<<"Input 2nd complex number :" ;
        cin>> y ;
        cout<<"Difference of two complex number is :"  <<endl;
        z = x-y ;
        cout<< z ;
        }
};
    int main (){
    Complex c1 ;



    return 0;
    }
