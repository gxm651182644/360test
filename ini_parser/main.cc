#include "ini_parser.h"
#include<cstring>
#include <assert.h>

void test1()
{
    const char* ini_text= "a=1\nb=2\n";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test3()
{
    //测试含有空格的情况
    const char* ini_text= "    a=1||b=2||c=3";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test4()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");

	std::string s=ini_text;
	bool f;
	const std::string& aa = parser.Get(s,"a",&f);
	assert(aa == "1");
}
void test5()
{   //测试key 比较长的情况
    const char* ini_text= "name1=1\nname2=2\n";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& name1 = parser.Get("name1", NULL);
    assert(name1 == "1");

    std::string name2 = parser.Get("name2", NULL);
    assert(name2 == "2");

    const std::string& name3 = parser.Get("name3", NULL);
    assert(name3 == "");
}


void test6()
{   //测试key和value比较长的情况
    const char* ini_text= "name1=val1\nname2=val2\n";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& name1 = parser.Get("name1", NULL);
    assert(name1 == "val1");

    std::string name2 = parser.Get("name2", NULL);
    assert(name2 == "val2");

    const std::string& name3 = parser.Get("name3", NULL);
    assert(name3 == "");
}


void test7()
{
    //测试key和valuezh之间的分割符比较长的情况
    const char* ini_text= "a=>>>1||b=>>>2||c=>>>3";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=>>>")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test8()
{
    //测试key和value里面包含相同字符的情况
    const char* ini_text= "a=>1|=|b=>2|=|c=>3";
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "|=|", "=>")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test9()
{
    /*测试get函数：
     const std::string& Get(const std::string& section, const std::string& key, bool* found);
    */
    const char* ini_text= "a=1\nb=2\n";
    std::string nstr=ini_text;
    qh::INIParser parser;

    const std::string& a = parser.Get(nstr,"a", NULL);
    assert(a == "1");

    std::string b = parser.Get(nstr,"b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get(nstr,"c", NULL);
    assert(c == "");
}

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    return 0;
}


