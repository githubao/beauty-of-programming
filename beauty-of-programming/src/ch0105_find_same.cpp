// Created by BaoQiang at 2017/4/28 21:06


/*
 * 找出两个id的不同
 *
 * */

#include <iostream>

using namespace std;

void FindTwoDifferentNum(int a[], int n, int &num1, int &num2) {
    int i, ans = 0, k;
    for (i = 0; i < n; i++) {
        ans ^= a[i];
    }

}