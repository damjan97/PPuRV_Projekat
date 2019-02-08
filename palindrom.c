/*
 * palindrom.c
 *
 *  Креирано 19.10.2018.
 *      Аутор: Дамјан Гламочић RA65/2015
 */

#include "palindrom.h"

/*
 * Низ показивача на функције које провјеравају да ли је број палиндромски у
 * окталном, декадном, односно хексадецималном бројном систему
 **/
static bool (*is_palindromic_number_functions[3])(uint_least32_t n) =
	{ &is_palindromic_number_octal, &is_palindromic_number_decimal, &is_palindromic_number_hexadecimal };

bool is_palindromic_number_octal(uint_least32_t n)
{
	/*
	 *  За број, за који се провјерава да ли је палиндромски, нађе се број који има исте цифре,
	 *  али у обрнутом редослиједу, и врши се провјера да ли су ти бројеви исти
	 * */

	uint_least32_t reversed_number_octal = (uint_least32_t) 0;
	uint_least32_t tmp_number_octal = n;
	uint_least32_t remainder_octal;

	while (tmp_number_octal != (uint_least32_t) 0)
	{
		/* remainder_hexadecimal = tmp_number_octal % 8 */
		remainder_octal = tmp_number_octal & (uint_least32_t) 7;

		/* reversed_number_octal = reversed_number_octal * 8 + remainder_hexadecimal */
		reversed_number_octal = (reversed_number_octal << (uint_least32_t) 3) + remainder_octal;

		/* tmp_number_octal /= 8 */
		tmp_number_octal >>= (uint_least32_t) 3;
	}

	/* Провјерава да ли су једнаки; ако јесу враћа тачно, ако нису враћа нетачно  */
	return (n ^ reversed_number_octal) ? false : true;
}

bool is_palindromic_number_decimal(uint_least32_t n)
{
	/*
	 *  За број, за који се провјерава да ли је палиндромски, нађе се број који има исте цифре,
	 *  али у обрнутом редослиједу, и врши се провјера да ли су ти бројеви исти
	 * */

	uint_least32_t reversed_number_decimal = (uint_least32_t) 0;
	uint_least32_t tmp_number_decimal = n;
	uint_least32_t remainder_decimal;

	while (tmp_number_decimal != (uint_least32_t) 0)
	{
		remainder_decimal = tmp_number_decimal % (uint_least32_t) 10;
		reversed_number_decimal = (reversed_number_decimal * (uint_least32_t) 10) + remainder_decimal;
		tmp_number_decimal /= (uint_least32_t) 10;
	}

	/* Провјерава да ли су једнаки; ако јесу враћа тачно, ако нису враћа нетачно  */
	return (n ^ reversed_number_decimal) ? false : true;
}

bool is_palindromic_number_hexadecimal(uint_least32_t n)
{
	/*
	 *  За број, за који се провјерава да ли је палиндромски, нађе се број који има исте цифре,
	 *  али у обрнутом редослиједу, и врши се провјера да ли су ти бројеви исти
	 * */

	uint_least32_t reversed_number_hexadecimal = (uint_least32_t) 0;
	uint_least32_t tmp_number_hexadecimal = n;
	uint_least32_t remainder_hexadecimal;

	while (tmp_number_hexadecimal != (uint_least32_t) 0)
	{
		/* remainder_hexadecimal = tmp_number_hexadecimal % 16 */
		remainder_hexadecimal = tmp_number_hexadecimal & (uint_least32_t) 15;

		/* reversed_number_hexadecimal = reversed_number_hexadecimal * 16 + remainder_hexadecimal */
		reversed_number_hexadecimal = (reversed_number_hexadecimal << (uint_least32_t) 4) + remainder_hexadecimal;

		/* tmp_number_hexadecimal /= 16 */
		tmp_number_hexadecimal >>= (uint_least32_t) 4;
	}

	/* Провјерава да ли су једнаки; ако јесу враћа тачно, ако нису враћа нетачно  */
	return (n ^ reversed_number_hexadecimal) ? false : true;
}

void calculate_palindromic_numbers(Node* const head, uint_least32_t n, uint_fast8_t numeral_system)
{

	/* Програм ради само ако је  numeral_system = 1, 2, или 3 (октални, декадни или хексадецимални бројни систем) */
	assert((numeral_system == (uint_fast8_t )1) || (numeral_system == (uint_fast8_t )2) || (numeral_system == (uint_fast8_t )3));

	if (n == (uint_least32_t) 0)
	{
		return;
	}

	uint_least32_t iterator;

	/* Треба нам посљедњи пронађени палиндром; не желимо да понављамо провјеру за бројеве које смо већ открили; фор петља креће од тог броја */
	uint_least32_t start = get_last(head);

	for (iterator = start + (uint_least32_t) 1; iterator < n; iterator++)
	{

		/* Ако је палиндромски број, убаци га на крај листе */
		if (is_palindromic_number_functions[numeral_system - (uint_least32_t) 1](iterator))
		{
			push_end(head, iterator);
		}
	}

	print_list_to_number(head, n);

}
