#include "deck.h"

int _strcompare(const char *s1, const char *s2);
char get_val(deck_node_t *card);
void insertion_sorted_Kinfofdeck(deck_node_t **deck);
void insertion_sorted_Valueofdeck(deck_node_t **deck);
void sort_deck(deck_node_t **deck);
/**
 *  _strcompare - string compare
 *  @s1: first string
 *  @s2: Scond String
 *  Return: int
 */
int _strcompare(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
/**
 * get_val - get card value
 * @card: card node
 * Return: char
 */
char get_val(deck_node_t *card)
{
	if (_strcompare(card->card->value, "Ace") == 0)
		return (0);
	if (_strcompare(card->card->value, "1") == 0)
		return (1);
	if (_strcompare(card->card->value, "2") == 0)
		return (2);
	if (_strcompare(card->card->value, "3") == 0)
		return (3);
	if (_strcompare(card->card->value, "4") == 0)
		return (4);
	if (_strcompare(card->card->value, "5") == 0)
		return (5);
	if (_strcompare(card->card->value, "6") == 0)
		return (6);
	if (_strcompare(card->card->value, "7") == 0)
		return (7);
	if (_strcompare(card->card->value, "8") == 0)
		return (8);
	if (_strcompare(card->card->value, "9") == 0)
		return (9);
	if (_strcompare(card->card->value, "10") == 0)
		return (10);
	if (_strcompare(card->card->value, "Jack") == 0)
		return (11);
	if (_strcompare(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}
/**
 * insertion_sorted_Kinfofdeck - insert sorted deck kind
 * @deck: node
 */
void insertion_sorted_Kinfofdeck(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}
/**
 * insertion_sorted_Valueofdeck - Insert sorted deck value
 * @deck: Node
 */
void insertion_sorted_Valueofdeck(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
				insert->card->kind == iter->card->kind &&
				get_val(insert) > get_val(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}
/**
 * sort_deck - sort deck of cards
 * @deck: node
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sorted_Kinfofdeck(deck);
	insertion_sorted_Valueofdeck(deck);
}
