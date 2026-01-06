#ifndef  SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter {
public:
    static void convert(std::string const &input);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();
};

#endif
