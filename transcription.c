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
#include <string.h>
#include "dogma.h"

Sequence *transcript(const Sequence *dna)
{
    /* initializes a return Sequence object */
    Sequence *rna = NULL;
    size_t it = 0;

    rna = seq_init(dna->length);
    rna->length = dna->length;

    /* actual compile process */
    for (it = 0; it < dna->length; it++)
    {
        switch (dna->seq[it])
        {
        case 'G':
            rna->seq[it] = 'C';
            break;
        case 'C':
            rna->seq[it] = 'G';
            break;
        case 'T':
            rna->seq[it] = 'A';
            break;
        case 'A':
            rna->seq[it] = 'U';
            break;
       case 'N':
            rna->seq[it] = 'N';
            break;
        }
    }

    return rna;
}