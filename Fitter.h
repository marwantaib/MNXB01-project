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
    //Define the object/function attributes
    int xmin;
    int xmax;
    std::string fit;  // “gaus” Gaussian function with 3 parameters: f(x) = p0*exp(-0.5*((x-p1)/p2)^2)

                      // “expo” An Exponential with 2 parameters: f(x) = exp(p0+p1*x)

                      // “pol N” A polynomial of degree N: f(x) = p0 + p1*x + p2*x2 +...

    TObject::TH1D histogram; 
    TObject::TGraph graph;
    double x[];
    double y[];
    int n;

    histogram_fitter(histogram, fit,xmin,xmax){
        
        if(fit = "gaus"){
            histogram-> TH1::Fit(fit,"R","",xmin, xmax);
            double constant = histogram->GetParameter(0);
            double mean = histogram->GetParameter(1);
            double sigma = histogram->GetParameter(2);
            cout << "The constant is equal to "<< constant << endl;
            cout << "The mean is equal to "<< mean << endl;
            cout << "The standard deviation is equal to "<< sigma << endl;
        }
        
        else{
            histogram-> TH1::Fit(fit,"R","", xmin, xmax);
            
        
        
        }
    }

    graph_fitter(graph,fit,xmin,xmax){
        graph->TH1::Fit(fit,"R","",xmin, xmax);
    }
};
#endif /* Fitter_h */
