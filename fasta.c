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

#define LMAX 4096

Sequence *read_fasta(const char *file)
{
    char *ln = NULL;            /* NULL forces getline to allocate    */
    FILE *fin = NULL;           /* file pointer to input              */
    Sequence *sequence = NULL;  /* create return Sequence object      */
    size_t idx = 0;             /* array index for number of lines    */
    size_t it = 0;              /* general iterator variable          */
    size_t lmax = LMAX;         /* current array pointer allocation   */
    size_t n = 0;               /* buf size, 0 use getline default    */
    ssize_t nchr = 0;           /* number of chars actually read      */

    fin = fopen(file, "r");
    e_errno(fin);

    sequence = seq_init(LMAX);

    while ((nchr = getline(&ln, &n, fin)) != -1)    /* read line    */
    {
        if (ln[0] == '>')
        {
            continue;                          /* ignore comments   */
        }
        
        while (nchr > 0 && (ln[nchr-1] == '\n' || ln[nchr-1] == '\r'))
        {
            ln[--nchr] = 0;               /* strip LF and CR        */
        }

        for (it = 0; it < nchr; it++)
        {
            if (idx == lmax)
            {
                seq_realloc(sequence, lmax * 2);
                lmax *= 2;
            }
            if (ln[it] != '\0')
            {
                sequence->seq[idx++] = ln[it];
            }
        }
    }

    sequence->length = idx;

    if (fin)
    {
        fclose(fin);
        fin = NULL;
    }
    if (ln)
    {
        free(ln);
        ln = NULL;
    }

    idx = 0;
    it = 0;
    lmax = 0;
    n = 0;
    nchr = 0;

    return sequence;
}

void write_fasta(const Sequence *output, char *file)
{
    FILE *fout = NULL;           /* file pointer to input              */
    Sequence *sequence = NULL;   /* create formatted Sequence object   */
    size_t it = 0;               /* general iterator variable          */
    size_t idx = 0;              /* array index for number of lines    */

    fout = fopen(file, "w");
    e_errno(fout);

    sequence = seq_init(output->length);
    sequence->length = output->length;

    for (it = 0; it < output->length; it++)
    {
        if (idx >= sequence->length)
        {
            seq_realloc(sequence, sequence->length * 2);
            sequence->length *= 2;
        }
        if (it != 0 && (it % 70) == 0)
        {
            sequence->seq[idx++] = '\n';
        }

        sequence->seq[idx++] = output->seq[it];
    }

    sequence->length = idx;
    fwrite(sequence->seq, sequence->length, sizeof(char), fout);

    if (fout)
    {
        fclose(fout);
        fout = NULL;
    }

    if (sequence)
    {
        seq_free(sequence);
        sequence = NULL;
    }

    it = 0;
    idx = 0;
}