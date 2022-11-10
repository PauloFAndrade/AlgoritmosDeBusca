/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>


#include "searching.h"

int main( void )
{
    sa::value_type ciclo{30};
    sa::value_type atual{10000};
    sa::value_type max{10000000};

    
    double soma = 0;
    double media;
    std::vector<sa::value_type> v;

    //===========================LINEAR SEARCH===================================================================
    std::ofstream linear( "TimeLinear.txt" );

    while(atual<max){
        soma = 0;
        v.resize(atual);
        std::fill(v.begin(), v.end(), 0);
        for(int i{0};i<ciclo;i++){
            auto start = std::chrono::steady_clock::now();
            int * ptr = sa::lsearch(&(v[0]),&v.back(),-2);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> time = end - start;
            soma += std::chrono::duration <double, std::milli> (time).count();
        }

        media = soma/ciclo;
        linear << atual << "\t" << media << std::endl;
        atual += 20000;
    }
    //===========================================================================================================


    //===========================BINARY SEARCH ITERATIVE=========================================================
    std::ofstream binaryInt( "TimeBinaryInt.txt" );
    atual = 10000;
    while(atual<max){
        soma = 0;
        v.resize(atual);
        std::fill(v.begin(), v.end(), 0);
        for(int i{0};i<ciclo;i++){
            auto start = std::chrono::steady_clock::now();
            auto ptr = sa::bsearch(&(v[0]),&v.back(),-2);
            auto end = std::chrono::steady_clock::now();
            //double time = double (std::chrono::duration_cast <std::chrono::milliseconds>(end-start).count());
            std::chrono::duration<double> time = end - start;
            soma += std::chrono::duration <double, std::milli> (time).count();
        }

        media = soma/ciclo;
        binaryInt << atual << "\t" << media << std::endl;
        atual += 20000;
    }
    //===========================================================================================================


    //===========================BINARY SEARCH RECURSIVE=========================================================
    std::ofstream binaryRecT( "TimeBinaryRec.txt" );
    atual = 10000;
    while(atual<max){
        soma = 0;
        v.resize(atual);
        std::fill(v.begin(), v.end(), 0);
        for(int i{0};i<ciclo;i++){
            auto start = std::chrono::steady_clock::now();
            auto ptr = sa::binaryRec(&(v[0]),&v.back(),-2);
            auto end = std::chrono::steady_clock::now();
            //double time = double (std::chrono::duration_cast <std::chrono::milliseconds>(end-start).count());
            std::chrono::duration<double> time = end - start;
            soma += std::chrono::duration <double, std::milli> (time).count();
        }

        media = soma/ciclo;
        binaryRecT << atual << "\t" << media << std::endl;
        atual += 20000;
    }
    //===========================================================================================================

    linear.close();
    binaryInt.close();
    binaryRecT.close();





    /*
    std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";
    auto start = std::chrono::steady_clock::now();
    //================================================================================

    // >>>>>>>>  Put the code that needs timing here  <<<<<<<<<<<< //
    typedef  int test_t; // The testing type for increment.
    int a{1};
    for ( test_t i=std::numeric_limits<test_t>::min() ; i < std::numeric_limits<test_t>::max() ; ++i )
    // for ( unsigned long long j{0} ; j < std::numeric_limits<unsigned long long>::max() ; ++j )
    // for ( unsigned long long j{0} ; j < std::numeric_limits<unsigned long long>::max() ; ++j )
        a *= 2;

    //================================================================================
    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";
    */

    //Store the time difference between start and end
    // auto diff = end - start;
    //std::chrono::duration<double> diff = end - start;

    // Milliseconds (10^-3)
    //std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
    //    << " ms" << std::endl;

    // Nanoseconds (10^-9)
    //std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
    //    << " ns" << std::endl;

    // Seconds
    //auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    //std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;

    //return EXIT_SUCCESS;

}
