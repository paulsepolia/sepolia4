#define BOOST_TEST_DYN_LINK

#include "../Containers/List/List.h"
#include <boost/test/unit_test.hpp>

using namespace SEPOLIA4::CONTAINERS;

namespace SEPOLIA4::BOOST_UNIT_TESTS
{
	constexpr size_t DIM = 10;

	BOOST_AUTO_TEST_SUITE(CONTAINER_LIST)

		BOOST_AUTO_TEST_CASE(TEST1)
		{
			auto list = List<double>();
			BOOST_CHECK(list.Size() == 0);
			BOOST_CHECK(list.Empty() == true);
			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(i));
			}
			BOOST_CHECK(list.Size() == DIM);
			BOOST_CHECK(list.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST2)
		{
			auto list = List({ 1, 2, 3, 4, 5, 6 });
			BOOST_CHECK(list.Size() == 6);
			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(i));
			}
			BOOST_CHECK(list.Size() == 6 + DIM);
			list.Append({ 5, 6, 7, 8, 9, 10 });
			BOOST_CHECK(list.Size() == 6 + DIM + 6);
			BOOST_CHECK(list.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST3)
		{
			auto list = List({ 1, 2 });
			list.Append({ 3, 4 });
			list.Insert(5);
			list.Insert(6);
			BOOST_CHECK(list.Size() == 6);
			BOOST_CHECK(list.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST4)
		{
			std::vector<double> values{ 1, 2 };
			auto list = List(values);
			BOOST_CHECK(list.Size() == 2);
			list.Append({ 3, 4 });
			list.Insert(5);
			list.Insert(6);
			BOOST_CHECK(list.Size() == 6);
			BOOST_CHECK(list.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST5)
		{
			std::vector<double> values{ 1, 2 };
			auto list = List(values);
			std::vector<double> values2{ 3, 4 };
			list.Append(values2);
			list.Insert(5);
			list.Insert(6);
			BOOST_CHECK(list.Size() == 6);
			BOOST_CHECK(list.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST6)
		{
			std::vector<double> values{ 1, 2, 3, 4, 5, 6 };
			const auto list1 = List(values);
			const auto list2 = List(list1);
			BOOST_CHECK(list1.Size() == 6);
			BOOST_CHECK(list2.Size() == 6);
			BOOST_CHECK(list1.Empty() == false);
			BOOST_CHECK(list2.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST7)
		{
			std::vector<double> values{ 1, 2, 3, 4, 5, 6 };
			const auto list1 = List(values);
			const auto& list2 = list1;
			BOOST_CHECK(list1.Size() == 6);
			BOOST_CHECK(list2.Size() == 6);
			BOOST_CHECK(list1.Empty() == false);
			BOOST_CHECK(list2.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST8)
		{
			std::vector<double> values{ 1, 2, 3, 4, 5, 6 };
			auto list1 = List(values);
			const auto list2 = List(std::move(list1));
			BOOST_CHECK(list2.Size() == 6);
			BOOST_CHECK(list2.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST9)
		{
			std::vector<double> values{ 1, 2, 3, 4, 5, 6, 7 };
			auto list1 = List(values);
			const auto list2 = std::move(list1);
			BOOST_CHECK(list2.Size() == 7);
			BOOST_CHECK(list2.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST10)
		{
			std::vector<double> values{ 1, 2, 3, 4, 5, 6 };
			auto list = List(values);
			BOOST_CHECK(list.Size() == 6);
			BOOST_CHECK(list.Empty() == false);
			int v = 1;
			list.EraseOne(v);
			list.Print();
			BOOST_CHECK(list.Size() == 5);
			BOOST_CHECK(list.Empty() == false);
			v = 3;
			list.EraseOne(v);
			list.Print();
			BOOST_CHECK(list.Size() == 4);
			BOOST_CHECK(list.Empty() == false);
			v = 6;
			list.EraseOne(v);
			list.Print();
			BOOST_CHECK(list.Size() == 3);
			BOOST_CHECK(list.Empty() == false);
		}

		BOOST_AUTO_TEST_CASE(TEST11)
		{
			std::vector<double> values{ 1, 2, 5, 1, 2, 4, 5 };
			auto list = List(values);
			BOOST_CHECK(list.Size() == 7);
			BOOST_CHECK(list.Empty() == false);
			int v = 1;
			list.EraseAll(v);
			list.Print();
			BOOST_CHECK(list.Size() == 5);
			BOOST_CHECK(list.Empty() == false);
			v = 2;
			list.EraseAll(v);
			list.Print();
			BOOST_CHECK(list.Size() == 3);
			BOOST_CHECK(list.Empty() == false);
			v = 5;
			list.EraseAll(v);
			list.Print();
			BOOST_CHECK(list.Size() == 1);
			BOOST_CHECK(list.Empty() == false);
			v = 6;
			list.EraseAll(v);
			list.Print();
			BOOST_CHECK(list.Size() == 1);
			BOOST_CHECK(list.Empty() == false);
			v = 4;
			list.EraseAll(v);
			list.Print();
			BOOST_CHECK(list.Size() == 0);
			BOOST_CHECK(list.Empty() == true);
		}

		BOOST_AUTO_TEST_CASE(TEST12)
		{
			std::vector<double> values(10, 4);

			auto list = List(values);

			BOOST_CHECK(list.Size() == 10);
			BOOST_CHECK(list.Empty() == false);

			list.Clear();
			list.Print();

			BOOST_CHECK(list.Size() == 0);
			BOOST_CHECK(list.Empty() == true);
		}

		BOOST_AUTO_TEST_CASE(TEST13)
		{
			std::vector<double> values({ 1, 2, 3, 4, 5 });

			auto list = List(values);

			list.Print();
			list.Reverse();

			BOOST_CHECK(list.Size() == 5);

			list.Print();
		}

		BOOST_AUTO_TEST_CASE(TEST14)
		{
			auto list = List<double>();

			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(i));
			}

			BOOST_CHECK(list.Size() == DIM);
			BOOST_CHECK(list.Empty() == false);
			BOOST_CHECK(list.FindOne(double(0)) == 0);
			BOOST_CHECK(list.FindOne(double(1)) == 1);
			BOOST_CHECK(list.FindOne(double(2)) == 2);
			BOOST_CHECK(list.FindOne(double(3)) == 3);
		}

		BOOST_AUTO_TEST_CASE(TEST15)
		{
			auto list = List<double>();

			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(i));
			}

			BOOST_CHECK(list.Size() == DIM);
			BOOST_CHECK(list.Empty() == false);
			BOOST_CHECK(list.FindAll(double(0)) == std::vector<int64_t>{ 0 });
			BOOST_CHECK(list.FindAll(double(1)) == std::vector<int64_t>{ 1 });
			BOOST_CHECK(list.FindAll(double(2)) == std::vector<int64_t>{ 2 });
			BOOST_CHECK(list.FindAll(double(DIM - 1)) == std::vector<int64_t>{ DIM - 1 });
			BOOST_CHECK(list.FindAll(double(DIM)).empty());
		}

		BOOST_AUTO_TEST_CASE(TEST16)
		{
			auto list = List<double>();

			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(0));
			}

			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(1));
			}

			BOOST_CHECK(list.Size() == 2 * DIM);
			BOOST_CHECK(list.Empty() == false);

			std::vector<int64_t> res0;
			for (size_t i = 0; i < DIM; i++)
			{
				res0.push_back(i);
			}
			BOOST_CHECK(list.FindAll(double(0)) == res0);

			std::vector<int64_t> res1;
			for (size_t i = 0; i < DIM; i++)
			{
				res1.push_back(DIM + i);
			}
			BOOST_CHECK(list.FindAll(double(1)) == res1);
			BOOST_CHECK(list.FindAll(double(2)).empty());
			BOOST_CHECK(list.FindAll(double(DIM - 1)).empty());
			BOOST_CHECK(list.FindAll(double(DIM)).empty());

			list.Reverse();
			BOOST_CHECK(list.FindAll(double(0)) == res1);
			BOOST_CHECK(list.FindAll(double(1)) == res0);

			list.Clear();
			BOOST_CHECK(list.FindAll(double(0)).empty());
			BOOST_CHECK(list.FindAll(double(1)).empty());

			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(0));
			}

			for (size_t i = 0; i < DIM; i++)
			{
				list.Insert(static_cast<double>(1));
			}

			BOOST_CHECK(list.Size() == 2 * DIM);
			BOOST_CHECK(list.Empty() == false);
			BOOST_CHECK(list.FindAll(double(0)) == res0);
			BOOST_CHECK(list.FindAll(double(1)) == res1);
		}

		BOOST_AUTO_TEST_CASE(TEST17)
		{
			std::vector<double> values{ 1, 2, 3, 4, 5 };
			List<double> list1(values);
			BOOST_CHECK(list1.Size() == 5);
			list1.EraseAll(values);
			BOOST_CHECK(list1.Empty() == true);
		}

		BOOST_AUTO_TEST_CASE(TEST18)
		{
			std::vector<double> values{ 1, 2, 3, 4, 5 };
			List<double> list1(values);
			List<double> list2(values);
			list2.Insert(6);
			list2.Insert(7);
			list2.Insert(8);
			list1.EraseAll(list2);
			BOOST_CHECK(list1.Empty() == true);
		}

		BOOST_AUTO_TEST_CASE(TEST19)
		{
			List<double> list({1, 2, 3, 4, 5, 6});
			list.EraseAll(list);
			BOOST_CHECK(list.Empty() == true);
		}

	BOOST_AUTO_TEST_SUITE_END()
}
