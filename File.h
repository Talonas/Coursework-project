#ifndef _FILE_H
#define	_FILE_H

#include <fstream>

using namespace std;

class File {
public:
    File(string);
    ~File();

    string getContent();
    string charToString(char);
    char   getChar();
    int    stringToInt(string);
    
private:
    ifstream file;
};

#endif	/* _FILE_H */

