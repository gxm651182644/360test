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
    //���Ժ��пո�����
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
{   //����key �Ƚϳ������
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
{   //����key��value�Ƚϳ������
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
    //����key��valuezh֮��ķָ���Ƚϳ������
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
    //����key��value���������ͬ�ַ������
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
    /*����get������
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
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
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


