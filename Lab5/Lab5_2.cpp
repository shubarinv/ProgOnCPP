//
// Created by vhund on 24.03.2019.
//
#include "../Lib/Stack.h"
#include <iostream>

using namespace std;

void clearBuff() {       ///< @brief Чистит буфер
	cin.clear();           // Restore input stream to working state
	cin.ignore(4276, '\n'); // Get rid of any garbage that user might have entered}
}

int main()
{
	Stack<float> stk;
	for (int i = 0; i < 5; ++i) {
		cin>>stk.Push();
	}

	return 0;
}