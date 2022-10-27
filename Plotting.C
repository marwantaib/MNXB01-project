#include <TH1D.h>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "dataprocessing.C"
#include<typeinfo>

// function that takes a vector of doubles and produces a histogram. Returns the memory place of the histogram so we can fit it.
TH1D* plot_hist(std::vector<double> x){
//takes the min and max value in the vector x
   int min = *std::min_element(x.begin(),x.end());
   int max = *std::max_element(x.begin(),x.end());
//check of filling of vector
    for(int i=0; i < x.size(); i++){
        std::cout<< x[i]<< std::endl;
    }
//creating the histogram and fills it using the for loop
    TH1D* h1 = new TH1D("h1","Histogram showing the trend in temperature in city",x.size(),min,max);
    for (int i = 0; i < x.size(); i++){
       std::cout << x[i]<< std::endl;
        h1->Fill(x[i]);
    };
   h1->Draw("hist");
   return h1;
};

//function that takes two vectors x and y and produces a graph. Returns the memory place of the graph so we can fit it
TGraph* plot_graph(std::vector<double> x_, std::vector<double> y_){
    double x[x_.size()], y[y_.size()];
    for(int i=0; i< x_.size(); i++){
        x[i]=x_[i];
        y[i]=y_[i];
    };
    //takes the min and max value in the vector x
       int min = *std::min_element(x_.begin(),x_.end());
       int max = *std::max_element(x_.begin(),x_.end());
//creating the graph
    TGraph *grl= new TGraph(x_.size(),x,y);
    grl->SetTitle("Graph showing the trend in mean temperature in city; Years; Temperature");
    grl->Draw("AC*");
    
    return grl;
};
