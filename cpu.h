#ifndef CPU_H
#define CPU_H

#include <string>

class CPU
{
private:
    uint8_t memory_[4096];
    uint8_t v_reg_[16];

    uint16_t opt_code_;

    uint16_t index_reg_;

    uint16_t program_counter_;

    uint8_t delay_;
    uint8_t timer_;

    uint16_t stack_[16];
    uint8_t stack_pointer_;

public:
    void Initialize(std::string rom);
    void RunCycle();
};

#endif