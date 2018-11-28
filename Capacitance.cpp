//
// Created by hassan on 28/11/18.
//

#include "Capacitance.h"

Capacitance::Capacitance(int srcNode, int dstNode, double value, double currentParam) : Component(srcNode, dstNode,
                                                                                                  value, currentParam) {

}

void Capacitance::updateMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {

}
