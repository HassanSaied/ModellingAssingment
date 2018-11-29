//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_CURRENTSOURCE_H
#define MODELLINGASSIGNMENT2_CURRENTSOURCE_H


#include "Component.h"

class CurrentSource : public Component {
public:
    CurrentSource(int srcNode, int dstNode, double value, double currentParam);
    void initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) override;
    void updateValueAfterIteration(XMatrix &xMatrix, ZMatrix &zMatrix) override;
};


#endif //MODELLINGASSIGNMENT2_CURRENTSOURCE_H
