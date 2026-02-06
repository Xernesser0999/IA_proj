// ReSharper disable CppFunctionIsNotImplemented
#pragma once
#include <vector>

#include "Node.h"

class FlowNode : public Node {           // Fonctionne un peu comme une struct
public:
    FlowNode() = default;               // Constructeur par defaut
    FlowNode(FlowNode* ParentNode);     // Constructeur qui a besoin d'un parent (genre rootNode / Fallback)
    FlowNode(FlowNode* ParentNode, const std::vector<Node*>& Childs);   // Constructeur avec des leafNode
    virtual ~FlowNode() = default;      // Destructeur virtual

    virtual void AddChild(Node* Child);         // Fonction pour ajouter des enfant au flowNode
    virtual void RemoveChild(Node* Child);      // Fonction pour retirer les enfnat du flownode

    virtual void OnChildWorkEnd(ENodeState ChildState);     // Quand les enfnat ont fini de travailler (bizarre comme phrase)
protected:
    std::vector<Node*> ChildNodes;      // Contien tous les enfant
    Node* CurrentExecuteChild;          // Contient l'enfant qui est en train d'etre executer en ce moment meme
};
