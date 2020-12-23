#include <iostream>

using namespace std;

void func(int** p);
void func_2(int a[][2]);


int main()
{
    int a[2][2]={{1,2},{3,4}};
    
    cout<<"调用前:"<<"a[0][0]= "<<a[0][0]<<", a[0][1]= "<<a[0][1]<<endl;
    func_2(a);
    cout<<"调用后:"<<"a[0][0]= "<<a[0][0]<<", a[0][1]= "<<a[0][1]<<endl;

    return 0;

}

void func(int* p)
{
   cout <<"+++++++"<<__FUNCTION__<<"+++++++"<<endl;
   cout << "before address: "<<p<<"   value: "<<*p<<endl;
   *p = 8;
   p=new int(10);
   cout << "change address: "<<p<<"   value: "<<*p<<endl;

  // p[0] =0;
  // p[1]=0;
}


void func_2(int a[][2])
{
   cout <<"+++++++"<<__FUNCTION__<<"+++++++"<<endl;
   int b = 5;
   int* pp =&b;

   cout << "int address: "<<&b<<" int value: "<<b<<endl;
   cout << "point address: "<<&pp<<"point  value: "<<pp << " point prefer value: "<<*pp<<endl;
   cout <<"------------------------------"<<endl;

   //func(a[0]);
   func(pp);
   
   cout <<"----------func退出后-------------"<<endl;
   cout << "after int address: "<<&b<<" int value: "<<b<<endl;
   cout << "after address: "<<&pp<<"   value: "<<pp<<endl;
   cout << "after address: "<<pp<<"   value: "<<*pp<<endl;
   cout <<"------------------------------"<<endl;
   //cout << "address: "<<a[0]<<endl;

//   cout<<"调用后:"<<"a[0][0]= "<<a[0][0]<<", a[0][1]= "<<a[0][1]<<endl;
}
