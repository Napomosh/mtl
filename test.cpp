#include "mvector.h"

TEST(PalTestCase, PalindromTrueTest) {

  EXPECT_EQ(is_palindrom("112211"), true);
}

TEST(PalTestCase, PalindromFalseTest) {

	EXPECT_EQ(is_palindrom("1122121"), false);
}

TEST(VectorTestCase, VectorPushBack) {

	ns::mvector<int> mv(5);
	for (int i = 0; i < mv.capacity(); i++) {
		mv.push_back(i);
	}
	EXPECT_EQ(mv.capacity(), 5);
	EXPECT_EQ(mv[mv.capacity() - 1], mv.capacity() - 1);
	EXPECT_EQ(mv[1], 1);
}

TEST(VectorTestCase, VectorInsert) {

	ns::mvector<int> mv(5);
	for (int i = 0; i < mv.capacity(); i++) {
		mv.push_back(i);
	}
	mv.insert(89, mv.begin());
	EXPECT_EQ(mv[0], 89);
}

TEST(SmokeTestCase, SmokeTest) {

	EXPECT_EQ(is_palindrom("1122121"), false);
}

int main (int argc, char* argv[]){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
