#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
// echo "" > log.txt

for var in -v -c -l -n -h -s -i -o
do
    TEST1="ABS tests/test_regex.c  $var"
    echo "$TEST1"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST1 > s21_grep.txt
    # leaks -atExit -- ./s21_grep $TEST1 > s21_grep.txt
    ./s21_grep $TEST1 > s21_grep.txt
    grep $TEST1 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST1" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST2="for tests/test_regex.c $var"
    echo "$TEST2"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST2 > s21_grep.txt
    ./s21_grep $TEST2 > s21_grep.txt
    grep $TEST2 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST2" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST3="-e for -e int grep.c $var"
    echo "$TEST3"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST3 > s21_grep.txt
    ./s21_grep $TEST3 > s21_grep.txt
    grep $TEST3 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST3" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

  TEST31="-e for -e ^int grep.c grep.h Makefile $var"
    echo "$TEST31"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST31 > s21_grep.txt
    ./s21_grep $TEST31 > s21_grep.txt
    grep $TEST31 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST3" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST4="-e for -e ^int grep.c $var"
    echo "$TEST4"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST4 > s21_grep.txt
    ./s21_grep $TEST4 > s21_grep.txt
    grep $TEST4 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST4" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST5="-e regex -e ^print grep.c $var -f tests/pattern.txt"
    echo "$TEST5"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST5 > s21_grep.txt
    # leaks -atExit -- ./s21_grep $TEST5 > s21_grep.txt
    ./s21_grep $TEST5 > s21_grep.txt
    grep $TEST5 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST5" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST6="-e while -e void grep.c Makefile $var -f tests/pattern.txt"
    echo "$TEST6"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST6 > s21_grep.txt
    ./s21_grep $TEST6 > s21_grep.txt
    grep $TEST6 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST6" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST7="-e regex -e ^print grep.c $var -f tests/pattern2.txt"
    echo "$TEST7"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST7 > s21_grep.txt
    ./s21_grep $TEST7 > s21_grep.txt
    grep $TEST7 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST7" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST8="-e while -e void grep.c Makefile $var -f tests/pattern2.txt"
    echo "$TEST8"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST8 > s21_grep.txt
    ./s21_grep $TEST8 > s21_grep.txt
    grep $TEST8 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST8" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST9="-e regex -e ^print grep.c $var -f tests/pattern3.txt"
    echo "$TEST9"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST9 > s21_grep.txt
    ./s21_grep $TEST9 > s21_grep.txt
    grep $TEST9 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST9" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST10="-e while -e void grep.c Makefile $var -f tests/pattern3.txt"
    echo "$TEST10"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST10 > s21_grep.txt
    ./s21_grep $TEST10 > s21_grep.txt
    grep $TEST10 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST10" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST11="-e regex -e ^print grep.c $var -f tests/pattern.txt -f tests/pattern2.txt"
    echo "$TEST11"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST11 > s21_grep.txt
    ./s21_grep $TEST11 > s21_grep.txt
    grep $TEST11 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST11" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST12="-e while -e void grep.c Makefile $var"
    echo "$TEST12"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST12 > s21_grep.txt
    ./s21_grep $TEST12 > s21_grep.txt
    grep $TEST12 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST12" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST13="-e regex -e ^print grep.c $var -f tests/pattern.txt -f tests/pattern2.txt tests/pattern3.txt"
    echo "$TEST13"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST13 > s21_grep.txt
    ./s21_grep $TEST13 > s21_grep.txt
    grep $TEST13 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST13" >> log.txt
        (( COUNTER_FAIL++ ))
    fi

    TEST14="-e while -e void grep.c Makefile $var -f tests/pattern.txt"
    echo "$TEST14"
    # valgrind --leak-check=full --track-origins=yes ./s21_grep $TEST14 > s21_grep.txt
    ./s21_grep $TEST14 > s21_grep.txt
    grep $TEST14 > grep.txt
    DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
    if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST14" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
done

for var in -v -c -l -n -h -s -i -o
do
  for var2 in -v -c -l -n -h -s -i -o
  do
        if [ $var != $var2 ]
        then

          TEST1="for grep.c grep.h Makefile $var $var2"
          echo "$TEST1"
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST1" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST2="for grep.c $var $var2"
          echo "$TEST2"
          ./s21_grep $TEST2 > s21_grep.txt
          grep $TEST2 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST2" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST3="-e for -e ^int grep.c grep.h Makefile $var $var2"
          echo "$TEST3"
          ./s21_grep $TEST3 > s21_grep.txt
          grep $TEST3 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST3" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST4="-e for -e ^int grep.c $var $var2"
          echo "$TEST4"
          ./s21_grep $TEST4 > s21_grep.txt
          grep $TEST4 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST4" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST5="-e regex -e ^print grep.c $var $var2 -f tests/pattern.txt"
          echo "$TEST5"
          ./s21_grep $TEST5 > s21_grep.txt
          grep $TEST5 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST5" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST6="-e while -e void grep.c Makefile $var $var2 -f tests/pattern.txt"
          echo "$TEST6"
          ./s21_grep $TEST6 > s21_grep.txt
          grep $TEST6 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST6" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST7="-e regex -e ^print grep.c $var $var2 -f tests/pattern2.txt"
          echo "$TEST7"
          ./s21_grep $TEST7 > s21_grep.txt
          grep $TEST7 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST7" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST8="-e while -e void grep.c Makefile $var $var2 -f tests/pattern2.txt"
          echo "$TEST8"
          ./s21_grep $TEST8 > s21_grep.txt
          grep $TEST8 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST8" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST9="-e regex -e ^print grep.c $var $var2 -f tests/pattern3.txt"
          echo "$TEST9"
          ./s21_grep $TEST9 > s21_grep.txt
          grep $TEST9 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST9" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST10="-e while -e void grep.c Makefile $var $var2 -f tests/pattern3.txt"
          echo "$TEST10"
          ./s21_grep $TEST10 > s21_grep.txt
          grep $TEST10 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST10" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST11="-e regex -e ^print grep.c $var $var2 -f tests/pattern.txt -f tests/pattern2.txt"
          echo "$TEST11"
          ./s21_grep $TEST11 > s21_grep.txt
          grep $TEST11 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST11" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST12="-e while -e void grep.c Makefile $var $var2 -f tests/pattern.txt -f tests/pattern2.txt"
          echo "$TEST12"
          ./s21_grep $TEST12 > s21_grep.txt
          grep $TEST12 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST12" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST13="-e regex -e ^print grep.c $var $var2 -f tests/pattern.txt -f tests/pattern2.txt tests/pattern3.txt"
          echo "$TEST13"
          ./s21_grep $TEST13 > s21_grep.txt
          grep $TEST13 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST13" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

          TEST14="-e while -e void grep.c Makefile $var $var2 -f tests/pattern.txt -f tests/pattern2.txt"
          echo "$TEST14"
          ./s21_grep $TEST14 > s21_grep.txt
          grep $TEST14 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST14" >> log.txt
              (( COUNTER_FAIL++ ))
          fi

     fi     
  done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"
