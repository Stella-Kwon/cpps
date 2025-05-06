clang++ -Wall -Wextra -Werror -W -std=c++20 *.cpp -o start
leaks --atExit -- ./start | cat -e
rm start