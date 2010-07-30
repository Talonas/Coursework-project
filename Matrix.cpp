#include <string>
#include "Matrix.h"

using namespace std;

/*
 * Public
 */
Matrix::Matrix(string file_name) {
    this->file_name = file_name;

    allocateMemory();
    fillContent();
}

Matrix::Matrix(string file_name, int size) {
    this->file_name = file_name;
    this->size      = size;

    allocateMemory();
    fillContent();
}

Matrix::~Matrix() {
    freeMemory();
}

string** Matrix::getContent() {
    /**
     * Returns content of a matrix
     */
    return this->content;
}

int Matrix::getSize() {
    /**
     * Returns matrix size
     */
    return this->size;
}

/*
 * Private
 */
void Matrix::allocateMemory() {
    /**
     * Allocates memory for matrix content
     */
    this->content = new string* [this->size];
    for (int i = 0; i < this->size; ++i)
        this->content[i] = new string[this->size];
}

void Matrix::freeMemory() {
    /**
     * Frees memory of matrix content
     */
    for (int i = 0; i < this->size; i++)
        free(this->content[i]);
    free(this->content);
}

void Matrix::fillContent() {
    /**
     * Fills matrix content
     */
}
