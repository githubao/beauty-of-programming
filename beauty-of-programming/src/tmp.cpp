#include "../stdafx.h"

#include <iostream>
#include <thread>

using namespace std;

void hello() {
	cout << "aaa\n" << endl;
}

int main() {

	//���ƹ��캯��
	thread t(hello);

	cout << t.hardware_concurrency() << endl;

	t.join();

	getchar();

	return 0;
}
