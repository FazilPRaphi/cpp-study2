#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;

    public:
    Complex(int r,int i){
        real=r;
        img=i;
    }

    void display(){
        cout<<real<<"+"<<img<<"i";
    }
    Complex operator + (Complex &c2){
        int resReal= this->real+c2.real;
        int resimg= this->img+c2.img;

        Complex c3(resReal,resimg);
        return c3;
    }

    

};
int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3 =  c1 + c2;
    c3.display();

}