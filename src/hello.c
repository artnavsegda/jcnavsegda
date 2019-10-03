#include <stdio.h>
#include <json-c/json.h>

int main()
{
  json_object *myobj;

  myobj = json_tokener_parse("{ \"test\": \"hello\" }");

  puts(json_object_to_json_string(myobj));

	return 0;
}
