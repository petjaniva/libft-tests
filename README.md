# libft-tests

Unit tests for 42-project libft. 

Done in 11/2021 and in Hive Helsinki. 

Tests use µnit C unit testing framework. https://nemequ.github.io/munit/# 

I don't think tests are particulary hard. And I will not promise that passing these tests means your library is perfect nor that failing these tests means your functions are wrong.

If you're using macOS or some other OS which has strlcat and strncat functions built-in use macOS branch. 

How-to:

1. Clone or copy folder to your the folder of your libft. For example your libft is in ~/libft then tests should be in ~/libft/tests/
2. Clone µnit to your tests-folder. If we continue our example the munit.c file should be in ~/libft/tests/munit/
3. Run compile_tests.sh. 
4. Now you should have separate .out files for easy, hard, lists and print tests. 
5. Run tests one by one and hopefully get lots of green. Print tests don't use the test framework, but taking a look in test_print.c should tell you what kind of output you're looking for.
