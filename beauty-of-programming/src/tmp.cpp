#include "../stdafx.h"

#include <iostream>
#include <thread>

using namespace std;

void hello() {
	cout << "aaa\n" << endl;
}

int main() {

	//复制构造函数
	thread t(hello);

	cout << t.hardware_concurrency() << endl;

	t.join();

	getchar();

	return 0;
}
