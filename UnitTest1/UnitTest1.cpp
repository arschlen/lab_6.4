#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_6.4/6.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { -1.2, 3.5, 0.0, 7.1, -8.3, 5.0 };
			int size = 6;
			int expectedCount = 3; // 3.5, 7.1, 5.0
			int result = CountPositive(arr, size);
			Assert::AreEqual(expectedCount, result);
		}
	};
}
