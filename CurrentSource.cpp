//
// Created by hassan on 28/11/18.
//

#include "CurrentSource.h"
#include "ZMatrix.h"
void CurrentSource::initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) {
    zMatrix.registerCurrentSource(*this);

}

CurrentSource::CurrentSource(int srcNode, int dstNode, double value, double currentParam) : Component(srcNode, dstNode,
                                                                                                      value,
                                                                                                      currentParam) {

}
