#include "s21_cat.h"

int main(int argc, char *argv[]) {
    OPTION_STATUS option_status = InitializationStructOptionStatus();
    int counter_for_argc = Parser(argc, argv, &option_status);
    for ( ; counter_for_argc < argc; counter_for_argc++) {
        FILE *data;
        data = fopen(argv[counter_for_argc], "r");
        if (data == NULL) {
            fprintf(stderr, "s21_cat: %s: ", argv[counter_for_argc]);
            perror("");
            continue;
        }
        GetDataFromFile(data, &option_status);
        fclose(data);
    }
}

int Parser(int argc, char *argv[], OPTION_STATUS *option_status) {
    int counter_for_argc = 1;
    OPTION_FLAGS option_flags = InitializationStructOptionFlags();

    for ( ; counter_for_argc < argc && argv[counter_for_argc][0] == option_flags.dash_option_flag; \
            counter_for_argc++) {
        if (argv[counter_for_argc][0] == option_flags.dash_option_flag \
                && argv[counter_for_argc][1] != option_flags.dash_option_flag) {
            CheckFlag(argv[counter_for_argc], &option_flags, option_status);
        }
        if (argv[counter_for_argc][0] == option_flags.dash_option_flag \
            && argv[counter_for_argc][1] == option_flags.dash_option_flag) {
            CheckFlagGNU(argv[counter_for_argc], option_status);
        }
    }
    return counter_for_argc;
}

void GetDataFromFile(FILE *data, OPTION_STATUS *option_status) {
    int check_empty_line = 0;
    int from_b_flag = option_status->b_option_status;
    int from_n_flag = option_status->n_option_status;
    int from_s_flag = 0;
    int counter_not_empty_line = 1;
    int counter_line = 1;
    for (int counter = 0; feof(data) == 0; counter++) {
        char sign = '\0';
        fread(&sign, sizeof(char), 1, data);
        CheckEmptyLineBegin(&sign, &check_empty_line);
        from_s_flag += FlagS(&check_empty_line, option_status);
        if (check_empty_line) {
            from_s_flag = 0;
        }
        if (from_s_flag > 1 && feof(data) == 0) {
            continue;
        }
        if (option_status->b_option_status == 1 && from_b_flag == 1 && feof(data) == 0) {
            from_b_flag = FlagB(&check_empty_line, &sign, &counter_not_empty_line);
        }
        if (option_status->n_option_status == 1 && from_n_flag == 1 && feof(data) == 0) {
            from_n_flag = FlagN(&counter_line);
        }
        if (option_status->v_option_status == 1 && feof(data) == 0) {
            sign = ProcessingOutsideSignASCII(sign);
        }
        if (option_status->t_option_status == 1) {
            if (sign == '\t') {
                printf("^");
                sign = 'I';
            }
        }
        if ((option_status->e_option_status == 1 || option_status->E_option_status == 1) \
                && sign == '\n' && feof(data) == 0) {
            printf("$");
        }
        PrintSign(data, &sign);
        counter_not_empty_line += CounterForNotEmptyLine(&check_empty_line, &sign);
        counter_line += CounterLine(&sign);

        if (option_status->b_option_status == 1 && sign == '\n') {
            from_b_flag = option_status->b_option_status;
        }
        if (option_status->n_option_status == 1 && sign == '\n') {
            from_n_flag = option_status->n_option_status;
        }
        CheckEmptyLineEnd(&sign, &check_empty_line);
    }
}

char ProcessingOutsideSignASCII(char sign) {
    int check = sign;
    if (check < 32 && check > -1 && sign != '\n' && sign != '\t') {
        printf("^");
        check += 64;
        sign = check;
    }
    if (check > 126) {
        printf("^");
        check -= 64;
        sign = check;
    }
    return sign;
}

void PrintSign(FILE *data, const char *sign) {
    if (feof(data) == 0) {
        printf("%c", *sign);
    }
}

int CounterForNotEmptyLine(const int *check_empty_line, const char *sign) {
    int counter = 0;
    if (*sign == '\n' && *check_empty_line == 1) {
        counter++;
    }
    return counter;
}

int CounterLine(const char *sign) {
    int counter = 0;
    if (*sign == '\n') {
        counter++;
    }
    return counter;
}

void CheckEmptyLineBegin(const char *sign, int *check_empty_line) {
    if (*sign != '\n' && *check_empty_line == 0) {
        *check_empty_line = 1;
    }
}

void CheckEmptyLineEnd(const char *sign, int *check_empty_line) {
    if (*sign == '\n') {
        *check_empty_line = 0;
    }
}

int FlagB(const int *check_empty_line, const char *sign, const int *counter_line) {
    int from_b_flag = 1;
    if (*check_empty_line == 1 && *sign != '\n') {
        printf("%6d", *counter_line);
        printf("\t");
        from_b_flag = 0;
    }
    return from_b_flag;
}

int FlagN(const int *counter_line) {
    int from_n_flag = 1;
    printf("%6d\t", *counter_line);
    from_n_flag = 0;
    return from_n_flag;
}

int FlagS(const int *check_empty_line, OPTION_STATUS *option_status) {
    int check_continue = 0;
    if (option_status->s_option_status == 1 && *check_empty_line == 0) {
        check_continue = 1;
    }
    return check_continue;
}

OPTION_FLAGS InitializationStructOptionFlags() {
    OPTION_FLAGS option_flags;
    option_flags.b_option_flag = 'b';
    option_flags.E_option_flag = 'E';
    option_flags.e_option_flag = 'e';
    option_flags.n_option_flag = 'n';
    option_flags.s_option_flag = 's';
    option_flags.T_option_flag = 'T';
    option_flags.t_option_flag = 't';
    option_flags.v_option_flag = 'v';
    option_flags.dash_option_flag = '-';
return option_flags;
}

OPTION_STATUS InitializationStructOptionStatus() {
    OPTION_STATUS option_status;
    option_status.b_option_status = 0;
    option_status.E_option_status = 0;
    option_status.e_option_status = 0;
    option_status.n_option_status = 0;
    option_status.s_option_status = 0;
    option_status.T_option_status = 0;
    option_status.t_option_status = 0;
    option_status.v_option_status = 0;
return option_status;
}

void CheckFlag(const char *argv, OPTION_FLAGS *option_flags, OPTION_STATUS *option_status) {
    for (int counter_argv = 0; argv[counter_argv] != '\0'; counter_argv++) {
        if (argv[counter_argv] == option_flags->b_option_flag) {
            option_status->b_option_status = 1;
            option_status->n_option_status = 0;
        }
        if (argv[counter_argv] == option_flags->E_option_flag) {
            option_status->E_option_status = 1;
            option_status->e_option_status = 1;
        }
        if (argv[counter_argv] == option_flags->e_option_flag) {
            option_status->e_option_status = 1;
            option_status->v_option_status = 1;
        }
        if (argv[counter_argv] == option_flags->n_option_flag) {
            option_status->n_option_status = 1;
            if (option_status->b_option_status == 1) {
                option_status->n_option_status = 0;
            }
        }
        if (argv[counter_argv] == option_flags->s_option_flag) {
            option_status->s_option_status = 1;
        }
        if (argv[counter_argv] == option_flags->T_option_flag) {
            option_status->T_option_status = 1;
            option_status->t_option_status = 1;
        }
        if (argv[counter_argv] == option_flags->t_option_flag) {
            option_status->t_option_status = 1;
            option_status->v_option_status = 1;
        }
        if (argv[counter_argv] == option_flags->v_option_flag) {
            option_status->v_option_status = 1;
        }
    }
}

void CheckFlagGNU(const char *argv,  OPTION_STATUS *option_status) {
    char *flag_one = "--number-nonblank";
    char *flag_two = "--number";
    char *flag_thrree = "--squeeze-blank";
    if (argv == flag_one) {
        option_status->b_option_status = 1;
    }
    if (argv == flag_two) {
        option_status->n_option_status = 1;
    }
    if (argv == flag_thrree) {
        option_status->s_option_status = 1;
    }
}
