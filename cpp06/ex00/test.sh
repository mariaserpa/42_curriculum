#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Test function
run_test() {
    local input="$1"
    local description="$2"
    local expected="$3"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${BLUE}=== Test $TOTAL_TESTS: $description ===${NC}"
    echo "Input: \"$input\""
    
    # Get actual output
    local actual
    if [ "$input" = "EMPTY" ]; then
        actual=$(./convert "" 2>&1)
    else
        actual=$(./convert "$input" 2>&1)
    fi
    
    echo "Expected:"
    echo -e "${YELLOW}$expected${NC}"
    echo "Actual:"
    echo "$actual"
    
    # Compare results (normalize whitespace)
    local expected_clean=$(echo "$expected" | tr -d '\r' | sed 's/[[:space:]]*$//')
    local actual_clean=$(echo "$actual" | tr -d '\r' | sed 's/[[:space:]]*$//')
    
    if [ "$expected_clean" = "$actual_clean" ]; then
        echo -e "${GREEN}✓ PASS${NC}"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        echo -e "${RED}✗ FAIL${NC}"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    echo "----------------------------------------"
    echo
}

# Build the program
echo "Building conversionScalar..."
make > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed! Please fix compilation errors.${NC}"
    exit 1
fi

echo -e "${BLUE}SCALAR CONVERTER TEST SUITE${NC}"
echo "============================"
echo

# 1. CHARACTER TESTS
run_test "a" "Single printable character" "char: 'a'
int: 97
float: 97.0f
double: 97.0"

run_test "Z" "Single uppercase character" "char: 'Z'
int: 90
float: 90.0f
double: 90.0"

run_test "@" "Single symbol character" "char: '@'
int: 64
float: 64.0f
double: 64.0"

run_test " " "Space character" "char: ' '
int: 32
float: 32.0f
double: 32.0"

run_test "5" "Single digit character" "char: Non displayable
int: 5
float: 5.0f
double: 5.0"

# 2. INTEGER TESTS
run_test "42" "Positive integer" "char: '*'
int: 42
float: 42.0f
double: 42.0"

run_test "-42" "Negative integer" "char: impossible
int: -42
float: -42.0f
double: -42.0"

run_test "0" "Zero" "char: Non displayable
int: 0
float: 0.0f
double: 0.0"

run_test "127" "Max ASCII value" "char: Non displayable
int: 127
float: 127.0f
double: 127.0"

run_test "128" "Beyond ASCII range" "char: impossible
int: 128
float: 128.0f
double: 128.0"

# 3. FLOAT TESTS
run_test "42.0f" "Simple float" "char: '*'
int: 42
float: 42.0f
double: 42.0"

run_test "42.5f" "Float with decimal" "char: impossible
int: impossible
float: 42.5f
double: 42.5"

run_test "-42.5f" "Negative float" "char: impossible
int: impossible
float: -42.5f
double: -42.5"

run_test "0.0f" "Zero float" "char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# 4. DOUBLE TESTS
run_test "42.0" "Simple double" "char: '*'
int: 42
float: 42.0f
double: 42.0"

run_test "42.5" "Double with decimal" "char: impossible
int: impossible
float: 42.5f
double: 42.5"

run_test "-42.5" "Negative double" "char: impossible
int: impossible
float: -42.5f
double: -42.5"

# 5. SCIENTIFIC NOTATION TESTS
run_test "1e5" "Scientific notation (100000)" "char: impossible
int: 100000
float: 100000.0f
double: 100000.0"

run_test "1.5e10f" "Scientific notation float" "char: impossible
int: impossible
float: 1.5e+10f
double: 1.5e+10"

run_test "5e38f" "Large float (overflow)" "char: impossible
int: impossible
float: +inff
double: 5e+38"

run_test "1e400" "Very large double (overflow)" "char: impossible
int: impossible
float: +inff
double: +inf"

# 6. PSEUDO-LITERAL TESTS
run_test "nan" "NaN double" "char: impossible
int: impossible
float: nanf
double: nan"

run_test "nanf" "NaN float" "char: impossible
int: impossible
float: nanf
double: nan"

run_test "+inf" "Positive infinity double" "char: impossible
int: impossible
float: +inff
double: +inf"

run_test "-inf" "Negative infinity double" "char: impossible
int: impossible
float: -inff
double: -inf"

run_test "+inff" "Positive infinity float" "char: impossible
int: impossible
float: +inff
double: +inf"

run_test "-inff" "Negative infinity float" "char: impossible
int: impossible
float: -inff
double: -inf"

# 7. EDGE CASES
run_test "EMPTY" "Empty string" "char: impossible
int: impossible
float: impossible
double: impossible"

run_test "abc" "Invalid string" "char: impossible
int: impossible
float: impossible
double: impossible"

run_test "42abc" "Number with letters" "char: impossible
int: impossible
float: impossible
double: impossible"

run_test "42." "Number ending with dot" "char: '*'
int: 42
float: 42.0f
double: 42.0"

run_test ".42" "Number starting with dot" "char: impossible
int: impossible
float: 0.42f
double: 0.42"

# 8. BOUNDARY TESTS
run_test "32" "First printable ASCII" "char: ' '
int: 32
float: 32.0f
double: 32.0"

run_test "31" "Last non-printable ASCII" "char: Non displayable
int: 31
float: 31.0f
double: 31.0"

run_test "126" "Last printable ASCII" "char: '~'
int: 126
float: 126.0f
double: 126.0"

# 9. CONVERSION ACCURACY TESTS
run_test "65" "ASCII 'A' value" "char: 'A'
int: 65
float: 65.0f
double: 65.0"

run_test "97" "ASCII 'a' value" "char: 'a'
int: 97
float: 97.0f
double: 97.0"

run_test "10" "Newline character value" "char: Non displayable
int: 10
float: 10.0f
double: 10.0"

# Summary
echo "============================"
echo -e "${BLUE}TEST SUMMARY${NC}"
echo "============================"
echo "Total tests: $TOTAL_TESTS"
echo -e "${GREEN}Passed: $PASSED_TESTS${NC}"
echo -e "${RED}Failed: $FAILED_TESTS${NC}"

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}🎉 ALL TESTS PASSED! 🎉${NC}"
    exit 0
else
    echo -e "${RED}❌ Some tests failed. Please review the output above.${NC}"
    exit 1
fi