#ifndef FA9219F7_9584_4F69_9D42_D2DA261388D4
#define FA9219F7_9584_4F69_9D42_D2DA261388D4

/**
 *  __________________________________________
 * |                                          |
 * |   ╭━━━━┳━━━┳╮╱╱╭━━━┳━━━┳━━━┳╮╱╭┳━╮╭━╮    |
 * |   ┃╭╮╭╮┃╭━╮┃┃╱╱┃╭━╮┃╭━━┻╮╭╮┃┃╱┃┃┃╰╯┃┃    |
 * |   ╰╯┃┃╰┫┃╱┃┃┃╱╱┃╰━━┫╰━━╮┃┃┃┃┃╱┃┃╭╮╭╮┃    |
 * |   ╱╱┃┃╱┃┃╱┃┃┃╱╭╋━━╮┃╭━━╯┃┃┃┃┃╱┃┃┃┃┃┃┃    |
 * |   ╱╱┃┃╱┃╰━╯┃╰━╯┃╰━╯┃╰━━┳╯╰╯┃╰━╯┃┃┃┃┃┃    |
 * |   ╱╱╰╯╱╰━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻╯╰╯╰╯    |
 * |__________________________________________|
 * |                                          |
 * | Permission is hereby granted, free of    |
 * | charge, to any person obtaining a copy of|
 * | of this software and accompanying files, |
 * | to use them without restriction,         |
 * | including, without limitation, the       |
 * | rights to use, copy, modify, merge,      |
 * | publish, distribute, sublicense and/or   |
 * | sell copies of the software. The authors |
 * | or copyright holders shall not be liable |
 * | for any claims, damages or other         |
 * | liability, whether in contract, tort or  |
 * | otherwise, arising out of or in          |
 * | connection with the software or your use |
 * | or other dealings with the software.     |
 * |__________________________________________|
 * |   website: tolsedum.ru                   |
 * |   email: tolsedum@gmail.com              |
 * |   email: tolsedum@yandex.ru              |
 * |__________________________________________|
 */

#include "functions.hpp"
#include "Conteiner.hpp"

namespace registry{
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
        void initAtIntager(std::string name, std::string value);
        void initAtFractional(std::string name, std::string value);

    };
}

#endif /* FA9219F7_9584_4F69_9D42_D2DA261388D4 */
