#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int b_option_status;
    int e_option_status;
    int E_option_status;
    int n_option_status;
    int s_option_status;
    int v_option_status;
    int T_option_status;
    int t_option_status;
} OPTION_STATUS;

typedef struct {
    char b_option_flag;
    char e_option_flag;
    char E_option_flag;
    char n_option_flag;
    char s_option_flag;
    char v_option_flag;
    char T_option_flag;
    char t_option_flag;
    char dash_option_flag;
} OPTION_FLAGS;

OPTION_FLAGS InitializationStructOptionFlags();
OPTION_STATUS InitializationStructOptionStatus();

int Parser(int argc, char *argv[], OPTION_STATUS *option_status);
void CheckFlag(const char *argv, OPTION_FLAGS *option_flags, OPTION_STATUS *option_status);
void CheckFlagGNU(const char *argv,  OPTION_STATUS *option_status);
void GetDataFromFile(FILE *data, OPTION_STATUS *option_status);

void PrintSign(FILE *data, const char *sign);
int CounterForNotEmptyLine(const int *check_empty_line, const char *sign);
int CounterLine(const char *sign);
void CheckEmptyLineBegin(const char *sign, int *check_empty_line);
void CheckEmptyLineEnd(const char *sign, int *check_empty_line);
char ProcessingOutsideSignASCII(char sign);

int FlagB(const int *check_empty_line, const char *sign, const int *counter_line);
int FlagN(const int *counter_line);
int FlagS(const int *check_empty_line, OPTION_STATUS *option_status);

#endif  // SRC_CAT_S21_CAT_H_
