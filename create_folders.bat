@echo off
setlocal enabledelayedexpansion

:: Define the problems (Topic, Problem Name, Language)
set problems[0]=Sliding_Window,Longest Substring Without Repeating Characters,C++
set problems[1]=Dynamic_Programming,Generate Parentheses,C++
set problems[2]=Dynamic_Programming,Edit Distance,Java
set problems[3]=Array,Combination Sum,Java
set problems[4]=Array,Maximum Subarray,Java
set problems[5]=Array,Search a 2D Matrix,Java
set problems[6]=Hash_Table,Repeated DNA Sequences,C++
set problems[7]=Array,Rotate Array,Java
set problems[8]=Array,Minimum Size Subarray Sum,C++
set problems[9]=Array,Product of Array Except Self,C++
set problems[10]=Array,Range Sum Query 2D - Immutable,C++
set problems[11]=Hash_Table,Longest Repeating Character Replacement,C++
set problems[12]=Hash_Table,Find All Anagrams in a String,C++
set problems[13]=Array,Subarray Sum Equals K,C++
set problems[14]=Hash_Table,Permutation in String,C++
set problems[15]=Two_Pointers,Palindromic Substrings,Java
set problems[16]=Array,Find K Closest Elements,C++
set problems[17]=Array,Subarray Product Less Than K,C++
set problems[18]=Array,Fruit Into Baskets,C++
set problems[19]=Array,Sort an Array,Java
set problems[20]=Array,Binary Subarrays With Sum,C++
set problems[21]=Array,Max Consecutive Ones III,C++
set problems[22]=Array,XOR Queries of a Subarray,C++
set problems[23]=Array,Number of Sub-arrays With Odd Sum,C++
set problems[24]=Array,Make Sum Divisible by P,C++
set problems[25]=Array,Maximum Sum of Distinct Subarrays With Length K,C++
set problems[26]=Array,Divide Players Into Teams of Equal Skill,C++
set problems[27]=Array,Count Mentions Per User,C++

:: Loop through the problems
for /L %%i in (0,1,27) do (
    set "problem=!problems[%%i]!"
    
    :: Extract the topic, problem name, and language
    for /f "tokens=1,2,3 delims=," %%a in ("!problem!") do (
        set "topic=%%a"
        set "problem_name=%%b"
        set "language=%%c"
        
        :: Create the topic folder if it doesn't exist
        if not exist "!topic!" (
            mkdir "!topic!"
        )
        
        :: Create the file name based on the problem name and language
        set "file_name=!problem_name: =_!.!language:~0,3!"
        
        :: Create the file with the appropriate extension
        if "!language!"=="C++" (
            set "file_extension=cpp"
        ) else if "!language!"=="Java" (
            set "file_extension=java"
        )
        
        :: Create the file and write some initial content
        echo // Solution for !problem_name! in !language! > "!topic!\!file_name!.!file_extension!"
        echo // This file contains the code for the problem: !problem_name! >> "!topic!\!file_name!.!file_extension!"
        echo // Topic: !topic! >> "!topic!\!file_name!.!file_extension!"
        echo // Language: !language! >> "!topic!\!file_name!.!file_extension!"
        echo. >> "!topic!\!file_name!.!file_extension!"
        echo // Your code here... >> "!topic!\!file_name!.!file_extension!"
    )
)

echo Folders and files have been created.
pause
