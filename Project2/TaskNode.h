#pragma once
#include "Node.h"

// Node qui va executer une tache (logique c'est dans le nom)
class TaskNode : public Node {
public:
    TaskNode() = default;               // Constructeur par defaut
    TaskNode(FlowNode* ParentNode);     // C'est un leaf node donc il a besoin d'un parent type FlowNode
    virtual ~TaskNode() = default;      // Destructeur
};


