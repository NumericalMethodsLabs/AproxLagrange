//
// Created by vadim on 21.02.2021.
//

#include "AproxLagrange.h"

static double fact(unsigned n) {
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}

AproxLagrangeErr_e AproxLagrange::Init(std::vector<double> x, std::vector<double> f_x) {
    AproxLagrangeErr_e err = AL_ERR_OK;
    if (x.size() != f_x.size())
        err = AL_ERR_SIZE_ERR;
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

std::valarray<double> AproxLagrange::CalcInPoints(std::valarray<double> p) {
    std::valarray<double> retv(p.size());
    for (unsigned i = 0; i < p.size(); ++i)
        retv[i] = CalcInPoint(p[i]);
    return retv;
}

double AproxLagrange::CalcError(double M, double p) {
    double omega = 1;
    for (auto _x : this->x)
        omega *= (p - _x);
    return M / fact(this->x.size() + 1) * fabs(omega);
}
