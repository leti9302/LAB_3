#include "CppUnitTest.h"
#include "../Lab_3/BST.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		BST* bst;
		// before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			bst = new BST();
		}
		// after each test
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete bst;
		}

		TEST_METHOD(contains_test)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(1);
			bst->insert(6);
			bst->insert(7);
			bst->insert(10);
			bst->insert(14);
			Assert::IsTrue(bst->contains(7));
		}

		TEST_METHOD(contains_test_2)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(1);
			bst->insert(6);
			bst->insert(7);
			bst->insert(10);
			bst->insert(14);
			Assert::IsTrue(bst->contains(14));
		}

		TEST_METHOD(contains_test_3)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(1);
			bst->insert(6);
			bst->insert(7);
			bst->insert(10);
			bst->insert(14);
			bst->insert(11);
			bst->insert(12);
			bst->insert(10);
			Assert::IsTrue(bst->contains(12));
		}

		TEST_METHOD(contains_test_no_element)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(1);
			Assert::IsFalse(bst->contains(10));
		}

		TEST_METHOD(insert_test)
		{
			bst->insert(10);
			bst->insert(5);
			bst->insert(11);
			Assert::IsTrue(bst->contains(11));
		}

		TEST_METHOD(insert_test_2)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(4);
			bst->insert(5);
			bst->insert(7);
			Assert::IsTrue(bst->contains(7));
		}

		TEST_METHOD(insert_test_3)
		{
			bst->insert(2);
			bst->insert(1);
			bst->insert(2);
			bst->insert(5);
			bst->insert(7);
			Assert::IsTrue(bst->contains(7));
		}

		TEST_METHOD(remove_test)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(1);
			bst->insert(6);
			bst->insert(7);
			bst->insert(10);
			bst->insert(14);
			bst->insert(11);
			bst->insert(12);
			bst->remove(11);
			Assert::IsTrue(bst->contains(12));
		}

		TEST_METHOD(remove_test_2)
		{
			bst->insert(8);
			bst->insert(6);
			bst->insert(7);
			bst->insert(10);
			bst->insert(18);
			bst->remove(6);
			Assert::IsFalse(bst->contains(6));
		}

		TEST_METHOD(remove_test_3)
		{
			bst->insert(8);
			bst->remove(8);
			Assert::IsFalse(bst->contains(8));
		}

		TEST_METHOD(remove_test_no_element)
		{
			try {
				bst->insert(8);
				bst->insert(3);
				bst->insert(1);
				bst->remove(11);
			}
			catch (char* e) {
				Assert::AreEqual("There is no such element!:", e);
			}
		}

		TEST_METHOD(remove_test_empty_BST)
		{
			try {
				bst->remove(11);
			}
			catch (char* e) {
				Assert::AreEqual("Tree is empty!", e);
			}
		}

		TEST_METHOD(dftIterator_test)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(1);
			bst->insert(10);
			bst->insert(14);
			bst->insert(13);
			bst->insert(6);
			bst->insert(4);
			bst->insert(7);
			int i = 0;
			int array[] = { 8, 3, 1, 6, 4, 7, 10, 14, 13 };
			Iterator* dft_iterator = bst->create_dft_iterator();
			while (dft_iterator->has_next()) {
				Assert::AreEqual(dft_iterator->next(), array[i]);
				i++;
			}
		}

		TEST_METHOD(bftIterator_test)
		{
			bst->insert(8);
			bst->insert(3);
			bst->insert(1);
			bst->insert(10);
			bst->insert(14);
			bst->insert(13);
			bst->insert(6);
			bst->insert(4);
			bst->insert(7);
			int i = 0;
			int array[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
			Iterator* bft_iterator = bst->create_bft_iterator();
			while (bft_iterator->has_next()) {
				Assert::AreEqual(bft_iterator->next(), array[i]);
				i++;
			}
		}
	};
}