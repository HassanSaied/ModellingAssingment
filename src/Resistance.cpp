//
// Created by hassan on 28/11/18.
//

#include "Resistance.h"
#include "AMatrix.h"
Resistance::Resistance(int srcNode, int dstNode, double value, double currentParam) : Component(srcNode, dstNode, value,
                                                                                                currentParam) {

}

void Resistance::initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {
    aMatrix.registerResistance(*this);

}

void Resistance::updateValueAfterIteration(XMatrix &xMatrix, ZMatrix &zMatrix) {

}
