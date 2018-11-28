//
// Created by hassan on 28/11/18.
//

#include "Capacitance.h"
#include "AMatrix.h"
#include "ZMatrix.h"
Capacitance::Capacitance(int srcNode, int dstNode, double value, double currentParam) : Component(srcNode, dstNode,
                                                                                                  value, currentParam) {

}

void Capacitance::initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {
    aMatrix.registerCapacitance(*this);
    zMatrix.registerCapacitance(*this);
}
