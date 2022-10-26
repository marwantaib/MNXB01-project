#include<TH1D.h>
#include<vector>
#include "../include/plot.h"
x

void plot::plot_hist(){
    TH1D* h1 = new TH1D("h1","Histogram showing the relation between x and y",10,0,100);
    for (int i = 0; i < x_.size(); i++){
        std::cout << x_[i]<< std::endl;
        h1->Fill(x_[i]);
    }
    h1->Draw("hist");
};
void plot::plot_graph(){
    double x[x_.size()], y[y_.size()];
    for(int i=0; i< x_.size(); i++){
        x[i]=x_[i];
        y[i]=y_[i];
    };
    TGraph *grl= new TGraph(vx.size(),x,y);
    grl->Draw("Al");
        
};


