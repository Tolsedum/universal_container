#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
/** Version 2.0 */

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

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <ctime>
#include <filesystem>
#include <cmath>
#include <format>
#include <cstring>
#include <sys/stat.h>
#include <algorithm>
#include <functional>


namespace hashes{
	typedef union uwb {
		unsigned w;
		unsigned char b[4];
	} MD5union;

	typedef unsigned DigestArray[4];
	typedef unsigned(*DgstFctn)(unsigned a[]);
	inline std::string get_md5_string(std::string msg);
}

/**
 * Universal functions
 * @author Tolsedum
*/
namespace ufn{

    /**
     * @brief Check string to date format
     * @author Tolsedum
     * @param str_date
     * @return If str_date is date then true else false
     */
    bool is_date(const std::string& str_date);

    inline std::runtime_error
        error_in_function_create_file_and_dir("");
    /**
     * @brief Сreate a file with parent directories
     * @author Tolsedum
     * @param path
     * @return If file is created then true else false and description
     *      in var error_in_function_create_file_and_dir
     */
    bool create_file_and_dirrs(
        std::string path,
        std::string content = ""
    );

    bool create_parents_folder(std::string path);

    /**
     * Check upper register in string
     * @author Tolsedum
    */
   bool has_upper_register(std::string line);

    /**
     * @brief to lowercase
     * @author Tolsedum
     * @return
     */
   std::string to_lower(const std::string &s);
   std::string to_apper(const std::string &s);

    /**
     * Delete pattern by both sides
     * @author Tolsedum
    */
    // std::string trim(std::string patient, char pattern = ' ');
    std::string trim(std::string patient, std::vector<char> pattern);
    std::string trim(
        const std::string& str,
        const std::string& chars = " \t\n\r\f\v"
    );
    void trim_inplace(
        std::string& str,
        const std::string& chars = " \t\n\r\f\v"
    );


    struct Converter {
        const std::string &x;
        template <typename Numeric> operator Numeric() { return 0;}
    };
    /**
     * @brief If a type is passed to a number with a
     *  string type, it returns this type. It is advisable
     *  to use it after isNumeric
     * @param numeric
     * @return numeric type if exists
    */
    std::string get_numeric_type(std::string numeric);

    /**
     * @brief Chekc if string is numeric
     * @param str chekcing string
     * @return bool if is numeric then true else false
     * @author Tolsedum
     */
    bool is_numeric(std::string str);

    inline std::string error_in_converter_function = "";
    inline short has_error_in_converter_function = 0;
    /**
     * @brief String to int
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return int
     * @author Tolsedum
     */
    int str_to_int(const std::string &number);

    /**
     * @brief String to double
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return double
     * @author Tolsedum
     */
    double str_to_double(const std::string &number);

    /**
     * @brief String to float
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return float
     * @author Tolsedum
     */
    float str_to_float(const std::string &number);

    /**
     * @brief String to unsigned
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return float
     * @author Tolsedum
     */
    unsigned str_to_unsigned(const std::string &number);

    /**
     * @brief String to long
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return long
     * @author Tolsedum
     */
    long str_to_long(const std::string &number);

    /**
     * @brief String to long double
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return long double
     * @author Tolsedum
     */
    long double str_to_long_double(const std::string &number);

    /**
     * @brief String to long long
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return long long
     * @author Tolsedum
     */
    long long str_to_long_long(const std::string &number);

     /**
     * @brief String to unsigned long
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return unsigned long
     * @author Tolsedum
     */
    unsigned long str_to_unsigned_long(const std::string &number);

    /**
     * @brief String to long long
     *      If has error then in has_error_in_int_function
     *      set true and error description in hear error_in_int_function.
     *
     * @param number number by string format
     * @return long long
     * @author Tolsedum
     */
    unsigned long long str_to_unsigned_long_long(
        const std::string &number
    );

    /**
     * explode string to vector conteiner
     * @author Tolsedum
    */
    std::vector<std::string> explode(
        const std::string &line,
        const std::string &delimiter
    );

    /**
     * explode string to vector conteiner
     * @author Tolsedum
    */
    std::vector<std::string> explode(
        const std::string &line,
        const std::string &delimiter,
        const std::function<void(std::string&)>&
    );

    /**
     * Get file content from file pointer
     * @author Tolsedum
    */
    std::string get_file_content(std::ifstream &file);

    /**
     * Get file content by file name
     * @author Tolsedum
    */
    std::string get_file_content(const std::string fileName);

    /**
     * Delete commtnts teg (#)
     * @author Tolsedum
    */
    std::string delete_comment(const std::string &str);

    /**
     * Hash function md5
     * @author Tolsedum
    */
    std::string md5 (std::string in);

    /**
     * Get the currant date using the format
     * @author Tolsedum
    */
    std::string current_date_time(
        std::string format = "%Y-%m-%d %H:%M:%S");// 2019-08-22 10:55:23


    unsigned long get_file_creation_date(
        const std::string &file_name
    );

    std::string convert_timestamp_date_to_string(
        unsigned long &timestamp,
        std::string format = "%Y-%m-%d %H:%M:%S" // 2019-08-22 10:55:23
    );

    /**
    * @brief Convert string date to timestam
    * @param date string date
    * @param format date format
    * @return unix time
    */
    unsigned long convert_string_date_to_timestamp(
        const std::string &date,
        std::string format = "%Y-%m-%d %H:%M:%S" // 2019-08-22 10:55:23
    );

    std::string get_parent_dir(const std::string_view dir);

    enum class ProgresBarColor{
        black, green, red, blue, yellow, magenta, cyan, grey
    };

    struct ProgresBarParams{
        ProgresBarColor color;
        int size_bar;
        float total;
        float current;
        std::string message;

        void incraesCurrent();
        std::string getColor();
        /// @brief
        /// @param ProgresBarColor color
        /// @param int size bar
        /// @param float total
        ProgresBarParams(ProgresBarColor, int, float);
        ~ProgresBarParams(){};
    };

    /**
     * Console progres bar
     */
    void console_progres_bar(ProgresBarParams&);

    /**
     * implode Template
     *  @author FGTS45
    */
    template<typename TContainer, typename TData>
    std::string implode (TContainer array , char separator = ',')
    {
        std::string outData;
        for (TData arrData : array){
            outData+=std::to_string(arrData) + separator;
        }
        return outData;
    }

    /**
     * Search existing in array
     * @author Tolsedum
    */
    template<class TConteiner, class TValue>
    bool in_array (TConteiner array, TValue value){
        return std::find(
            array.begin(), array.end(), value) != array.end();
    }

    // ! ToDo
    inline constexpr std::string_view format_l{"{}"};
    void concat_args(
        std::string &out, std::string_view separator, auto&& in
    ){
        out.append(separator)
            .append(std::format(format_l, in));
    }

    template<typename T>
    std::string format_vector(
        const std::vector<T>& vec,
        std::string_view separator = "; ",
        auto&&... args
    ) {
        if (vec.empty())
            return "";
        std::string result;
        size_t trigger = vec.size() - 1;
        for (size_t i = 0; i < vec.size(); ++i) {
            result += std::format(format_l, vec[i]);
            if (i < trigger) {
                result += separator;
            }
        }

        (concat_args(result, separator, std::forward<decltype(args)>(args)), ...);
        return result;
    }
 };
#endif // !FUNCTIONS_HPP
