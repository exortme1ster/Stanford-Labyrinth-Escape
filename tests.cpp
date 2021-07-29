#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"



TEST(grid, defaultConstructor){
    
Grid<int> g;


ASSERT_EQ(g.numrows(), 4);
    
}

TEST(grid, defaultConstructor1){
    
Grid<double> g;


ASSERT_EQ(g.numrows(), 4.0);
    
}

TEST(grid, parameterizedConstructor1){
    
Grid<int> g(100,100);


ASSERT_EQ(g.numrows(), 100);
    
}

TEST(grid, parameterizedConstructorDouble){
    
Grid<double> g(100.0,100.0);


ASSERT_EQ(g.numrows(), 100.0);
    
}

TEST(grid, parameterizedConstructor2){
    
Grid<int> g(500,500);


ASSERT_EQ(g.numrows(), 500);
    
}

TEST(grid, parameterizedConstructor3){
    
Grid<int> g(1000,1000);


ASSERT_EQ(g.numrows(), 1000);
    
}

TEST(grid, equalityoperator1){
    Grid<int> g;
    
    Grid<int> g1(100,100);
    
    g = g1;
    
    ASSERT_EQ(g.numrows(), 100);
}

TEST(grid, equalityoperator2){
    Grid<int> g;
    
    Grid<int> g1(100,100);
        Grid<int> g2(500,500);
            Grid<int> g3(2000,2000);
            
    
    g = g1;
    ASSERT_EQ(g.numrows(), 100);
    g = g2;
    ASSERT_EQ(g.numrows(), 500);
    g = g3;
    ASSERT_EQ(g.numrows(), 2000);
}

TEST(grid, referencetotheelement) {
    Grid<int> g(100,100);
    
    g(50,45) = 40;
    g(50,46) = 41;
    g(50,47) = 42;
    g(50,48) = 43;
    g(50,49) = 44;
    g(50,50) = 45;
    
    
    ASSERT_EQ(g(50,45), 40);
    ASSERT_EQ(g(50,46), 41);
    ASSERT_EQ(g(50,47), 42);
    ASSERT_EQ(g(50,48), 43);
    ASSERT_EQ(g(50,49), 44);
    ASSERT_EQ(g(50,50), 45);
}

TEST(grid, size)
{
    Grid<int> g(100,100);
    
    ASSERT_EQ(g.size(), 10000);
}

TEST(grid, size1)
{
    Grid<int> g(400,400);
    
    Grid<int> g1(100,100);
    
    ASSERT_EQ(g.size(), 160000);
    
    g = g1;
    
    ASSERT_EQ(g.size(), 10000);
    
    ASSERT_NE(g.size(), 16000);
}

TEST(grid, numrows){
    
    Grid<int> g1(100,100);

    
    ASSERT_EQ(g1.numrows(), 100);
}

TEST(grid, numcols){
    
    Grid<int> g1(100,100);

    
    ASSERT_EQ(g1.numcols(1), 100);
    ASSERT_NE(g1.numcols(15), 99);
}

TEST(EscapeTheLabyrinth, checkWord){
    string check = "SWSENEESNNWN";
    string check1 = "SWSENEESNNWN23131";
    string check2 = "SWSENEESNNWN$#2@";
    
     EXPECT_TRUE(checkWord(check));
          EXPECT_FALSE(checkWord(check1));
               EXPECT_FALSE(checkWord(check2));
}



// Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);

    MazeCell* start = m.getStart(2, 2);
//
//    /* These paths are the ones in the handout. They all work. */
    EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
    EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
    EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));
//
//    /* These paths don't work, since they don't pick up all items. */
    EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

//    /* These paths don't work, since they aren't legal paths. */
    EXPECT_FALSE(isPathToFreedom(start, "WW"));
    EXPECT_FALSE(isPathToFreedom(start, "NN"));
    EXPECT_FALSE(isPathToFreedom(start, "EE"));
    EXPECT_FALSE(isPathToFreedom(start, "SS"));
}
//
//// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
    vector<string> textMaze;

    textMaze.push_back("* S *");
    textMaze.push_back("     ");
    textMaze.push_back("W * P");
    textMaze.push_back( "     ");
    textMaze.push_back( "* * *");

    Maze m(textMaze);

    MazeCell* start = m.getStart(1, 1);

    EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
    EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
    EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
    EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}
//
//// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
    vector<string> textMaze;

    textMaze.push_back("P-S-W");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    EXPECT_TRUE(isPathToFreedom(start, "EE"));
   
    start = m.getStart(0, 1);
    EXPECT_TRUE(isPathToFreedom(start, "WEE"));
    
    start = m.getStart(0, 2);
    EXPECT_TRUE(isPathToFreedom(start, "WW"));

}
//
//// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    /* These paths contain characters that aren't even close to permissible. */
    EXPECT_FALSE(isPathToFreedom(start, "Q"));
    EXPECT_FALSE(isPathToFreedom(start, "X"));
    EXPECT_FALSE(isPathToFreedom(start, "!"));
    EXPECT_FALSE(isPathToFreedom(start, "?"));

    EXPECT_FALSE(isPathToFreedom(start, "n"));
    EXPECT_FALSE(isPathToFreedom(start, "s"));
    EXPECT_FALSE(isPathToFreedom(start, "e"));
    EXPECT_FALSE(isPathToFreedom(start, "w"));

//     ///* These are tricky - they're legal paths that happen to have an unexpected
//     // * character at the end.
   
    start = m.getStart(2, 2);
    EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

 }
 

//
//// Provided Test: This tests your personalized regular maze to see if you were
//// able to escape.
TEST(maze, escapeRegularMaze) {
    Maze m(4, 4);
    MazeCell* start = m.mazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}
//
//// Provided Test: This tests your personalized twisty maze to see if you were
//// able to escape.
TEST(maze, escapeTwistyMaze) {
    Maze m(4, 4);
    MazeCell* start = m.twistyMazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}

