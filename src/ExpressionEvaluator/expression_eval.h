#ifndef CALC_H
#define CAL_H

namespace calc {

    class Expression {
        
    };

    class Calculator {
        private:
            Expression e;
        public:
            double evaluate(Expression& e);
    };

}


#endif