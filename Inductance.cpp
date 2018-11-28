//
// Created by hassan on 28/11/18.
//

#include "Inductance.h"

Inductance::Inductance(int srcNode, int dstNode, double value, double currentParam) : Component(srcNode, dstNode, value,
                                                                                                currentParam) {

}

void Inductance::updateMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {

}
