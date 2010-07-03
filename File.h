/* 
 * File:   File.h
 * Author: Paulius Pilkauskas
 *
 * Created on July 3, 2010, 4:20 PM
 */

#ifndef _FILE_H
#define	_FILE_H

#include <string>
#include <fstream>

using namespace std;

class File {
public:
    File(string);
    ~File();

    /*
     * Methods
     */
    string getContent();
    char   getChar();
    bool   isGood();
    string charToString(char);
    int    stringToInt(string);

private:
    ifstream* file;

    /*
     * Methods
     */

};

#endif	/* _FILE_H */

