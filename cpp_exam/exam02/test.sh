clang++ -Wextra -Werror -Wall -W -std=c++20 *.cpp -o start
# ./valgrind --leak-check=full ./start
leaks --atExit -- ./start | cat -e
# ./start | cat -e
rm start