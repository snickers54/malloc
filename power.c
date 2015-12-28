/*
** power.c for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Thu Feb  3 18:10:47 2011 julien singler
** Last update Fri Feb 11 22:28:15 2011 julien singler
*/

#include "my_malloc.h"

size_t		getNextPower(size_t size)
{
  size_t	temp;

  for (temp = GNU_OUR_PAGESIZE; temp < size; temp <<= 1);
  return temp;
}

size_t		getPower(size_t needed)
{
  size_t	power;
  size_t	temp;

  for (temp = 1, power = 0; temp < needed; temp <<= 1, power++);
  return power;
}
