#include "registry/ConfigReader.hpp"


registry::ReturnSettingsLine registry::ConfigReader::getContent(
    const std::string &settings_line
){
    std::string name;
    std::string value = settings_line;
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

void registry::ConfigReader::initAtIntager(
    std::string name, std::string value
){
    int int_type = ufn::strToInt(value);
    if(ufn::has_error_in_converter_function == 2){
        long long_type = ufn::strToLong(value);
        if(ufn::has_error_in_converter_function == 2){
            long long llong_type = ufn::strToLongLong(value);
            if(ufn::has_error_in_converter_function == 2){
                unsigned long ul_type = ufn::strToUnsignedLong(value);
                if(ufn::has_error_in_converter_function == 2){
                    unsigned long long ull_type = ufn::strToUnsignedLongLong(value);
                    if(ufn::has_error_in_converter_function == 2){
                        registry::Container::addElement<std::string>(name, value);
                    }else{
                        registry::Container::addElement<unsigned long long>(name, ull_type);
                    }
                }else{
                    registry::Container::addElement<unsigned long>(name, ul_type);
                }
            }else{
                registry::Container::addElement<long long>(name, llong_type);
            }
        }else{
            registry::Container::addElement<long>(name, long_type);
        }
    }else{
        registry::Container::addElement<int>(name, int_type);
    }
}

void registry::ConfigReader::initAtFractional(
    std::string name, std::string value
){
    float float_type = ufn::strToFloat(value);
    if(ufn::has_error_in_converter_function == 2){
        double double_type = ufn::strToDouble(value);
        if(ufn::has_error_in_converter_function == 2){
            long double long_double_type = ufn::strToLongDouble(value);
            if(ufn::has_error_in_converter_function == 2){
                registry::Container::addElement<std::string>(name, value);
            }else{
                registry::Container::addElement<long double>(name, long_double_type );
            }
        }else{
            registry::Container::addElement<double>(name, double_type);
        }
    }else{
        registry::Container::addElement<float>(name, float_type);
    }
}

void registry::ConfigReader::initAtMapContainer(
    std::string name, std::string value
){
    if(value.empty() || name.empty()){
        return;
    }
    std::map<std::string, std::vector<std::string>> content;
    std::string elem_name, v;
    std::vector<std::string> elem_valu;
    bool set_value = false;
    for (auto &&c : value){
        if(c == ':'){
            set_value = true;
            continue;
        }else if(c == '[' || c == ']'){
            if(c == ']'){
                if(!v.empty()){
                    elem_valu.push_back(v);
                    v.clear();
                }
                content.insert(
                    std::pair<std::string, std::vector<std::string>>
                    {elem_name, elem_valu}
                );
                elem_name.clear();
                elem_valu.clear();
                set_value = false;
            }
            continue;
        }
        if(!ufn::inArray
            <std::vector<char>, char>({'\n', '\r', ' '}, c)
        ){
            if(set_value){
                if(c == ','){
                    elem_valu.push_back(v);
                    v.clear();
                }else{
                    v.append(1, c);
                }
            }else if(c != ','){
                elem_name.append(1, c);
            }
        }
    }
    registry::Container::addElement
        <std::map<std::string, std::vector<std::string>>>
        (name, content);
}
void registry::ConfigReader::loadConfigFile(std::string settings_path){
    std::ifstream i_file(settings_path);
    std::string line;
    if(i_file.is_open()){
        bool get_settings_content = false;
        bool is_map = false;
        std::string content_settings;
        while (getline(i_file, line)){
            line = ufn::deleteComment(line);
            if (line.empty()){
                continue;
            }

            std::size_t pos = line.find("{");
            if(!get_settings_content && pos != std::string::npos){
                std::string tmp = line.substr(0, pos);
                line.erase(0, pos + 1);
                line = tmp + line;
                get_settings_content = true;
            }
            if(get_settings_content){
                std::size_t pos = line.find("}");
                if(pos != std::string::npos){
                    line.erase(pos);
                    get_settings_content = false;
                }
                content_settings.append(line);
                if(get_settings_content)
                    continue;
                line = content_settings;
                is_map = true;
            }

            ReturnSettingsLine settingsParam =
                getContent(line);

            if(settingsParam.value_.empty())
                continue;

            if(is_map){
                registry::ConfigReader::initAtMapContainer(
                    settingsParam.name_,
                    settingsParam.value_
                );
            }else if(settingsParam.value_ == "true"
                || settingsParam.value_ == "false"
            ){
                if(settingsParam.value_ == "true"){
                    registry::Container::addElement<bool>(settingsParam.name_, true);
                }else registry::Container::addElement<bool>(settingsParam.name_, false);
            }else if(settingsParam.value_[0] == '[' && settingsParam.value_.find(",") != std::string::npos){
                settingsParam.value_.erase(0, 1);
                settingsParam.value_.erase(settingsParam.value_.size()-1, 1);
                registry::Container::addElement<std::vector<std::string>>(
                    settingsParam.name_,
                    ufn::exploed(settingsParam.value_, ",")
                );
            }else if(ufn::isNumeric(settingsParam.value_)){
                if(settingsParam.value_.find(".") != std::string::npos){
                    initAtFractional(settingsParam.name_, settingsParam.value_);
                }else{
                    initAtIntager(settingsParam.name_, settingsParam.value_);
                }
            }else{
                registry::Container::addElement<std::string>(
                    settingsParam.name_,
                    settingsParam.value_
                );
            }
            is_map = false;
        }
    }else
        throw std::runtime_error(
            "File cannot be opened " + settings_path
        );

    i_file.close();
}
