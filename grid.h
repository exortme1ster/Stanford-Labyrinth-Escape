// Grid.h file
// Used to create mazes

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct ROW {
    T*  Cols;     // array of column elements
    size_t NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // array of ROWs
  size_t  NumRows;  // total # of rows (0..NumRows-1)
public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 Grid.  All
  // elements are initialized to the default value of T.
  //
  Grid() {
    Rows = new ROW[4];  // 4 rows
    NumRows = 4;
    // initialize each row to have 4 columns:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r].Cols = new T[4];
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (size_t c = 0; c < Rows[r].NumCols; ++c) {
        Rows[r].Cols[c] = T();  // default value for type T:
      }
    }
  }
  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a Grid with R rows,
  // where each row has C columns. All elements are initialized to 
  // the default value of T.
  //
  Grid(size_t R, size_t C) {
      Rows = new ROW[R];
      NumRows = R;  // R rows
      // initialize each row to have R columns:
      for (size_t r = 0; r < NumRows; ++r) {
          Rows[r].Cols = new T[C];
          Rows[r].NumCols = C;
        // initialize the elements to their default value:
          for (size_t c = 0; c < Rows[r].NumCols; ++c) {
              Rows[r].Cols[c] = T();
          }
      }
      
  }
  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated by the vector.
  //
  virtual ~Grid() {
     for(size_t i = 0; i < NumRows; i++)
     {
         delete[] Rows[i].Cols;
        //  cout << "Column deleted!" << endl;
     }
     
     delete[] Rows;
    //  cout << "Rows deleted!" << endl;
  }


  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {
      this->Rows = new ROW[other.NumRows];
      this->NumRows = other.NumRows;
      
      for (size_t r = 0; r < NumRows; r++)
      {
          this->Rows[r].Cols = new T[other.Rows[r].NumCols];
          this->Rows[r].NumCols = other.Rows[r].NumCols; 
      
      
            for (size_t c = 0; c < other.Rows[r].NumCols; ++c) {
              this->Rows[r].Cols[c] = other.Rows[r].Cols[c];
          }
      }
  }
  //
  // copy operator=
  //
  // Called when you assign one vector into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
      if (this == &other)
      return *this;

        for (size_t i = 0; i < NumRows; i++)
     {
         delete[] Rows[i].Cols;
     }
     delete[] Rows;
      this->Rows = new ROW[other.NumRows];
      this->NumRows = other.NumRows;
      
      for (size_t r = 0; r < NumRows; r++)
      {
          this->Rows[r].Cols = new T[other.Rows[r].NumCols];
          this->Rows[r].NumCols = other.Rows[r].NumCols; 
      
      
            for (size_t c = 0; c < other.Rows[r].NumCols; ++c) {
              this->Rows[r].Cols[c] = other.Rows[r].Cols[c];
          }
      }
      return *this; 
  }
  //
  // numrows
  //
  // Returns the # of rows in the Grid.  The indices for these rows
  // are 0..numrows-1.
  //
  size_t numrows() const {
    return NumRows; 
  }
  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  For now, each row will have the same number of columns.
  //
  size_t numcols(size_t r) const {
      if (r >= 0 && r < NumRows) {
      return Rows[r].NumCols;
      } else {
         throw out_of_range("out_of_range");
      }
  }
  //
  // size
  //
  // Returns the total # of elements in the grid.
  //
  size_t size() const {
    int counter = 0;
    for (size_t r = 0; r < NumRows; r++) {
        counter = counter + Rows[r].NumCols;
    }
    return counter;
  }
  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) {
    if ((r >= 0 && r < NumRows) && (c >= 0 && c < Rows[r].NumCols)) {
    return Rows[r].Cols[c];
    } else {
        throw out_of_range("out_of_range");
    }
  }
  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  This is not
  // tested.
  //
  void _output() {
          for (size_t r = 0; r < NumRows; ++r) {
          for (size_t c = 0; c < Rows[r].NumCols; ++c) {
              cout <<  Rows[r].Cols[c] << " ";
          }
      
  }
  }
};
