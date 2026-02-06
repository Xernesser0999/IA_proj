#pragma once
#include "SequenceFlow.h"
#include "TaskNode.h"

class IsArrived : public TaskNode {               // Du coup faut une classe qui depend de TaskNode pour crée un tache
public:
    IsArrived() = default;
    IsArrived(FlowNode* ParentNode);
    virtual ~IsArrived() override = default;

    virtual void BeginExecute() override;           // Qunad le node démarre
    virtual void Tick(float DeltaTime) override;    // A chaque tick
    virtual ENodeState EndExecute() override;       // A la fin
};


// Objectif :
// Si le client n'est pas devant le magasin alors le node retourne false sinon il retourne true
// Le fallback auquel il est lié déclenchera la task moveAI si ce node retourne false. 
// Sinon il passera a au deuxieme fallabck si ce node retourne true