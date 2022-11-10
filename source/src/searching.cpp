/*!
 * \file searching.cpp
 * Binary search, Linear search, Upper bound, lower bound implementation for an array of integers.
 * \author Selan R. dos Santos
 * \date June 17th, 2021.
 */

#include "searching.h"

#include <iostream>

namespace sa {

    /*!
     * Performs a **linear search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lsearch( value_type * first, value_type * last, value_type value )
    {
        // TODO
        for(int i{0};i<(last-first);i++){
            if((*(first+i)==value)){
                return first+i; 
            }
        }
        return last;
    }

    /*!
     * Performs a **binary search** for `value` in `[first;last)` and returns a pointer to the location of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * bsearch( value_type * first, value_type * last, value_type value )
    {
       int left=-1;
       int right=last-first;
       while(left<right-1){
           int mid = (left+right)/2;
           if(*(first+mid)<value){
               left = mid;
           }else{
               right = mid;
           }
       }
       if(*(first+right)==value){
           return first+right;
       }else{
           return last;
       }
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _not less_  than (i.e. greater or equal to) `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * lbound( value_type * first, value_type * last, value_type value )
    {
        // TODO
        int lower = 0;
        int tam = last - first;
        int higher = tam - 1;
        while((higher-lower)>1){
            int mid = (higher+lower)/2;
            if(*(first+mid)<value){
                lower = mid + 1;
            }else{
                higher = mid;
            }
        }
        if(*(first+lower)>=value){
            return first+lower;
        }else if(*(first+higher)>=value){
            return first+higher;
        }else{
            return last;
        }
    }

    /*!
     * Returns a pointer to the first element in the range `[first, last)` that is _greater_  than `value`, or `last` if no such element is found.
     * \note The range **must** be sorted.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param value The value we are looking for.
     */
    value_type * ubound( value_type * first, value_type * last, value_type value )
    {
        // TODO
        int lower = 0;
        int tam = last - first;
        int higher = tam - 1;
        while((higher-lower)>1){
            int mid = (higher+lower)/2;
            if(*(first+mid)<=value){
                lower = mid + 1;
            }else{
                higher = mid;
            }
        }
        if(*(first+lower)>value){
            return first+lower;
        }else if(*(first+higher)>value){
            return first+higher;
        }else{
            return last;
        }
    }

    value_type * salvaIssoAi(value_type * first, value_type * last, value_type value){
        int left = 0;
        int right = last - first;

        int mid = (left+right)/2;

        if((first+left)==(first+right)){
            return nullptr;
        }else if(*(first+mid) == value){
            return first+mid;
        }else if(*(first+mid) < value){
            return salvaIssoAi(first+mid+1,last,value);
        }else{
            return salvaIssoAi(first,first+mid,value);
        }
    }

    value_type * binaryRec( value_type * first, value_type * last, value_type value ){
        int * ptr = salvaIssoAi(first,last,value);
        if(ptr == nullptr){
            return last;
        }else{
            return ptr;
        }
        
    }
}

