#include <TH1D.h>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "dataprocessing.C"
#include<typeinfo>
#include<TStyle.h>
#include<TCanvas>

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
    
   //Fitting for Histograms------------------------------------

   h1->Fit(gaus,"R");
   h1->SetMinimum(0);
   gStyle->SetOptStat(1111);
   gStyle->SetOptFit(1111);
   h1->DrawCopy("hist"); 
   h1->SetFillColor(kBlue);
   h1->SetFillStyle(3018);
   h1->Draw("e2same");
   //End of Fitting ------------------------------------
    return h1;
};


TGraph* plot_graph(std::vector<int> x_, std::vector<double> y_, std::vector<double> e_y_){
    double x[x_.size()], y[y_.size()], e_y[e_y_.size()],;
=======
   h1->Draw("hist");
   return h1;
};

//function that takes two vectors x and y and produces a graph. Returns the memory place of the graph so we can fit it
TGraph* plot_graph(std::vector<int> x_, std::vector<double> y_){
    double x[x_.size()], y[y_.size()];
    for(int i=0; i< x_.size(); i++){
        x[i]=x_[i];
        y[i]=y_[i];
        e_y[i]=e_y_[i]; // new line for error encorporation
    };

   //Fitting for Graphs + errors
   auto e_grl = new TGraphErrors(x_size,x,y,ey);
   TGraph *grl= new TGraph(x_.size(),x,y);
   grl->Fit("pol4");
   e_grl->Fit(pol4);
   gStyle->SetOptStat(1111);
   gStyle->SetOptFit(1111);
   e_grl->SetTitle("TGraphErrors Example");
   e_grl->SetMarkerColor(4);
   e_grl->SetMarkerStyle(6);
   e_grl->Draw("ACP");
   e_grl->Draw("grlsame");
    

   //End of Fitting 
    
    return grl;
};
