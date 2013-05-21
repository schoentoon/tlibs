#include "debug.h"

int main(int argc, char** argv) {
  debug = 5;
  DEBUG(0, "Debug level is set at %d.", debug);
  DEBUG(1, "This is debug level 1.");
  DEBUG(5, "This is debug level 5.");
  DEBUG(255, "This is debug level 255.");
  return 0;
};
