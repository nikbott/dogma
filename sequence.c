/*
Copyright 2021 Vinícius Kury

This file is part of dogma.

dogma is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

dogma is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with dogma.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dogma.h"

Sequence *seq_init(size_t length)
{
    Sequence *sequence = NULL;

    sequence = calloc(1, sizeof(Sequence));
    e_errno(sequence);

    sequence->seq = calloc(length, sizeof(char));
    e_errno(sequence->seq);

    return sequence;
}

void seq_free(Sequence *sequence)
{
    e_errno(sequence);

    if (sequence->seq)
    {
        free(sequence->seq);
        sequence->seq = NULL;
    }

    sequence->length = 0;
    free(sequence);
}

void seq_realloc(Sequence *sequence, size_t length)
{
    char *tmp;

    e_errno(sequence);

    tmp = reallocarray(sequence->seq, length, sizeof(char));
    e_errno(tmp);

    sequence->seq = tmp;
}