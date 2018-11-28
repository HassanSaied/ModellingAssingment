//
// Created by hassan on 28/11/18.
//

#include "ZMatrix.h"
#include "Matrix.h"

void ZMatrix::registerCapacitance(const Capacitance &capacitance) {
    double value = capacitance.getValue()*capacitance.getCurrentParameter();
    if(capacitance.getSrcNode() == 0){
        editIMatrix(capacitance.getDstNode(),value);
        return;
    }
    if(capacitance.getDstNode() ==0){
        editIMatrix(capacitance.getSrcNode(),value);
        return;
    }
    editIMatrix(capacitance.getSrcNode(),value);
    editIMatrix(capacitance.getDstNode(),-value);

}

void ZMatrix::registerVoltageSource(const VoltageSource &voltageSource) {
    editEMatrix(voltageSource.getIndex(),voltageSource.getValue());
}

void ZMatrix::registerCurrentSource(const CurrentSource &currentSource) {
    if(currentSource.getSrcNode() == 0){
        editIMatrix(currentSource.getDstNode(),currentSource.getValue());
        return;
    }
    if(currentSource.getDstNode() == 0){
        editIMatrix(currentSource.getSrcNode(),currentSource.getValue());
        return;
    }
    editIMatrix(currentSource.getSrcNode(),currentSource.getValue());
    editIMatrix(currentSource.getDstNode(),-currentSource.getValue());
}

void ZMatrix::registerInductance(const Inductance &inductance) {
    double value = inductance.getValue()*inductance.getCurrentParameter();
    editEMatrix(inductance.getIndex(),value);
}

ZMatrix::ZMatrix(int n, int m) {
    matrixSize = n+m;
    matrix = new double*[matrixSize];
    for (int i = 0; i < matrixSize; ++i) {
        matrix[i] = new double;
    }
    initializeMatrix(matrix,matrixSize,1);
    eMatrixBegin = n;

}

void ZMatrix::editIMatrix(int row, double value) {
    row-=1;
    matrix[row][1] = value;
}

void ZMatrix::editEMatrix(int row, double value) {
    row+=eMatrixBegin;
    matrix[row][1] = value;
}

ZMatrix::~ZMatrix() {
    for (int i = 0; i < matrixSize; ++i) {
        delete matrix[i];
    }
    delete []matrix;
}

std::ostream &operator<<(std::ostream &outputStream, const ZMatrix &zMatrix) {
    for (int i = 0; i < zMatrix.matrixSize; ++i) {
        outputStream<<zMatrix.matrix[i]<<std::endl;
    }
    return outputStream;
}
