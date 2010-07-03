/* 
 * File:   Matrix.h
 * Author: Paulius Pilkauskas
 *
 * Created on July 2, 2010, 2:52 PM
 */

#ifndef _MATRIX_H
#define	_MATRIX_H

#include <string>

using namespace std;

class Matrix {
public:
    Matrix(int, string);
    ~Matrix();
private:
    /*
     * Variables
     */
    string** matrix;
    string   fileName;
    int      size;

    /*
     * Methods
     */
    string** getMatrix();

    bool compareMatrix(string**);

    void allocateMemory();
    void freeMemory();
    void fillMatrixValues();

};

#endif	/* _MATRIX_H */

