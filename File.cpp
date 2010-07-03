/* 
 * File:   File.cpp
 * Author: Paulius Pilkauskas
 * 
 * Created on July 3, 2010, 4:20 PM
 */

#include "File.h"
#include <sstream>
using namespace std;

File::File(string fileName) {
    this->file = new ifstream(fileName.c_str(), ios_base::in);
}

File::~File() {
}

/*
 * PRIVATE
 */


/*
 * PUBLIC
 */

string File::charToString(char c) {
    stringstream ss;
    string       s;

    ss << c;
    ss >> s;

    return s;
}

int File::stringToInt(string s) {
    stringstream ss;
    int          i;

    ss << s;
    ss >> i;

    return i;
}

string File::getContent() {
    string content = "";

    while (this->file->good())
        content += charToString(getChar());

    return content;
}

char File::getChar() {
    char c;

    if (this->file->good())
        c = this->file->get();

    return c;
}

bool File::isGood() {
    return this->file->good() ? true : false;
}
