#include <iostream>
#include <cstring>

using namespace std;

bool _GetSubPath(std::string& strPath,std::string& strSubPath, int nSearch);

int main()
{
    /*
     * 查找某个字符串中某两个子字符串之间的字符串（返回“2000坐标系”）
     */
    std::string strPath = "E:\\数据\\2018\\2000坐标系\\a.shp";
    std::string::size_type nPos1 = std::string::npos;
    std::string::size_type nPos2 = std::string::npos;
    nPos1 = strPath.find_last_of("\\");
    nPos2 = strPath.find_last_of("\\", nPos1 - 1);
    if(nPos1 !=-1 && nPos2 != -1)
    {
        strPath = strPath.substr(nPos2 + 1, nPos1 - nPos2 - 1);
    }

    cout <<strPath<<endl;
    /*
     *直接查找字符串中是否具有某个字符串（返回"1"）
     */
    int a = 0;
    if (strPath.find("2018") == std::string::npos)
    {
        a = 1;
    }
    else
    {
        a = 2;
    }
    cout <<a<<endl;

    //  查找某个字符串的字符串（返回“E:”）
    int nPos = strPath.find("\\");
    if(nPos != -1)
    {
        strPath = strPath.substr(0, nPos);
    }
    cout <<strPath<<endl;

//获取路径名中的子目录:strPath为路径名，strSubPath为输出的子目录，
// nSearch为从尾向前检索的级别(默认为1级)

    std::string strSubPath = "";
    if(_GetSubPath(strPath, strSubPath, 1))
    {
        printf("返回'a.shp'");
    }
    if(_GetSubPath(strPath, strSubPath, 2))
    {
        printf("返回'2000坐标系'");
    }

    return 0;
}


//获取路径名中的子目录:strPath为路径名，strSubPath为输出的子目录，
// nSearch为从尾向前检索的级别(默认为1级)

bool _GetSubPath(std::string& strPath, std::string& strSubPath, int nSearch)
{
    if (-1 == nSearch || strPath.empty())
        return false;
    std::string::size_type nPos1 = std::string::npos;
    nPos1 = strPath.find_last_of("\\");
    if (nPos1 != -1)
    {
        strPath = strPath.substr(0, nPos1);
        strSubPath = strPath.substr(nPos1 + 1, strPath.length() - nPos1);
        int nNewSearch = nSearch > 1 ? nSearch - 1 : -1;
        _GetSubPath(strPath, strSubPath, nNewSearch);
    }
    return true;
}

