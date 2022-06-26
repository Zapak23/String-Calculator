#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    if (digit == '0'){
        return 0;
    }
    if (digit == '1'){
        return 1;
    }
    if (digit == '2'){
        return 2;
    }
    if (digit == '3'){
        return 3;
    }
    if (digit == '4'){
        return 4;
    }
    if (digit == '5'){
        return 5;
    }
    if (digit == '6'){
        return 6;
    }
    if (digit == '7'){
        return 7;
    }
    if (digit == '8'){
        return 8;
    }
    if (digit == '9'){
        return 9;
    }
    else {throw std::invalid_argument("Wrong character");}
}

char decimal_to_digit(unsigned int decimal) {
    if (decimal == 0){
        return '0';
    }
    if (decimal == 1){
        return '1';
    }
    if (decimal == 2){
        return '2';
    }
    if (decimal == 3){
        return '3';
    }
    if (decimal == 4){
        return '4';
    }
    if (decimal == 5){
        return '5';
    }
    if (decimal == 6){
        return '6';
    }
    if (decimal == 7){
        return '7';
    }
    if (decimal == 8){
        return '8';
    }
    if (decimal == 9){
        return '9';
    }
    else {throw std::invalid_argument("Wrong character");}
}

string trim_leading_zeros(string num) {
    // Negative numbers
    long unsigned int i = 0;
    long unsigned int count = 0;
    if (num.at(0) == '-'){
        for (i = 1; i < num.size(); i++){
            if (num.at(i) == '0'){
                count += 1;
            }
    }
    if (count == num.size() - 1){
        return "0";
    }


    while (num.at(1) == '0'){
        num.erase(num.begin() + 1);
    }
        return num;    
    }

    // Positive numbers
    for (i = 0; i < num.size(); i++){
        if (num.at(i) == '0'){
            count += 1;
        }
    }
    if (count == num.size()){
        return "0";
    }


    while (num.at(0) == '0'){
        num.erase(num.begin());
    }
    return num;
}

string add(string lhs, string rhs) {
    if (lhs.at(0) == '-' && rhs.at(0) == '-'){
        lhs.erase(lhs.begin());
        rhs.erase(rhs.begin());
        lhs.insert(0,"0");
        rhs.insert(0,"0");

    while (lhs.size() < rhs.size()){
        lhs.insert(0,"0");
    }

    while (rhs.size() < lhs.size()){
        rhs.insert(0,"0");
    }
    long unsigned int i = 0;
    int sum = 0;
    int carry = 0;
    int ans = 0;
    char partStringAns;
    string stringAns;
    for (i = 1; i <= lhs.size(); i++){
        sum = digit_to_decimal(rhs.at(rhs.size() - i)) + digit_to_decimal(lhs.at(lhs.size() - i)) + carry;
        carry = sum/10;
        ans = sum % 10;
        partStringAns = decimal_to_digit(ans);
        stringAns.insert(stringAns.begin(), partStringAns);
    }
    stringAns.insert(stringAns.begin(), '-');
    return trim_leading_zeros(stringAns);
    }
    
    lhs.insert(0,"0");
    rhs.insert(0,"0");

    while (lhs.size() < rhs.size()){
        lhs.insert(0,"0");
    }

    while (rhs.size() < lhs.size()){
        rhs.insert(0,"0");
    }

    long unsigned int i = 0;
    int sum = 0;
    int carry = 0;
    int ans = 0;
    char partStringAns;
    string stringAns;
    for (i = 1; i <= lhs.size(); i++){
        sum = digit_to_decimal(rhs.at(rhs.size() - i)) + digit_to_decimal(lhs.at(lhs.size() - i)) + carry;
        carry = sum/10;
        ans = sum % 10;
        partStringAns = decimal_to_digit(ans);
        stringAns.insert(stringAns.begin(), partStringAns);
    }

    return trim_leading_zeros(stringAns);
}

string multiply(string lhs, string rhs) {
    if (lhs.at(0) == '-' && rhs.at(0) == '-'){
        lhs.erase(lhs.begin());
        rhs.erase(rhs.begin());
    
    long unsigned int totalSize = 0;
    totalSize = lhs.size() + rhs.size();
    while (lhs.size() < totalSize){
        lhs.insert(0,"0");
    }
    while (rhs.size() < totalSize){
        rhs.insert(0,"0");
    }

    long unsigned int i = 0;
    long unsigned int a = 0;
    int c = 0;
    int partialDigit = 0;
    int carry = 0;
    int ans = 0;
    char partStringAns;
    int count = 0;
    string finalAnswer = "0";
    for (i = 1; i <= rhs.size(); i++){
        string stringAns;
        count += 1;
        for (c = 1; c < count; c++){
            stringAns.insert(0,"0");
        }
        for (a = 1; a <= lhs.size(); a++){
            partialDigit = digit_to_decimal(rhs.at(rhs.size() - i)) * digit_to_decimal(lhs.at(lhs.size() - a)) + carry;
            carry = partialDigit / 10;
            ans = partialDigit % 10;
            partStringAns = decimal_to_digit(ans);
            stringAns.insert(stringAns.begin(), partStringAns);
        }
        finalAnswer = add(stringAns, finalAnswer);
        
    }
    return finalAnswer;
    }

    if (lhs.at(0) != '-' && rhs.at(0) == '-'){
        rhs.erase(rhs.begin());

    long unsigned int totalSize = 0;
    totalSize = lhs.size() + rhs.size();
    while (lhs.size() < totalSize){
        lhs.insert(0,"0");
    }
    while (rhs.size() < totalSize){
        rhs.insert(0,"0");
    }

    long unsigned int i = 0;
    long unsigned int a = 0;
    int c = 0;
    int partialDigit = 0;
    int carry = 0;
    int ans = 0;
    char partStringAns;
    int count = 0;
    string finalAnswer = "0";
    for (i = 1; i <= rhs.size(); i++){
        string stringAns;
        count += 1;
        for (c = 1; c < count; c++){
            stringAns.insert(0,"0");
        }
        for (a = 1; a <= lhs.size(); a++){
            partialDigit = digit_to_decimal(rhs.at(rhs.size() - i)) * digit_to_decimal(lhs.at(lhs.size() - a)) + carry;
            carry = partialDigit / 10;
            ans = partialDigit % 10;
            partStringAns = decimal_to_digit(ans);
            stringAns.insert(stringAns.begin(), partStringAns);
        }
        finalAnswer = add(stringAns, finalAnswer);
        
    }
    finalAnswer.insert(finalAnswer.begin(), '-');
    return finalAnswer;
    }

    if (lhs.at(0) == '-' && rhs.at(0) != '-'){
        lhs.erase(lhs.begin());

    long unsigned int totalSize = 0;
    totalSize = lhs.size() + rhs.size();
    while (lhs.size() < totalSize){
        lhs.insert(0,"0");
    }
    while (rhs.size() < totalSize){
        rhs.insert(0,"0");
    }

    long unsigned int i = 0;
    long unsigned int a = 0;
    int c = 0;
    int partialDigit = 0;
    int carry = 0;
    int ans = 0;
    char partStringAns;
    int count = 0;
    string finalAnswer = "0";
    for (i = 1; i <= rhs.size(); i++){
        string stringAns;
        count += 1;
        for (c = 1; c < count; c++){
            stringAns.insert(0,"0");
        }
        for (a = 1; a <= lhs.size(); a++){
            partialDigit = digit_to_decimal(rhs.at(rhs.size() - i)) * digit_to_decimal(lhs.at(lhs.size() - a)) + carry;
            carry = partialDigit / 10;
            ans = partialDigit % 10;
            partStringAns = decimal_to_digit(ans);
            stringAns.insert(stringAns.begin(), partStringAns);
        }
        finalAnswer = add(stringAns, finalAnswer);
        
    }
    finalAnswer.insert(finalAnswer.begin(), '-');
    return finalAnswer;
    }


    //This adds 0's to the front of both input strings
    long unsigned int totalSize = 0;
    totalSize = lhs.size() + rhs.size();
    while (lhs.size() < totalSize){
        lhs.insert(0,"0");
    }
    while (rhs.size() < totalSize){
        rhs.insert(0,"0");
    }

    long unsigned int i = 0;
    long unsigned int a = 0;
    int c = 0;
    int partialDigit = 0;
    int carry = 0;
    int ans = 0;
    char partStringAns;
    int count = 0;
    string finalAnswer = "0";
    for (i = 1; i <= rhs.size(); i++){
        string stringAns;
        count += 1;
        for (c = 1; c < count; c++){
            stringAns.insert(0,"0");
        }
        for (a = 1; a <= lhs.size(); a++){
            partialDigit = digit_to_decimal(rhs.at(rhs.size() - i)) * digit_to_decimal(lhs.at(lhs.size() - a)) + carry;
            carry = partialDigit / 10;
            ans = partialDigit % 10;
            partStringAns = decimal_to_digit(ans);
            stringAns.insert(stringAns.begin(), partStringAns);
        }
        finalAnswer = add(stringAns, finalAnswer);
        
    }

    return finalAnswer;
}
