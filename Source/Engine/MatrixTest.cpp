#include "MatrixTest.h"

namespace Testing
{
	namespace Math
	{
		MatrixTest::MatrixTest(void)
		{
		}


		MatrixTest::~MatrixTest(void)
		{
		}

		void MatrixTest::run()
		{
			char input[255];
			input[0] = '\0';
	
			math::Matrix p;
			math::Matrix f1;
			math::Matrix f2;
			math::Matrix r;
	
			p.setRow(0, 1, 0, 0, 0);
			p.setRow(1, 0, 1, 0, 0);
			p.setRow(2, 0, 0, 1, 0);
			p.setRow(3, 3.89453, -32.1888, -13.9317, 1);
			printf("p:\n");
			p.printMatrix();

			f1.setRow(0, 1, 0, 0, 0);
			f1.setRow(1, 0, 1, 0, 0);
			f1.setRow(2, 0, 0, 1, 0);
			f1.setRow(3, 0, 0, 0, 1);
			printf("f1:\n");
			f1.printMatrix();

			f2.setRow(0, 1, 0, 0, 0);
			f2.setRow(1, 0, 1, 0, 0);
			f2.setRow(2, 0, 0, 1, 0);
			f2.setRow(3, 0.152898, 0, 0.0550032, 1);
			printf("f2:\n");
			f2.printMatrix();

			r = (p * f2);
			printf("r:\n");
			r.printMatrix();

			printf("Finished.\n");
			scanf(input);
		}
	}
}