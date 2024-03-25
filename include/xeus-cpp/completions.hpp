#ifndef COMPLETIONS_HPP
#define COMPLETIONS_HPP

#include <nlohmann/json.hpp>
#include "model.hpp"

namespace nl = nlohmann;

namespace xcpp
{
    class completions
    {
        public:
            completions();

            void set_model(model* model);

            nl::json complete(const std::string& code);

            nl::json generate_code(const std::string& code);
            

        private:
            model* m_model;
    };
}

#endif