#include"systemc.h"
#include<fstream>
struct Memory :sc_module {
public:	sc_inout<sc_lv<8>> data;sc_in<sc_bv<32>> address;sc_in<bool> CE;sc_in<bool> WE;//sc_in<bool>clk;
																					   //sc_signal<sc_lv<8>> ram[size];
		Memory(sc_module_name _n, int _size) :sc_module(_n), size(_size) {
			ram = new sc_lv<8>[size];
			SC_THREAD(entry);
			sensitive << address << WE << CE;
			dont_initialize();
			ifstream input;
			input.open("F://T1.txt");
			int x;sc_uint<8> y;sc_lv<8> z;
			for (int i = 0;i<1040;i++)
			{
				input >> x >> hex >> x; 
				y = x;z = y;
				ram[i] = z;
			}
			input.close();
		}
		SC_HAS_PROCESS(Memory);

		void entry() {
			while (1) {
				if (CE.read() == 0) { 
					cout << "operation has been discarded" << endl; 
				}
				else
				{
					if (WE.read() == 1)
					{
						if (address.read().to_int()> 32) {
							SC_REPORT_ERROR("ERROR<001>", "Reading out of range");
						}
						else {
							ram[address.read().to_int()] = (data.read());wait(SC_ZERO_TIME);
							cout << "writing data" << hex << data << " " << "at" << " " << address << endl;
						}
					}
					else
					{
						if (address.read().to_int()> 32) {
							SC_REPORT_ERROR("ERROR<002>", "Writing out of range");
						}
						else {
							data = ram[address.read().to_int()];wait(SC_ZERO_TIME);
							cout << "Reading data" << hex << data << " " << "at" << " " << address << endl;
						}
					}
				}
				wait();
			}
		}
		;
		const int size;
		sc_lv<8> *ram;
		sc_lv<8> *ram1;
};
