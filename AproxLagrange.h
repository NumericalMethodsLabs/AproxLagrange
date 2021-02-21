//
// Created by vadim on 21.02.2021.
//

#ifndef INTERPOLATION_APROXLAGRANGE_H
#define INTERPOLATION_APROXLAGRANGE_H

#include <vector>
#include <valarray>

enum AproxLagrangeErr_e{
        ERR_OK = 0U,
        ERR_SIZE_ERR
};

class AproxLagrange {
    double range_l;
    double range_r;
    std::vector<double> x;
    std::vector<double> f_x;

    double calc_F_i(double x, unsigned ind);

public:
    AproxLagrange(double range_l, double range_r);

    AproxLagrangeErr_e Init(std::vector<double> x, std::vector<double> f_x);

    double CalcInPoint(double p);

    std::valarray<double> CalcInPoint(std::valarray<double> p);
};

#endif //INTERPOLATION_APROXLAGRANGE_H
