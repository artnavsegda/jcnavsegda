#include <stdio.h>
#include <json-c/json.h>

int main()
{
  FILE *jsonfile = fopen("test.json", "r");
  char buffer[1000];
  fread(buffer, sizeof(buffer), 1, jsonfile);

	return 0;
}
