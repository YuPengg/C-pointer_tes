#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    /*
     * 标准库的string类提供了3个成员函数来从一个string得到c类型的字符数组：c_str()、data()、copy(p,n)。
     c_str()是Borland封装的String类中的一个函数，它返回当前字符串的首字符地址。换种说法，c_str()函数返回一个指向正规C字符串    的指针常量，内容与本string串相同。这是为了与C语言兼容，在C语言中没有string类型，故必须通过string类对象的成员函数c_str()把    string对象转换成C中的字符串样式。
     c_str()的原型是：const char*c_str() const;
     c_str()生成一个const char*指针，指向以空字符终止的数组。而data()与c_str()类似，但是返回的数组不以空字符终止。
     注意：一定要使用strcpy()等函数来操作c_str()返回的指针。例如下面这样写就是错误的：
     */
    char *cstr,*p;
    string str ("Please split this phrase into tokens");
    cstr = new char [str.size()+1];
    strcpy (cstr, str.c_str());
    cout <<cstr <<endl;

    /*
       copy(p,n,size_type _Off = 0)：从string类型对象中至多复制n个字符到字符指针p指向的空间中。默认从首字符开始，但是也可以    指定，开始的位置（记住从0开始）。返回真正从对象中复制的字符。第三个参数可以缺省。以下代码显示了copy()函数的用法：
       */

    basic_string <char>:: size_type cc;
    char arr[20] = {0};
    basic_string <char>:: pointer arrayPtr = arr;
    cc = str.copy(arrayPtr,10);
    cout << "The number of copied characters in cc is: "<< cc << endl;
    cout << "The copied characters array1 is: "<<arrayPtr<<endl;

    return 0;
}
