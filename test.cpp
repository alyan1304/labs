#include "pch.h"
#include "..\calculator\myStack.h"


class StackTest : public testing::Test {
protected:
	void SetUp() override {
		doubleStack1 << 3.14;
		charStack1 << 'a';
	}
	Stack<double> doubleStack1;
	Stack<double> doubleStack2;
	Stack<char> charStack1;
	Stack<char> charStack2;
};


TEST_F(StackTest, isEmpty) {
	EXPECT_EQ(doubleStack1.isEmpty(), false);
	EXPECT_EQ(doubleStack2.isEmpty(), true);
	EXPECT_EQ(charStack1.isEmpty(), false);
	EXPECT_EQ(charStack2.isEmpty(), true);
}

TEST_F(StackTest, Push) {
	doubleStack2 << 1.23 << 4.56;
	EXPECT_EQ(doubleStack2.isEmpty(), false);
	EXPECT_EQ(doubleStack2[1], 4.56);

	charStack2 << 'b' << 'c';
	EXPECT_EQ(charStack2.isEmpty(), false);
	EXPECT_EQ(charStack2[2], 'c');
}

TEST_F(StackTest, Pop) {
	double value;
	char character;

	EXPECT_THROW(doubleStack2 >> value, std::out_of_range);
	doubleStack1 >> value;
	EXPECT_EQ(value, 3.14);
	EXPECT_EQ(doubleStack1.isEmpty(), true);

	EXPECT_THROW(charStack2 >> character, std::out_of_range);
	charStack1 >> character;
	EXPECT_EQ(character, 'a');
	EXPECT_EQ(charStack1.isEmpty(), true);
}



TEST_F(StackTest, Assignment) {
	doubleStack2 = doubleStack1;
	EXPECT_EQ(doubleStack2[1], 3.14);

	charStack2 = charStack1;
	EXPECT_EQ(charStack2[1], 'a');
}

TEST_F(StackTest, Index) {
	EXPECT_EQ(doubleStack1[1], 3.14);
	EXPECT_THROW(doubleStack1[2], std::out_of_range);

	EXPECT_EQ(charStack1[1], 'a');
	EXPECT_THROW(charStack1[2], std::out_of_range);
}


TEST_F(StackTest, LessThanOperator) {
	EXPECT_EQ(doubleStack1 < doubleStack2, false);
	doubleStack2 << 1.23;
	EXPECT_EQ(doubleStack1 < doubleStack2, false);
	EXPECT_EQ(doubleStack2 < doubleStack1, true);

	EXPECT_EQ(charStack1 < charStack2, false);
	charStack2 << 'b';
	EXPECT_EQ(charStack1 < charStack2, true);
}


TEST_F(StackTest, EqualOperator) {
	Stack<double> doubleStack3 = doubleStack1;
	Stack<char> charStack3 = charStack1;

	EXPECT_EQ(doubleStack1 == doubleStack3, true);
	EXPECT_EQ(charStack1 == charStack3, true);

	doubleStack1 << 2.71;
	EXPECT_EQ(doubleStack1 == doubleStack3, false);

	charStack1 << 'z';
	EXPECT_EQ(charStack1 == charStack3, false);
}

