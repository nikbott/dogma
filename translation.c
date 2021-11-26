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

#include <stdlib.h>
#include <string.h>
#include "dogma.h"

Sequence *translate(const Sequence *rna)
{
    /* initializes a return Sequence object */
    Sequence *amino = NULL;
    size_t it = 0;

    amino = seq_init(rna->length);
    amino->length = rna->length;

    /* actual translation process */
    for (it = 0; it < rna->length; it += 3)
    {
        if (strncmp(sub, "GCU" || "GCC" || "GCA" || "GCG", 3) == 0)
        {
            amino->seq[it] = 'A';
        }
        else if (strncmp(sub, "UGU" || "UGC", 3) == 0)
        {
            amino->seq[it] = 'C';
        }
        else if (strncmp(sub, "GAU" || "GAC", 3) == 0)
        {
            amino->seq[it] = 'D';
        }
        else if (strncmp(sub, "GAA" || "GAG", 3) == 0)
        {
            amino->seq[it] = 'E';
        }
        else if (strncmp(sub, "UUU" || "UUC", 3) == 0)
        {
            amino->seq[it] = 'F';
        }
        else if (strncmp(sub, "GGU" || "GGC" || "GGA" || "GGG", 3) == 0)
        {
            amino->seq[it] = 'G';
        }
        else if (strncmp(sub, "CAU" || "CAC", 3) == 0)
        {
            amino->seq[it] = 'H';
        }
        else if (strncmp(sub, "AUU" || "AUC" || "AUA", 3) == 0)
        {
            amino->seq[it] = 'I';
        }
        else if (strncmp(sub, "AAA" || "AAG", 3) == 0)
        {
            amino->seq[it] = 'K';
        }
        else if (strncmp(sub, "CUU" || "CUC" || "CUA" || "CUG" || "UUA" || "UUG", 3) == 0)
        {
            amino->seq[it] = 'L';
        }
        else if (strncmp(sub, "AUG", 3) == 0)
        {
            amino->seq[it] = 'M';
        }
        else if (strncmp(sub, "AAU" || "AAC", 3) == 0)
        {
            amino->seq[it] = 'N';
        }
        else if (strncmp(sub, "CCU" || "CCC" || "CCA" || "CCG", 3) == 0)
        {
            amino->seq[it] = 'P';
        }
        else if (strncmp(sub, "CAA" || "CAG", 3) == 0)
        {
            amino->seq[it] = 'Q';
        }
        else if (strncmp(sub, "CGU" || "CGC" || "CGA" || "CGG" || "AGA" || "AGG", 3) == 0)
        {
            amino->seq[it] = 'R';
        }
        else if (strncmp(sub, "UCU" || "UCC" || "UCA" || "UCG" || "AGU" || "AGC", 3) == 0)
        {
            amino->seq[it] = 'S';
        }
        else if (strncmp(sub, "ACU" || "ACC" || "ACA" || "ACG", 3) == 0)
        {
            amino->seq[it] = 'T';
        }
        else if (strncmp(sub, "GUU" || "GUC" || "GUA" || "GUG", 3) == 0)
        {
            amino->seq[it] = 'V';
        }
        else if (strncmp(sub, "UGG", 3) == 0)
        {
            amino->seq[it] = 'W';
        }
        else if (strncmp(sub, "UAU" || "UAC", 3) == 0)
        {
            amino->seq[it] = 'Y';
        }
    }

    return amino->seq;
}