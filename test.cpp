#include "mvector.h"
#include <gtest/gtest.h>

// TEST(VectorTestCase, VectorPushBack) {

// 	ns::mvector<int> mv(5);
// 	for (int i = 0; i < mv.capacity(); i++) {
// 		mv.push_back(i);
// 	}
// 	EXPECT_EQ(mv.capacity(), 5);
// 	EXPECT_EQ(mv[mv.capacity() - 1], mv.capacity() - 1);
// 	EXPECT_EQ(mv[1], 1);
// }

// TEST(VectorTestCase, VectorInsert) {

// 	ns::mvector<int> mv(5);
// 	for (int i = 0; i < mv.capacity(); i++) {
// 		mv.push_back(i);
// 	}
// 	mv.insert(89, mv.begin());
// 	EXPECT_EQ(mv[0], 89);
// }

TEST(VectorTestCase, Test1) {

	int v[] = {1, 2, 3, 4, 5};
	EXPECT_EQ(v[1], 1);
}

TEST(VectorTestCase, Test2) {

	int v[] = {1, 2, 3, 4, 5};
	EXPECT_EQ(v[1], 2);
}

int main (int argc, char* argv[]){
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
