//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_VOLTAGESOURCE_H
#define MODELLINGASSIGNMENT2_VOLTAGESOURCE_H


#include "Component.h"

class VoltageSource : public Component {
private:
    int index;
public:
    VoltageSource(int srcNode, int dstNode, double value, double currentParam,int index);

    int getIndex() const;

    void initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) override;
};


#endif //MODELLINGASSIGNMENT2_VOLTAGESOURCE_H
