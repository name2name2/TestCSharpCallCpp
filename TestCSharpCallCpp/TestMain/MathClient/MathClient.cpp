// MathClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "MathLib.h"
#include <windows.h>
#include "libloaderapi.h"


typedef void(_cdecl *Fib_INIT)(const unsigned long long a, const unsigned long long b);
typedef bool(_cdecl *Fib_NEXT)();
typedef unsigned long long(_cdecl *Fib_CURRENT)();
typedef unsigned(_cdecl *Fib_INDEX)();

//ADD TEST BY MYSELF
typedef void(_cdecl *Fib_INIT_Reference_Pointer)(const unsigned long long *a, const unsigned long long &b);


int main()
{


	//---------------------Example 1----------------------------

	//USE MSDN EXMAPLE                沒有用到 * &
	//https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=vs-2017

	//// Initialize a Fibonacci relation sequence.
	//fibonacci_init(1, 1);
	//// Write out the sequence values until overflow.
	//do {
	//	std::cout << fibonacci_index() << ": "
	//		<< fibonacci_current() << std::endl;
	//} while (fibonacci_next());
	//// Report count of values written before overflow.
	//std::cout << fibonacci_index() + 1 <<
	//	" Fibonacci sequence values fit in an " <<
	//	"unsigned 64-bit integer." << std::endl;


	//---------------------Example 2----------------------------

	////改編   USE _cdecl (類似_stdcall)      沒有用到 * &
	//HINSTANCE hInst = LoadLibrary(L"MathLib.dll");

	//Fib_INIT pInit = (Fib_INIT)GetProcAddress(hInst, "fibonacci_init");
	//Fib_NEXT pNEXT = (Fib_NEXT)GetProcAddress(hInst, "fibonacci_next");
	//Fib_CURRENT pCURRENT = (Fib_CURRENT)GetProcAddress(hInst, "fibonacci_current");
	//Fib_INDEX pINDEX = (Fib_INDEX)GetProcAddress(hInst, "fibonacci_index");

	//// Initialize a Fibonacci relation sequence.
	//pInit(1, 1);
	//// Write out the sequence values until overflow.
	//do {
	//	std::cout << pINDEX() << ": "
	//		<< pCURRENT() << std::endl;
	//} while (pNEXT());
	//// Report count of values written before overflow.
	//std::cout << pINDEX() + 1 <<
	//	" Fibonacci sequence values fit in an " <<
	//	"unsigned 64-bit integer." << std::endl;

	//std::cout << "PAUSE   Ctrl+C to END" << std::endl; 
	//int pause;
	//std::cin >> pause;
	
	//---------------------Example 1 - *& ----------------------------


	//USE MSDN EXMAPLE                用到 * &

	//const unsigned long long v1 = 1; //v1 數字 值
	//const unsigned long long *a = &v1; // 取 v1 數字值 的 位址  (C++專有名詞  可查資料或看書了解意義)
	//
	//const unsigned long long v2 = 1; //v2 數字 值
	//const unsigned long long &b = v2; //直接取  參考 (C++專有名詞   可查資料或看書了解意義)

	//// Initialize a Fibonacci relation sequence.
	//fibonacci_init_Reference_Pointer(a, b);
	//// Write out the sequence values until overflow.
	//do {
	//	std::cout << fibonacci_index() << ": "
	//		<< fibonacci_current() << std::endl;
	//} while (fibonacci_next());
	//// Report count of values written before overflow.
	//std::cout << fibonacci_index() + 1 <<
	//	" Fibonacci sequence values fit in an " <<
	//	"unsigned 64-bit integer." << std::endl;


	//---------------------Example 2 - *&   ----------------------------

	//改編   USE _cdecl (類似_stdcall)      用到 * &
	HINSTANCE hInst = LoadLibrary(L"MathLib.dll");

	Fib_INIT_Reference_Pointer pInit_Reference_Pointer = (Fib_INIT_Reference_Pointer)GetProcAddress(hInst, "fibonacci_init_Reference_Pointer");
	Fib_NEXT pNEXT = (Fib_NEXT)GetProcAddress(hInst, "fibonacci_next");
	Fib_CURRENT pCURRENT = (Fib_CURRENT)GetProcAddress(hInst, "fibonacci_current");
	Fib_INDEX pINDEX = (Fib_INDEX)GetProcAddress(hInst, "fibonacci_index");

	const unsigned long long v1 = 1; //v1 數字 值
	const unsigned long long *a = &v1; // 取 v1 數字值 的 位址  (C++專有名詞  可查資料或看書了解意義)

	const unsigned long long v2 = 1; //v2 數字 值
	const unsigned long long &b = v2; //直接取  參考 (C++專有名詞   可查資料或看書了解意義)


	// Initialize a Fibonacci relation sequence.
	pInit_Reference_Pointer(a, b);
	// Write out the sequence values until overflow.
	do {
		std::cout << pINDEX() << ": "
			<< pCURRENT() << std::endl;
	} while (pNEXT());
	// Report count of values written before overflow.
	std::cout << pINDEX() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;

	std::cout << "PAUSE   Ctrl+C to END" << std::endl;
	int pause;
	std::cin >> pause;




}