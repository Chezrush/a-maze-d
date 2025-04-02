#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int my_printf(char const *format, ...);

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, empty_string, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, simple_string_with_flag_d, .init = redirect_all_std)
{
    my_printf("I need %d", 42);
    cr_assert_stdout_eq_str("I need 42");
}

Test(my_printf, simple_string_with_flag_c, .init = redirect_all_std)
{
    my_printf("I need %c", 'c');
    cr_assert_stdout_eq_str("I need c");
}

Test(my_printf, simple_string_with_flag_i, .init = redirect_all_std)
{
    my_printf("I need %i", 42);
    cr_assert_stdout_eq_str("I need 42");
}

Test(my_printf, simple_string_with_flag_s, .init = redirect_all_std)
{
    my_printf("I need %s", "a str");
    cr_assert_stdout_eq_str("I need a str");
}

Test(my_printf, simple_string_with_flag_pourcentage, .init = redirect_all_std)
{
    my_printf("I need %%");
    cr_assert_stdout_eq_str("I need %");
}

Test(my_printf, simple_string_with_flag_neg_value, .init = redirect_all_std)
{
    my_printf("I need %d", -21474);
    cr_assert_stdout_eq_str("I need -21474");
}

Test(my_printf, simple_string_with_flag_min_size_of_int, .init = redirect_all_std)
{
    my_printf("I need %d", 2147483647);
    cr_assert_stdout_eq_str("I need 2147483647");
}

Test(my_printf, output_return_len, .init = redirect_all_std)
{
    cr_assert_eq(my_printf("abcdefghijklmnopqrstuvwxyz"), 26);
}

Test(my_printf, simple_string_with_flag_u, .init = redirect_all_std)
{
    my_printf("I need %u", 314);
    cr_assert_stdout_eq_str("I need 314");
}

// Test(my_printf, simple_string_with_flag_o, .init = redirect_all_std)
// {
//     my_printf("I need %o", 255);
//     cr_assert_stdout_eq_str("I need 377");
// }

// Test(my_printf, simple_string_with_flag_e, .init = redirect_all_std)
// {
//     my_printf("I need %e", 123.456);
//     cr_assert_stdout_eq_str("I need 1.234560e+02");
// }

// Test(my_printf, simple_string_with_flag_E, .init = redirect_all_std)
// {
//     my_printf("I need %E", 123.456);
//     cr_assert_stdout_eq_str("I need 1.234560E+02");
// }

// Test(my_printf, simple_string_with_flag_f, .init = redirect_all_std)
// {
//     my_printf("I need %f", 123.456);
//     cr_assert_stdout_eq_str("I need 123.456000");
// }

// Test(my_printf, simple_string_with_flag_F, .init = redirect_all_std)
// {
//     my_printf("I need %F", 123.456);
//     cr_assert_stdout_eq_str("I need 123.456000");
// }

// Test(my_printf, simple_string_with_flag_b, .init = redirect_all_std)
// {
//     my_printf("I need %b", 5);
//     cr_assert_stdout_eq_str("I need 101");
// }

// Test(my_printf, simple_string_with_flag_B, .init = redirect_all_std)
// {
//     my_printf("I need %B", 5);
//     cr_assert_stdout_eq_str("I need 101");
// }

// Test(my_printf, simple_string_with_flag_p, .init = redirect_all_std)
// {
//     int x = 42;
//     my_printf("I need %p", (void *)&x);
//     cr_assert_stdout_eq_str("I need " /* add expected pointer format here */);
// }

// Test(my_printf, simple_string_with_flag_P, .init = redirect_all_std)
// {
//     int x = 42;
//     my_printf("I need %P", (void *)&x);
//     cr_assert_stdout_eq_str("I need " /* add expected pointer format here */);
// }

// Test(my_printf, simple_string_with_flag_x, .init = redirect_all_std)
// {
//     my_printf("I need %x", 255);
//     cr_assert_stdout_eq_str("I need ff");
// }

// Test(my_printf, simple_string_with_flag_X, .init = redirect_all_std)
// {
//     my_printf("I need %X", 255);
//     cr_assert_stdout_eq_str("I need FF");
// }
