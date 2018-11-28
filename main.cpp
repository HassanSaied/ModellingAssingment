#include <bits/stdc++.h>
#include "CurrentSource.h"
#include "Capacitance.h"
#include "Inductance.h"
#include "VoltageSource.h"
#include "Resistance.h"
#include "ZMatrix.h"
#include "AMatrix.h"

#define INPUT_FILE "input.txt"
#define CurrentSourceString "Isrc"
#define ResistanceString "R"
#define VoltageSourceString "Vsrc"
#define InductanceString "I"
#define CapacitanceString "C"
#define H 0.1
using namespace std;
int voltageSourcesIndex = 0;
int numNodes = 0;

Component *createComponent(string componentType, int src, int dst, double value, double initialValue) {
    Component *newComponent;
    if (componentType == CurrentSourceString) {
        newComponent = new CurrentSource(src, dst, value, initialValue);
    } else if (componentType == ResistanceString) {
        newComponent = new Resistance(src, dst, 1 / value, initialValue);
    } else if (componentType == VoltageSourceString) {
        newComponent = new VoltageSource(src, dst, value, initialValue, voltageSourcesIndex++);
    } else if (componentType == InductanceString) {
        newComponent = new Inductance(src, dst, value / H, initialValue, voltageSourcesIndex++);
    } else if (componentType == CapacitanceString) {
        newComponent = new Capacitance(src, dst, value / H, initialValue);
    }
}

vector<Component *> readFile(string fileName) {
    vector<Component *> components;
    ifstream inputStream(fileName);
    string objectType;
    int src, dst;
    double value, initialValue;
    if (inputStream.is_open()) {
        while (!inputStream.eof()) {
            inputStream >> objectType >> src >> dst >> value >> initialValue;
            components.push_back(createComponent(objectType, src, dst, value, initialValue));
            numNodes = max(numNodes, max(src, dst));
        }
    }
    return components;
}

int main() {
    vector<Component*> components = readFile(INPUT_FILE);
    AMatrix aMatrix(numNodes,voltageSourcesIndex);
    ZMatrix zMatrix(numNodes,voltageSourcesIndex);
    for (auto component : components){
        component->initializeMatrix(aMatrix,zMatrix);
    }
    cout<< aMatrix<<endl<<zMatrix;

}