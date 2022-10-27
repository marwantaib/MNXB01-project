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
    for(int i=0; i< x_.size(); i++){
        x[i]=x_[i];
        y[i]=y_[i];
        e_y[i]=e_y_[i]; // new line for error encorporation
       
    };
   TGraph *grl= new TGraph(x_.size(),x,y);
   
   //Fitting for Graphs + errors ------------------------------------
   auto e_grl = new TGraphErrors(x_size,x,y,ey);
   e_grl->Fit(pol4,"R");
   gStyle->SetOptStat(1111);
   gStyle->SetOptFit(1111);
   e_grl->SetTitle("TGraphErrors Example");
   e_grl->SetMarkerColor(4);
   e_grl->SetMarkerStyle(21);
   e_grl->Draw("ALP");

   //End of Fitting ------------------------------------

    
    return grl;
            
};
