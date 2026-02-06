#pragma once

class FlowNode;         // Foward declaration

enum class ENodeState { // Etats du node
    Unknown = 0,
    Success = 1,
    Failure = 2,
    Abort = 3,
};

//Base class pour les nodes et le système de composition
class Node {
public:

    Node() = default;               // Constructeur par defaut
    Node(FlowNode* ParentNode);     // si c'est un leaf node il a besoin d'un flowNode
    virtual ~Node() = default;      // Destructeur Virtual pour s'adapter a tous les leafNode

    virtual void BeginExecute() {};         // Begin play 
    virtual void Tick(float DeltaTime) {};  // Event tick / se produit a chaque tick ?
    virtual ENodeState EndExecute() { return ENodeState::Success; };  // Se produit a l'arret du node ou arrète la node reste a savoir

    virtual void Abort() {};        // Abort
    FlowNode* GetParent() const;    // jsp encore
private:
    FlowNode* Parent;               // Foward declaration pour utiliser les fonction du flowNode
};
