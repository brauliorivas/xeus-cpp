/************************************************************************************
 * Copyright (c) 2023, xeus-cpp contributors                                        *
 * Copyright (c) 2023, Johan Mabille, Loic Gouarin, Sylvain Corlay, Wolf Vollprecht *
 *                                                                                  *
 * Distributed under the terms of the BSD 3-Clause License.                         *
  *                                                                                 *
 * The full license is in the file LICENSE, distributed with this software.         *
 ************************************************************************************/


#ifndef XEUS_CPP_INTERPRETER_HPP
#define XEUS_CPP_INTERPRETER_HPP

#include <memory>
#include <streambuf>
#include <string>
#include <vector>

#include <clang/Interpreter/Interpreter.h>

#include <nlohmann/json.hpp>

#include <xeus/xinterpreter.hpp>

#include "xbuffer.hpp"
#include "xeus_cpp_config.hpp"
#include "xmanager.hpp"
#include "completions.hpp"

namespace nl = nlohmann;

namespace xcpp
{
    class XEUS_CPP_API interpreter : public xeus::xinterpreter
    {
    public:

        interpreter(int argc, const char* const* argv);
        virtual ~interpreter();

        void publish_stdout(const std::string&);
        void publish_stderr(const std::string&);

        completions& get_completions();

    private:

        void configure_impl() override;

        nl::json execute_request_impl(
            int execution_counter,
            const std::string& code,
            bool silent,
            bool store_history,
            nl::json user_expressions,
            bool allow_stdin
        ) override;

        nl::json complete_request_impl(const std::string& code, int cursor_pos) override;

        nl::json inspect_request_impl(const std::string& code, int cursor_pos, int detail_level) override;

        nl::json is_complete_request_impl(const std::string& code) override;

        nl::json kernel_info_request_impl() override;

        void shutdown_request_impl() override;

        nl::json get_error_reply(
            const std::string& ename,
            const std::string& evalue,
            const std::vector<std::string>& trace_back
        );

        void redirect_output();
        void restore_output();

        void init_includes();
        void init_preamble();
        void init_magic();

        std::string get_stdopt(int argc, const char* const* argv);

        std::unique_ptr<clang::Interpreter> m_interpreter;

        std::string m_version;

        xmagics_manager xmagics;
        xpreamble_manager preamble_manager;

        std::streambuf* p_cout_strbuf;
        std::streambuf* p_cerr_strbuf;

        xoutput_buffer m_cout_buffer;
        xoutput_buffer m_cerr_buffer;

        completions* m_completions;
    };
}

#endif
