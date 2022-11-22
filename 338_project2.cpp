#include<iostream>
using namespace std;
// demonstrating function overloading
void volume(float r)
{
    float v;
    v=(4*3.14*r)/3;
    cout<<"the volume of the sphere is: "<<v<<endl;
}
void volume(float r1,float h2)
{
    float v;
    v=3.14*r1*r1*h2;
    cout<<"the volume of cylinder is: "<<v<<endl;
}
void volume(float length,float breadth,float height)
{
    float v;
    v=length*breadth*height;
    cout<<"the volume of the cuboid is: "<<v<<endl;
}

// demonstrating constructors and destructors
int count=0;
class time
{
    int hours;
    int minutes;
    public:
    time()
    {
        count++;
        hours=10;
       minutes=5;
    }
    time(int x,int y=0)
    {
        count++;
        hours=x;
        minutes=y;
    }

    void display(void)
    {
        cout<<"time is: "<<hours<<":"<<minutes<<endl;
    }
    ~time()
    {
        cout<<"now the destructor is being invoked for object"<<count<<endl;
        count--;
    }
};
// demostrate ineritance
class Base1
{
public:
    Base1()
    {
        cout << "Non parum of base 1 " << endl;
    }
    Base1(int a)
    {
        cout << "parum of base 1 : " << a << endl;
    }
    ~Base1()
    {
        cout << "destructor of base 1 " << endl;
    }
};
class Base2
{
public:
    Base2()
    {
        cout << "Non parum of base 2" << endl;
    }
    Base2(int a)
    {
        cout << "parum of base 2 : " << a << endl;
    }
    ~Base2()
    {
        cout << "destructor of base 2 " << endl;
    }
};

class Derived : public Base1, public Base2
{
public:
    Derived()
    {
        cout << "Non  of derived" << endl;
    }
    Derived(int a, int b, int c) : Base1(a), Base2(b)
    {
        cout << "Parum of derived : " << c << endl;
    }
    ~Derived()
    {
        cout << "destructor of derived " << endl;
    }
};

// demonstrating operator overloading
class complex
{
    int real;
    int imaginary;
    public:
    complex(int x=0,int y=0)
    {
        real=x;
        imaginary=y;
    }
    complex operator -(complex D)
    {
        complex temp;
        temp.real=real+D.real;
        temp.imaginary=imaginary+D.imaginary;
        return temp;
    }
    void operator --()
    {
        --real;
        --imaginary;
    }
   void operator --(int)
    {
        real--;
        imaginary--;
    }
    void display()
    {
        cout<<real<<" +"<<imaginary<<"i"<<endl;
    }

};
// demonstrating class template 
template<class T>
class A
{
    T x;
    public:
    A(T x)
    {
        cout<<x<<endl;
    }
};
// demostrate exception handling
void Exception()
{
    int a[] = {1, 2, 3, 4, 5};
    int s = sizeof(a) / sizeof(int);
    int x;
    cout << "enter index: ";
    cin >> x;
    try
    {
        if (x > s)
            throw x;
        else
        {
            cout << "Element at index " << x << " is: " << a[x] << endl;
        }
    }
    catch (int n)
    {
        cout << "Out of bound \nAt Given index: " << x;
    }
}
int main()
{
    int choice;
    char ch;
    do
    {
        cout<<"Enter choice according to the following menu: "<<endl;
        cout<<"\n 1. demonstrate function overloading  ";
        cout<< "\n 2 . demonstrate constructor and destructor";
        cout<<"\n 3. demonstrate inheritance";
        cout<<"\n 4. demonstrate operator overloading";
        cout<<"\n 5. demonstrate class template";
        cout<<"\n 6. demonstrate exception handling ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
            volume(3.0);
            volume(3.0,5.0);
            volume(5.0,2.5,1.0);
            
            break;
            }
            case 2:
            {
            time t1;
            t1.display();
            time t2(15,20);
            t2.display();
            time t3(9);
            t3.display();
            break;
            }
            case 3:
            {
            Derived d(1, 2, 3);
            break;
            }
            case 4:{
            A<int>a(3);
            A<double>b(3.5);
            break;
            }
            case 5:{
            complex A(10,20),B(15,25);
             complex C=A-B;
             C.display();
             A.operator --();
             A.display();
             B.operator --();
             B.display();
            break;
            }
            case 6:
            {
            Exception();
            break;
            }

        }
        cout<<"do you wnat to continue: y/n"<<endl;
        cin>>ch;
    }while(ch=='y');
    return 0;
}