#ifndef BASIC_H
#define BASIC_H
#include <cctype>
#include <iostream>
#include <fstream>
#include <regex>
#include <cstring>
#include <string>

using namespace std;

string read(string path);
string whichPath(void);
void save(string text, string path, int shift);
void readTabelFromText(string table[], string path);
void readTabelFromText(char table[], string path);
#endif // BASIC_H
