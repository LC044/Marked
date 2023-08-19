//
// Created by zenglj on 2023/1/29.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

// 整数变字符串
string int2str(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

// 整数变字符串
string double2str(double num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}
std::string readFileIntoString(const std::string& path) {
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}
// 检查字符是否是字母（大小写字母）
bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// 检查字符是否为数字(0-9)
bool isDigital(char ch)
{
    return (ch >= '0' && ch <= '9');
}

// 检查字符是否为大小写字符或数字(0-9)
bool isLetterDigital(char ch)
{
    return isLetter(ch) || isDigital(ch);
}

// 检查字符是否为大小写字符或数字(0-9)或下划线
bool isLetterDigitalUnderLine(char ch)
{
    return isLetterDigital(ch) || (ch == '_');
}

// 检查字符是否为大小写字符或下划线
bool isLetterUnderLine(char ch)
{
    return isLetter(ch) || (ch == '_');
}

void printError(int lineno, std::string msg)
{
    printf("line: %d : %s\n", lineno, msg.c_str());
}