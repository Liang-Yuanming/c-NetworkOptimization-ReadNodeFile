//
//  main.cpp
//  network_hw1
//
//  Created by mike on 2016/3/19.
//  Copyright © 2016年 Naction Cheng Kung University. All rights reserved.
//

#include <iostream>
#include<sstream>
#include <fstream>
#include "Arc.h"
using namespace std;
#define SIZE 1024
char line[SIZE];

int main(int argc, const char * argv[]) {
    // insert code here...
    string fileName;
    cout << "Please input network filename:";
    cin >> fileName;
    string problemName,typeProblem;
    int n,m;
    int mp=0;
    fstream fin;
    fin.open(fileName,ios::in);
    Arc *arc = nullptr;
    while(fin.getline(line,sizeof(line),'\n')){
        if (line[0]=='t') {
            int i=2;
            while (line[i]) {
                problemName+=line[i];
                i++;
            }
        }else if (line[0]=='p'){
            int i=2;
            string temp="";
            int k=1;
            while (line[i]) {
                
                if (line[i]!=' ' && line[i]!='\t') {
                    temp+=line[i];
                }else{
                    if (k==1 && temp!="") {
                        typeProblem=temp;
                        k++;
                    }else if(k==2 && temp!=""){
                        stringstream ss;
                        ss << temp;
                        ss >> n;
                        k++;
                    }
                    
                    temp="";
                }
                i++;
            }
            if (k==3 && temp !="") {
                stringstream ss;
                ss << temp;
                ss >> m;
                k++;
                temp="";
                arc=new Arc[m];
            }
        }else if(line[0]=='a'){
            int i=2;
            string temp="";
            int k=1;
            while (line[i]) {
                
                if (line[i]!=' ' && line[i]!='\t') {
                    temp+=line[i];
                    
                }else{
                    if (k==1 && temp!="") {
                        int from=0;
                        stringstream ss;
                        ss << temp;
                        ss >> from;
                        arc[mp].setFrom(from);
                        k++;
                    }else if(k==2 && temp!=""){
                        int to=0;
                        stringstream ss;
                        ss << temp;
                        ss >> to;
                        arc[mp].setTo(to);
                        k++;
                    }
                    
                    temp="";
                }
                i++;
            }
            if (k==3 && temp !="") {
                double length=0.0;
                stringstream ss;
                ss << temp;
                ss >> length;
                arc[mp].setLength(length);
                k++;
                temp="";
//                Arc *arc=new Arc[m];
            }
            mp++;
        }
    }
    fin.close();
    
    int nodeInput;
    cout << "Please input a source node(0->exit): ";
    cin >> nodeInput;
    while (nodeInput!=0) {
        if (nodeInput > n || nodeInput<0) {
            cout << "!!Warning!!: node "<< nodeInput <<" does not exist" << endl;
        }else{
            for (int i=0; i<m; i++) {
                if (arc[i].getFrom()==nodeInput || arc[i].getTo()==nodeInput) {
                    cout << "arc["<< i+1 <<"]: " << arc[i].getFrom() << "-" << arc[i].getTo() << " : " << arc[i].getLength() << endl;
                }
            }
        }
        cout << "Please input a source node(0->exit): ";
        cin >> nodeInput;
    }
    
    //    cout << problemName <<endl;
//    cout << typeProblem <<endl;
//    cout << n <<endl;
//    cout << m <<endl;
//    cout << arc[2].getFrom() << endl;
    //cout << "Unable to open file\n";
    //cout << "File name = " << fileName << endl;
    
    return 0;
}
