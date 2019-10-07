#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <json-c/json.h>

int main()
{
  int jsonfile = open("test.json", O_RDONLY);
  struct stat st;
  fstat(jsonfile, &st);
  char *buffer = malloc(st.st_size);
  read(jsonfile, buffer, st.st_size);
  json_object *myobj = json_tokener_parse(buffer);
//  puts(json_object_to_json_string(myobj));

  json_object_object_foreach(myobj, key, val)
  {
    puts(key);
    puts(json_object_to_json_string(val));
  }

  json_object *name = NULL;

  if (json_object_object_get_ex(myobj, "name", &name))
  {
    puts(json_object_to_json_string(name));
  }
	return 0;
}
