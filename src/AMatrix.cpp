//
// Created by hassan on 28/11/18.
//

#include "../includes/AMatrix.h"
#include <bits/stdc++.h>

void AMatrix::registerResistance(const Resistance &resistance) {
    editGMatrix(resistance.getSrcNode(), resistance.getSrcNode(), resistance.getValue());
    editGMatrix(resistance.getDstNode(), resistance.getDstNode(), resistance.getValue());
    editGMatrix(resistance.getSrcNode(), resistance.getDstNode(), -resistance.getValue());
    editGMatrix(resistance.getDstNode(), resistance.getSrcNode(), -resistance.getValue());
}

void AMatrix::registerCapacitance(const Capacitance &capacitance) {
    editGMatrix(capacitance.getSrcNode(), capacitance.getSrcNode(), capacitance.getValue());
    editGMatrix(capacitance.getDstNode(), capacitance.getDstNode(), capacitance.getValue());
    editGMatrix(capacitance.getSrcNode(), capacitance.getDstNode(), -capacitance.getValue());
    editGMatrix(capacitance.getDstNode(), capacitance.getSrcNode(), -capacitance.getValue());


}

void AMatrix::registerInductance(const Inductance &inductance) {
    editBMatrix(inductance.getSrcNode(), inductance.getIndex()+1, 1);
    editBMatrix(inductance.getDstNode(), inductance.getIndex()+1, -1);
    editDMatrix(inductance.getIndex(), inductance.getIndex(), -inductance.getValue());
}

void AMatrix::registerVoltageSource(const VoltageSource &voltageSource) {
    editBMatrix(voltageSource.getSrcNode(), voltageSource.getIndex() + 1, 1);
    editBMatrix(voltageSource.getDstNode(), voltageSource.getIndex() + 1, -1);
}

void AMatrix::editGMatrix(int row, int column, double value) {
    if (checkAndDecrement(row, column)) {
        row += gMatrixRowStart;
        column += gMatrixColumnStart;
        matrix[row][column] += value;
    }
}

void AMatrix::editBMatrix(int row, int column, double value) {
    if (checkAndDecrement(row, column)) {
        row += bMatrixRowStart;
        column += bMatrixColumnStart;
        if (value == 1) {
            matrix[row][column] = 1;
        } else if (value == -1) {
            matrix[row][column] = matrix[row][column] == -1 ? matrix[row][column] : matrix[row][column] + value;
        } else {
            matrix[row][column] += value;
        }
        editCMatrix(column - bMatrixColumnStart, row - bMatrixRowStart, matrix[row][column]);
    }
}

void AMatrix::editCMatrix(int row, int column, double value) {
    row += cMatrixRowStart;
    column += cMatrixColumnStart;
    matrix[row][column] = value;
}

void AMatrix::editDMatrix(int row, int column, double value) {
    row += dMatrixRowStart;
    column += dMatrixColumnStart;
    matrix[row][column] += value;
}

AMatrix::AMatrix(int n, int m) {
    numRows = n + m;
    numColumns = m + n;
    matrix = new double *[numRows];
    for (int i = 0; i < numRows; ++i) {
        matrix[i] = new double[numColumns];
    }
    initializeMatrix(matrix, numRows, numColumns);

    gMatrixRowStart = 0;
    gMatrixColumnStart = 0;

    bMatrixRowStart = 0;
    bMatrixColumnStart = n;

    cMatrixRowStart = n;
    cMatrixColumnStart = 0;

    dMatrixRowStart = n;
    dMatrixColumnStart = n;
}

bool AMatrix::checkAndDecrement(int &row, int &column) {
    if (row == 0 || column == 0) {
        return false;
    }
    row -= 1;
    column -= 1;
}

AMatrix::~AMatrix() {
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[]matrix;
}

std::ostream &operator<<(std::ostream &outputStream, const AMatrix &aMatrix) {
    for (int i = 0; i < aMatrix.numRows; ++i) {
        for (int j = 0; j < aMatrix.numColumns; ++j) {
            outputStream << aMatrix.matrix[i][j] << " ";
        }
        outputStream << std::endl;
    }
    return outputStream;
}

double **AMatrix::getMatrix() const {
    return matrix;
}
