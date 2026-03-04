#include<iostream>
using namespace std ;
 class Minus {
private:
    int a, b,c ;
public :
     Minus(){
     a=0;b=0;c=0 ;
     }
     Minus(int A , int B , int C ){
      a = A;
      b = B;
      c = C ;
     }

     void display1(){
     cout<<"the value of object before using operator is :"<<a<<" "<<b<<" "<<c<<endl;
     }
     void display2(){
     cout<<"the value of object after using operator is :"<<a<<" "<<b<<" "<<c<<endl;
     }

     Minus operator- (){
     Minus temp ;
     temp.a = -a;
     temp.b = -b;
     temp.c = -c ;
     return temp;
     }
    };

    int main (){
    Minus obj1(4,8,-6);Minus  obj2 ;
    obj1.display1();
    obj2 = -obj1 ;
    obj2.display2();


return 0;
}

