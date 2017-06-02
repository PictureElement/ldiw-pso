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
 * File: pso.h
 * Description: PSO class
 * Created: 26.03.2016
 * Author: Sofokleous Marios
 */

#ifndef PSO_H
#define PSO_H

#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <vector>
#include "particle.h"
#include "fitness.h"
#include "config.h"
#include "cvt.h"

class PSO {

	private:

    	/******** DATA MEMBERS ********/

    	// Global best known position
        std::vector<double> x_global;
        // Id for each dimension
        std::vector<std::string> dim_id;
        // Output of fitness function corresponding to x_global
        double value_global;
        // Limit on velocity
        double Vmax;
        // Swarm of particles
        std::vector<particle> particles;
        // Dimensionality
        const int dim;
        // Boundaries (Lower & Upper range limits)
        const double lo;
        const double up;
        // Swarm size
        const int swarm_size;
        // Maximum # of iterations (stopping condition #1)
        const int max_iter;
        // Maximum # of stall generations (stopping condition #2)
        const int max_stall_iter;
        // Inertia weight
        const double wi;
        const double wf;
        // Learning factors
        const double c1, c2;
        // Stopping condition selection
        const bool mode;

        /******** UTILITY FUNCTIONS ********/

        void equation1 (int index, int iter);
        void equation2 (int index, int& stall_iter);
        double random_float (double a, double b) const;
        void set_x_global (const particle& p);
        void print_result () const;
        double bound (double x, double lo, double up) const;

    public:

        PSO (int dim, int swarm_size, double lo, double up, int max_iter, int max_stall_iter, double wi, double wf, double c1, double c2, double k, bool mode);
        double optimize ();
};

#endif