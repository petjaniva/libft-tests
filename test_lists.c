#include "munit/munit.h"
#include "../libft.h"
#include <strings.h>
#include <ctype.h>

static MunitResult test_lstnew(const MunitParameter params[], void *data)
{
	t_list *new_elem;
	char	*str;
	(void)	params;
	(void)	data;

	str = ft_strdup("hello");
	new_elem = ft_lstnew(str, ft_strlen(str));
	munit_assert_string_equal(str, new_elem->content);
	return (MUNIT_OK);
}

static void del(void *cont, size_t cont_size)
{
	(void) cont_size;
	free(cont);
	cont = NULL;
}

static MunitResult test_lstdelone(const MunitParameter params[], void *data)
{
	t_list *new_elem;
	char	*str;
	(void)	params;
	(void)	data;

	str = ft_strdup("hello");
	new_elem = ft_lstnew(str, ft_strlen(str));
	ft_lstdelone(&new_elem, &del);
	munit_assert_null(new_elem);
	return (MUNIT_OK);
}

static MunitResult test_lstdel(const MunitParameter params[], void *data)
{
	t_list	*new_elem;
	t_list	*another_elem;
	char	*str;
	(void)	params;
	(void)	data;

	str = ft_strdup("hello");
	new_elem = ft_lstnew(str, ft_strlen(str));
	another_elem = ft_lstnew(str, ft_strlen(str));
	new_elem->next = another_elem;
	ft_lstdel(&new_elem, &del);
	munit_assert_null(new_elem);
	return (MUNIT_OK);
}

static MunitResult test_lstadd(const MunitParameter params[], void *data)
{
	t_list	*first_elem;
	t_list	*second_elem;
	char	*str;
	char	*str2;
	(void)	params;
	(void)	data;

	str = ft_strdup("hello");
	str2 = ft_strdup("hi");
	first_elem = ft_lstnew(str, ft_strlen(str));
	second_elem = ft_lstnew(str2, ft_strlen(str2));
	ft_lstadd(&first_elem, second_elem);
	munit_assert_string_equal(str2, first_elem->content);
	munit_assert_string_equal(str, first_elem->next->content);
	return (MUNIT_OK);
}


static void test_lstiter_helper(t_list *elem)
{
	int i;

	i = 0;

	while(((char*)elem->content)[i])
	{
		((char*)elem->content)[i] = ft_toupper(((char*)elem->content)[i]);
		++i;
	}
}

static MunitResult test_lstiter(const MunitParameter params[], void *data)
{
	t_list	*first_elem;
	t_list	*second_elem;
	char	*str;
	char	*str2;
	(void)	params;
	(void)	data;

	str = ft_strdup("hello");
	str2 = ft_strdup("hi");
	first_elem = ft_lstnew(str, ft_strlen(str));
	second_elem = ft_lstnew(str2, ft_strlen(str2));
	first_elem->next = second_elem;
	ft_lstiter(first_elem, &test_lstiter_helper);
	munit_assert_string_equal("HI", second_elem->content);
	return (MUNIT_OK);
}

static t_list *test_lstmap_helper(t_list *elem)
{
	t_list *new_elem;

	new_elem = ft_lstnew(elem->content, elem->content_size);
	return (new_elem);
}

static MunitResult test_lstmap(const MunitParameter params[], void *data)
{
	t_list	*first_elem;
	t_list	*second_elem;
	t_list	*new_head;
	char	*str;
	char	*str2;
	(void)	params;
	(void)	data;

	str = ft_strdup("hello");
	str2 = ft_strdup("hi");
	first_elem = ft_lstnew(str, ft_strlen(str));
	second_elem = ft_lstnew(str2, ft_strlen(str2));
	first_elem->next = second_elem;
	new_head = ft_lstmap(first_elem, &test_lstmap_helper);
	munit_assert_ptr_not_equal(first_elem, new_head);
	munit_assert_string_equal(second_elem->content, new_head->next->content);
	return (MUNIT_OK);
}


static MunitTest test_suite_tests[] =
{
	{(char *) "/lstnew", test_lstnew, 0, 0, 0, 0},
	{(char *) "/lstdelone", test_lstdelone, 0, 0, 0, 0},
	{(char *) "/lstdel", test_lstdel, 0, 0, 0, 0},
	{(char *) "/lstadd", test_lstadd, 0, 0, 0, 0},
	{(char *) "/lstiter", test_lstiter, 0, 0, 0, 0},
	{(char *) "/lstmap", test_lstmap, 0, 0, 0, 0},
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
