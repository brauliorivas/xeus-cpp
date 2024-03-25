#include "xcompletions.hpp"

namespace xcpp {
    xcompletions_magic::xcompletions_magic(completions& context)
        : m_context(context)
    {
    }

    void xcompletions_magic::operator()(const std::string& line, const std::string& cell)
    {
        // Implement the completion magic here
        std::cout << "Completion magic called with line: " << line << " and cell: " << cell << std::endl;
        // Setup of completions: 
        // %%ai list -> list available models 
        // %%ai setup <model> -> setup LLM with api key
        // %%ai set <model> -> set the model to be used
        // %%ai <model>
        // <text> -> send request to model and return results

        // right after setting model, code completions should be available in interpreter::complete_request_impl
        // syntax checking: TODO
        // semantic understanding: TBD
    }
}