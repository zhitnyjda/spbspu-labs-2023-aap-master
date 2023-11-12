#ifndef VALIDATIONANDCONVERSATIONTOINT_H
#define VALIDATIONANDCONVERSATIONTOINT_H

#include <string>

const std::string ARG_ERR = "Wrong count of params";
const std::string FIRST_ARG_ERR = "Invalid first argument";
const std::string INVALID_INPUT = "Invalid input";

int getInt(std::string number);

void check(int argc, char **argv);

#endif //VALIDATIONANDCONVERSATIONTOINT_H
