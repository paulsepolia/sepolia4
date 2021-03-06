#define BOOST_TEST_DYN_LINK

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/test/unit_test.hpp>

namespace SEPOLIA4::BOOST_UNIT_TESTS
{
	using namespace boost::numeric;

	BOOST_AUTO_TEST_SUITE(UBLAS_MATRIX)

		BOOST_AUTO_TEST_CASE(TEST1)
		{
			ublas::matrix<double> m1(3, 3);
			ublas::matrix<double> m2(3, 3);
			ublas::matrix<double> m3(3, 3);

			for (unsigned i = 0; i < m1.size1(); ++i)
			{
				for (unsigned j = 0; j < m1.size2(); ++j)
				{
					m1(i, j) = 1;
					m2(i, j) = 2;
					m3(i, j) = 3;
				}
			}

			for (size_t i = 0; i < m1.size1(); i++)
			{
				for (size_t j = 0; j < m1.size2(); j++)
				{
					BOOST_CHECK(m1(i, j) + m2(i, j) == m3(i, j));
				}
			}
		}

		BOOST_AUTO_TEST_CASE(TEST2)
		{
			const int NROWS = 5;
			const int NCOLS = 6;

			ublas::matrix<double> m1(NROWS, NCOLS);
			ublas::matrix<double> m2(NCOLS, NCOLS);
			ublas::matrix<double> m3(NROWS, NCOLS);

			for (int i = 0; i < NROWS; ++i)
			{
				for (int j = 0; j < NCOLS; ++j)
				{
					m1(i, j) = 1.0;
				}
			}

			for (int i = 0; i < NCOLS; ++i)
			{
				for (int j = 0; j < NCOLS; ++j)
				{
					m2(i, j) = 2.0;
				}
			}

			m3 = ublas::prod(m1, m2);

			for (int i = 0; i < NROWS; ++i)
			{
				for (int j = 0; j < NCOLS; ++j)
				{
					BOOST_CHECK(m3(i, j) == static_cast<double>(2 * NCOLS));
				}
			}
		}

	BOOST_AUTO_TEST_SUITE_END()
}
