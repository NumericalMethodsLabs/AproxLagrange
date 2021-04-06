//
// Created by vadim on 21.02.2021.
//

#ifndef INTERPOLATION_APROXLAGRANGE_H
#define INTERPOLATION_APROXLAGRANGE_H

#include <cmath>
#include <vector>
#include <valarray>

enum AproxLagrangeErr_e{
        AL_ERR_OK = 0U,
        AL_ERR_SIZE_ERR
};

class AproxLagrange {
    std::vector<double> x;
    std::vector<double> f_x;

    double calc_F_i(double x, unsigned ind);

public:
    AproxLagrange() = default;

    AproxLagrangeErr_e Init(std::vector<double> x, std::vector<double> f_x);

    double CalcInPoint(double p);

    std::valarray<double> CalcInPoints(std::valarray<double> p);

    double CalcError(double M, double p);
};

#endif //INTERPOLATION_APROXLAGRANGE_H
