//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_INDUCTANCE_H
#define MODELLINGASSIGNMENT2_INDUCTANCE_H


#include "Component.h"

class Inductance : public Component {
private:
public:
    int getIndex() const;

private:
    int index;
public:
    Inductance(int srcNode, int dstNode, double value, double currentParam, int index);

    void initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) override;

};


#endif //MODELLINGASSIGNMENT2_INDUCTANCE_H
