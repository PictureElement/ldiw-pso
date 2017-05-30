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
 * File: main.cpp
 * Created: 26.03.2016
 * Author: Sofokleous Marios
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include "config.h"
#include "pso.h"

int main() {
    
    using namespace std::chrono;

    PSO p (DIM, SWARM_SIZE, MAX_ITER, MAX_STALL_ITER, WI, WF, C1, C2, K, MODE);
    // Print global best
    std::cout << p.optimize() << std::endl;

    /*
    // Test 2: Epochs
    int runs = 1;
    double sum = 0.0;
    for(int i=0; i<runs; i++){
        //PSO(int dim, int swarm_size, int max_iter, double target, double threshold, double wi, double wf, double c1, double c2, double k, bool mode);
        PSO p (DIM, SWARM_SIZE, MAX_ITER, TARGET, THRESHOLD, 0.9, 0.4, 2.0, 2.0, 0.1, MODE);
        sum = sum + p.optimize();
    }
    std::cout<<"mean_iter = "<<sum/runs<<std::endl;

    // Test 3: Execution Time
    int runs = 50;
    double sum = 0;
    steady_clock::time_point t1 = steady_clock::now();
    for(int i=0; i<runs; i++){
        //PSO(int dim, int swarm_size, int max_iter, double target, double threshold, double wi, double wf, double c1, double c2, double k, bool mode);
        PSO p(DIM, SWARM_SIZE, MAX_ITER, TARGET, THRESHOLD, 0.9, 0.4, 2.0, 2.0, 0.1, MODE);
        sum = sum + p.optimize();
    }
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "runs = " << runs << ", " << "interval = " << time_span.count() << " sec" <<std::endl;
    std::cout << "mean error = " << sum/runs << std::endl;
		*/

    return 0;
}