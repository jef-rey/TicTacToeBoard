/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, testToggleTurnX){
  TicTacToeBoard test;
  ASSERT_EQ(test.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, testToggleTurnO){
  TicTacToeBoard test;
  test.toggleTurn();
  ASSERT_EQ(test.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, testPlacePiece){
  TicTacToeBoard test;
  test.placePiece(0,0);
  ASSERT_EQ(test.placePiece(0,0), X);
}

//TEST(TicTacToeBoardTest, placeNotValid){
//  TicTacToeBoard test;
//  test.placePiece(0,0);
//  test.placePiece(0,0);
//  ASSERT_EQ(test.placePiece(0,0), Invalid);
//}

TEST(TicTacToeBoardTest, testGetPiece){
  TicTacToeBoard test;
  test.placePiece(0,0);
  ASSERT_EQ(test.getPiece(0,0), X);
}

TEST(TicTacToeBoardTest, testGetWinner){
  TicTacToeBoard test;
  test.placePiece(0,0); // x
  test.placePiece(1,0); // o
  test.placePiece(1,1); // x
  test.placePiece(0,1); // o
  test.placePiece(2,2); // x <-- win
  ASSERT_EQ(test.getWinner(), X);
  /*
   *        0       1       2
   *  
   *  0     x   |   o    |
   *       --------------------
   *  1     o   |   x    |      
   *       --------------------
   *  2        |       |   x
   *
   *
   */
}
