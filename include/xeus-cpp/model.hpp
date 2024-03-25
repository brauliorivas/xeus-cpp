#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace nl = nlohmann;

namespace xcpp
{
    class model
    {
        protected:
            std::string model_name;
            std::string api_key;

        public:
            model(const std::string& model_name);
            virtual ~model() = default;

            void set_api_key(const std::string& api_key)
            {
                this->api_key = api_key;
            }

            virtual nl::json send_request(const std::string& text) = 0;
    };
}
#endif