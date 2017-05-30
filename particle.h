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
 * File: particle.h
 * Description: Particle class
 * Created: 26.03.2016
 * Author: Sofokleous Marios
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <exception> // throw
#include <stdexcept> // out_of_range
#include <vector>

class particle {

		private:

   			// Dimensionality
        const int dim;

        // Particle's position
        std::vector<double> x;

				// Local best known position
				std::vector<double> x_local;

				// Output of fitness function corresponding to input x
				double value_x;

				// Output of fitness function corresponding to input x_local
				double value_x_local;

				// Particle's velocity.
				std::vector<double> v;

		public:

  			// Ctor
				particle (int dim);

        std::vector<double> get_x_vector () const;
        double get_x (int index) const;
        void set_x (double value, int index);

        std::vector<double> get_x_local_vector () const;
        double get_x_local (int index) const;
        void set_x_local (double value, int index);
        void set_x_local_vector ();

        double get_value_x () const;
        void set_value_x (double value);

        double get_value_x_local () const;
        void set_value_x_local (double value);

        double get_v (int index) const;
				void set_v (double value, int index);

        // Print current & personal best positions
        void print () const;
};

#endif