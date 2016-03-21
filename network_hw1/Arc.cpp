//
//  Arc.cpp
//  network_hw1
//
//  Created by mike on 2016/3/20.
//  Copyright © 2016年 Naction Cheng Kung University. All rights reserved.
//

#include "Arc.h"
Arc::Arc(){
    
}
Arc::Arc(int from,int to,double length){
    this->from=from;
    this->to=to;
    this->length=length;
}
void Arc::setFrom(int from){
    this->from=from;
}
void Arc::setTo(int to){
    this->to=to;
}
void Arc::setLength(double length){
    this->length=length;
}
int Arc::getFrom(){
    return this->from;
}
int Arc::getTo(){
    return this->to;
}
double Arc::getLength(){
    return this->length;
}