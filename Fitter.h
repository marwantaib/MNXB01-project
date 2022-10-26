//
//  Fitter.h
//  Fitter
//
//  Created by Sherwan Jamo on 2022-10-26.
//

#include<iostream>
#include <string>
#include <vector>

#include<TH1F.h> 
#include<TF1.h>
#include<TH1.h>
#include<TObject.h>

#ifndef Fitter_h
#define Fitter_h

class fitter{
    public:

    std::string fit;
    TObject::TH1D histogram; 
    TObject::TGraph graph;
    double x[];
    double y[];
    int n;

    histogram_fitter(histogram, fit){
        histogram-> TH1::Fit(fit,"R");
        hist->Draw();
    }

    graph_fitter(graph,fit){
        graph->TH1::Fit(fit,"R");
        g->Draw();
    }
};
#endif /* Fitter_h */
