//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_ZMATRIX_H
#define MODELLINGASSIGNMENT2_ZMATRIX_H

#include "CurrentSource.h"
#include "Capacitance.h"
#include "VoltageSource.h"
class ZMatrix {
private:
    double ** matrix;
public:
    void registerCurrentSource(CurrentSource currentSource);
    void registerVoltageSource(VoltageSource voltageSource);
    void registerCapacitance(Capacitance capacitance);

};


#endif //MODELLINGASSIGNMENT2_ZMATRIX_H
