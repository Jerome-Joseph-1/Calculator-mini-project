#ifndef BASIC_CALC_H
#define BASIC_CALC_H

namespace basic_calc {
    class BasicCalc {
        public:
            double sqrt(double x);
            long long factorial(long long x);
            double natural_log(double x);
            double pow(double x, double y);

            void menu();
            void run();
    };
}

#endif