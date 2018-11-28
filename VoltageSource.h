//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_VOLTAGESOURCE_H
#define MODELLINGASSIGNMENT2_VOLTAGESOURCE_H


#include "Component.h"

class VoltageSource : public Component {
    VoltageSource(int srcNode, int dstNode, double value, double currentParam);

    void updateMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) override;
};


#endif //MODELLINGASSIGNMENT2_VOLTAGESOURCE_H
