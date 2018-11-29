//
// Created by hassan on 28/11/18.
//

#include "../includes/Capacitance.h"
#include "../includes/AMatrix.h"
#include "../includes/ZMatrix.h"
#include "../includes/XMatrix.h"
Capacitance::Capacitance(int srcNode, int dstNode, double value, double currentParam) : Component(srcNode, dstNode,
                                                                                                  value, currentParam) {

}

void Capacitance::initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {
    aMatrix.registerCapacitance(*this);
    zMatrix.registerCapacitance(*this);
}

void Capacitance::updateValueAfterIteration(XMatrix &xMatrix, ZMatrix &zMatrix) {
    setCurrentParameter(xMatrix.getVoltageBetweenTwoNodes(getSrcNode(),getDstNode()));
    zMatrix.registerCapacitance(*this);
}
