//
// Created by hassan on 28/11/18.
//

#include "Component.h"

Component::Component(int srcNode, int dstNode, double value, double currentParameter) :srcNode(srcNode), dstNode(dstNode), value(value), currentParameter(currentParameter) {

}

int Component::getSrcNode() const {
    return srcNode;
}

void Component::setCurrentParameter(double currentParameter) {
    Component::currentParameter = currentParameter;
}

int Component::getDstNode() const {
    return dstNode;
}

double Component::getValue() const {
    return value;
}

double Component::getCurrentParameter() const {
    return currentParameter;
}
