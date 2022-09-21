

/*
  Tests entry point 

*/

#include <test.hpp>

int main ( int argc, char **argv)
{
  if (argc != 2) { std::cout << "Usage : " << argv[0] << " <container name>" << std::endl; return 1; }
  char *container = argv[1];
  if (strcmp(container, "all") == 0) {
	// call all container's test suite.
  }
  else if (strcmp(container, "vector" ) == 0) {
	// call vector test suite
  } 
}

