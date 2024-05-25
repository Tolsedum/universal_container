#ifndef FA9219F7_9584_4F69_9D42_D2DA261388D4
#define FA9219F7_9584_4F69_9D42_D2DA261388D4

#include "functions.hpp"
#include "Conteiner.hpp"

/**
 * Returned value from function Conteiner.getContent()
 * @author Tolsedum
*/
struct ReturnSettingsLine{
    std::string name_;
    std::string value_;

    ReturnSettingsLine(std::string name, std::string value)
        : name_(name)
        , value_(value)
    {};
    ~ReturnSettingsLine(){};

    friend std::ostream& operator<< (
        std::ostream &o_stream,
        const ReturnSettingsLine &settingsLine
    ){
        o_stream
            << "name: " << settingsLine.name_
            << " value: " << settingsLine.value_
        << std::endl;
        return o_stream;
    }
};

class ConfigReader{
protected:
    static ReturnSettingsLine getContent(
        const std::string &strrings_line
    );
public:
    ConfigReader(/* args */){};
    ~ConfigReader(){};

    /**
     * @brief Get list params, from config file
     *
     * @param settings_path
     * @return
     */
    void loadConfigFile(std::string settings_path);


};

#endif /* FA9219F7_9584_4F69_9D42_D2DA261388D4 */
