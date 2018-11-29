//
// Created by hassan on 28/11/18.
//

#include "Inductance.h"
#include "AMatrix.h"
#include "ZMatrix.h"
#include "XMatrix.h"
Inductance::Inductance(int srcNode, int dstNode, double value, double currentParam, int index) : Component(srcNode, dstNode, value,
                                                                                                currentParam),index(index) {

}

void Inductance::initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {
    aMatrix.registerInductance(*this);
    zMatrix.registerInductance(*this);
}

int Inductance::getIndex() const {
    return index;
}

void Inductance::updateValueAfterIteration(XMatrix &xMatrix, ZMatrix &zMatrix) {
    setCurrentParameter(xMatrix.getCurrentThroughVoltageSrc(index));
    zMatrix.registerInductance(*this);

}
