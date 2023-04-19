#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_FILE="bytes.txt"
TEST_FILE_TWO="bytes_old.txt"
echo "" > log.txt

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt" "not_file.txt"
do
    TEST1="$file"
    echo "$TEST1"
    ./s21_cat $TEST1 > s21_cat.txt
    cat $TEST1 > cat.txt
    DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
    if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST1" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in -b -e -n -s -t -v #-E #-T --number-nonblank --number --squeeze-blank
  do
      TEST1="$var $file"
      echo "$TEST1"
      # valgrind ./s21_cat $TEST1 > s21_cat.txt
      ./s21_cat $TEST1 > s21_cat.txt
      cat $TEST1 > cat.txt
      DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
      if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
        then
          (( COUNTER_SUCCESS++ ))
        else
          echo "$TEST1" >> log.txt
          (( COUNTER_FAIL++ ))
      fi
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
    do
      if [ $var != $var2 ]
      then
        TEST1="$var $var2 $file"
        echo "$TEST1"
        ./s21_cat $TEST1 > s21_cat.txt
        cat $TEST1 > cat.txt
        DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
        if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
          then
            (( COUNTER_SUCCESS++ ))
          else
            echo "$TEST1" >> log.txt
            (( COUNTER_FAIL++ ))
        fi
      fi
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
        do
          if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ]
          then
            TEST1="$var $var2 $var3 $file"
            echo "$TEST1"
            ./s21_cat $TEST1 > s21_cat.txt
            cat $TEST1 > cat.txt
            DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
            if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
              then
                (( COUNTER_SUCCESS++ ))
              else
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
          fi
        done
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
        do
            for var4 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
            do
              if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ]
              then
                TEST1="$var $var2 $var3 $var4 $file"
                echo "$TEST1"
                ./s21_cat $TEST1 > s21_cat.txt
                cat $TEST1 > cat.txt
                DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST1" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
              fi
            done
        done
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
        do
            for var4 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
            do
              for var5 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
              do
              if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ] \
                  && [ $var != $var5 ] && [ $var2 != $var5 ] && [ $var3 != $var5 ] && [ $var4 != $var5 ]
              then
                TEST1="$var $var2 $var3 $var4 $var5 $var6 $file"
                echo "$TEST1"
                ./s21_cat $TEST1 > s21_cat.txt
                cat $TEST1 > cat.txt
                DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST1" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
              fi
              done
            done
        done
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
        do
            for var4 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
            do
              for var5 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
              do
                for var6 in -b -e -n -s -t -v #-E -T --number-nonblank --number --squeeze-blank
                do
              if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ] \
                  && [ $var != $var5 ] && [ $var2 != $var5 ] && [ $var3 != $var5 ] && [ $var4 != $var5 ] && [ $var != $var6 ] \
                  && [ $var2 != $var6 ] && [ $var3 != $var6 ] && [ $var4 != $var6 ] && [ $var5 != $var6 ]
              then
                TEST1="$var $var2 $var3 $var4 $var5 $var6 $file"
                echo "$TEST1"
                ./s21_cat $TEST1 > s21_cat.txt
                cat $TEST1 > cat.txt
                DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST1" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
              fi
                done
              done
            done
        done
    done
  done
done


for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
  do    
    TEST1="-$var $file"
    echo "$TEST1"
    ./s21_cat $TEST1 > s21_cat.txt
    cat $TEST1 > cat.txt
    DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
    if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
      then
        (( COUNTER_SUCCESS++ ))
      else
        echo "$TEST1" >> log.txt
        (( COUNTER_FAIL++ ))
    fi
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
    do
      if [ $var != $var2 ]
      then
        TEST1="-$var$var2 $file"
        echo "$TEST1"
        ./s21_cat $TEST1 > s21_cat.txt
        cat $TEST1 > cat.txt
        DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
        if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
          then
            (( COUNTER_SUCCESS++ ))
          else
            echo "$TEST1" >> log.txt
            (( COUNTER_FAIL++ ))
        fi
      fi
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
        do
          if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ] \
              && [ $var != $var5 ] && [ $var2 != $var5 ] && [ $var3 != $var5 ] && [ $var4 != $var5 ] && [ $var != $var6 ] \
              && [ $var2 != $var6 ] && [ $var3 != $var6 ] && [ $var4 != $var6 ] && [ $var5 != $var6 ]
          then
            TEST1="-$var$var2$var3 $file"
            echo "$TEST1"
            ./s21_cat $TEST1 > s21_cat.txt
            cat $TEST1 > cat.txt
            DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
            if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
              then
                (( COUNTER_SUCCESS++ ))
              else
                echo "$TEST1" >> log.txt
                (( COUNTER_FAIL++ ))
            fi
          fi
        done
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
        do
            for var4 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
            do
              if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ]
              then
                TEST1="-$var$var2$var3$var4 $file"
                echo "$TEST1"
                ./s21_cat $TEST1 > s21_cat.txt
                cat $TEST1 > cat.txt
                DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST1" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
              fi
            done
        done
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
        do
            for var4 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
            do
              for var5 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
              do
              if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ] \
                  && [ $var != $var5 ] && [ $var2 != $var5 ] && [ $var3 != $var5 ] && [ $var4 != $var5 ]
              then
                TEST1="-$var$var2$var3$var4$var5 $file"
                echo "$TEST1"
                ./s21_cat $TEST1 > s21_cat.txt
                cat $TEST1 > cat.txt
                DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST1" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
              fi
              done
            done
        done
    done
  done
done

for file in "tests/bytes.txt" "tests/bytes_old.txt" "tests/man.txt" "tests/empty.txt" "tests/enter.txt"
do
  for var in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
  do
    for var2 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
    do
        for var3 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
        do
            for var4 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
            do
              for var5 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
              do
                for var6 in b e n s t v #-E -T --number-nonblank --number --squeeze-blank
                do
              if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ] && [ $var != $var4 ] && [ $var2 != $var4 ] && [ $var3 != $var4 ] \
                  && [ $var != $var5 ] && [ $var2 != $var5 ] && [ $var3 != $var5 ] && [ $var4 != $var5 ] && [ $var != $var6 ] \
                  && [ $var2 != $var6 ] && [ $var3 != $var6 ] && [ $var4 != $var6 ] && [ $var5 != $var6 ]
              then
                TEST1="-$var$var2$var3$var4$var5$var6 $file"
                echo "$TEST1"
                ./s21_cat $TEST1 > s21_cat.txt
                cat $TEST1 > cat.txt
                DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
                if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]
                  then
                    (( COUNTER_SUCCESS++ ))
                  else
                    echo "$TEST1" >> log.txt
                    (( COUNTER_FAIL++ ))
                fi
              fi
                done
              done
            done
        done
    done
  done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"