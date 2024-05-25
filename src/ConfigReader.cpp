#include "ConfigReader.hpp"


ReturnSettingsLine ConfigReader::getContent(
    const std::string &settings_line
){
    std::string name;
    std::string value = ufn::deleteComment(settings_line);
    if(value.size() > 2){
        size_t pos = value.find('=');
        if(pos != std::string::npos){
            name = value.substr(0, pos);
            value.erase(0, pos + 1);
        }
        name = ufn::trim(name);
        value = ufn::trim(value);
    }
    return ReturnSettingsLine(name, value);
}

void ConfigReader::loadConfigFile(std::string settings_path){
    std::ifstream i_file(settings_path);
    std::string line;
    if(i_file.is_open()){
        while (getline(i_file, line)){
            ReturnSettingsLine settingsParam =
                getContent(line);

            if(settingsParam.value_.find(",") != std::string::npos){
                Container::addElement<std::vector<std::string>>(
                    settingsParam.name_,
                    ufn::exploed(settingsParam.value_, ",")
                );
            }else if(settingsParam.value_ == "true"
                || settingsParam.value_ == "false"
            ){
                if(settingsParam.value_ == "true"){
                    Container::addElement<bool>(settingsParam.name_, true);
                }else Container::addElement<bool>(settingsParam.name_, false);
            }else{
                Container::addElement<std::string>(
                    settingsParam.name_,
                    settingsParam.value_
                );
            }
        }
    }else
        throw std::runtime_error(
            "File cannot be opened " + settings_path
        );

    i_file.close();
}
