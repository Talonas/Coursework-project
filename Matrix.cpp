/* 
 * File:   Matrix.cpp
 * Author: Paulius Pilkauskas
 * 
 * Created on July 2, 2010, 2:52 PM
 */

#include "Matrix.h"
#include "File.h"

using namespace std;

/*
 * PUBLIC
 */

Matrix::Matrix(int size, string fileName) {
    this->size     = size;
    this->fileName = fileName;

    allocateMemory();
    fillMatrixValues();
}

Matrix::~Matrix() {
    freeMemory();
}

/*
 * PRIVATE
 */

void Matrix::allocateMemory() {
    this->matrix = new string * [this->size];
    for (int i = 0; i < this->size; ++i)
        this->matrix[i] = new string[this->size];
}

void Matrix::freeMemory() {
    for (int i = 0; i < this->size; i++)
        free(this->matrix[i]);
    free(this->matrix);
}

void Matrix::fillMatrixValues() {
    File * file = new File(this->fileName);
    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            this->matrix[i][j] = file->charToString(file->getChar());
}

/*
 * PUBLIC
 */

string** Matrix::getMatrix() {
    return this->matrix;
}

bool Matrix::compareMatrix(string** otherMatrix) {
    for (int i = 0; i < this->size; i++)
        for (int j = 0; j < this->size; j++)
            if (otherMatrix[i][j] != this->matrix[i][j])
                return false;

    return true;
}