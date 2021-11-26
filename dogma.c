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

int main(int argc, char **argv)
{
    Sequence *dna = NULL;
    Sequence *rna = NULL;

    if (argc < 3)
    {
        fprintf(stderr, "Usage: dogma [SOURCE] [DEST]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dna = read_fasta(argv[1]);
    rna = transcript(dna);
    write_fasta(rna, argv[2]);

    if (dna)
    {
       seq_free(dna);
       dna = NULL;
    }

    if (rna)
    {
        seq_free(rna);
        rna = NULL;
    }

    exit(EXIT_SUCCESS);
}