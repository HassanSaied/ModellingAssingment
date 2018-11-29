//
// Created by hassan on 11/29/18.
//

#ifndef MODELLINGASSIGNMENT2_XMATRIX_H
#define MODELLINGASSIGNMENT2_XMATRIX_H

#include <bits/stdc++.h>
#include "AMatrix.h"
#include "ZMatrix.h"
using namespace std;
class XMatrix {
private:
    double** currentResultMatrix,**invertedAMatrix;
    int matrixSize,numNodes,numVoltageSources;
    vector<vector<double>> nodeVoltages;
    vector<vector<double>> currentValues;
public:
    XMatrix(int n, int m);
    void updateMatrix(const AMatrix & aMatrix, const ZMatrix & zMatrix);
    double getVoltageBetweenTwoNodes(int src, int dst);
    double getCurrentThroughVoltageSrc(int voltageSourceIndex);
    ~XMatrix();
    friend ostream &operator << (ostream & out, const XMatrix & xMatrix);
};


#endif //MODELLINGASSIGNMENT2_XMATRIX_H
