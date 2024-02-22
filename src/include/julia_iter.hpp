#pragma once


class julia_iter
{
private:
    /* data */
    double real = 0;
    double imaginary = 0;
public:
    int max_iter = 1000; // maximum number of iterations

    julia_iter(double real_, double imaginary_){
        real = real_;
        imaginary = imaginary_;
    };
    ~julia_iter();

    double evaluate(double real, double imaginary){
        // choose random number
        // calculate the initial 
         double zn_real = real;
         double zn_imaginary = imaginary;
         double znplus1_real = 0;
         double znplus1_imaginary = 0;

        for(int i=0; i<max_iter;++i){
            //calculate zn+1 = zn^2 + c
            znplus1_real = (zn_real * zn_real) - (zn_imaginary * zn_imaginary) + real;
            znplus1_imaginary = 2*zn_real*zn_imaginary+imaginary;

            //set zn to zn+1
            zn_real = znplus1_real;
            zn_imaginary = znplus1_imaginary;

            //
        }
        return 1.0;
    }
};



