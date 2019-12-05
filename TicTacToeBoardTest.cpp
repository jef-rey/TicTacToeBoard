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



TEST(TicTacToeBoardTest, placeNotValid){
  TicTacToeBoard test;
  ASSERT_EQ(test.placePiece(4,6), Invalid);
}

TEST(TicTacToeBoardTest, testGetPiece_blank){
  TicTacToeBoard test;
  ASSERT_EQ(test.getPiece(0,0), Blank);
}
TEST(TicTacToeBoardTest, testGetPieceX){
  TicTacToeBoard test;
  test.placePiece(0,0);
  ASSERT_EQ(test.getPiece(0,0), X);
}

TEST(TicTacToeBoardTest, testGetPieceO){
  TicTacToeBoard test;
  test.placePiece(0,0);
  test.placePiece(0,1);
  ASSERT_EQ(test.getPiece(0,1), O);
}

TEST(TicTacToeBoardTest, testGetPiece_invalid){
  TicTacToeBoard test;
  test.placePiece(0,0);
  test.placePiece(0,1);
  ASSERT_EQ(test.getPiece(4,1), Invalid );
}

TEST(TicTacToeBoardTest, testGetWinnerX_diag){
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


TEST(TicTacToeBoardTest, testGetWinnerX_col){
  TicTacToeBoard test;
  test.placePiece(1,0); // x
  test.placePiece(2,1); // o
  test.placePiece(2,0); // x
  test.placePiece(2,2); // o
  test.placePiece(0,0); // x <-- win
  ASSERT_EQ(test.getWinner(), X);
  /*
   *        0       1       2
   *  
   *  0     x   |   o    |
   *       --------------------
   *  1     x   |   o    |      
   *       --------------------
   *  2     x   |        |   
   *
   *
   */
}


TEST(TicTacToeBoardTest, testGetWinnerX_row){
  TicTacToeBoard test;
  test.placePiece(0,0); // x
  test.placePiece(2,0); // o
  test.placePiece(0,1); // x
  test.placePiece(2,2); // o
  test.placePiece(0,2); // x <-- win
  ASSERT_EQ(test.getWinner(), X);
  /*
   *        0       1       2
   *  
   *  0     x   |   x    |  x
   *       --------------------
   *  1         |        |      
   *       --------------------
   *  2     o   |        |  o
   *
   *
   */
}

TEST(TicTacToeBoardTest, testGetWinner_invalid){
  TicTacToeBoard test;
  test.placePiece(0,0); // x
  test.placePiece(1,1); // o
  test.placePiece(0,2); // x
  test.placePiece(2,0); // o
  test.placePiece(1,0); // x 
  test.placePiece(1,2); // o
  test.placePiece(2,2); // x
  test.placePiece(0,1); // o
  ASSERT_EQ(test.getWinner(), Invalid);
  /*
   *        0       1       2
   *  
   *  0     x   |   o    |  x
   *       --------------------
   *  1     x   |   o    |  o   
   *       --------------------
   *  2     o   |        |  x 
   *
   *
   */
}


TEST(TicTacToeBoardTest, testGetWinner_draw){
  TicTacToeBoard test;
  test.placePiece(0,0); // x
  test.placePiece(1,1); // o
  test.placePiece(2,2); // x
  test.placePiece(0,2); // o
  test.placePiece(2,0); // x 
  test.placePiece(2,1); // o
  test.placePiece(0,1); // x
  test.placePiece(1,0); // o
  test.placePiece(1,2); // x
  ASSERT_EQ(test.getWinner(), Blank);
}


