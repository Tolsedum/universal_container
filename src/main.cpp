#include "registry/Conteiner.hpp"
#include "registry/ConfigReader.hpp"

int main(){
    registry::ConfigReader configReader;
    configReader.loadConfigFile("settings_test.conf");
    std::string name_params{"TEST"};
    std::cout<< name_params  << ": "<< registry::Container::getElement<std::string>(name_params) <<std::endl;
    std::cout << "Hello world!" << std::endl;
}
