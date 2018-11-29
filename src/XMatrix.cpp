//
// Created by hassan on 11/29/18.
//


#include "XMatrix.h"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

XMatrix::XMatrix(int n, int m) : nodeVoltages(n, vector<double>()), currentValues(m, vector<double>()) {
    matrixSize = n + m;
    numNodes = n;
    numVoltageSources = m;
    currentResultMatrix = new double *[matrixSize];
    for (int i = 0; i < n + m; ++i) {
        currentResultMatrix[i] = new double;
    }
    invertedAMatrix = new double *[matrixSize];
    for (int i = 0; i < matrixSize; ++i) {
        invertedAMatrix[i] = new double[matrixSize];
    }

}

void XMatrix::updateMatrix(const AMatrix &aMatrix, const ZMatrix &zMatrix) {
    MatrixInversion(aMatrix.getMatrix(), matrixSize, invertedAMatrix);
    MatrixMultiplication(invertedAMatrix, matrixSize, zMatrix.getMatrix(), currentResultMatrix);
    for (int i = 0; i < numNodes; ++i) {
        nodeVoltages[i].push_back(currentResultMatrix[i][0]);
    }
    for (int j = 0; j < numVoltageSources; ++j) {
        currentValues[j].push_back(currentResultMatrix[numNodes + j][0]);
    }

}

double XMatrix::getVoltageBetweenTwoNodes(int src, int dst) {
    if (src == 0) {
        return nodeVoltages[dst - 1].back();
    }
    if (dst == 0) {
        return nodeVoltages[src - 1].back();
    }
    return nodeVoltages[src - 1].back() - nodeVoltages[dst - 1].back();
}

double XMatrix::getCurrentThroughVoltageSrc(int voltageSourceIndex) {
    return currentValues[voltageSourceIndex].back();
}

XMatrix::~XMatrix() {
    for (int i = 0; i < matrixSize; ++i) {
        delete currentResultMatrix[i];
    }
    delete[] currentResultMatrix;
    for (int j = 0; j < matrixSize; ++j) {
        delete[]invertedAMatrix[j];
    }
    delete[] invertedAMatrix;

}

ostream &operator<<(ostream &outputStream, const XMatrix &xMatrix) {
    int nodeCounter = 0;
    double timeCounter = 0.1;
    for (const vector<double> &singleNodeVoltages :xMatrix.nodeVoltages) {
        outputStream << "Voltages at node " << ++nodeCounter << std::endl;
        for (const double &nodeVoltage : singleNodeVoltages) {
            outputStream << "Time : " << timeCounter << " Voltage Value : " << nodeVoltage << std::endl;
            timeCounter += 0.1;
        }
    }
    int voltageSourceCounter = 0;
    timeCounter = 0.1;
    for (const vector<double> &singleVoltageSourceCurrent : xMatrix.currentValues) {
        outputStream << "Current through voltage Source " << ++voltageSourceCounter << std::endl;
        for (const double &currentThroughVoltageSource : singleVoltageSourceCurrent) {
            outputStream << "Time : " << timeCounter << " Current Value : " << currentThroughVoltageSource << std::endl;
            timeCounter += 0.1;
        }
    }
    return outputStream;
}

void XMatrix::plot() {
    vector<double> time(nodeVoltages[0].size(), 0);
    double timeCounter = 0;
    for (auto &timeUnit : time) {
        timeCounter += 0.1;
        timeUnit = timeCounter;
    }
    int nodeCounter = 0;
    for (auto &nodeVoltageVector : nodeVoltages) {
        plt::named_plot("Voltage at node " + to_string(++nodeCounter), time, nodeVoltageVector);
    }
    plt::title("Voltage Values");
    plt::xlabel("Time(s)");
    plt::ylabel("Transient Response(v)");
    plt::legend();
    plt::show();
    int currentSourceCounter = 0;
    for (auto &voltageThroughCurrentSource : currentValues) {
        plt::named_plot("Current through voltage source " + to_string(++currentSourceCounter), time,
                        voltageThroughCurrentSource);
    }
    plt::title("Current Values");
    plt::xlabel("Time(s)");
    plt::ylabel("Current (Amp)");
    plt::legend();
    plt::show();


}


