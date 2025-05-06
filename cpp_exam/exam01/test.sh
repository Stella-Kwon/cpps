clang++ -Wextra -Werror -Wall -W -g -std=c++20 *.cpp -o start
leaks --atExit -- ./start | cat -e
rm start