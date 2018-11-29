//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_ZMATRIX_H
#define MODELLINGASSIGNMENT2_ZMATRIX_H

#include "CurrentSource.h"
#include "Capacitance.h"
#include "VoltageSource.h"
#include "Inductance.h"
#include <ostream>


class ZMatrix {
private:
    double ** matrix;
    int eMatrixBegin;
    int matrixSize;
    void editIMatrix(int row, double value);
    void editEMatrix(int row, double value);
public:
    void registerCurrentSource(const CurrentSource &currentSource);
    void registerVoltageSource(const VoltageSource &voltageSource);
    void registerCapacitance(const Capacitance &capacitance);
    void registerInductance(const Inductance & inductance);
    friend std::ostream & operator << (std::ostream & outputStream, const ZMatrix & zMatrix);
    ZMatrix(int n, int m);
    ~ZMatrix();

    double **getMatrix() const;

};


#endif //MODELLINGASSIGNMENT2_ZMATRIX_H
