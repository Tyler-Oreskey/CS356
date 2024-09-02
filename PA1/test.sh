#!/bin/bash

PROGRAM="./cipher"
INPUT_FILE="./input.txt"
OUTPUT_FILE="./output.txt"
KEY_FILE="./key.txt"
PLAIN_TEXT_1="abcdefghijklmnop1234567890abcdefHello, world!123\"asdasdasdasdkjasd"
PLAIN_TEXT_2=$(printf "abcdefghijklm\nnop1234567890abcdef\nHello, world!\n123\"asdasdasdasdkjasd")
PLAIN_TEXT_3=$(printf "abcdefghijklm\nn      op1234567890abcdef\nHello, world!\n1    23\"asdasdasdasdkjasd")
KEY_TXT="COMPUTER76543210"

init() {
    rm -rf $INPUT_FILE
    rm -rf $OUTPUT_FILE
    rm -rf $KEY_FILE

    touch "$INPUT_FILE"
    touch "$OUTPUT_FILE"
    touch "$KEY_FILE"

    local plainTextFile="$1"

    if [ "$plainTextFile" -eq 1 ]; then
        echo "$PLAIN_TEXT_1" > "$INPUT_FILE"
    elif [ "$plainTextFile" -eq 2 ]; then
        echo "$PLAIN_TEXT_2" > "$INPUT_FILE"
    elif [ "$plainTextFile" -eq 3 ]; then
        echo "$PLAIN_TEXT_3" > "$INPUT_FILE"
    else
        echo "Invalid input for plainTextFile. Must be 1 or 2."
    fi

    echo "$KEY_TXT" > "$KEY_FILE"
    echo "" > "$OUTPUT_FILE"
}

assert() {
    local condition="$1"
    local message="$2"
    
    if ! eval "$condition"; then
        echo "Assertion failed: $message"
        exit 1
    fi
}

assert_not() {
    local condition="$1"
    local message="$2"
    
    if eval "$condition"; then
        echo "Assertion failed: $message"
        exit 1
    fi
}

b_test_encrypt_to_decrypt() {
    # Block Cypher Encrypt -> Decrypt
    $PROGRAM B $INPUT_FILE $OUTPUT_FILE $KEY_FILE E
    assert_not "diff -q $INPUT_FILE $OUTPUT_FILE" "File: $INPUT_FILE and File: $OUTPUT_FILE should not be the same."

    # Block Cypher Decrypt -> Encrypt
    $PROGRAM B $OUTPUT_FILE $OUTPUT_FILE $KEY_FILE D
    assert "diff -q $INPUT_FILE $OUTPUT_FILE" "File: $INPUT_FILE and File: $OUTPUT_FILE should be the same."
    echo "Files are the same."
}

s_test_encrypt_to_decrypt() {
    # Stream Cypher Encrypt -> Decrypt
    $PROGRAM S $INPUT_FILE $OUTPUT_FILE $KEY_FILE E
    assert_not "diff -q $INPUT_FILE $OUTPUT_FILE" "File: $INPUT_FILE and File: $OUTPUT_FILE should not be the same."

    # Stream Cypher Decrypt -> Encrypt
    $PROGRAM S $OUTPUT_FILE $OUTPUT_FILE $KEY_FILE D
    assert "diff -q $INPUT_FILE $OUTPUT_FILE" "File: $INPUT_FILE and File: $OUTPUT_FILE should be the same."
    echo "Files are the same."
}

s_test_decrypt_to_encrypt() {
    # Stream Cypher Decrypt -> Encrypt
    $PROGRAM S $INPUT_FILE $OUTPUT_FILE $KEY_FILE D
    assert_not "diff -q $INPUT_FILE $OUTPUT_FILE" "File: $INPUT_FILE and File: $OUTPUT_FILE should not be the same."

    # Stream Cypher Encrypt -> Decrypt
    $PROGRAM S $OUTPUT_FILE $OUTPUT_FILE $KEY_FILE E
    assert "diff -q $INPUT_FILE $OUTPUT_FILE" "File: $INPUT_FILE and File: $OUTPUT_FILE should be the same."
    echo "Files are the same."
}

init 1
b_test_encrypt_to_decrypt

init 2
b_test_encrypt_to_decrypt

init 3
b_test_encrypt_to_decrypt

init 1
s_test_encrypt_to_decrypt

init 3
s_test_decrypt_to_encrypt