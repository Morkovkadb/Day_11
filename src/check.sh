#!/bin/bash

# Путь к вашей директории с исходными файлами
SOURCE_DIR="/Users/saadfleu/T11D17-1/src"

# Получаем список имен файлов в директории
FILES=$(ls $SOURCE_DIR/*.c)

# Проверка кода с использованием Cppcheck для каждого файла
for file in $FILES; do
    cppcheck --enable=all --suppress=missingIncludeSystem $file
done

# Применение clang-format к каждому файлу
# for file in $FILES; do
     clang-format -i *.c *.h
# done

# Компиляция каждого файла с использованием GCC
# for file in $FILES; do
#     output_name="${file%.c}"
#     gcc -Wall -Wextra -pedantic -Werror -o $output_name $file

#     # Проверка результатов компиляции
#     if [ $? -eq 0 ]; then
#         echo "Компиляция файла $file успешно завершена без ошибок."
#     else
#      echo "Компиляция файла $file завершилась с ошибками."
#     fi
# done

# for file in $FILES; do 
#     output_name="${file%.c}"
#     leaks -atExit -- $output_name
#     if [ $? -eq 0 ]; then
#     echo "Файл $file не содержит утечек памяти."
#      else
#          echo "Обнаружена утечка памяти у файла $file."
#     fi
# done