#pragma once
#include"systemc.h"
SC_MODULE(Test) {
	sc_out<sc_bv<32>>address;
	sc_out<bool> CE;sc_out<bool> WE;
	void generate();
	SC_CTOR(Test) {	
		SC_THREAD(generate);
	}
};