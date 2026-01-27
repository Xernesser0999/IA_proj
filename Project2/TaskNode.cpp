#include "TaskNode.h"

TaskNode::TaskNode(){
}

TaskNode::~TaskNode(){
}

void TaskNode::begin(){
	actualTime = time;
}

void TaskNode::tick(float deltaTime){
    actualTime = actualTime - deltaTime;
    if (actualTime <= 0.0f) {
        parentNode->onNodeEnd();
    }
    else {
        std::cout << actualTime << std::endl;
    }
}
