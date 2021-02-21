//
// Created by vadim on 21.02.2021.
//

#include "AproxLagrange.h"

AproxLagrange::AproxLagrange(double range_l, double range_r) {
    this->range_l = range_l;
    this->range_r = range_r;
}

AproxLagrangeErr_e AproxLagrange::Init(std::vector<double> x, std::vector<double> f_x) {
    AproxLagrangeErr_e err = ERR_OK;
    if (x.size() != f_x.size())
        err = ERR_SIZE_ERR;
    else {
        this->x = x;
        this->f_x = f_x;
    }
    return err;
}

double AproxLagrange::calc_F_i(double x, unsigned int ind) {
    double retv = 1;
    for (unsigned j = 0; j < this->x.size(); ++j) {
        if (j != ind)
            retv *= ((x - this->x[j]) / (this->x[ind] - this->x[j]));
    }
    return retv;
}

double AproxLagrange::CalcInPoint(double p) {
    double retv = 0;
    for (unsigned i = 0; i < x.size(); ++i)
        retv += (f_x[i] * calc_F_i(p, i));
    return retv;
}

std::valarray<double> AproxLagrange::CalcInPoint(std::valarray<double> p) {
    std::valarray<double> retv(p.size());
    for (unsigned i = 0; i < p.size(); ++i)
        retv[i] = CalcInPoint(p[i]);
    return retv;
}
