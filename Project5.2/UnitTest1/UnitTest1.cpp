#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Study\ООП\Project5.2\Project5.2\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a = 2, b = 3, c = 3;
			double s = 2.82843;
			s = Area1(a, b, c);
			Assert::IsTrue(s);
		}
	};
}
