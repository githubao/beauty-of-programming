// Created by BaoQiang at 2017/4/27 20:08

#include <windows.h>

/*
 * 控制CPU的时间在50%
 *
 * 100% 工作运行一个时间时，然后sleep一个时间时，看起来就像50%一样
 */

//typedef unsigned int DWORD;

//static void MakeUsage(float level) {
//    PerformanceCounter p = new PerformanceCounter("Processor","%Processor Time","_Totle");
//    while (true){
//        if(p.NextValue() > level){
//            System.Threading.Thread.Sleep(10);
//        }
//    }
//}

int main() {
    const DWORD busyTime = 10;
    const DWORD idleTime = busyTime;

    int startTime = 0;
    while (1) {
        DWORD startTime = GetTickCount();
        while ((GetTickCount() - startTime) <= busyTime) {

        }
        Sleep(idleTime);
    }

    return 0;
}

int main1() {
    for (; ;) {
        for (int i = 0; i < 9600000; ++i) {

        }
        Sleep(10);
    }
    return 0;
}