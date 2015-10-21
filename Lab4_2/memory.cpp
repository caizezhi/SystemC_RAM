#include"memory.h"

void Memory::entry() {
	while (1) {
		if (CE.read() == 0) { cout << "operation has been discarded" << endl; }
		else
		{
			if (WE.read() == 1)
			{
				ram[address.read().to_int()] = (data.read());wait(SC_ZERO_TIME);
				cout << "writing data" << data << "at" << address << endl;
			}
			else
			{
				data = ram[address.read().to_int()];wait(SC_ZERO_TIME);
				cout << "reading date" << data << "at" << address << endl;
			}
		}
		wait();
	}
}


