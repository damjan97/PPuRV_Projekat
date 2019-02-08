/*
 * singlyLinkedList.h
 *
 *  Креирано 21.10.2018.
 *      Аутор: Дамјан Гламочић RA65/2015
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#pragma CHECK_MISRA("none")
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#pragma CHECK_MISRA("1.2, 2.4, 3.1, 5.2, 6.1, 7.1, 8.5, 8.6, 16.2")

#define true (1)
#define false (0)

typedef int_fast8_t bool;

typedef struct node
{
	uint_least32_t number;
	struct node* next;
} Node;

/* Функција која убацује елемент у листу на посљедње мјесто */
bool push_end(Node* const head, uint_least32_t n);

/* Функција која убацује елемент на почетак листе */
bool push_begin(Node** head, uint_least32_t n);

/* Фунцкија која исписује све елементе листе у три бројна система: окталном, декадном и хексадецималном */
void print_list(Node* const head);

/* Фунцкија која исписује елементе листе редом док не наиђе на елемент који је прослијеђен функцији */
void print_list_to_number(Node* const head, uint_least32_t n);

/* Функција која уклања елемент са краја листе */
uint_least32_t remove_last(Node* head);

/* Функција која враћа вриједност посљедњег елемента из листе */
uint_least32_t get_last(Node* const head);

/* Функција која брише све елементе из листе (ослобађа динамички заузету меморију) */
void clear_list(Node** head);

#endif /* SINGLYLINKEDLIST_H_ */
