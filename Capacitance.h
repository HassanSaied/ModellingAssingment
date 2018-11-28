//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_CAPACITANCE_H
#define MODELLINGASSIGNMENT2_CAPACITANCE_H


#include "Component.h"

class Capacitance : public Component {
    Capacitance(int srcNode, int dstNode, double value, double currentParam);

    void updateMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) override;
};


#endif //MODELLINGASSIGNMENT2_CAPACITANCE_H
