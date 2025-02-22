#include "pch.h"
#include "CppUnitTest.h"

extern "C" int RNG(int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RNGTests
{
	TEST_CLASS(RNGTests)
	{
	public:
		
		TEST_METHOD(WithinRange) {	// tests weather RNG function stays within 0 and maxVal for n number of uses
			int maxVal = 20;
			int n = 100;
			bool inRange = true;
			for (int i = 0; i < n; i++) {
				int tmp = RNG(maxVal, 0);
				if (tmp < 0 || maxVal < tmp)
					inRange = false;
			}
			Assert::IsTrue(inRange);
		}
		TEST_METHOD(MinVal01) {	// tests weather RNG function Min value is 0 (if false, but MinVal02 is true then 1 is the minimum value)
			int maxVal = 20;
			int n = 1000;	// 1000 attempts makes it more likely to roll the lowest possible number
			bool minVal = false;
			for (int i = 0; i < n; i++) {
				int tmp = RNG(maxVal, 0);
				if (tmp == 0)
					minVal = true;
			}
			Assert::IsTrue(minVal);
		}
		TEST_METHOD(MinVal02) {	// tests weather RNG function Min value is 1
			int maxVal = 20;
			int n = 1000;	// 1000 attempts makes it more likely to roll the lowest possible number
			bool minVal = false;
			for (int i = 0; i < n; i++) {
				int tmp = RNG(maxVal, 0);
				if (tmp == 1)
					minVal = true;
			}
			Assert::IsTrue(minVal);
		}
	};
}
