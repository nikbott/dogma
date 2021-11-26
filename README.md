# dogma

WARNING: dogma is currently in an initial development stage and is expected to have lots of bugs.

dogma is a FASTA parser that transcripts DNA strands to RNA and translates it to aminoacids according to the standard code.

## Building

Download and extract package or:
```sh
git clone https://github.com/nikbott/dogma
```

Edit config.mk as needed

```sh
make
make install
```

## Usage

Initially only capable of transcripting

```sh
dogma [SOURCE] [DEST]
```

## License

Copyright 2021 Vinícius Kury

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