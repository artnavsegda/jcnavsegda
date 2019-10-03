#include <stdio.h>
#include <json-c/json.h>

int main()
{
  FILE *jsonfile = fopen("test.json", "r");
  char buffer[1000];
  fread(buffer, sizeof(buffer), 1, jsonfile);
  json_object *myobj = json_tokener_parse(buffer);
  puts(json_object_to_json_string(myobj));

	return 0;
}
