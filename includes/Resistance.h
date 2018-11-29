//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_RESISTANCE_H
#define MODELLINGASSIGNMENT2_RESISTANCE_H


#include "Component.h"

class Resistance :  public Component {
public:
    Resistance(int srcNode, int dstNode, double value, double currentParam);

    void initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) override;
    void updateValueAfterIteration(XMatrix &xMatrix, ZMatrix &zMatrix) override;
};


#endif //MODELLINGASSIGNMENT2_RESISTANCE_H
