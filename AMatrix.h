//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_AMATRIX_H
#define MODELLINGASSIGNMENT2_AMATRIX_H

#include "Resistance.h"
#include "Inductance.h"
#include "Capacitance.h"
#include "VoltageSource.h"
#include "Matrix.h"
class AMatrix {
private:
    double ** matrix;
    int gMatrixRowStart,gMatrixColumnStart;
    int bMatrixRowStart,bMatrixColumnStart;
    int cMatrixRowStart,cMatrixColumnStart;
    int dMatrixRowStart,dMatrixColumnStart;
    void editGMatrix(int row, int column, double value);
    void editBMatrix(int row, int column, double value);
    void editCMatrix(int row, int column, double value);
    void editDMatrix(int row, int column, double value);
public:
    void registerResistance(Resistance resistance);
    void registerCapacitance(Capacitance capacitance);
    void registerInductance(Inductance inductance);
    void registerVoltageSource(VoltageSource voltageSource);
    AMatrix(int n, int m, int l);

};


#endif //MODELLINGASSIGNMENT2_AMATRIX_H
