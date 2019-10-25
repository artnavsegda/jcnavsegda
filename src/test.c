#include <stdio.h>
#include <json-c/json.h>

int main()
{
  json_object * root_jo =  json_object_from_file("test.json"); //json_tokener_parse(json);

  json_object * node_id_jo;
  json_pointer_get(root_jo, "/nodeId", &node_id_jo);
  printf("[json] parse example: node_id = %s\n", json_object_get_string(node_id_jo));

  json_object * eui_jo;
  json_pointer_get(root_jo, "/deviceEndpoint/eui64", &eui_jo);
  printf("[json] parse example: eui = %s\n", json_object_get_string(eui_jo));

  json_object * endpoint_jo;
  json_pointer_get(root_jo, "/deviceEndpoint/endpoint", &endpoint_jo);
  printf("[json] parse example: endpoint = %d\n", json_object_get_int(endpoint_jo));
}
