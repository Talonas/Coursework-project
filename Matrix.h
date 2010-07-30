#include <string>

#ifndef _MATRIX_H
#define	_MATRIX_H

using namespace std;

class Matrix {
public:
    Matrix(string);
    Matrix(string, int);
    ~Matrix();

    string** getContent();
    int      getSize();

private:
    string** content;
    string   file_name;
    int      size;

    void allocateMemory();
    void freeMemory();
    void fillContent();
};

#endif	/* _MATRIX_H */

