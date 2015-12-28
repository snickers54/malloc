/*
** main.c for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Tue Feb  1 00:37:10 2011 julien singler
** Last update Fri Feb 11 22:34:57 2011 julien singler
*/

#include "my_malloc.h"

chunk *chunkList = 0;
chunk *freeList[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
chunk	*last = 0;

chunk		*getNewChunk(size_t needed)
{
  size_t	size_real;
  chunk		*part;

  size_real = getNextPower(needed + (unsigned int) sizeof(*part));
  if ((part = my_sbrk(size_real)) == 0)
    return 0;
  if (last)
      part = (void *)((unsigned int)last + last->size + sizeof(*part));
  part->size = needed;
  part->used = 1;
  part->real_size = size_real;
  part->hash = CRC;
  part->isHead = 1;
  part->next = 0;
  part->alea = 0;
  if (last)
    {
      part->real_size += (last->real_size - last->size - sizeof(*part));
      last->real_size = last->size + sizeof(*part);
    }
  if (!chunkList)
    chunkList = part;
  else
    last->next = part;
  last = part;
  return part;
}

void		*my_sbrk(size_t toto)
{
  chunk		*part;

  if (toto > 2147483647)
    {
      part = sbrk(2147483646);
      sbrk(toto - 2147483646);
    }
  else
    part = sbrk(toto);
  if ((void *)part >= sbrk(0))
    return 0;
  return part;
}

void		*malloc(size_t size)
{
  chunk		*part;

  if (size + 1 <= 0)
    return 0;
  size += sizeof(*part);
  if ((part = getFreeChunk(size)))
    return (void *)((unsigned int)part + sizeof(*part));
  if ((part = getFragmentChunk(size)))
    return (void *)((unsigned int)part + sizeof(*part));
  if ((part = getNewChunk(size)))
    return (void *)((unsigned int) part + sizeof(*part));
  return 0;
}

void		*realloc(void *ptr, size_t len)
{
  void		*p;
  chunk		*test;

  test = (void*)((unsigned int)ptr - sizeof(*test));
  if (!ptr)
    return (p = malloc(len));
  if (!(test <= last && test >= chunkList))
    return 0;
  if (len == 0 && ptr)
    free(ptr);
  else
    {
      if (test->size > len)
	return ptr;
      p = malloc(len);
      p = memcpy(p, ptr, test->size);
      free(ptr);
      return p;
    }
  return 0;
}

void		*calloc(size_t number, size_t len)
{
  void	*p;

  p = malloc(number * len);
  if (!p)
    return 0;
  return p;
}
