@echo off
for /l %%x in (1, 1, 1000) do (
    zen %%x > int
    a < int > out1 
    tester < int > out2
    fc out1 out2 > testResult || exit /b
    echo %%x
)
echo all tests passed