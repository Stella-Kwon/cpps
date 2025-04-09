#!/bin/bash

# 색상 설정
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RESET='\033[0m'

# 테스트 함수
test_convert() {
    echo -e "\n${GREEN}===== Testing: $1 =====${RESET}"
    ./convert "$1"
    echo -e "${YELLOW}==========================${RESET}"
}

# 기본 테스트가 실행 가능한지 확인
if [ ! -f ./convert ]; then
    echo -e "${YELLOW}Error: 'convert' executable not found. Run 'make' first.${RESET}"
    exit 1
fi

echo -e "${GREEN}======== SCALAR CONVERTER TEST ========${RESET}"

# 문자 테스트
echo -e "\n${YELLOW}CHARACTER TESTS:${RESET}"
test_convert "'a'"
test_convert "'0'"
test_convert "' '"
test_convert "'\n'"

# 정수 테스트
echo -e "\n${YELLOW}INTEGER TESTS:${RESET}"
test_convert "0"
test_convert "42"
test_convert "-42"
test_convert "2147483647"    # INT_MAX
test_convert "-2147483648"   # INT_MIN
test_convert "2147483648"    # INT_MAX + 1

# Float 테스트
echo -e "\n${YELLOW}FLOAT TESTS:${RESET}"
test_convert "0.0f"
test_convert "4.2f"
test_convert "-4.2f"
test_convert "42.0f"
test_convert "nanf"
test_convert "+inff"
test_convert "-inff"
test_convert "3.402823e+38f"

# Double 테스트
echo -e "\n${YELLOW}DOUBLE TESTS:${RESET}"
test_convert "0.0"
test_convert "4.2"
test_convert "-4.2"
test_convert "42.0"
test_convert "nan"
test_convert "+inf"
test_convert "-inf"
test_convert "1.7976931348623157e+308"

# 경계 케이스
echo -e "\n${YELLOW}EDGE CASES:${RESET}"
test_convert "127"
test_convert "128"  # over ascii
test_convert "0.0000001f"
test_convert ""

# 특수 케이스
echo -e "\n${YELLOW}SPECIAL CASES:${RESET}"
test_convert "42.f" 
test_convert ".42f" #no decimal part
test_convert "42."
test_convert ".42"
test_convert "hello" #wrong input

echo -e "\n${GREEN}========= TEST COMPLETED ==========${RESET}"