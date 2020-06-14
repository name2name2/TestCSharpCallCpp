using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace TestCSharp_UseCPPdll
{
	class Program
	{
		static void Main(string[] args)
		{

			//---------Example 1---------無 * & 版本

			//// Initialize a Fibonacci relation sequence.
			//fibonacci_init(1, 1);
			//// Write out the sequence values until overflow.

			//int isNext = 0;
			//do
			//{
			//	Console.WriteLine(fibonacci_index() + ":" + fibonacci_current());
			//	isNext = fibonacci_next();
			//} while (isNext >= 0);
			//// Report count of values written before overflow.
			//Console.WriteLine(fibonacci_index() + 1 + " Fibonacci sequence values fit in an " + "unsigned 64-bit integer.");

			//Console.Read();

			//---------Example 2---------有 * & 版本
			// Initialize a Fibonacci relation sequence.
			ulong a = 1;
			fibonacci_init_Reference_Pointer(ref a, ref a);
			// Write out the sequence values until overflow.

			int isNext = 0;
			do
			{
				Console.WriteLine(fibonacci_index() + ":" + fibonacci_current());
				isNext = fibonacci_next();
			} while (isNext >= 0);
			// Report count of values written before overflow.
			Console.WriteLine(fibonacci_index() + 1 + " Fibonacci sequence values fit in an " + "unsigned 64-bit integer.");

			Console.Read();


		}




		//extern "C" MATHLIBRARY_API void fibonacci_init(
		//const unsigned long long a, const unsigned long long b);

		////ADD TEST BY MYSELF
		//extern "C" MATHLIBRARY_API void fibonacci_init_Reference_Pointer(
		//const unsigned long long* a, const unsigned long long &b);

		//extern "C" MATHLIBRARY_API bool fibonacci_next();

		//extern "C" MATHLIBRARY_API unsigned long long fibonacci_current();

		//extern "C" MATHLIBRARY_API unsigned fibonacci_index();

		[DllImport(@"你的專案\TestCSharpCallCpp\TestMain\Debug\MathLib.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern void fibonacci_init(ulong a, ulong b);


		//發現遇到 * &   全部都用ref代入
		[DllImport(@"你的專案\TestCSharpCallCpp\TestMain\Debug\MathLib.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern void fibonacci_init_Reference_Pointer(ref ulong a, ref ulong b);

		//!!!!這邊本來宣告應該是回傳bool  但我發現用bool接  一直跑不會停  表示bool接的不正確  改用int接發現C++回傳false 到C#  變成一個很大的負值
		//所以程式我改寫成
		//isNext = fibonacci_next();
		//} while (isNext >= 0);
		[DllImport(@"你的專案\TestCSharpCallCpp\TestMain\Debug\MathLib.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern int fibonacci_next();

		[DllImport(@"你的專案\TestCSharpCallCpp\TestMain\Debug\MathLib.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern ulong fibonacci_current();

		[DllImport(@"你的專案\TestCSharpCallCpp\TestMain\Debug\MathLib.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern uint fibonacci_index();


	}
}
