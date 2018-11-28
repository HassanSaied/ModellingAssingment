//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_CURRENTSOURCE_H
#define MODELLINGASSIGNMENT2_CURRENTSOURCE_H


#include "Component.h"

class CurrentSource : Component {
    CurrentSource(int srcNode, int dstNode, double value, double currentParam);
    void updateMatrix(AMatrix & aMatrix, ZMatrix & zMatrix) override;
};


#endif //MODELLINGASSIGNMENT2_CURRENTSOURCE_H
