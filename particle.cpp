/*
 * MIT License
 *
 * Copyright 2016 Marios Sofokleous
 * Permission is hereby granted, free of charge, to any person obtaining a copy 
 * of this software and associated documentation files (the "Software"), to deal 
 * in the Software without restriction, including without limitation the rights 
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
 * SOFTWARE.
 * 
 * File: particle.cpp
 * Description: Particle class
 * Created: 26.03.2016
 * Author: Sofokleous Marios
 */

#include "particle.h"

//------------------------------------------------------------------------------

particle::particle (int dim) : dim (dim) {
 		x.resize (dim);
    x_local.resize (dim);
    v.resize (dim);
    value_x = 0.0;
    value_x_local = 0.0;
}

//------------------------------------------------------------------------------

std::vector<double> particle::get_x_vector () const {
    return x;
}

double particle::get_x (int index) const {
    return x[index];
}

void particle::set_x (double value, int index) {
    x[index] = value;
}

//------------------------------------------------------------------------------

std::vector<double> particle::get_x_local_vector () const {
    return x_local;
}

double particle::get_x_local (int index) const {
    return x_local[index];
}

void particle::set_x_local (double value, int index) {
    x_local[index] = value;
}

void particle::set_x_local_vector () {
    x_local = x;
}

//------------------------------------------------------------------------------

double particle::get_value_x () const {
    return value_x;
}

void particle::set_value_x (double value) {
    value_x = value;
}

//------------------------------------------------------------------------------

double particle::get_value_x_local () const {
    return value_x_local;
}

void particle::set_value_x_local (double value) {
    value_x_local = value;
}

//------------------------------------------------------------------------------

double particle::get_v (int index) const {
    return v[index];
}

void particle::set_v (double value, int index) {
    v[index] = value;
}

//------------------------------------------------------------------------------

void particle::print () const {
    for(int i=0; i < x.size (); i++)
        std::cout << x[i] << " ";
    std::cout<<std::endl;
}