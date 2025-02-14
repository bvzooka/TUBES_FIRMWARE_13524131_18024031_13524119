#include "Arduino.h"
#include "PID.h"

PID::PID(int Kp_, int Ki_, int Kd_): Kp(Kp_), Ki(Ki_), Kd(Kd_), err(0), lastErr(0), errSum(0) {}

int PID::getKp() {
    return Kp;
}

int PID::getKi() {
    return Ki;
}

int PID::getKd() {
    return Kd;
}

void PID::calcErr(int des, int now) {
	lastErr = err;
	err = now - des;
	errSum += err;
	if (errSum > 200) {
		errSum = 200;
	} else if (errSum < -200) {
		errSum = -200;
	}
}

float PID::feedback() {
	float out = Kp * err + Ki * errSum + Kd * (err - lastErr) + 90;
	if (out > 180) {
		out = 180;
	}
	if (out < 0) {
		out = 0;
	}
	return out;
}

float PID::getOutput() {
	if (err > 5 || err < -5) {
		return feedback();
	} else {
		return 90;
	}
}