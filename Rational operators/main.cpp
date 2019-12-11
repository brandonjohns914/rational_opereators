//
//  main.cpp
//  lab_6
//
//  Created by Brandon Johns on 4/3/18.
//  Copyright © 2018 Brandon Johns. All rights reserved.
//

#include <iostream>
using namespace std;


////////number 1
class Resource
{
private:
    int status;
    int writeTo;
    friend bool check_status(Resource &, Resource &);
public:
    Resource()
    {
        status=writeTo=0;
    }
    Resource(int num)
    {
        writeTo=num;
    }
    int getstatus()
    {
        return status;
    }
    int getW()
    {
        return writeTo;
    }
    void setstatu(int s)
    {
        status=s;
    }
    void setWrite(int w)
    {
        writeTo=w;
    }
    void output(ostream &out)
    {
        out<<"Status is : "<<status<<endl;
        out<<"WriteTo is : "<<writeTo<<endl;
    }
};
bool check_status(Resource &res1, Resource &res2)
{
    if(res1.getstatus()==res2.getstatus())
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Rational
{
private:
    int numerator;
    int denominator;
public:
    Rational(int N, int D);/// setting values
    Rational(int Whole_number);/// whole number over 1
    Rational();//// setting to zero and 1
    friend bool operator == (const Rational& number1, const Rational& number2);
    friend bool operator >= (const Rational& number1, const Rational& number2);
    friend bool operator <= (const Rational& number1, const Rational& number2);
    friend bool operator <(const Rational& number1, const Rational& number2);
    friend bool operator >(const Rational& number1, const Rational& number2);
    
    
    friend istream& operator>>(istream& input, Rational& frctn);
    friend ostream& operator<<(ostream& output,const Rational& frctn);
    friend Rational operator +(const Rational& number1, const Rational& number2);
    friend Rational operator -(const Rational& number1, const Rational& number2);
    friend Rational operator /(const Rational& number1, const Rational& number2);
    friend Rational operator *(const Rational& number1, const Rational& number2);
};
void normalize(int& num, int& den);
int GCM(int number1, int number2);
istream& operator>>(istream& input, Rational& frctn)
{
    char ch;
    input>>frctn.numerator>> ch>>frctn.denominator;
    if (ch!='/')
    {
        cout<<"wrong in put: " <<  ch <<endl;
        
    }
    
    return input;
}

ostream& operator<<(ostream& output, const Rational& frctn)
{
    
    output<<(char)frctn.numerator<<'/'<<frctn.denominator;
    return output;
    
    
}


bool operator == (const Rational& number1, const Rational& number2)
{
    return number1.numerator*number2.denominator==number2.numerator*number1.denominator;
    
}
bool operator >= (const Rational& number1, const Rational& number2)
{
    return number1.numerator*number2.denominator>=number2.numerator*number1.denominator;
}
bool operator < (const Rational& number1, const Rational& number2)
{
    return number1.numerator*number2.denominator<number2.numerator*number1.denominator;
}
bool operator <= (const Rational& number1, const Rational& number2)
{
    return number1.numerator*number2.denominator<= number2.numerator*number1.denominator;
}
bool operator > (const Rational& number1, const Rational& number2)
{
    return number1.numerator*number2.denominator>number2.numerator*number1.denominator;
}
Rational operator +(const Rational& number1, const Rational& number2)
{
    int n;
    int d;
    Rational addtion;
    n=(number1.numerator*number2.denominator) + (number1.denominator*number2.numerator);
    d=number1.denominator*number2.denominator;
    normalize(n,d);
    addtion=Rational(n,d);
    return addtion;
}
Rational operator -(const Rational& number1, const Rational& number2)
{
    int n;
    int d;
    Rational subtraction;
    n=number1.numerator*number2.denominator-number1.denominator*number2.numerator;
    d=number1.denominator*number2.denominator;
    normalize(n,d);
    subtraction=Rational(n,d);
    return subtraction;
}

Rational operator *(const Rational& number1, const Rational& number2)
{
    int n;
    int d;
    Rational multi;
    n=number1.numerator*number2.numerator;
    d=number1.denominator*number2.denominator;
    normalize(n,d);
    multi=Rational(n,d);
    return multi;
}
Rational operator /(const Rational& number1, const Rational& number2)
{
    int n;
    int d;
    Rational div;
    n=number1.numerator*number2.denominator;
    d=number1.denominator*number2.numerator;
    normalize(n,d);
    div=Rational(n,d);
    return div;
}






Rational::Rational()
{
    numerator=0;
    denominator=1;
}

Rational:: Rational(int Whole_number)
{
    numerator=Whole_number;
    denominator=1;
}
Rational::Rational(int N, int D)
{
    numerator=N;
    denominator=D;
    normalize(N,D);
    
    if(denominator==0)
    {
        cout<<"denominator cannot be zero" <<endl;
    }
}

void normalize(int& num, int& den)
{
    int gcd;
    gcd=GCM(num, den);
    if((num>0&& den<0) || (num<0 && den<0))
    {
        num=-num;
        den=-den;
    }
}
int GCM(int number1, int number2)
{
    int temp;
    int remainder;
    number1=abs(number1);
    number2=abs(number2);
    if(number1>number2)
    {
        temp=number1;
        number1=number2;
        number2=temp;
    }
    while(remainder!=0)
    {
        remainder= number1% number2;
        number1=number2;
        number2=remainder;
    }
    return number1;
}

int main()
{
    Resource obj(1);
    obj.setstatu(1);
    obj.setWrite(1);
    obj.output(cout);
    Resource obj1(1);
    obj1.setstatu(1);
    obj1.setWrite(1);
    obj1.output(cout);
    Resource obj3;
    if(check_status(obj,obj1))
    {
        cout<<"Status are equal "<<endl;
    }
    else
    {
        cout<<"Status are not equal "<<endl;
    }
    
    cout<< "number 2" <<endl;
    Rational rational;
    
    cout<<"Results of Rational() constructor: "<< rational <<endl;
    rational=Rational(2);
    cout<<"Reuslts of Rational(int) constructor: " << rational <<endl;
    cout<<"Results of Rational(int int) constructor: "<< rational<<endl;
    
    
    cout<<"enter a fraction(Numerator/ Denomianator): ";
    cin>> rational;
    
    rational=Rational(12,-18);
    cout<<"results of rational(int int): " << rational <<endl;
    
    cout<< "the equivalent fraction is: " << rational <<endl;
    
    Rational rational1 =Rational(1,2);
    Rational rational2 =Rational(2,3);
    
    cout<<"rational numbers used for testing are: "<<endl;
    cout<<"Rational number -1: " <<endl;
    cout<< "Rational number -2: "<<endl;
    
    cout<<"testing the conditional operations: "<<endl;
    cout<< "is " << rational1<< " == " << rational2 <<"?: "<<endl;
    if(rational1==rational2)
    {
        cout<< "TRUE" <<endl;
        
    }
    
    else{
        cout<<"FALSE" <<endl;
    }
    
    cout<<"testing the conditional operations: "<<endl;
    cout<< "is " << rational1<< " < " << rational2 <<"?: "<<endl;
    if(rational1<rational2)
    {
        cout<< "TRUE" <<endl;
        
    }
    
    else{
        cout<<"FALSE" <<endl;
    }
    
    cout<<"testing the conditional operations: "<<endl;
    cout<< "is " << rational1<< " > " << rational2 <<"?: "<<endl;
    if(rational1>rational2)
    {
        cout<< "TRUE" <<endl;
        
    }
    
    else{
        cout<<"FALSE" <<endl;
    }
    
    cout<<"testing the conditional operations: "<<endl;
    cout<< "is " << rational1<< " <= " << rational2 <<"?: "<<endl;
    if(rational1<= rational2)
    {
        cout<< "TRUE" <<endl;
        
    }
    
    else
    {
        cout<<"FALSE" <<endl;
    }
    
    cout<<"testing the conditional operations: "<<endl;
    cout<< "is " << rational1<< " => " << rational2 <<"?: "<<endl;
    if(rational1>= rational2)
    {
        cout<< "TRUE" <<endl;
        
    }
    
    else{
        cout<<"FALSE" <<endl;
    }
    
    cout << "testing + operations: " <<endl;
    cout<<"rational1 " << " + " << " rational2" <<endl;
    cout<< rational1+rational2 <<endl;;
    cout<<endl;
    
    cout << "testing - operations: " <<endl;
    cout<<"rational1 " << " - " << " rational2" <<endl;
    cout<< rational1-rational2<<endl;
    cout<<endl;
    
    cout << "testing * operations: " <<endl;
    cout<<"rational1 " << " *" << " rational2" <<endl;
    cout<<(rational1*rational2)<<endl;
    cout<<endl;
    cout << "testing / operations: " <<endl;
    cout<<"rational1 " << " / " << " rational2" <<endl;
    cout<< rational1/ rational2<<endl;
    cout<<endl;
    
}

