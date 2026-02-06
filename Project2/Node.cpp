#include "Node.h"

#include "FluxNode.h"

Node::Node(FlowNode* ParentNode) : Parent(ParentNode) {
}

FlowNode* Node::GetParent() const {
    return Parent;
}
