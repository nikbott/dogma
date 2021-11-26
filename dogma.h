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

#ifndef __DOGMA_H__
#define __DOGMA_H__

#define e_errno(X) if (!X) {perror("error"); exit(EXIT_FAILURE);}

typedef struct sequence
{
    char *seq;
    size_t length;
}Sequence;

/* allocate memory and zero initialize a Sequence object */
Sequence *seq_init(size_t length);

/* free Sequence object and deallocate memory*/
void seq_free(Sequence *sequence);

/* reallocate memory to Sequence internal string */
void seq_realloc(Sequence *sequence, size_t length);

/* transcript a DNA sequence to its RNA complement */
Sequence *transcript(const Sequence *dna);

/* translate a RNA sequence to its protein */
Sequence *translate(const Sequence *rna);

/* reverse transcript a RNA sequence to its DNA complement */
Sequence *reverse_transcript(const Sequence *rna);

/* parses a FASTA file line by line */
Sequence *read_fasta(const char *file);

/* writes to a FASTA file line by line */
void write_fasta(const Sequence *output, char *file);

#endif