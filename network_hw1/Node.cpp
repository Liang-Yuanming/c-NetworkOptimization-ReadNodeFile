//
//  Node.cpp
//  network_hw1
//
//  Created by mike on 2016/3/20.
//  Copyright © 2016年 Naction Cheng Kung University. All rights reserved.
//

#include "Node.h"
Node::Node(int index){
    this->index=index;
}
void Node::setIndex(int index){
    this->index=index;
}
int Node::getIndex(){
    return this->index;
}