#include "pch.h"
#include "CppUnitTest.h"
#include "../laba9.3/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			struct 
			{
				int RP;
				int RO;
				int suma;
			};
			
			int n = 1;
			Bill* bill1 = new Bill[n];
			bill1[0].RP = 123;
			bill1[0].RO = 321;
			bill1[0].suma = 432;
			Bill t =sum(bill1, n);
		    Assert::AreEqual(t, 432);

		}
	};
}
