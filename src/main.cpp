#include "registry/Conteiner.hpp"
#include "registry/ConfigReader.hpp"

int main(){
    registry::ConfigReader configReader;
    configReader.loadConfigFile("settings_test.conf");

    std::string name_params{"PUBLIC_FILES"};
    auto data = registry::Container::getElement
        <std::vector<std::string>>(name_params);

    for (auto &&i : data){
        std::cout<< i << std::endl;
    }
    if(data.empty()){
        std::cout<< "Is empty" << std::endl;
    }

    return 0;
}
