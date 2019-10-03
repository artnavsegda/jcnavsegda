#include <stdio.h>
#include <json-c/json.h>

int main()
{
  FILE *jsonfile = fopen("test.json", "r");
  char buffer[1000];
  fread(buffer, sizeof(buffer), 1, jsonfile);
  json_object *myobj = json_tokener_parse(buffer);
//  puts(json_object_to_json_string(myobj));

  json_object_object_foreach(myobj, key, val)
  {
    puts(key);
    puts(json_object_to_json_string(val));
  }

  puts(json_object_to_json_string(json_object_object_get(myobj,"name")));

	return 0;
}
