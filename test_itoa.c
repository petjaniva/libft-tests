/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:23:59 by pniva             #+#    #+#             */
/*   Updated: 2021/11/23 13:46:59 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "munit/munit.h"
#include "../libft.h"
#include <strings.h>
#include <ctype.h>
#include <limits.h>



static MunitResult	test_itoa_max(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*res;

	res = ft_itoa(INT_MAX);
	munit_assert_string_equal(res, "2147483647");
	return (MUNIT_OK);
}

static MunitResult	test_itoa_min(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*res;

	res = ft_itoa(INT_MIN);
	munit_assert_string_equal(res, "-2147483648");
	return (MUNIT_OK);
}

static MunitResult	test_itoa_neg_zero(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*res;

	res = ft_itoa(-0);
	munit_assert_string_equal(res, "0");
	return (MUNIT_OK);
}

static MunitResult	test_itoa_num_and_let(const MunitParameter params[], void *data)
{
	(void)	params;
	(void)	data;
	char	*res;

	res = ft_itoa(-1230ll);
	munit_assert_string_equal(res, "-1230");
	return (MUNIT_OK);
}




static MunitTest test_suite_tests[] =
{
	{(char *) "/itoa/max", test_itoa_max, 0, 0, 0, 0},
	{(char *) "/itoa/min", test_itoa_min, 0, 0, 0, 0},
	{(char *) "/itoa/neg_zero", test_itoa_neg_zero, 0, 0, 0, 0},
	{(char *) "/itoa/num_and_let", test_itoa_num_and_let, 0, 0, 0, 0},
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
