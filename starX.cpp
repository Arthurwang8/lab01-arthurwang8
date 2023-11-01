// starX.cpp

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starX(int width);
void runTests(void);

string starX(int width)
{
  string result = "";
  // check if parameters are valid
  if (width < 3){
    return result; // return without printing anything
    }
  // add the first height-1 rows that are a single star
  // followed by width-1 spaces, then a \n
  for (int co = 0; co < width; co++)
  {
    for (int b1 = 0; b1 <= co; b1++){
    result += " ";
    }
  result += "*";
    for (int b2 = co +1 ; b2 <= (width - co -1); b2++){
    result += " ";
    }
    result += "*";
    for (int b2 = (width - co ) ; b2 < width; b2++){
    result += " ";
    }
    result += "\n";
  }
  
  return result;
}

// Test-Driven Development;
// check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starX3Expected =
      "* *\n"
      " * \n"
      "* *\n";

  assertEquals(starX3Expected, starX(3), "starX(3)");

  string starX5Expected =
      "*   *\n"
      " * * \n"
      "  *  \n"
      " * * \n"
      "*   *\n";

  assertEquals(starX5Expected, starX(5), "starX(5)");

  assertEquals("", starX(0), "starX(0)");
  assertEquals("", starX(2), "starX(2)");
  assertEquals("", starX(4), "starX(4)");
}

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
    ;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

// Main function


int main(int argc, char *argv[])
{
   if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " width height" << endl;
    exit(1);
  }

  int width = stoi(argv[1]);
  
  if (width == -1)
  {
    runTests();
    exit(0);
  }

  cout << starX(width);
  return 0;
}
