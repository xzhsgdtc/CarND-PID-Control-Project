#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
	p_error = d_error = i_error = avg_error = total_square_error = 0.0;
	prev_cte = 0;
	step = 0;

}

void PID::UpdateError(double cte) {
	if(step == 0){
		prev_cte = cte;
	}
	step += 1;

	p_error = cte;
	i_error += cte;
	d_error = cte - prev_cte;

	total_square_error += cte * cte;
	avg_error = total_square_error/step;
	cout << step << ";" << avg_error << ";" << cte << endl;
	prev_cte = cte;

}

double PID::TotalError() {

	return -Kp * p_error - Ki * i_error - Kd * d_error;
}


// 2.9229,  10.327,  0.49327