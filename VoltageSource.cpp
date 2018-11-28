//
// Created by hassan on 28/11/18.
//

#include "VoltageSource.h"

VoltageSource::VoltageSource(int srcNode, int dstNode, double value, double currentParam) : Component(srcNode, dstNode,
                                                                                                      value,
                                                                                                      currentParam) {

}

void VoltageSource::updateMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {

}
