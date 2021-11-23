/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:23:59 by pniva             #+#    #+#             */
/*   Updated: 2021/11/23 13:46:43 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "munit/munit.h"
#include "../libft.h"
#include <strings.h>
#include <ctype.h>

size_t strlcat(char *dst, const char *src, size_t siz);
char *strnstr(const char *s, const char *find, size_t slen);

static MunitResult	test_memset(const MunitParameter params[], void *data)
{
	void	*og_memset;
	void	*new_memset;
	(void)	params;
	(void)	data;

	og_memset = malloc(sizeof(char) * 6);
	new_memset = malloc(sizeof(char) * 6);
	memset(og_memset, '\0', 6);
	ft_memset(new_memset, '\0', 6);
	munit_assert_string_equal(og_memset, new_memset);
	return (MUNIT_OK);
}

static MunitResult	test_memset_under_malloc(const MunitParameter params[], void *data)
{
	void	*og_memset;
	void	*new_memset;
	(void)	params;
	(void)	data;

	og_memset = malloc(sizeof(char) * 3);
	new_memset = malloc(sizeof(char) * 3);
	memset(og_memset, '\0', 6);
	ft_memset(new_memset, '\0', 6);
	munit_assert_string_equal(og_memset, new_memset);
	return (MUNIT_OK);
}

static MunitResult test_bzero(const MunitParameter params[], void *data)
{
	void	*og_bzero;
	void	*new_bzero;
	(void)	params;
	(void)	data;
	
	og_bzero = malloc(sizeof(char) * 6);
	new_bzero = malloc(sizeof(char) * 6);
	bzero(og_bzero, 0);
	ft_bzero(new_bzero, 0);
	munit_assert_string_equal(og_bzero, new_bzero);
	return (MUNIT_OK);
}

static MunitResult test_memcpy(const MunitParameter params[], void *data)
{
	char	str[] = "abc\0efghi";
	void	*og_memcpy;
	void	*new_memcpy;
	(void)	params;
	(void)	data;

	og_memcpy = malloc(sizeof(char) * 10);
	new_memcpy = malloc(sizeof(char) * 10);
	memcpy(og_memcpy, str, 10);
	ft_memcpy(new_memcpy, str, 10);
	munit_assert_string_equal(new_memcpy, og_memcpy);
	return (MUNIT_OK);
}

static MunitResult test_memcpy_zero(const MunitParameter params[], void *data)
{
	char	str[] = "abc\0efghi";
	void	*og_memcpy;
	void	*new_memcpy;
	(void)	params;
	(void)	data;

	og_memcpy = malloc(sizeof(char) * 10);
	new_memcpy = malloc(sizeof(char) * 10);
	memcpy(og_memcpy, str, 0);
	ft_memcpy(new_memcpy, str, 0);
	munit_assert_string_equal(new_memcpy, og_memcpy);
	return (MUNIT_OK);
}


static MunitResult test_memccpy(const MunitParameter params[], void *data)
{
	char	str[] = "abcdefghi";
	void	*og_memccpy;
	void	*new_memccpy;
	void	*og_return;
	void	*new_return;
	(void)	params;
	(void)	data;
	
	og_memccpy = malloc(sizeof(char) * 10);
	new_memccpy = malloc(sizeof(char) * 10);
	og_return = memccpy(og_memccpy, str, 'c', 2);
	new_return = ft_memccpy(new_memccpy, str, 'c', 2);
	(void) og_return;
	(void) new_return;
	munit_assert_string_equal(new_memccpy, og_memccpy);
	return (MUNIT_OK);
}

static MunitResult test_memccpy_no_c(const MunitParameter params[], void *data)
{
	char	str[] = "abcdefghi";
	void	*og_memccpy;
	void	*new_memccpy;
	void	*og_return;
	void	*new_return;
	(void)	params;
	(void)	data;
	
	og_memccpy = malloc(sizeof(char) * 10);
	new_memccpy = malloc(sizeof(char) * 10);
	og_return = memccpy(og_memccpy, str, 'l', 10);
	new_return = ft_memccpy(new_memccpy, str, 'l', 10);
	(void) og_return;
	(void) new_return;
	munit_assert_string_equal(new_memccpy, og_memccpy);
	return (MUNIT_OK);
}


static MunitResult test_memmove(const MunitParameter params[], void *data)
{
	char	str[] = "ab\0fghi";
	void	*og_memmove;
	void	*new_memmove;
	(void)	params;
	(void)	data;

	og_memmove = malloc(sizeof(char) * 10);
	new_memmove = malloc(sizeof(char) * 10);
	memmove(og_memmove, str, 5);
	ft_memmove(new_memmove, str, 5);
	munit_assert_string_equal(og_memmove, new_memmove);
	return (MUNIT_OK);
}

static MunitResult test_memmove_overlap(const MunitParameter params[], void *data)
{
	void	*og_memmove;
	void	*new_memmove;
	(void)	params;
	(void)	data;

	og_memmove = malloc(sizeof(char) * 10);
	new_memmove = malloc(sizeof(char) * 10);
	memset(og_memmove, 'a', 10);
	memset(new_memmove, 'a', 10);
	memmove(og_memmove, (og_memmove + 3), 5);
	ft_memmove(new_memmove, (new_memmove +3), 5);
	munit_assert_string_equal(og_memmove, new_memmove);
	return (MUNIT_OK);
}

static MunitResult test_memmove_underlap(const MunitParameter params[], void *data)
{
	void	*og_memmove;
	void	*new_memmove;
	(void)	params;
	(void)	data;

	og_memmove = malloc(sizeof(char) * 10);
	new_memmove = malloc(sizeof(char) * 10);
	memset(og_memmove, 'a', 10);
	memset(new_memmove, 'a', 10);
	memmove((og_memmove + 3), og_memmove, 5);
	ft_memmove((new_memmove + 3), new_memmove, 5);
	munit_assert_string_equal(og_memmove, new_memmove);
	return (MUNIT_OK);
}


static MunitResult test_memchr(const MunitParameter params[], void *data)
{
	char	str[] = "Hopsuhoplaa";
	void	*og_return;
	void	*new_return;
	(void)	params;
	(void)	data;

	og_return = memchr(str, 'f', 32);
	new_return = ft_memchr(str, 'f', 32);
	munit_assert_ptr_equal(og_return, new_return);
	return (MUNIT_OK);
}

static MunitResult test_memchr_last_c(const MunitParameter params[], void *data)
{
	char	str[] = "Test _Word";
	void	*og_return;
	void	*new_return;
	(void)	params;
	(void)	data;

	og_return = memchr(str, 'd', 10);
	new_return = ft_memchr(str, 'd', 10);
	munit_assert_ptr_equal(og_return, new_return);
	return (MUNIT_OK);
}

static MunitResult test_memchr_zero(const MunitParameter params[], void *data)
{
	char	str[] = "Test _Word";
	void	*og_return;
	void	*new_return;
	(void)	params;
	(void)	data;

	og_return = memchr(str, 'd', 0);
	new_return = ft_memchr(str, 'd', 0);
	munit_assert_ptr_equal(og_return, new_return);
	return (MUNIT_OK);
}

static MunitResult test_memcmp(const MunitParameter params[], void *data)
{
	char	str1[] = "Hehehe";
	char	str2[] = "Heheh";
	char	str3[] = "H\0ha";
	char	str4[] = "H\0hb";
	int		og_return1;
	int		og_return2;
	int		new_return1;
	int		new_return2;
	(void)	params;
	(void)	data;

	og_return1 = memcmp(str1, str2, 6);
	og_return2 = memcmp(str3, str4, 4);
	new_return1 = ft_memcmp(str1, str2, 6);
	new_return2 = ft_memcmp(str3, str4, 4);
	munit_assert_int(og_return1, >, 0);
	munit_assert_int(new_return1, >, 0);
	munit_assert_int(og_return2, <, 0);
	munit_assert_int(new_return2, <, 0);
	return (MUNIT_OK);
}

static MunitResult test_strlen(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str1[] = "Heh\0ehe";
	char	str2[] = " H ";
	int		og_return1;
	int		og_return2;
	int		new_return1;
	int		new_return2;

	og_return1 = strlen(str1);
	og_return2 = strlen(str2);
	new_return1 = ft_strlen(str1);
	new_return2 = ft_strlen(str2);
	munit_assert_int(og_return1, ==, new_return1);
	munit_assert_int(og_return2, ==, new_return2);
	return (MUNIT_OK);
}

static MunitResult test_strdup_middle_null(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "abc\0def";
	void	*og_return;
	void	*new_return;

	og_return = strdup(str);
	new_return = ft_strdup(str);
	munit_assert_string_equal(og_return, new_return);
	return (MUNIT_OK);
}

static MunitResult test_strcpy(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "ab\0cdef";
	void	*og_strcpy;
	void	*new_strcpy;

	og_strcpy = malloc(sizeof(*og_strcpy) * 7);
	new_strcpy = malloc(sizeof(*new_strcpy) * 7);
	strcpy(og_strcpy, str);
	ft_strcpy(new_strcpy, str);
	munit_assert_string_equal(og_strcpy, new_strcpy);
	return (MUNIT_OK);
}

static MunitResult test_strncpy(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "abcd\0ef";
	void	*og_strncpy;
	void	*new_strncpy;

	og_strncpy = malloc(sizeof(*og_strncpy) * 7);
	new_strncpy = malloc(sizeof(*new_strncpy) * 7);
	strncpy(og_strncpy, str, 5);
	ft_strncpy(new_strncpy, str, 5);
	munit_assert_string_equal(og_strncpy, new_strncpy);
	return (MUNIT_OK);
}

static MunitResult test_strncpy_one(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "abcd\0ef";
	void	*og_strncpy;
	void	*new_strncpy;

	og_strncpy = malloc(sizeof(*og_strncpy) * 7);
	new_strncpy = malloc(sizeof(*new_strncpy) * 7);
	strncpy(og_strncpy, str, 1);
	ft_strncpy(new_strncpy, str, 1);
	munit_assert_string_equal(og_strncpy, new_strncpy);
	return (MUNIT_OK);
}

static MunitResult test_strcat(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	*og_dst;
	char	*new_dst;

	og_dst = malloc(sizeof(*og_dst) * 11);
	new_dst = malloc(sizeof(*new_dst) * 1);
	memset(og_dst, 'a', 4);
	memset(new_dst, 'a', 4);
	strcat(og_dst, src);
	ft_strcat(new_dst, src);
	munit_assert_string_equal(og_dst, new_dst);
	return (MUNIT_OK);
}

static MunitResult test_strncat(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	*og_dst;
	char	*new_dst;

	og_dst = malloc(sizeof(*og_dst) * 11);
	new_dst = malloc(sizeof(*new_dst) * 11);
	memset(og_dst, 0, 11);
	memset(new_dst, 0, 11);
	memset(og_dst, 'a', 4);
	memset(new_dst, 'a', 4);
	strncat(og_dst, src, 3);
	ft_strncat(new_dst, src, 3);
	munit_assert_string_equal(og_dst, new_dst);
	return (MUNIT_OK);
}

static MunitResult test_strlcat(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	*og_dst;
	char	*new_dst;

	og_dst = malloc(sizeof(*og_dst) * 11);
	new_dst = malloc(sizeof(*new_dst) * 11);
	memset(og_dst, 0, 11);
	memset(new_dst, 0, 11);
	memset(og_dst, 'a', 4);
	memset(new_dst, 'a', 4);
	strlcat(og_dst, src, 6);
	ft_strlcat(new_dst, src, 6);
	munit_assert_string_equal(og_dst, new_dst);
	return (MUNIT_OK);
}

static MunitResult test_strchr(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "is\0good";
	char	*og_ptr;
	char	*new_ptr;

	og_ptr = strchr(src, 'g');
	new_ptr = ft_strchr(src, 'g');
	munit_assert_ptr_equal(og_ptr, new_ptr);
	return (MUNIT_OK);
}

static MunitResult test_strrchr(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	*og_ptr;
	char	*new_ptr;

	og_ptr = strrchr(src, 'f');
	new_ptr = ft_strrchr(src, 'f');
	munit_assert_ptr_equal(og_ptr, new_ptr);
	return (MUNIT_OK);
}

static MunitResult test_strstr(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	needle[] ="isgoodier";
	char	*og_ptr;
	char	*new_ptr;

	og_ptr = strstr(src, needle);
	new_ptr = ft_strstr(src, needle);
	munit_assert_ptr_equal(og_ptr, new_ptr);
	return (MUNIT_OK);
}

static MunitResult test_strnstr(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	needle[] ="ood";
	char	*og_ptr;
	char	*new_ptr;

	og_ptr = strnstr(src, needle, 3);
	new_ptr = ft_strnstr(src, needle, 3);
	munit_assert_ptr_equal(og_ptr, new_ptr);
	return (MUNIT_OK);
}

static MunitResult test_strcmp(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	needle[] ="good";
	int		og_ret;
	int		new_ret;

	og_ret = strcmp(src, needle);
	new_ret = ft_strcmp(src, needle);
	munit_assert_int(og_ret, ==, new_ret);
	return (MUNIT_OK);
}

static MunitResult test_strncmp(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "isgood";
	char	needle[] ="isgouda";
	int		og_ret;
	int		new_ret;

	og_ret = strncmp(src, needle, 4);
	new_ret = ft_strncmp(src, needle, 4);
	munit_assert_int(og_ret, ==, new_ret);
	return (MUNIT_OK);
}


static MunitResult test_atoi(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = " aa 12ff  34";
	int		og_ret;
	int		new_ret;

	og_ret = atoi(src);
	new_ret = ft_atoi(src);
	munit_assert_int(og_ret, ==, new_ret);
	return (MUNIT_OK);
}

static MunitResult test_atoi_neg_plus(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = " aa -+1234  ";
	int		og_ret;
	int		new_ret;

	og_ret = atoi(src);
	new_ret = ft_atoi(src);
	munit_assert_int(og_ret, ==, new_ret);
	return (MUNIT_OK);
}

static MunitResult test_atoi_plus_spaces(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "+   1234  ";
	int		og_ret;
	int		new_ret;

	og_ret = atoi(src);
	new_ret = ft_atoi(src);
	munit_assert_int(og_ret, ==, new_ret);
	return (MUNIT_OK);
}

static MunitResult test_atoi_plus_neg(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	src[] = "+-1234  ";
	int		og_ret;
	int		new_ret;

	og_ret = atoi(src);
	new_ret = ft_atoi(src);
	munit_assert_int(og_ret, ==, new_ret);
	return (MUNIT_OK);
}

static MunitResult test_atoi_null(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*src = NULL;
	int		og_ret;
	int		new_ret;

	og_ret = atoi(src);
	new_ret = ft_atoi(src);
	munit_assert_int(og_ret, ==, new_ret);
	return (MUNIT_OK);
}


static MunitResult test_strnew(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(8);
	while (i < 8)
	{
		munit_assert_char('\0', ==, str[i]);
		++i;
	}
	return (MUNIT_OK);
}

static MunitResult test_strdel(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*to_delete;
	
	to_delete = ft_strdup("aa\0");
	ft_strdel(&to_delete);
	munit_assert_ptr_equal(0, to_delete);
	return (MUNIT_OK);
}

static MunitResult test_strclr(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(8);
	while (i < 8)
	{
		munit_assert_char('\0', ==, str[i]);
		++i;
	}
	return (MUNIT_OK);
}

static void striter_helper(char *c)
{
	*c = 'b';
}

static MunitResult test_striter(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "aa\0aa";
	ft_striter(str, &striter_helper);
	munit_assert_string_equal("bb", str);

	return (MUNIT_OK);
}

static void striteri_helper(unsigned int i, char *c)
{
	if (i == 1)
	{
		*c = 'b';
	}
}

static MunitResult test_striteri(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "aa\0a";
	ft_striteri(str, &striteri_helper);
	munit_assert_string_equal("ab", str);

	return (MUNIT_OK);
}

static char strmap_helper(char c)
{
	if (c)
	{
		return ('b');
	}
	return ('c');
}

static MunitResult test_strmap(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "aa\0aa";
	char	*str2;
	
	str2 = ft_strmap(str, &strmap_helper);
	munit_assert_string_equal("aa", str);
	munit_assert_string_equal("bb", str2);
	return (MUNIT_OK);
}

static char strmapi_helper(unsigned int i, char c)
{
	if (i == 1)
	{
		return ('b');
	}
	return (c);
}

static MunitResult test_strmapi(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "aaaa";
	char	*str2;
	
	str2 = ft_strmapi(str, &strmapi_helper);
	munit_assert_string_equal("aaaa", str);
	munit_assert_string_equal("abaa", str2);
	return (MUNIT_OK);
}

static MunitResult test_strequ(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "aaaa";
	char	str2[] = "aaa\0";
	int		i;

	i = ft_strequ(str, str2);
	munit_assert_int(i, !=, 1);
	return (MUNIT_OK);
}

static MunitResult test_strnequ(const MunitParameter params[], void *data){
	(void)	params;
	(void)	data;
	char	str[] = "aaaa";
	char	str2[] = "aaab";
	int		i;

	i = ft_strnequ(str, str2, 3);
	munit_assert_int(i, ==, 1);
	return (MUNIT_OK);
}

static MunitResult test_strsub(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "hello";
	char	*res;
	
	res = ft_strsub(str, 0, 3);
	munit_assert_string_equal("hel", res);
	return (MUNIT_OK);
}

static MunitResult test_strjoin(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "hello";
	char	str2[] = "again";
	char	*res;
	
	res = ft_strjoin(str, str2);
	munit_assert_string_equal("helloagain", res);
	return (MUNIT_OK);
}

static MunitResult test_strtrim(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = " \the\tllo\n ";
	char	*res;
	
	res = ft_strtrim(str);
	munit_assert_string_equal("he\tllo", res);
	return (MUNIT_OK);
}

static MunitResult test_strsplit(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	str[] = "hello    again \nfriend";
	char	**res;
	
	res = ft_strsplit(str, ' ');
	munit_assert_string_equal(res[0], "hello");
	munit_assert_string_equal(res[1], "again");
	munit_assert_string_equal(res[2], "\nfriend");
	return (MUNIT_OK);
}

static MunitTest test_suite_tests[] =
{
	{(char *) "/memset", test_memset,0,	0, 0, 0},
	{(char *) "/memset/under_malloc", test_memset_under_malloc,0,	0, 0, 0},
	{(char *) "/bzero",	test_bzero,	0, 0,0,	0},
	{(char *) "/memcpy", test_memcpy, 0, 0, 0, 0},
	{(char *) "/memcpy/zero", test_memcpy_zero, 0, 0, 0, 0},
	{(char *) "/memccpy", test_memccpy, 0, 0, 0, 0},
	{(char *) "/memccpy/no_c", test_memccpy_no_c, 0, 0, 0, 0},
	{(char *) "/memmove", test_memmove,	0, 0, 0, 0},
	{(char *) "/memmove/overlap", test_memmove_overlap,	0, 0, 0, 0},
	{(char *) "/memmove/underlap", test_memmove_underlap, 0, 0, 0, 0},
	{(char *) "/memchr", test_memchr, 0, 0, 0, 0},
	{(char *) "/memchr/last_c", test_memchr_last_c, 0, 0, 0, 0},
	{(char *) "/memchr/zero", test_memchr_zero, 0, 0, 0, 0},
	{(char *) "/memcmp", test_memcmp, 0, 0, 0, 0},
	{(char *) "/strlen", test_strlen, 0, 0, 0, 0},
	{(char *) "/strdup/middle_null", test_strdup_middle_null, 0, 0, 0, 0},
	{(char *) "/strcpy", test_strcpy, 0, 0, 0, 0},
	{(char *) "/strncpy", test_strncpy, 0, 0, 0, 0},
	{(char *) "/strncpy/one", test_strncpy_one, 0, 0, 0, 0},
	{(char *) "/strcat", test_strcat, 0, 0, 0, 0},
	{(char *) "/strncat", test_strncat, 0, 0, 0, 0},
	{(char *) "/strlcat", test_strlcat, 0, 0, 0, 0},
	{(char *) "/strchr", test_strchr, 0, 0, 0, 0},
	{(char *) "/strrchr", test_strrchr, 0, 0, 0, 0},
	{(char *) "/strstr", test_strstr, 0, 0, 0, 0},
	{(char *) "/strnstr", test_strnstr, 0, 0, 0, 0},
	{(char *) "/strcmp", test_strcmp, 0, 0, 0, 0},
	{(char *) "/strncmp", test_strncmp, 0, 0, 0, 0},
	{(char *) "/atoi", test_atoi, 0, 0, 0, 0},
	{(char *) "/atoi/neg_plus", test_atoi_neg_plus, 0, 0, 0, 0},
	{(char *) "/atoi/plus_spaces", test_atoi_plus_spaces, 0, 0, 0, 0},
	{(char *) "/atoi/plus_neg", test_atoi_plus_neg, 0, 0, 0, 0},
	{(char *) "/atoi/null", test_atoi_null, 0, 0, 0, 0},
	{(char *) "/strnew", test_strnew, 0, 0, 0, 0},
	{(char *) "/strdel", test_strdel, 0, 0, 0, 0},
	{(char *) "/strclr", test_strclr, 0, 0, 0, 0},
	{(char *) "/striter", test_striter, 0, 0, 0, 0},
	{(char *) "/striteri", test_striteri, 0, 0, 0, 0},
	{(char *) "/strmap", test_strmap, 0, 0, 0, 0},
	{(char *) "/strmapi", test_strmapi, 0, 0, 0, 0},
	{(char *) "/strequ", test_strequ, 0, 0, 0, 0},
	{(char *) "/strnequ", test_strnequ, 0, 0, 0, 0},
	{(char *) "/strsub", test_strsub, 0, 0, 0, 0},
	{(char *) "/strjoin", test_strjoin, 0, 0, 0, 0},
	{(char *) "/strtrim", test_strtrim, 0, 0, 0, 0},
	{(char *) "/strsplit", test_strsplit, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

static const MunitSuite test_suite =
{
	(char *) "",
	test_suite_tests,
	0,
	1,
	0
};

int	main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return munit_suite_main(&test_suite, (void *) "munit", argc, argv);
}
