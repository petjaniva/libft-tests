for file in *.test; do
mv -- "$file" "${file%%.test}"
done
cd munit/
for file in *.test; do
mv -- "$file" "${file%%.test}"
done
cd ..
cd ..
make
make clean
cd tests/
gcc -o easy.out -Wall -Wextra -Werror test_easy.c ../libft.a munit/munit.c
gcc -o hard.out -Wall -Wextra -Werror test_hard.c ../libft.a munit/munit.c
gcc -o lists.out -Wall -Wextra -Werror test_lists.c ../libft.a munit/munit.c
gcc -o itoa.out -Wall -Wextra -Werror test_itoa.c ../libft.a munit/munit.c
gcc -o print.out -Wall -Wextra -Werror test_print.c ../libft.a munit/munit.c
