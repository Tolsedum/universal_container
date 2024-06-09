#include "registry/Conteiner.hpp"
#include "registry/ConfigReader.hpp"

int main(){
    registry::ConfigReader configReader;
    configReader.loadConfigFile("settings_test.conf");

    std::string name_params{"MIME_TYPES"};
    auto data = registry::Container::getElement
        <std::map<std::string, std::vector<std::string>>>(name_params);

    for (auto &&i : data){
        std::cout<< i.first << ": " << std::endl;
        for (auto &&y : i.second){
            std::cout<< "  " << y << std::endl;
        }
    }
    if(data.empty()){
        std::cout<< "Is empty" << std::endl;
    }

    return 0;
}
