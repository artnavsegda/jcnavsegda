#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <json-c/json.h>

int main()
{
  json_object *myobj = json_object_from_file("test.json");

  json_object_iter iter;
    
  json_object_object_foreachC(myobj, iter)
  {
    puts(iter.key);
    puts(json_object_to_json_string(iter.val));
  }

//  json_object *name;

//  if (json_pointer_get(myobj, "one", &name))
//  if (json_object_object_get_ex(myobj, "one", &name))
//  {
//    puts(json_object_get_string(name));
//  }
	return 0;
}
