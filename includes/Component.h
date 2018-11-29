//
// Created by hassan on 28/11/18.
//

#ifndef MODELLINGASSIGNMENT2_COMPONENT_H
#define MODELLINGASSIGNMENT2_COMPONENT_H


class XMatrix;
class AMatrix;
class ZMatrix;
class Component {
private:
    int srcNode, dstNode;
    double value;
public:
    int getSrcNode() const;

    int getDstNode() const;

    double getValue() const;

    double getCurrentParameter() const;

private:
    double currentParameter;

public:
    Component(int srcNode, int dstNode, double value, double currentParameter);
    virtual void initializeMatrix(AMatrix &aMatrix, ZMatrix &zMatrix) = 0;
    void setCurrentParameter(double currentParameter);
    virtual void updateValueAfterIteration(XMatrix &xMatrix, ZMatrix &zMatrix) = 0;

};


#endif //MODELLINGASSIGNMENT2_COMPONENT_H
