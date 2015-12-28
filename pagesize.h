/*
** pagesize.h for  in /home/single_j//projets/malloc
** 
** Made by julien singler
** Login   <single_j@epitech.net>
** 
** Started on  Wed Feb  9 23:40:46 2011 julien singler
** Last update Thu Feb 10 11:58:10 2011 julien singler
*/

#ifndef __MYPAGESIZE_H__
#define __MYPAGESIZE_H__
#include <sys/types.h>
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#undef GNU_OUR_PAGESIZE
#if defined (HAVE_SYSCONF) && defined (HAVE_UNISTD_H)
#include <unistd.h>
#ifdef _SC_PAGESIZE
#define GNU_OUR_PAGESIZE sysconf(_SC_PAGESIZE)
#endif
#endif

#ifndef GNU_OUR_PAGESIZE
# ifdef PAGESIZE
#  define GNU_OUR_PAGESIZE PAGESIZE
# else/* no PAGESIZE */
#  ifdef EXEC_PAGESIZE
#   define GNU_OUR_PAGESIZE EXEC_PAGESIZE
#  else/* no EXEC_PAGESIZE */
#   ifdef NBPG
#    define GNU_OUR_PAGESIZE (NBPG * CLSIZE)
#    ifndef CLSIZE
#     define CLSIZE 1
#    endif/* CLSIZE */
#   else/* no NBPG */
#    ifdef NBPC
#     define GNU_OUR_PAGESIZE NBPC
#    else/* no NBPC */
#     define GNU_OUR_PAGESIZE 4096/* Just punt and use reasonable value */
#    endif /* NBPC */
#   endif /* NBPG */
#  endif /* EXEC_PAGESIZE */
# endif /* PAGESIZE */
#endif /* GNU_OUR_PAGESIZE */
#endif
