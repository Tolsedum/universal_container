#include "registry/Conteiner.hpp"
#include "registry/ConfigReader.hpp"

#include <functions.hpp>

class Logger{
    unsigned long buffer_size_;
    unsigned long long file_line_count_;

    public:
    Logger(
        unsigned long buffer_size,
        unsigned long long file_line_count
    )
        : buffer_size_(buffer_size)
        , file_line_count_(file_line_count)
    {

    };

    void log(){
        std::cout<< "buffer_size: " << buffer_size_ << std::endl;
        std::cout<< "file_line_count: " << file_line_count_ << std::endl;
    }
};

class Service{
private:
    // error_code code_;
    int code_;
    std::string message_;
public:
    Service(int code, std::string message = "")
        : code_(code)
        , message_(message)
    {};

    static Logger &getLogger(){
        static Logger log(
            registry::Container::getElement
                <unsigned long>("BUFFER_SIZE")
            , registry::Container::getElement
                <unsigned long long>("FILE_LINE_COUNT")
        );
        return log;
    }

    static void pushInLog(){
        getLogger().log();
        std::cout << "Log2" <<std::endl;
    }
};

int main(){
    registry::ConfigReader configReader;
    configReader.loadConfigFile("settings_test.conf");
    std::cout
        << "FILE_LINE_COUNT: "
            << registry::Container::getElement
                <unsigned long>
                ("FILE_LINE_COUNT")
    << std::endl;
    std::string str{"FILE_LINE_COUNT=1000UL#sdfdsf"};
    std::cout<< ufn::deleteComment(str) << std::endl;

    // Service::pushInLog();

    // std::string name_params{"PUBLIC_FILES"};
    // auto data = registry::Container::getElement
    //     <std::vector<std::string>>(name_params);

    // for (auto &&i : data){
    //     std::cout<< i << std::endl;
    // }
    // if(data.empty()){
    //     std::cout<< "Is empty" << std::endl;
    // }

    return 0;
}
