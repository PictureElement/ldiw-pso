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
#include "cvt.h"

// Row of the matrix
typedef std::vector<double> Row;
typedef std::vector<Row> Matrix;

class PSO {

		private:

    		/******** DATA MEMBERS ********/

    		// Global best known position
        std::vector<double> x_global;
        // Feasible region (boundaries)
        Matrix bounds;
        // Id for each dimension
        std::vector<std::string> dim_id;
        // Output of fitness function corresponding to x_global
        double value_global;
        // Swarm of particles
        std::vector<particle> particles;
        // Dimensionality
        const int dim;
        // Swarm size
        const int swarm_size;
        // maximum # of iterations
        const int max_iter;
        // Solution (for testing purposes)
        const double target;
        // Error threshold
        double threshold;
        // Inertia weight
        const double wi;
        const double wf;
        // Learning factors
        const double c1, c2;
        // Limit on velocity
        std::vector<double> Vmax;
        // Stopping condition
        const bool mode;

        /******** UTILITY FUNCTIONS ********/

        void equation1 (int index, int iter);
        void equation2 (int index);
        double random_float (double a, double b) const;
        void set_x_global (const particle& p);
        void print_result () const;
        double bound (double x, double lo, double up) const;

    public:

        PSO (int dim, int swarm_size, int max_iter, double target, double threshold, double wi, double wf, double c1, double c2, double k, bool mode);
        double optimize ();
};

#endif