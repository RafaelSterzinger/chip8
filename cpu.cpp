#include "cpu.h"
#include <fstream>
#include <iostream>

void CPU::Initialize(std::string rom)
{
    program_counter_ = 0x200;
    opt_code_ = 0;
    index_reg_ = 0;
    stack_pointer_ = 0;

    std::ifstream file;
    file.open(rom, std::ios::binary);

    char byte;
    u_int16_t offset = 0;

    if (file.is_open())
    {
        while (file.get(byte))
        {
            memory_[0x200 + offset++] = byte;
        }
    }
    else
    {
        throw std::runtime_error("file not found");
    }

    file.close();
}

void CPU::RunCycle()
{
    opt_code_ = memory_[program_counter_] << 8 | memory_[program_counter_ + 1];
    std::cout << std::hex << static_cast<unsigned>(opt_code_ & 0xF000) << "\n";

    switch (opt_code_ & 0xF000)
    {
    case 0x6000:
        std::cout << "success!!!\n";
        break;
    
    default:
        throw std::runtime_error("unknown instruction");
    }
    program_counter_ +=2;
}