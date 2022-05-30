#pragma once

#include <string.h>

#include <iostream>
#include <string>

class CmdLine
{
public:
    const static char* CURR_PREFIX; // Current
    const static char* DEF_PREFIX;  // Default
    const static char* ML_PREFIX;   // Multiliners
    const static long long int MAX_CMD_LENGTH;

    CmdLine();

    const char* HandleInput() const;

private:

    char* m_Cmd = new char[CmdLine::MAX_CMD_LENGTH];
};