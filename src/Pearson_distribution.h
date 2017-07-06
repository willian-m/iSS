#include <vector>
#include "RandomVariable.h"

#ifndef Pearson_distribution_h
#define Pearson_distribution_h

class PearsonDistribution: public RandomVariable {
 private:
    double r;
    double a;
    double nu;
    double lambda;
    double m;

    double chi_1;  //!< mean
    double chi_2;  //!< 2nd moment
    double chi_3;  //!< 3rd moment
    double chi_4;  //!< 4th moment

 public:
    PearsonDistribution(double chi_1_in=0., double chi_2_in=1.,
                        double chi_3__in=0., double chi_4_in=0.);
    ~PearsonDistribution();

    double mean, std;         //!< mean and standard deviation
    double mode;              //!< maximum position of pdf

    double pdf(double x);

    //! reset parameter for pdf with lambda_in.
    //! calculate mean, std, and mode for the given pdf
    //! it then construct the envelop functions for better
    //! sampling efficiencies.
    void resetDistribution(double chi_1, double chi_2,
                           double chi_3, double chi_4);
       
    //! return random integer according to Poisson distribution
    double rand();

    //! return random integer according to Poisson distribution
    //! with given parameter lambda
    double rand(double chi_1, double chi_2, double chi_3, double chi_4);
};

#endif  // Pearson_distribution_h
