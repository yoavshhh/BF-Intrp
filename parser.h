#pragma once

#include <iostream>
#include <string>

#include "operation.h"

class Parser
{
public:
    static bool m_ShouldParse;

    Parser();

    void SetString(const std::string& str);

    Operation* Parse();

private:

    void m_Rec_Parse(size_t& ind, Operation* &op);

    std::string m_Cmd;
};