#include "cmdline.h"

const char* CmdLine::DEF_PREFIX = "$$ ";
const char* CmdLine::ML_PREFIX = ">> ";
const char* CmdLine::CURR_PREFIX = CmdLine::DEF_PREFIX;
const long long int CmdLine::MAX_CMD_LENGTH = 1 << 8;


CmdLine::CmdLine() {}

const char* CmdLine::HandleInput() const {
    // Clear buffer
    memset(m_Cmd, 0, CmdLine::MAX_CMD_LENGTH);

    std::cout << CmdLine::CURR_PREFIX;
    
    std::cin.getline(m_Cmd, CmdLine::MAX_CMD_LENGTH);

    return m_Cmd;
}