#include "Conteiner.hpp"
#include "ConfigReader.hpp"

int main(){
    ConfigReader configReader;
    configReader.loadConfigFile("settings_test.conf");
    std::string name_params{"TEST"};
    std::cout<< name_params  << ": "<< Container::getElement<std::string>(name_params) <<std::endl;
    std::cout << "Hello world!" << std::endl;
}
