/*
** my_malloc.h for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Tue Feb  1 00:38:08 2011 julien singler
** Last update Fri Feb 11 22:26:32 2011 julien singler
*/

#ifndef __MY_MALLOC_H__
#define __MY_MALLOC_H__
#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "pagesize.h"

#define CRC	4242

typedef struct s_chunk
{
  struct s_chunk *next;
  struct s_chunk *alea;
  size_t	size;
  size_t	hash;
  size_t	real_size;
  unsigned char	used;
  unsigned char isHead;
} chunk;

extern chunk *chunkList;
extern chunk *freeList[32];
extern chunk *last;

void		*my_sbrk(size_t toto);
void		*realloc(void *ptr, size_t len);
chunk		*getNewChunk(size_t needed);
void		*malloc(size_t size);
size_t		getNextPower(size_t size);
size_t		getPower(size_t needed);
chunk		*getFreeChunk(size_t needed);
void		put_to_hash(chunk *part, size_t power);
void		free(void *ptr);
void		del_to_hash(chunk *ch);
chunk		*fusion(void);
void		show_alloc_mem(void);
chunk		*getFragmentChunk(size_t needed);
void		*calloc(size_t number, size_t len);
#endif
