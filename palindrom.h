/*
 * palindrom.h
 *
 *  Креирано 19.10.2018.
 *      Аутор: Дамјан Гламочић RA65/2015
 */

#ifndef PALINDROM_H_
#define PALINDROM_H_

#include "singlyLinkedList.h"

#pragma CHECK_MISRA("none")
#include <assert.h>
#include <math.h>
#pragma CHECK_MISRA("1.2, 2.4, 3.1, 5.2, 6.1, 7.1, 8.5, 8.6, 16.2")

/* Фунцкија која провјерава да ли је број палиндромски у окталном бројном систему */
bool is_palindromic_number_octal(uint_least32_t n);

/* Фунцкија која провјерава да ли је број палиндромски у декадном бројном систему */
bool is_palindromic_number_decimal(uint_least32_t n);

/* Фунцкија која провјерава да ли је број палиндромски у хексадецималном бројном систему */
bool is_palindromic_number_hexadecimal(uint_least32_t n);

/* Функција која смјешта у листу све палиндромске бројеве мање од прослијеђеног */
void calculate_palindromic_numbers(Node* const head, uint_least32_t n, uint_fast8_t numeral_system);

#endif /* PALINDROM_H_ */
