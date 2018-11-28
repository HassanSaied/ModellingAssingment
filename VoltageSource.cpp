//
// Created by hassan on 28/11/18.
//

#include "VoltageSource.h"
#include "AMatrix.h"
#include "ZMatrix.h"
VoltageSource::VoltageSource(int srcNode, int dstNode, double value, double currentParam, int index) : Component(
        srcNode, dstNode,
        value,
        currentParam), index(index) {

}

void VoltageSource::initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {
    aMatrix.registerVoltageSource(*this);
    zMatrix.registerVoltageSource(*this);

}

int VoltageSource::getIndex() const {
    return index;
}
