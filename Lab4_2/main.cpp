#include"systemc.h"
#include"memory.h"
#include"test.h"
//#include"match.h"
int sc_main(int argc, char*argv[])
{
	Memory memory("memory", 2048);Test test("test");//match mt("mt");
	sc_signal<bool>  CE;sc_signal<bool> WE;
	sc_signal_rv<8> data;
	sc_signal<sc_bv<32>>address;
	memory.CE(CE);
	memory.WE(WE);
	memory.data(data);
	memory.address(address);
	test.CE(CE);
	test.WE(WE);
	test.address(address);
	sc_start();
	return 0;
};