//
// Created by hassan on 28/11/18.
//

#include "AMatrix.h"
#include <bits/stdc++.h>
void AMatrix::registerResistance(Resistance resistance) {
    editGMatrix(resistance.getSrcNode(),resistance.getSrcNode(), resistance.getValue());
    editGMatrix(resistance.getDstNode(),resistance.getDstNode(),resistance.getValue());
    editGMatrix(resistance.getSrcNode(),resistance.getDstNode(),-resistance.getValue());
    editGMatrix(resistance.getDstNode(),resistance.getSrcNode(),-resistance.getValue());
}

void AMatrix::registerCapacitance(Capacitance capacitance) {
    editGMatrix(capacitance.getSrcNode(),capacitance.getSrcNode(), capacitance.getValue());
    editGMatrix(capacitance.getDstNode(),capacitance.getDstNode(),capacitance.getValue());
    editGMatrix(capacitance.getSrcNode(),capacitance.getDstNode(),-capacitance.getValue());
    editGMatrix(capacitance.getDstNode(),capacitance.getSrcNode(),-capacitance.getValue());


}

void AMatrix::registerInductance(Inductance inductance) {

}

void AMatrix::registerVoltageSource(VoltageSource voltageSource) {

}

void AMatrix::editGMatrix(int row, int column, double value) {
    row += gMatrixRowStart;
    column += gMatrixColumnStart;
    matrix[row][column] += value;
}

void AMatrix::editBMatrix(int row, int column, double value) {
    row += bMatrixRowStart;
    column += bMatrixColumnStart;
    matrix[row][column] = std::max(1 ,std::min(-1,(int)matrix[row][column] + value);
}

void AMatrix::editCMatrix(int row, int column, double value) {
    row +=cMatrixRowStart;
    column += cMatrixColumnStart;
    matrix[row][column] += value;
}

void AMatrix::editDMatrix(int row, int column, double value) {
    row += dMatrixRowStart;
    column +=dMatrixColumnStart;
    matrix[row][column] += value;
}

AMatrix::AMatrix(int n, int m, int l) {
    initializeMatrix(matrix, n, m + l);

    gMatrixRowStart = 0;
    gMatrixColumnStart = 0;

    bMatrixRowStart = 0;
    bMatrixColumnStart = n;

    cMatrixRowStart = n;
    cMatrixColumnStart = 0;

    dMatrixRowStart = n;
    dMatrixColumnStart = n;
}
