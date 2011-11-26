/*
    corfiles.c:

    Copyright (C) 2011 John ffitch

    This file is part of Csound.

    The Csound Library is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    Csound is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Csound; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
    02111-1307 USA
*/

#ifndef __corfil

#define __corfil

CORFIL *corfile_create_w(void);
CORFIL *corfile_create_r(char *text);
void corfile_putc(int c, CORFIL *f);
void corfile_puts(char *s, CORFIL *f);
void corfile_flush(CORFIL *f);
void corfile_rm(CORFIL *f);
int corfile_getc(CORFIL *f);
void corfile_ungetc(CORFIL *f);
#define corfile_ungetc(f)  (--f->p)
MYFLT corfile_get_flt(CORFIL *f);
void corfile_rewind(CORFIL *f);
#define corfile_rewind(f) (f->p=0)
int corfile_tell(CORFIL *f);
#define corfile_tell(f) (f->p)
char *cirfile_body(CORFIL *f);
#define corfile_body(f) (f->body)
CORFIL *copy_to_corefile(char *);
//CORFIL *copy_to_corefile_path(CSOUND *, char *);
int corfile_length(CORFIL *f);
#define corfile_length(f) (strlen(f->body))

#endif
