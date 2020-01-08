#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <json-c/json.h>

int main()
{
  json_object *myobj = json_object_from_file("test3.json");

  puts(json_object_to_json_string(myobj));

  json_object_object_foreach(myobj, key, val)
  {
    puts(key);
    puts(json_object_to_json_string(val));
  }

  return 0;
}
