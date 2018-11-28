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
#include <ostream>
class AMatrix {
private:
    double ** matrix;
    int numRows,numColumns;
    int gMatrixRowStart,gMatrixColumnStart;
    int bMatrixRowStart,bMatrixColumnStart;
    int cMatrixRowStart,cMatrixColumnStart;
    int dMatrixRowStart,dMatrixColumnStart;
    void editGMatrix(int row, int column, double value);
    void editBMatrix(int row, int column, double value);
    void editCMatrix(int row, int column, double value);
    void editDMatrix(int row, int column, double value);
    bool checkAndDecrement(int & row, int & column);
public:
    void registerResistance(const Resistance &resistance);
    void registerCapacitance(const Capacitance &capacitance);
    void registerInductance(const Inductance &inductance);
    void registerVoltageSource(const VoltageSource &voltageSource);
    friend std::ostream & operator << (std::ostream & ostream, const AMatrix & aMatrix);
    AMatrix(int n, int m);
    ~AMatrix();

};


#endif //MODELLINGASSIGNMENT2_AMATRIX_H
