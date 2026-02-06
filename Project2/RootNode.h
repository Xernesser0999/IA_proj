#pragma once
#include "Node.h"

class RootNode : public Node {                   // c'est un node donc il herite de Node. C'est le point de depart y'en a besoin au debit de chaque behavior tree
public:
    RootNode() = default;           // Constructeur par defaut
    RootNode(FlowNode* ChilNode);   // Le root node n'accepte pas direct des leaf node donc il ne peut y avoir que des flownode en enfant (et un seul max)
    virtual ~RootNode() override = default;     // Destructeur

    virtual void BeginExecute() override;       // Begin play

    void SetChild(FlowNode* RootChild);         // Attribue un flownode en tant qu'enfant au root node
private:
    FlowNode* Child;    // Pas besoin d'un include vue que Node.h a une foward declaration de FlowNode
};
