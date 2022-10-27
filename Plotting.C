#include <TH1D.h>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "dataprocessing.C"
#include<typeinfo>


TH1D* plot_hist(std::vector<double> x){
   int min = *std::min_element(x.begin(),x.end());
   int max = *std::max_element(x.begin(),x.end());
//check of filling of vector
    for(int i=0; i < x.size(); i++){
        std::cout<< x[i]<< std::endl;
    }

    TH1D* h1 = new TH1D("h1","Histogram showing the relation between x and y",x.size(),min,max);
    for (int i = 0; i < x.size(); i++){
       std::cout << x[i]<< std::endl;
        h1->Fill(x[i]);
    };
   h1->Draw("hist");
    std::cout<< typeid(h1).name() <<std::endl;
    return h1;
};


TGraph* plot_graph(std::vector<int> x_, std::vector<double> y_){
    double x[x_.size()], y[y_.size()];
    for(int i=0; i< x_.size(); i++){
        x[i]=x_[i];
        y[i]=y_[i];
    };
    TGraph *grl= new TGraph(x_.size(),x,y);
    grl->Draw("AC*");
    
    return grl;
            
};
