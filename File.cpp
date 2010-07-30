#include <sstream>

#include "File.h"

using namespace std;

/*
 * Public
 */
File::File(string file_name) {
    this->file = new ifstream(file_name.c_str(), ios_base::in);
}

File::~File() {
}

string File::getContent() {
    /**
     * Returns content of a file
     */
    string content = "";

    while (this->file->good())
        content += charToString(getChar());
}

string File::charToString(char c) {
    /**
     * Converts char to string
     */
    stringstream ss;
    string       s;

    ss << c;
    ss >> s;

    return s;
}

char File::getChar() {
    char c;

    if (this->file->good())
        c = this->file->get();

    return c;
}

int File::stringToInt(string s) {
    /**
     * Converts string to integer
     */
    stringstream ss;
    int          i;

    ss << s;
    ss >> i;

    return i;
}
