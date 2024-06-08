#include "registry/Conteiner.hpp"
#include "registry/ConfigReader.hpp"

int main(){
    registry::ConfigReader configReader;
    configReader.loadConfigFile("settings_test.conf");

    std::string name_params{"PORT"};
    std::cout
        << name_params  << ": "<< registry::Container::getElement<std::string>(name_params)
        << std::endl
        << name_params  << ": "<< registry::Container::getElement<int>(name_params)
        << std::endl;



    // std::cout
    //     << "strToFloat: " << ufn::strToInt(test)
    //     << std::endl
    //     << " Error: " << ufn::has_error_in_converter_function << " " << ufn::error_in_converter_function
    //     << std::endl
    //     << " Size: " << sizeof(ufn::strToFloat(test))
    // << std::endl;
    return 0;
}
