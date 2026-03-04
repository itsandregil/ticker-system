#include "utils/utils.h"
#include <stdio.h>

int main() {
  char *id = read_string_input("Ingresa tu numero de identificacion: ");
  char *email = read_string_input("Ingresa tu correo electronico:");
  char *desc = read_string_input("Ingresa una descripcion de tu reclamo: ");
  printf("Ingresaste %s", id);
  printf("Ingresaste %s", email);
  printf("Ingresaste %s", desc);
  return 0;
}
