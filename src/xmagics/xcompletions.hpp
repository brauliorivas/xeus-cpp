#ifndef XCOMPLETIONS_MAGIC_HPP
#define XCOMPLETIONS_MAGIC_HPP

#include "xeus-cpp/xmagics.hpp"
#include "xeus-cpp/xutils.hpp"
#include "xeus-cpp/completions.hpp"
#include <string>

namespace xcpp {

    class xcompletions_magic : public xmagic_cell
    {
        public:
            xcompletions_magic(completions& context);

            virtual ~xcompletions_magic() = default;
            virtual void operator()(const std::string& line, const std::string& cell) override;

        private:
            completions m_context;
    };

}

#endif