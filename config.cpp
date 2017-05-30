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
 * File: config.cpp
 * Description: PSO parameter definitions
 * Created: 24.04.2016
 * Author: Sofokleous Marios
 */

#include "config.h"

//-------------------- PSO PARAMETERS (MANUALLY CONFIGURED) --------------------

// Dimensionality
int DIM = 30;

// # of particles
int SWARM_SIZE = 20;

// Termination criterions
int MAX_ITER = 1000000;
int MAX_STALL_ITER = 1000;

// Inertia weight (0 <= WI <= 2, 0 <= WF <= 2)
double WI = 0.9;
double WF = 0.4;

// Learning factors (0 <= C1 <= 4, 0 <= C1 <= 4, usually C1 = C2 = 2)
double C1 = 2.0;
double C2 = 2.0;

// Velocity clamping factor (0 < K <= 1)
double K = 0.1;

/*
 * MODE = 1: Stopping condition max_stall_iter
 * MODE = 0: Stopping condition max_iter
 */
bool MODE = 1;