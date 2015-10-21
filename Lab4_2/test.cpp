#include"test.h"
void Test::generate() {
	CE = 1;
	for (int i = 0;i != 1041;i++)
	{
		wait(5,SC_NS);
		address.write(i);
	}
	//WE = 1;
	//for (int m = 0;m < 1040;m++) {
		//wait(5, SC_NS);
		//address.write(m);
	//}
};
