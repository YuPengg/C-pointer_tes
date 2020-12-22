#include <iostream>

using namespace std;

void func(int* p);
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
   *p = 0;
   *(p+1)=0;
   cout <<"+++++++"<<__FUNCTION__<<"+++++++"<<endl;
}

void func_2(int a[][2])
{
   func(a[0]);
   cout <<"+++++++"<<__FUNCTION__<<"+++++++"<<endl;
   cout<<"调用后:"<<"a[0][0]= "<<a[0][0]<<", a[0][1]= "<<a[0][1]<<endl;
}
