#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include<vector>
#include <fstream>

using namespace std;

template <class T>

class Matrix
{
private:
	int rows;
	int cols;
	T** data;

public:
	Matrix(int rows, int cols) : rows(rows), cols(cols) {
		data = new T * [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new T[cols];
		}
	}
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void random() {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = rand() % 10;
            }
        }
    }

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Введите значение для элемента в строке " << i << " и колонна " << j << ": ";
                cin >> data[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << '\n';
        }
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Размеры матрицы не совпадают");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Размеры матрицы не совпадают");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    
    T max() {
        T max = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] > max) {
                    max = data[i][j];
                }
            }
        }
        return max;
    }

    T min() {
        T min = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] < min) {
                    min = data[i][j];
                }
            }
        }
        return min;
    }
};