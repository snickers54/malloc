/*
** fragment.c for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Feb  3 18:11:49 2011 julien singler
** Last update Wed Feb  9 23:00:06 2011 julien singler
*/

#include "my_malloc.h"

chunk		*getFragmentChunk(size_t needed)
{
  chunk		*part;

  if (last)
    if ((last->real_size) > (last->size + sizeof(*part)) &&
	(last->real_size - (last->size + sizeof(*part))
	 >= (needed + (unsigned int) sizeof(*part))))
      {
	part = (void *)((unsigned int)last + (last->size + sizeof(*part)));
	part->size = needed;
	part->used = 1;
	part->isHead = 0;
	part->alea = 0;
	part->hash = CRC;
	part->next = 0;
	part->real_size = (unsigned int) (last->real_size - (last->size + sizeof(*part)));
	last->real_size = (unsigned int) (last->size + sizeof(*part));
	last->next = part;
	last = part;
	return part;
      }
  return 0;
}
