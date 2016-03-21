//
//  Arc.hpp
//  network_hw1
//
//  Created by mike on 2016/3/20.
//  Copyright © 2016年 Naction Cheng Kung University. All rights reserved.
//

class Arc{
public:
    Arc();
    Arc(int from,int to,double length);
    void setFrom(int from);
    void setTo(int to);
    void setLength(double length);
    int getFrom();
    int getTo();
    double getLength();
private:
    int from;
    int to;
    double length;
};
