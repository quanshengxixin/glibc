/* Copyright (C) 1996,97,2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@gnu.org>, 1996.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <wchar.h>

wchar_t *
wmemchr (s, c, n)
     register const wchar_t *s;
     register wchar_t c;
     register size_t n;
{
  /* For performance reasons unfold the loop four times.  */
  while (n >= 4)
    {
      if (s[0] == c)
	return (wchar_t *) s;
      if (s[1] == c)
	return (wchar_t *) &s[1];
      if (s[2] == c)
	return (wchar_t *) &s[2];
      if (s[3] == c)
	return (wchar_t *) &s[3];
      s += 4;
      n -= 4;
    }

  if (n > 0)
    {
      if (*s == c)
	return (wchar_t *) s;
      ++s;
      --n;
    }
  if (n > 0)
    {
      if (*s == c)
	return (wchar_t *) s;
      ++s;
      --n;
    }
  if (n > 0)
    if (*s == c)
      return (wchar_t *) s;

  return NULL;
}
libc_hidden_def (wmemchr)
