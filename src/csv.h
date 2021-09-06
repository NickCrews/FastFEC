#pragma once

#include "memory.h"
#include "writer.h"

struct field_info
{
  int num_commas;
  int num_quotes;
};
typedef struct field_info FIELD_INFO;

void processFieldChar(char c, FIELD_INFO *info);

void writeDelimeter(WRITE_CONTEXT *context, char *filename);

void writeNewline(WRITE_CONTEXT *context, char *filename);

static inline int endOfField(char c);

// Read a field from a file delimited by the character with the
// ascii code 28. If both the start and end of the field are `"`
// then return the field contents inside the quotes.
void readAscii28Field(STRING *line, int *position, int *start, int *end, FIELD_INFO *field);

// Read a CSV field in-place, modifying line and returning start and
// end positions of the unescaped field. Since CSV fields are always
// longer escaped than not, this will always work in-place.
void readCsvField(STRING *line, int *position, int *start, int *end, FIELD_INFO *field);

void writeField(WRITE_CONTEXT *context, char *filename, STRING *line, int start, int end, FIELD_INFO *info);