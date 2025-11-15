#!/bin/bash

# RPN Calculator Test Script
# filepath: /Users/malu/Documents/Projects/42_curriculum/cpp09/ex01/test_rpn.sh

echo "=== RPN Calculator Test Suite ==="
echo

# Function to run a test case
run_test() {
    local test_name="$1"
    local input="$2"
    local expected="$3"
    
    echo "Test: $test_name"
    echo "Input: '$input'"
    
    # Run the program and capture output
    result=$(./RPN "$input" 2>&1)
    exit_code=$?
    
    if [ $exit_code -eq 0 ]; then
        echo "Output: $result"
        if [ "$result" = "$expected" ]; then
            echo "✅ PASS"
        else
            echo "❌ FAIL - Expected: $expected"
        fi
    else
        echo "$result"
        if [[ "$result" == *"$expected"* ]]; then
            echo "✅ PASS (Expected error)"
        else
            echo "❌ FAIL - Expected error containing: $expected"
        fi
    fi
    echo "---"
}

# Build the program first
echo "Building RPN calculator..."
make > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "❌ Build failed!"
    exit 1
fi
echo "✅ Build successful"
echo

# Valid test cases
echo "=== VALID EXPRESSIONS ==="
run_test "Subject Example" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "Subject Example" "7 7 * 7 -" "42"
run_test "Subject Example"  "1 2 * 2 / 2 * 2 4 - +" "0"
run_test "Simple subtraction" "5 3 -" "2"
run_test "Simple multiplication" "4 2 *" "8"
run_test "Simple division" "8 2 /" "4"
run_test "Complex expression" "3 4 + 2 * 7 /" "2"

echo
echo "=== ERROR CASES ==="
run_test "Empty string" "" "Empty expression"
run_test "Whitespace only" "   " "Empty expression"
run_test "Multi-digit number" "12 3 +" "multi-digit numbers"
run_test "No space after number" "1a" "Invalid character"
run_test "Insufficient operands" "1 1+" "There must be a space after operands"
run_test "Insufficient operands" "1 +" "Insufficient operands"
run_test "Too many operands" "1 2 3 +" "RPN expression is invalid"
run_test "Division by zero" "5 0 /" "Division by zero"
run_test "Invalid character" "1 2 &" "Invalid character"
run_test "Invalid character (letter)" "1 2 a" "Invalid character"

echo
echo "=== EDGE CASES ==="
run_test "Multiple spaces" "1   2   +" "3"
run_test "Leading/trailing spaces" "  1 2 +  " "3"
run_test "All operators" "1 2 + 3 - 4 * 5 /" "0"

echo
echo "=== TEST SUMMARY ==="
echo "All tests completed!"