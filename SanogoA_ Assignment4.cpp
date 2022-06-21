 /************************************************************************
*  Assignment    : 4                                                     *
*  Name          : Anthony Sanogo                                        *
*  Student ID    : 002-27-9811                                           *
*  Date          : 2020-11-24                                            *
*  Program that simulates the behavior of a population of living cells   *
*  that evolves from one generation to the next given a set of criteria. *
************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Global constants
const int MAXGEN = 5; // maximum no. of generations
const int n = 10; // no. of rows
const int m = 10;// no. of colums

void initialize(char grid[10][10]) { // initialize the nxm population

  int input = 0;
  for (int i = 0; i < n; i++) {

    cout << "Enter one after the other ( 0 for dead and 1 for live) for each cell of row number " << (i + 1) << "." << endl;

    for (int j = 0; j < m; j++) {
      cin >> input;

      //puts x if alive and empty space if dead
      if (input == 0) {
        grid[i][j] = ' ';
      } else if (input == 1) {
        grid[i][j] = 'x';
      }

    }

  }

}

void initialize2(char grid[10][10], int density) { // initialize given a density
  srand((unsigned) time(0));
  int random;
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < m; j++) {

      random = (rand() % 100) + 1;//generate random number from 1 to 100
      //put x or empty space depending on random number and density
      if (random <= density) {
        grid[i][j] = 'x';
      } else {
        grid[i][j] = ' ';
      }

    }
  }
}
int countNeighbours(char grid[10][10], int x, int y) { // counts live neighbours of cell x,y

  int neighbours = 0;
  int xleft, xright, yabove, ybellow;

  //checks index to the left
  if (x == 0)
    xleft = n - 1;
  else
    xleft = x - 1;

  //checks index to the right
  if (x == (n - 1))
    xright = 0;
  else
    xright = x + 1;


  //checks index above
  if (y == 0)
    yabove = m - 1;
  else
    yabove = y - 1;

  //checks index bellow
  if (y == (m - 1))
    ybellow = 0;
  else
    ybellow = y + 1;

//checks all the neighbours(eight)
  if (grid[xleft][ybellow] == 'x')
    ++neighbours;
  if (grid[x][ybellow] == 'x')
    ++neighbours;
  if (grid[xleft][y] == 'x')
    ++neighbours;
  if (grid[xleft][yabove] == 'x')
    ++neighbours;
  if (grid[xright][ybellow] == 'x')
    ++neighbours;
  if (grid[xright][y] == 'x')
    ++neighbours;
  if (grid[x][yabove] == 'x')
    ++neighbours;
  if (grid[xright][yabove] == 'x')
    ++neighbours;

  return neighbours;

}

void print(char grid[10][10]) { // prints a population
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }

}

bool allDead(char grid[10][10]) { // checks if the population is dead
  bool dead;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      //checks if index is dead or alive
      if (grid[i][j] == 'x') {
        return false;

      }
    }

  }
  return true;
}

void reproduce(char grid[10][10]) { // produce the next generation
  int neighbours = 0;
  char nextGen[10][10];//next generation board

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {

      //count neighbours at index
      neighbours = countNeighbours(grid, i, j);

      //checks if index will survive next generation
      if (neighbours < 2)
        nextGen[i][j] = ' ';
      else if (neighbours > 3)
        nextGen[i][j] = ' ';
      else if (neighbours == 3)
        nextGen[i][j] = 'x';
      else if (grid[i][j] == 'x' && neighbours == 2)
        nextGen[i][j] = 'x';
      else
        nextGen[i][j] = ' ';

    }

  }
//copy back next generation in the original array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      grid[i][j] = nextGen[i][j];
    }

  }

}

int main() {
  char grid[n][m];
  initialize(grid); // you should call either initialize, or initialize2
  cout << "Initial population = \n";
  print(grid);
  int gen = 1;
  while (gen <= MAXGEN && !allDead(grid)) {
    cout << "gen = " << gen << endl;
    reproduce(grid); // will call the function countNeighbours for each cell
    print(grid);
    gen++;
  }
}
