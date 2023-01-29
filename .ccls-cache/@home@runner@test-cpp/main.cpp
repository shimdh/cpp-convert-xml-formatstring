#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>

template <typename T>
std::wstring ConvertXmlFormatStringClass(const T& Target)
{
    std::wstringstream StringStream;
    StringStream << L"<R " << Target.toString().c_str() << L" />";
    return StringStream.str();
}

template <typename T>
std::wstring ConvertXmlFormatString(const std::wstring& ParamName, const T& Target)
{
    std::wstringstream StringStream;
    StringStream << ParamName.c_str() << L"=\"" << Target << L"\" ";
    return StringStream.str();
}


class MyClass {
    std::map<std::wstring, std::wstring> m_data;
public:
    MyClass(std::map<std::wstring, std::wstring> data) : m_data(data) {}
    std::wstring toString() const {
        std::wstring result;
        for (const auto& [key, value] : m_data) {
            result += ConvertXmlFormatString(key, value);
        }
        return result;
    }
};

void ConvertXmlFormatStringMap(const std::vector<MyClass>& myClassList) {
    for (const auto& myClass : myClassList) {
        std::wstring result = ConvertXmlFormatStringClass(myClass);
        std::wcout << result << std::endl;
    }
}

int main()
{
    std::vector<MyClass> myClassList = {
        MyClass({ { L"name", L"John Doe" }, { L"age", L"30" } }),
        MyClass({ { L"name", L"Jane Doe" }, { L"age", L"25" } }),
        MyClass({ { L"name", L"Bob Smith" }, { L"age", L"35" } })
    };

    ConvertXmlFormatStringMap(myClassList);
}