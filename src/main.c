#include "utils/utils.h"
#include <stdio.h>

int main() {
  char *id =
      read_string_input("Ingresa tu numero de identificacion: ", validate_id);
  char *email =
      read_string_input("Ingresa tu correo electronico:", validate_email);
  char *desc = read_string_input("Ingresa una descripcion de tu reclamo: ",
                                 validate_is_not_empty);
  printf("Ingresaste %s", id);
  printf("Ingresaste %s", email);
  printf("Ingresaste %s", desc);
  return 0;
}
