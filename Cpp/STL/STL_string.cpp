#include <iostream>
using namespace std;
#include <string>

void test1()
{
    string s1;
    const char* str = "hello";
    string s2(str);
    cout << "s2=" << s2 << endl;
    string s3(s2);
    cout << s3 << endl;
    string s4(4, 'a');
    cout << s4;
}
void test2()
{
    string str1;
    str1 = "hell0";
    cout << str1 << endl;
    string str2 = str1;
    cout << str2 << endl;
    string str4;
    str4.assign("hellaosdfja");
    cout << str4 << endl;
    string str5;
    str5.assign("asfas;klkalfdj", 6);
    cout << str5 << endl;
    string str6;
    str6.assign(str5);
    string str7;
    str7.assign(5, 'f');
    cout << str7 << endl;


}

void test3()
{
    //拼接字符串
    string str1 = "I";

    str1 += " like GAme ";

    cout << str1 << endl;
    str1 += ';';
    cout << str1 << endl;

    string str2 = "pubg";
    str1 += str2;
    cout << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << str3 << endl;

    str3.append("pubg", 2);
    cout << str3 << endl;

    str3.append(str1);
    cout << str3 << endl;

    str3.append(str1, 11, 4);
    cout << str3 << endl;
}

void test4()
{
    //find 从左往右找
    string s1 = "abcdefgde";

    int pos = s1.find("de");
    int pos1 = s1.find("ed");
    if (pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }
    //rfind 从右往左找
    pos = s1.rfind("de");

    cout << "pos = " << pos << endl;

    //替换 
    s1.replace(1, 3, "1111");//从1位起,把三个字符替换为""里的字符串
    cout << s1 << endl;

}

void test5()
{
    string s1 = "hello";
    string s2 = "aello";

    int ret = s1.compare(s2);

    if (ret == 0) {
        cout << "s1 等于 s2" << endl;
    }
    else if (ret > 0)
    {
        cout << "s1 大于 s2" << endl;
    }
    else
    {
        cout << "s1 小于 s2" << endl;
    }
}

void test6()
{
    string str = "hello world";
    //1.通过[]访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    //2.通过at访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    //修改单个字符
    str[0] = 'x';
    str.at(1) = 'z';
    cout << str << endl;
}

void test7()
{
    string str = "hello";
    str.insert(1, "111");
    cout << str << endl;

    str.erase(1, 3);  //从1号位置开始3个字符
    cout << str << endl;
}

void test8()
{
    string str = "abcdefg";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;
    //实用操作-获取用户名
    string email = "hello@sina.com";
    int pos = email.find("@");
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;
}
int main()
{
    //test1();//string构造函数 string("xxx") string(s1) string()
    //test2();//string赋值    = assign
    //test3();//字符串拼接 += append
    //test4();//查找和替换 find rfind(right->left) replace
    //test5();//字符串比较 compare
    //test6();//字符串存取 []/at
    //test7();//字符串插入和删除 insert eraser
    test8();//获取子串 substr
    return 0;
}