/*
** free.c for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Feb  3 18:09:45 2011 julien singler
** Last update Fri Feb 11 22:35:08 2011 julien singler
*/

#include "my_malloc.h"

chunk		*getFreeChunk(size_t needed)
{
  size_t	power;
  chunk		*temp;

  for (power = getPower(needed); power < 32; power++)
    for (temp = freeList[power]; temp; temp = temp->alea)
      if (temp->size >= (needed))
	{
	  del_to_hash(temp);
	  temp->used = 1;
	  return temp;
	}
  return 0;
}

void		del_to_hash(chunk *ch)
{
  size_t	power;
  chunk		*temp;
  chunk		*tp1;

  power = getPower(ch->size);
  temp = freeList[power];
  if (temp == ch)
    {
      temp = temp->alea;
      (freeList[power])->alea = 0;
      freeList[power] = temp;
      return ;
    }
  for (; temp && temp->alea; temp = temp->alea)
    if (temp->alea == ch)
      {
	tp1 = temp->alea;
	if (temp->alea->alea)
	  temp->alea = temp->alea->alea;
	else
	  temp->alea = 0;
	tp1->alea = 0;
	return;
      }
}

void		put_to_hash(chunk *part, size_t power)
{
  chunk		*temp;

  if (!freeList[power])
    {
      part->alea = 0;
      freeList[power] = part;
      return;
    }
  for (temp = freeList[power]; temp && temp->alea &&
	 temp->alea->size < part->size; temp = temp->alea);
  if (temp->alea)
    {
      part->alea = temp->alea;
      temp->alea = part;
    }
  else
    temp->alea = part;
}

void		free(void *ptr)
{
  chunk		*part;
  chunk		*temp;

  temp = 0;
  if (ptr == 0)
    return ;
  part = (void *)((unsigned int)ptr - sizeof(*part));
  if (part <= last && part >= chunkList && part->used == 1
      && part->hash == CRC)
    {
      memset(ptr, 0, part->size);
      part->used = 0;
      temp = fusion();
      if (temp)
	put_to_hash(temp, getPower(temp->size));
      else
	put_to_hash(part, getPower(part->size));
    }
}
