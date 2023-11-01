// starC.cpp
// A demonstration of ASCII Art printing C characters

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starC(int width, int height);
void runTests(void);

// Write starC per specifictions in the lab writeup

string starC(int width, int height)
{
   string result = "";
  // check if parameters are valid
  if (height <=2 || width <= 2 ){
    return result; // return without printing anything
    }
  // add the first height-1 rows that are a single star
  // followed by width-1 spaces, then a \n
  for (int co = 0; co < width; co++)
  {
  result += "*";
    
  }
  result += "\n";

  // add the final row of width stars
  for (int row = 1; row < height-1; row++)
  {
    
    result += "*";
   for (int co = 1; co < width; co++){
   result += " ";
   }
    result += "\n";
  }
  for (int co = 0; co < width; co++)
  {
  result += "*";
    
  }
  result += "\n";
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starC34Expected =
      "***\n"
      "*  \n"
      "*  \n"
      "***\n";

  assertEquals(starC34Expected, starC(3, 4), "starC(3,4)");

  string starC53Expected =
      "*****\n"
      "*    \n"
      "*****\n";

  assertEquals(starC53Expected, starC(5, 3), "starC(5,3)");

  assertEquals("", starC(2, 1), "starC(2,1)");
  assertEquals("", starC(2, 2), "starC(2,2)");

  string starC23Expected =
      "**\n"
      "* \n"
      "**\n";

  assertEquals(starC23Expected, starC(2, 3), "starC(2,3)");
}

// Test harness
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

  if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " width height" << endl;
    exit(1);
  }

  int width = stoi(argv[1]);
  int height = stoi(argv[2]);
  // If the program is executed with parameters -1 -1 unit test
  // the starL() function using our automated test framework
  if (width == -1 && height == -1)
  {
    runTests();
    exit(0);
  }

  cout << starC(width, height);
  return 0;
}
