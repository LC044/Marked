//
// Created by zenglj on 2023/1/29.
//

#pragma once

#include <string>

std::string int2str(int num);

std::string double2str(double num);
std::string readFileIntoString(const std::string& path); 
bool isLetter(char ch);
bool isDigital(char ch);
bool isLetterDigital(char ch);
bool isLetterDigitalUnderLine(char ch);
bool isLetterUnderLine(char ch);
void printError(int lineno, std::string msg);