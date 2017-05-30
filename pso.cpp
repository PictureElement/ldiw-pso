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
 * File: pso.cpp
 * Description: PSO class
 * Created: 26.03.2016
 * Author: Sofokleous Marios
 */

#include "pso.h"

PSO::PSO (int dim, int swarm_size, int max_iter, int max_stall_iter, double wi, double wf, double c1, double c2, double k, bool mode) : dim (dim), value_global (0.0), swarm_size (swarm_size), max_iter (max_iter), max_stall_iter (max_stall_iter), wi (wi), wf (wf), c1 (c1), c2 (c2), mode (mode) {

		bounds.resize (dim);
    double lo, up;
    std::string id;

    for (int i = 0; i < dim; i++) {
    		id = "x" + std::to_string (i + 1);
        dim_id.push_back (id);
        // Lower bound
        lo = -5;
        bounds[i].push_back(lo);
        // Upper bound
        up = 10;
        bounds[i].push_back(up);
        Vmax.push_back (k * (up - lo));
		}

		x_global.resize (dim);

    // Create swarm
    for (int i = 0; i < swarm_size; i++) {
    		particle p (dim);
        particles.push_back (p);
    }

    /* INITIALIZATION PROCESS */

    // CVT initialization
    std::vector<point> init_points = CVT (swarm_size, 50000, dim, 5, bounds, 0.5, 0.5, 0.5, 0.5);

    double value_d;

    for (int i = 0; i < swarm_size; i++) { // For each particle
    		for (int j = 0; j < dim; j++) { // For each dimension
            // Initialize position
            value_d = init_points[i].get_term (j);
            particles[i].set_x (value_d, j);
            particles[i].set_x_local (value_d, j);

            // Initialize velocity
            value_d = random_float (-abs (bounds[j][1] - bounds[j][0]), abs (bounds[j][1] - bounds[j][0]));
            particles[i].set_v (value_d, j);
        }

				// Initialize personal best
        value_d = fitness_funct (particles[i].get_x_vector (), false, dim); // Fitness value
        particles[i].set_value_x (value_d);
        particles[i].set_value_x_local (value_d);

        // Initialize global best
        if (i == 0) {
						x_global = particles[i].get_x_local_vector ();
            value_global = particles[i].get_value_x_local ();
        }
        else {
						if (particles[i].get_value_x_local () < value_global) {
								x_global = particles[i].get_x_local_vector ();
								value_global = particles[i].get_value_x_local ();
						}
				}
		}
}

/*
 * OPTIMIZATION PROCESS
 * Stopping conditions: MAX_ITER, MAX_STALL_ITER
 */
double PSO::optimize () {

		// # of iterations
    int iter = 0;

    // # of stall iterations
    int stall_iter = 0;

    // Maximum # of iterations (stopping condition #1)
    if (mode == 0) {
    		do {
    				//cout << "Generation #" << iter+1 << "\n";

        		// For each particle
            for (int j = 0; j < swarm_size; j++) {

                // Update particle's velocity
                equation1 (j, iter);

                // Update particle's position, personal best and global best
                equation2 (j, stall_iter);
            }

            iter++;

        } while (iter < max_iter);

				return value_global;
    }
    // Maximum # of stall generations (stopping condition #2)
    else {
        do {
        		//cout << "Generation #" << iter+1 << "\n";

        		// For each particle
            for (int j = 0; j < swarm_size; j++) {

            		// Update particle's velocity
                equation1 (j, iter);

              	// Update particle's position, personal best and global best
            		equation2 (j, stall_iter);
            }

            iter++;
 
        } while (stall_iter < max_stall_iter);
        
        return value_global;
    }
}

// Update particle's velocity
void PSO::equation1 (int index, int iter) {

		double w,vi;
		double v_update;

		for (int i = 0; i < dim; i++) {
				// Linear decreasing inertia weight
				w = ((wi - wf) * ((max_iter - iter) / max_iter)) + wf;
				vi = w * particles[index].get_v (i) + c1 * random_float (0.0, 1.0) * (particles[index].get_x_local (i) - particles[index].get_x (i)) + c2 * random_float (0.0, 1.0) * (x_global[i] - particles[index].get_x(i));
		  	// Set velocity clamping
		   	v_update = bound (vi, -Vmax[i], Vmax[i]);
		   	particles[index].set_v (v_update, i);
	  }
}

// Update particle's position, personal best and global best
void PSO::equation2 (int index, int& stall_iter) {

		double value_x, value_x_local;
		double xi;
    double vi;
    double x_update;
    
    for (int i = 0; i < dim; i++) {
    		// Update position
        xi = particles[index].get_x (i);
        vi = particles[index].get_v (i);
        x_update = bound (xi+vi, bounds[i][0], bounds[i][1]);
        // Update position
        particles[index].set_x (x_update,i);
    }

    value_x = fitness_funct (particles[index].get_x_vector (), false, dim); // Fitness value
    particles[index].set_value_x (value_x);

    value_x_local = particles[index].get_value_x_local ();

    // Update personal best (x_local)
    if (value_x < value_x_local) {
    		particles[index].set_value_x_local (value_x);
        particles[index].set_x_local_vector ();
    }

    value_x_local = particles[index].get_value_x_local ();

    // Update global best (x_global).
    {
    		if (value_x_local < value_global) {
    				stall_iter = 0;
        		x_global = particles[index].get_x_local_vector ();
            value_global = particles[index].get_value_x_local ();
        }
        else {
        		stall_iter ++;
       	}
    }
}

// Random number distribution that produces floating-point values according to a uniform distribution (every value is equally probable)
double PSO::random_float (double a, double b) const {
		// Use a non-deterministic seed
		static std::random_device rd;
		// Mersenne_twister_engine is a random number engine
		static std::mt19937 gen(rd());
		// Produce a random number in the range [a,b).
	  std::uniform_real_distribution<double> distr (a,b);
	  return distr (gen);
}

void PSO::set_x_global (const particle& p) {
    for (int i = 0; i < dim; i++)
    		x_global[i] = p.get_x_local (i);
}

void PSO::print_result () const {
		// Print global best
    std::cout<<"RESULT:\n";
    for (int i = 0; i < dim; i++)
    		std::cout << dim_id[i] << " = " << x_global[i] << std::endl;
    std::cout << "value_global = " << value_global << std::endl;
}

// Bound the position and velocity
double PSO::bound (double x, double lo, double up) const {
		if (x < lo)
    		return lo;
    else if (x > up)
    		return up;
    else
    		return x;
}