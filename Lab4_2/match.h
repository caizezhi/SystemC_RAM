#pragma once
#include<systemc.h>
SC_MODULE(match) {
	sc_in<sc_bv<32>>address;
	sc_in<sc_bv<32>>address1;
	sc_in<sc_bv<32>>address2;
	sc_out<sc_bv<32>>address3;
	SC_CTOR(match) {
		SC_THREAD(add_match);
		sensitive << address1 << address2 ;
	}
	void add_match() {
		int counter = 0;
		while (1) {
			if (address.read().to_int() == address1.read().to_int()) {
				cout << "NO_MISMATCH" << endl;
			}
			else if (address1.read().to_int() == address2.read().to_int()) {
				cout << "NO_MISMATCH" << endl;
			}
			else if (address.read().to_int() != address1.read().to_int()) {
				address3.write(address);
				cout << "MISMATCH_ADD" << "¡¡" << address << endl;
			}
			else if (address1.read().to_int() != address2.read().to_int()) {
				address3.write(address1);
				cout << "MISMATCH_ADD" << " " << address1 << endl;
			}
			counter++;
			if (counter > 100) {
				break;
			}
			wait();
		}
		sc_stop();
	}
};