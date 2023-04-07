#include <iostream>
#include "cpu.h"

void Run() {
  CPU cpu;
  cpu.Initialize("pong.rom");
  bool quit = false;
  while (!quit) {
    cpu.RunCycle();
  }
}

int main(int argc, char** argv) {
  try {
    Run();
  } catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what();
    return 1;
  }
}