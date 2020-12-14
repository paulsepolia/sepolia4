#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include "../Vector/Vector.h"
#include <boost/test/unit_test.hpp>

//#include <cblas.h>
//int main()
//{
//	// Create arrays that represent the matrices A,B,C
//	const int n = 20;
//	auto* A = new double[n * n];
//	auto* B = new double[n * n];
//	auto* C = new double[n * n];
//
//	// Fill A and B with random numbers
//	for (uint32_t i = 0; i < n; i++)
//	{
//		for (uint32_t j = 0; j < n; j++)
//		{
//			A[i * n + j] = 1;
//			B[i * n + j] = 1;
//		}
//	}
//
//	// Calculate A*B=C
//	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, B, n, 0.0, C, n);
//
//	std::cout << C[0] << std::endl;
//	std::cout << C[1] << std::endl;
//	std::cout << C[2] << std::endl;
//
//	// Clean up
//	delete[] A;
//	delete[] B;
//	delete[] C;
//
//	return 0;
//}

namespace bt = boost::unit_test;

#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>

namespace std
{
	ostream& operator<<(ostream& stream, Vector const& term)
	{
		return stream;
	}
}

namespace TESTS_SEPOLIA4_VECTOR
{
	constexpr size_t DIM = 10;

	BOOST_AUTO_TEST_CASE(TEST1)
	{
		Vector v1;
		BOOST_TEST(v1.Size() == 0);
		BOOST_TEST(v1.IsDeallocated());

		v1.Allocate(DIM);
		BOOST_TEST(v1.Size() == DIM);
		BOOST_TEST(v1.IsAllocated());

		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = static_cast<double>(i);
		}

		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(v1.At(i) == static_cast<double>(i));
		}

		v1.Deallocate();
		BOOST_TEST(v1.Size() == 0);
		BOOST_TEST(v1.IsDeallocated());
	}

	BOOST_AUTO_TEST_CASE(TEST2)
	{
		Vector v1;
		Vector v2;

		BOOST_TEST(v1.Size() == 0);
		BOOST_TEST(v2.Size() == 0);
		BOOST_TEST(v1.IsDeallocated());
		BOOST_TEST(v2.IsDeallocated());

		v1.Allocate(DIM);
		v2.Allocate(DIM);

		BOOST_TEST(v1.Size() == DIM);
		BOOST_TEST(v2.Size() == DIM);
		BOOST_TEST(v1.IsAllocated());
		BOOST_TEST(v2.IsAllocated());

		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = static_cast<double>(i);
			v2[i] = v1.At(i);
		}

		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(v1.At(i) == static_cast<double>(i));
			BOOST_TEST(v1.At(i) == v2.At(i));
		}

		BOOST_CHECK(v1 == v2);

		v1[0] = 2;
		v2[0] = 3;
		BOOST_CHECK(v1 != v2);

		v1.Deallocate();
		v2.Deallocate();
		BOOST_TEST(v1.Size() == 0);
		BOOST_TEST(v2.Size() == 0);
		BOOST_TEST(v1.IsDeallocated());
		BOOST_TEST(v2.IsDeallocated());
	}

	BOOST_AUTO_TEST_CASE(TEST3)
	{
		Vector v1;
		Vector v2;
		v1.Allocate(DIM);
		v2.Allocate(DIM);

		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = static_cast<double>(i);
			v2[i] = static_cast<double>(i + 1);
		}

		const auto v3 = v1 + v2;

		for (size_t i = 0; i < DIM; i++)
		{
			//BOOST_TEST(v3.At(i) == static_cast<double>(i) + static_cast<double>(i + 1));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST4)
	{
		Vector v1;
		Vector v2;
		v1.Allocate(DIM);
		v2.Allocate(DIM);

		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = static_cast<double>(i);
			v2[i] = static_cast<double>(i + 1);
		}

		const auto v3 = v1 - v2;

		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(v3.At(i) == static_cast<double>(i) - static_cast<double>(i + 1));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST5)
	{
		Vector v1;
		Vector v2;

		v1.Allocate(DIM);
		v2.Allocate(DIM);

		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = static_cast<double>(i);
			v2[i] = static_cast<double>(i + 1);
		}

		const auto v3 = v1 * v2;

		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(v3.At(i) == static_cast<double>(i) * static_cast<double>(i + 1));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST6)
	{
		Vector v1;
		Vector v2;
		v1.Allocate(DIM);
		v2.Allocate(DIM);

		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = static_cast<double>(i);
			v2[i] = static_cast<double>(i + 1);
		}

		const auto v3 = v1 / v2;

		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(v3.At(i) == static_cast<double>(i) / static_cast<double>(i + 1));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST7)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 11;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i);
		}

		const auto res = v + val;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == v.At(i) + val);
		}
	}

	BOOST_AUTO_TEST_CASE(TEST8)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 12;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i);
		}

		const auto res = v - val;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == v.At(i) - val);
		}
	}

	BOOST_AUTO_TEST_CASE(TEST9)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 12;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i);
		}

		const auto res = v * val;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == v.At(i) * val);
		}
	}

	BOOST_AUTO_TEST_CASE(TEST10)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 12;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i);
		}

		const auto res = v / val;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == v.At(i) / val);
		}
	}

	BOOST_AUTO_TEST_CASE(TEST11)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 11;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i);
		}

		const auto res = val + v;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == val + v.At(i));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST12)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 12;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i);
		}

		const auto res = val - v;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == val - v.At(i));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST13)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 13;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i);
		}

		const auto res = val * v;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == val * v.At(i));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST14)
	{
		Vector v;
		v.Allocate(DIM);
		const double val = 14;

		for (size_t i = 0; i < DIM; i++)
		{
			v[i] = static_cast<double>(i + 1);
		}

		const auto res = val / v;
		for (size_t i = 0; i < DIM; i++)
		{
			BOOST_TEST(res.At(i) == val / v.At(i));
		}
	}

	BOOST_AUTO_TEST_CASE(TEST15)
	{
		Vector v1;
		v1.Allocate(DIM);
		const double val = 10;
		v1 = val;

		for (size_t i = 0; i < v1.Size(); i++)
		{
			BOOST_TEST(v1.At(i) == val);
		}
	}

	BOOST_AUTO_TEST_CASE(TEST16)
	{
		Vector v1;
		v1.Allocate(DIM);
		const double val = 10;
		v1 = val;

		Vector v2(std::move(v1));

		BOOST_TEST(v2.Size() == DIM);

		for (size_t i = 0; i < v2.Size(); i++)
		{
			BOOST_TEST(v2.At(i) == val);
		}
	}

	BOOST_AUTO_TEST_CASE(TEST17)
	{
		Vector v1;
		v1.Allocate(DIM);
		const double val = 10;
		v1 = val;

		Vector v2;
		v2 = std::move(v1);

		BOOST_TEST(v2.Size() == DIM);

		for (size_t i = 0; i < v2.Size(); i++)
		{
			BOOST_TEST(v2.At(i) == val);
		}
	}

	BOOST_AUTO_TEST_CASE(TEST18)
	{
		Vector v1;
		v1.Allocate(DIM);
		v1 = 10;
		auto v2 = -v1;
		BOOST_TEST(v1 == 10);
		BOOST_TEST(10 == v1);
		BOOST_TEST(v2 == -v1);
		BOOST_TEST(-v1 == v2);
		BOOST_TEST(v1 != 11);
		BOOST_TEST(v2 != v1);
		BOOST_TEST(11 != v1);
	}

	BOOST_AUTO_TEST_CASE(TEST19)
	{
		Vector v1;
		v1.Allocate(DIM);
		const double val = 10;
		v1 = val;
		Vector v2(v1);

		BOOST_TEST(v1 == val);
		BOOST_TEST(val == v1);
		BOOST_TEST(v2 == v1);
		BOOST_TEST(v2 == val);
	}

	BOOST_AUTO_TEST_CASE(TEST20)
	{
		Vector v1;
		v1.Allocate(DIM);
		Vector v2;
		v2.Allocate(DIM);
		Vector v3;
		v3.Allocate(DIM);

		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = std::sin(i);
			v2[i] = std::sin(i);
			v3[i] = std::sin(i);
		}

		BOOST_TEST(v1 == v2);
		BOOST_TEST(v2 == v3);
		BOOST_TEST(v1 == v3);
	}

	BOOST_AUTO_TEST_CASE(TEST21)
	{
		Vector v1{ 1, 2, 3, 4 };
		BOOST_TEST(v1.Size() == 4);
		BOOST_TEST(v1[0] == 1);
		BOOST_TEST(v1[1] == 2);
		BOOST_TEST(v1[2] == 3);
		BOOST_TEST(v1[3] == 4);
	}

	BOOST_AUTO_TEST_CASE(TEST22)
	{
		std::vector<double> v1STL{ 1, 2, 3, 4 };
		Vector v1(v1STL);
		BOOST_TEST(v1.Size() == 4);
		BOOST_TEST(v1[0] == 1);
		BOOST_TEST(v1[1] == 2);
		BOOST_TEST(v1[2] == 3);
		BOOST_TEST(v1[3] == 4);
	}

	BOOST_AUTO_TEST_CASE(TEST23)
	{
		Vector v1(DIM);
		BOOST_TEST(v1.Size() == DIM);
		const double val = 12.34;
		for (size_t i = 0; i < DIM; i++)
		{
			v1[i] = static_cast<double>(val);
		}

		BOOST_TEST(v1 == val);
		BOOST_TEST(val == v1);
	}

	BOOST_AUTO_TEST_CASE(TEST24)
	{
		Vector v1(DIM);
		Vector v2(DIM);
		Vector v3(DIM);
		Vector v4(DIM);
		const double val1 = 1;
		v1 = val1;
		const double val2 = 2;
		v2 = val2;
		const double val3 = 3;
		v3 = val3;
		const double val4 = 4;
		v4 = val4;

		v4 = v1 + v2 + v3 + v4;
		BOOST_TEST(v4 == val1 + val2 + val3 + val4);

		v4 = val1;
		BOOST_TEST(val1 == v4);

		v4 = val1 + val2 + val3 - val1 - val2 - val3;
		BOOST_TEST(v4 == 0);

		v4 = val1;
		BOOST_TEST(val1 == v4);

		v4 = -v1 + val1 + v2 - val2;
		BOOST_TEST(v4 == 0);
	}

	BOOST_AUTO_TEST_CASE(TEST25)
	{
		Vector v1(DIM);
		Vector v2(DIM);
		Vector v3(DIM);
		const double val1 = 1;
		v1 = val1;
		const double val2 = 2;
		v2 = val2;

		v3 = (v1 / v2) * (v2 / v1);
		BOOST_TEST(v3 == 1.0);
	}

	BOOST_AUTO_TEST_CASE(TEST26)
	{
		Vector v1(DIM);
		double val1 = 1;
		v1 = val1;
		++v1;
		++val1;
		BOOST_TEST(v1 == val1);
	}

	BOOST_AUTO_TEST_CASE(TEST27)
	{
		Vector v1(DIM);
		double val1 = 1;
		v1 = val1;
		--v1;
		--val1;
		BOOST_TEST(v1 == val1);
	}

	BOOST_AUTO_TEST_CASE(TEST28)
	{
		Vector v1(DIM);
		double val1 = 1;
		v1 += val1;
		BOOST_TEST(v1 == val1);
		v1 += val1;
		BOOST_TEST(v1 == 2 * val1);
		v1 += v1;
		BOOST_TEST(v1 == 4 * val1);
	}

	BOOST_AUTO_TEST_CASE(TEST29)
	{
		Vector v1(DIM);
		double val1 = 1;
		v1 -= val1;
		BOOST_TEST(v1 == -1 * val1);
		v1 -= val1;
		BOOST_TEST(v1 == -2 * val1);
		v1 -= v1;
		BOOST_TEST(v1 == 0);
	}

	BOOST_AUTO_TEST_CASE(TEST30)
	{
		Vector v1(DIM);
		double val1 = 3;
		double val2 = 4;
		v1 = val1;
		v1 *= val2;
		BOOST_TEST(v1 == val1 * val2);
		v1 *= v1;
		BOOST_TEST(v1 == val1 * val2 * val1 * val2);
	}

	BOOST_AUTO_TEST_CASE(TEST31)
	{
		Vector v1(DIM);
		const double val1 = 3;
		const double val2 = 4;
		v1 = val1;
		v1 /= val2;
		BOOST_TEST(v1 == val1 / val2);
		v1 /= v1;
		BOOST_TEST(1.0 == v1);
	}
}
