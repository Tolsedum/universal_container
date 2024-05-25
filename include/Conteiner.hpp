#ifndef C6F35E3E_DBD0_44B1_BDD9_771CB2E984FB
#define C6F35E3E_DBD0_44B1_BDD9_771CB2E984FB

#include "functions.hpp"

/**
 * Global conteiner for save and getting elements
 * @author Tolsedum
*/
class Container{
protected:
    /**
     * @brief List settings
     * @tparam T settings object (numver, string, vector, map ...)
    */
    template<class T>
    inline static std::map<std::string, T>
        conteiner_;

private:

    /**
     * @brief Non-erasable data
     */
    static std::array<std::string, 3> noeraseble_data;

    template<class Type>
    static bool checkEmptyElements(std::string settings_key, Type value);
public:

    /**
     * @brief Getting value, by key
     * @tparam T settings object (string, vector, map ...)
     * @param settings_key
     * @return T settings object (string, vector, map ...)
    */
    template<class T>
    static T getElement(std::string settings_key);

    /**
     * @brief Add T object in conteiner
     * @tparam T settings object (string, vector, map ...)
     * @param sttings_key
     * @param settings
     * @return If false then not append, else append
    */
    template <class Type>
    static bool addElement(
        std::string settings_key, Type content
    );
};

//*------------------ Template realization ----------------*/
template<class Type>
inline bool Container::checkEmptyElements(std::string settings_key, Type value){
    return !settings_key.empty() && !value.empty();
}
template<>
inline bool Container::checkEmptyElements(std::string settings_key, bool value){
    return !settings_key.empty();
}
template<>
inline bool Container::checkEmptyElements(std::string settings_key, int value){
    return !settings_key.empty();
}

template <class Type>
bool Container::addElement(
    std::string settings_key, Type content
){
    bool ret_value = true;
    ufn::trim(settings_key);
    if(checkEmptyElements(settings_key, content)){
        conteiner_<Type>[settings_key] = content;
    }else ret_value = false;

    return ret_value;
}

// template <>
// inline  bool Container::addElement(
//     std::string settings_key, bool content
// ){
//     bool ret_value = true;
//     ufn::trim(settings_key);
//     if(!settings_key.empty()){
//         conteiner_<bool>[settings_key] = content;
//     }else ret_value = false;
//     return ret_value;
// }

// template <>
// inline  bool Container::addElement(
//     std::string settings_key, int content
// ){
//     bool ret_value = true;
//     ufn::trim(settings_key);
//     if(!settings_key.empty()){
//         conteiner_<int>[settings_key] = content;
//     }else ret_value = false;
//     return ret_value;
// }

template <class T>
inline T Container::getElement(std::string settings_key){
    static T _ret_value;
    static std::string _key_name;
    T ret_str;

    if(_key_name != settings_key){
        if(auto search = conteiner_<T>.find(settings_key);
            search != conteiner_<T>.end()
        ){
            _ret_value = search->second;
            ret_str = _ret_value;
            _key_name = settings_key;
        }
    }else if(_key_name == settings_key){
        ret_str = _ret_value;
    }
    return ret_str;
}


//*---------------- END Template realization ---------------*/

#endif /* C6F35E3E_DBD0_44B1_BDD9_771CB2E984FB */
