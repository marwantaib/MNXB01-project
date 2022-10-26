#ifndef plot_H
#define plot_H
#include<vector>
#include<iostream>

class plot {
public:
    plot(const std::vector<double> x , const std::vector<double> y):
    x_(x);
    y_(y);
    {}
//input x,y of type vector
    const std::vector<double> x_;
    const std::vector<double> y_;
// two functions that plot x,y depending if x,y are discrete or continous
    void plot_hist();
    void plot_graph();
};

#endif //plot_H
