#include "application.h"

Application::Application() {}
Application::~Application() {}

void Application::Init()
{
    std::cout << "Welcome to my Brainf*ck Interpeter!" << '\n'
            << "(written in cpp by Yoav Shifman, all rights reserved)" << '\n';
}

std::string strip(const std::string &inpt)
{
    auto start_it = inpt.begin();
    auto end_it = inpt.rbegin();
    while (std::isspace(*start_it))
        ++start_it;
    while (std::isspace(*end_it))
        ++end_it;
    return std::string(start_it, end_it.base());
}

void Application::Mainloop()
{
    std::string last = "";
    while(1)
    { // MAIN LOOP

        std::string inp = last + strip(m_CmdLine.HandleInput());

        if (inp.back() == '\\' || !Parser::m_ShouldParse) {
            // *true* : inp was relatively empty - start parsing
            // *false* : additional data inserted - don't parse yet
            Parser::m_ShouldParse = last == inp;
            last = inp;
            CmdLine::CURR_PREFIX = CmdLine::ML_PREFIX;
            continue;
        }
        last = "";
        Parser::m_ShouldParse = true;
        CmdLine::CURR_PREFIX = CmdLine::DEF_PREFIX;

        m_Parser.SetString(inp);

        Operation* op = m_Parser.Parse();

        m_Brainfuck.ApplyAll(op);
        std::cout << '\n';
        
        m_Brainfuck.Reset();
        

        delete op;

    } // END MAIN LOOP
}

void Application::Destory() {}