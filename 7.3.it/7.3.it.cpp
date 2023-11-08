#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.3.it/PR7.3.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My73it
{
	TEST_CLASS(My73it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** arr1 = new int* [3];
			for (int i = 0; i < 3; i++) {
				arr1[i] = new int[3];
			}
			arr1[0][0] = 4;
			arr1[0][1] = 6;
			arr1[0][2] = 33;
			arr1[1][0] = 8;
			arr1[1][1] = 30;
			arr1[1][2] = 12;
			arr1[2][0] = 24;
			arr1[2][1] = 6;
			arr1[2][2] = 7;
			Sort(arr1, 3);
			int** arr2 = new int* [3];
			for (int i = 0; i < 3; i++) {
				arr2[i] = new int[3];
			}
			arr2[0][0] = 33;
			arr2[0][1] = 6;
			arr2[0][2] = 33;
			arr2[1][0] = 8;
			arr2[1][1] = 30;
			arr2[1][2] = 12;
			arr2[2][0] = 24;
			arr2[2][1] = 6;
			arr2[2][2] = 24;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Assert::AreEqual(arr2[i][j], arr1[i][j]);
				}
			}

			for (int i = 0; i < 3; i++) {
				delete[] arr1[i];
				delete[] arr2[i];
			}
			delete[]arr1, arr2;

		}
	};
}
