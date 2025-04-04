#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI ThreadFunction1(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        cout << "Thread 1 count is" << i << endl;
        Sleep(100);
    }
    return 0;
}

DWORD WINAPI ThreadFunction2(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        cout << "Thread 2 count" << i << endl;
        Sleep(150);
    }
    return 0;
}

int main() {
    HANDLE hThread1, hThread2;
    DWORD dwThreadId1, dwThreadId2;

    hThread1 = CreateThread(NULL, 0, ThreadFunction1, NULL, 0 &dwThreadId1);

    if (hThread1 == NULL) {
        cerr << "Error creating Thread1:" << GetLastError() << endl;
        return 1;
    }

    hThread2 = CreateThread(NULL, 0, ThreadFunction2, NULL, 0, &dwThreadId2);
    
    if (hThread2 == NULL) {
        cerr << "Error creating Thread 2" << endl;
        return 1;
    }

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);

    return 0;

}
