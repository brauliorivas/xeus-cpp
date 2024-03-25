#ifndef GEMINI_HPP
#define GEMINI_HPP

#include <nlohmann/json.hpp>
#include "xeus-cpp/model.hpp"

namespace nl = nlohmann;

namespace xcpp
{
    class gemini : public model
    {
        gemini(const std::string& model_name);

        nl::json send_request(const std::string& text) override;
    };
}

#endif