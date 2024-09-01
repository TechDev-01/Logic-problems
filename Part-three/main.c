#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct para almacenar los roles en el ejercicio num 21.
typedef struct {
  char role[10];
  const char *actions[4];
  int num_actions;
}Rol;

// Struct para almacenar los productos del ejercicio num 26.
typedef struct {
  char name[30];
  int cant;
  float price;
}Inventory;
// Funcion del ejercicio num 21.
void access_by_role();
// Funcion del ejercicio num 22.
void overtime();
// Funcion del ejercicio num 23.
bool secure_password(const char *password);
// Funcion del ejercicio num 24.
void credit();
// Funcion del ejercicio num 25.
void conversion_menu();
// Funcion del ejercicio num 26.
void inventory();
// Funcion del ejercicio num 27.
void iva();
// Funcion del ejercicio num 28.
void grades();
// Funcion del ejercicio num 29.
void atm();
// Funcion del ejercicio num 30.
void reservation();

int main() {
  // Ejercicio num 21.
   access_by_role();
  // Ejercicio num 22.
   overtime();
  // Ejercicio num 23
   char password[256];
   printf("Ingrese una contrasena valida: ");
   scanf("%255s", password);
   secure_password(password);
  // Ejercicio num 24.
   credit();
  // Ejercicio num 25.
  conversion_menu();
  // Ejercicio num 26.
  inventory();
  // Ejercicio num 27.
  iva();
  // Ejercicio num 28.
  grades();
  // Ejercicio num 29.
  atm();
  // Ejercicio num 30.
  reservation();
  return 0;
}

// Implementacion de la funcion del ejercicio num 21.
void access_by_role() {
  Rol roles[] = {
    {"admin", {"Create", "Delete", "Edit", "Visualize"}, 4},
    {"editor", {"Edit", "Visualize"}, 2},
    {"lector", {"Visualize"}, 1}
  };

  char role_input[10];
  printf("Ingrese su rol (Admin/Editor/Lector): ");
  scanf("%s", role_input);

  // Busqueda del rol y impresion de las acciones para cada rol.
  int role_found = 0; // flag para saber si se encontro el rol o no.
  for (int i = 0; i < sizeof(roles) / sizeof(roles[0]); i++) {
    if (strcmp(roles[i].role, role_input) == 0) {
      printf("Acciones permitidas: \n");
      for (int j = 0; j < roles[i].num_actions; j++) {
        printf("- %s\n", roles[i].actions[j]);
      }
      role_found = 1;
      break;
    }
  }
  if (!role_found) {
    printf("Error, rol invalido.\n");
  }
}

// Implementacion de la funcion del ejercicio num 22.
void overtime() {
  double salary, total_salary;
  int hours;

  printf("Ingrese su salario base por hora: ");
  scanf("%lf", &salary);

  printf("Ingrese las horas trabajadas: ");
  scanf("%d", &hours);

  // Calculo del salario total
  if (hours <= 40) {
    total_salary = salary * hours;
  } else {
    int ovrtime = hours - 40;
    total_salary = (40 * salary) + (ovrtime * salary * 1.5);
  }
  printf("El salario total es %.2lf\n", total_salary);
}

// Implementacion de la funcion del ejercicio num 23.
bool secure_password(const char *password) {
  int lenght = strlen(password);
  bool has_upper = false, has_lower = false, has_digit = false,
       has_special = false;

  if (lenght >= 8) {
    for (int i = 0; i < lenght; i++) {
      if (isupper(password[i]))
        has_upper = true;
      else if (islower(password[i]))
        has_lower = true;
      else if (isdigit(password[i]))
        has_digit = true;
      else
        has_special = true;
    }
  }

  if (has_upper && has_lower && has_digit && has_special) {
    printf("Contraseña valida\n");
  } else {
    printf("Contraseña invalida\n");
  }
}

// Implementacion de la funcion del ejercicio num 24.
void credit() {
  double salary;
  int age;
  char credit_history[10];
  bool is_eligible = false;

  printf("Ingrese su salario mensual: ");
  scanf("%lf", &salary);

  printf("Ingrese su edad: ");
  scanf("%d", &age);

  printf("Ingrese su historial crediticio (bueno/malo): ");
  scanf("%s", credit_history);

  if (age >= 18 && age <= 65) {
    if (salary >= 1.300000) {
      if (strcmp(credit_history, "bueno") == 0) {
        is_eligible = true;
      }
    }
  }
  if (is_eligible == true) {
    printf("Usted es apto para un credito bancario!!\n");
  } else {
    printf("Usted no es apto para un credito bancario!!\n");
  }
}

// Implementacion de la funcion del ejercicio num 25.
void conversion_menu() {
  const char *conversions[] = {
    "Libras a Kilos", 
    "Metros a Pies",
    "Galones a litros"
  };

  double value;
  double value_converted;
  int option;

  // Mostrar lista de opciones disponibles.
  for (int i = 0; i < sizeof(conversions) / sizeof(conversions[0]); i++) {
    printf("%d. %s\n", i + 1, conversions[i]);
  }

  printf("Escoga una opcion: (1, 2, 3): ");
  scanf("%d", &option);

  // Valida si la opcion es valida.
  if (option < 1 || option > 3) {
    printf("Opcion invalida!!!\n");
    return;
  }
  // Pedir el valor a convertir
  printf("Ingrese un valor a convertir: ");
  scanf("%lf", &value);
  // Realizar la conversion segun la opcion escogida.
  if (option == 1) {
    value_converted = value * 0.4536;
  } else if (option == 2) {
    value_converted = value * 3.281;
  } else {
    value_converted = value * 3.785;
  }
  printf("El valor convertido es: %lf\n", value_converted);
}

// Implementacion de la funcion del ejercicio num 26.
void inventory() {
  Inventory products[] = {
    {"jabon", 13, 2.000},
    {"papel", 20, 1.500},  
    {"croquetas", 5, 2.550},
    {"cereales", 11, 3.450},
    {"desodorante", 4, 2.000}
};

  char product_name[30];
  int product_cant;
  float product_price;

  printf("Ingrese el nombre de un producto: ");
  scanf("%s", product_name);
  
  printf("Ingrese la cantidad del producto: ");
  scanf("%d", &product_cant);

  printf("Ingrese el precio del producto: "); 
  scanf("%lf", &product_price);

  int num_products = (sizeof(products) / sizeof(products[0]));
  int product_found = 0;
  for (int i = 0; i < num_products; i++) {
    if (strcmp(products[i].name, product_name) == 0) {
      printf("Producto encontrado \n");
      for (int j = 0; j < products[i].cant; j++) {
        // printf("%s\n", products[i].name);
      }
      if (products[i].cant < 5) {
        printf("Alerta, reestablezca este producto.\n");
      }
      product_found = 1;
      break;
    }
  }
  if (!product_found) {
    printf("Error, no existe ese producto.\n");
  }
}

//Implementacion de la funcion del ejercicio num 27,
void iva(){
  float price, final_price;
  float iva;
  char product;

  printf("Ingrese el precio de un producto: ");
  scanf(" %f", &price);

  printf("Es de primera necesidad? (S/N): ");
  scanf(" %c", &product);
  product = toupper(product);
  
  if(product == 'S'){
    iva = 0.08;
  } else {
    iva = 0.16;
  }
  //Calcular el precio con el IVA.
  final_price = price + (price * iva);

  printf("El precio final de su producto es: %.2f\n", final_price);
}

//Implementacion de la funcion del ejercicio num 28.
void grades(){
  int note_a, note_b, note_c;
  int average;
  int extra_note;

  printf("Nota uno: ");
  scanf("%d", &note_a);

  printf("Nota dos: ");
  scanf("%d", &note_b);
  
  printf("Nota tres: ");
  scanf("%d", &note_c);

  average = (note_a + note_b + note_c) / 3;

  if (average >= 6) {
    printf("Felicidades has aprobado.\n");
  } else if(average < 6){
    printf("Aun puedes aprobar, ingresa otra calificacion: ");
    scanf("%d", &extra_note);
    average = average + extra_note;
  }else {
    printf("Lo lamento, aun asi no has aprobado\n");
  }

  printf("Tu promedio es: %d\n", average);
}

//Implementacion de la funcion del ejercicio num 29.
void atm(){
  const double SALDO = 3.000000;
  double cant;
  
  printf("Ingrese una cantidad a retirar: ");
  scanf("%lf", &cant);

  if (cant > SALDO) {
    printf("La cantidad a retirar excede el saldo!!!!\n");
  } else {
    printf("Transaccion exitosa!!\n", cant);
  }
}

//Implementacion de la funcion del ejericicio num 30.
void reservation(){
  char *rooms[] = {
    "simple",
    "doble",
    "suite"
  };
  int nights;
  char room[10];
  char anticipacion;
  double price;
  double final_price;
  int discount = 0;
  
  int num_rooms = (sizeof(rooms) / sizeof(rooms[0]));
  
  printf("--- Habitaciones ---\n");
  for (int i = 0; i < num_rooms; i++){
    printf("%d. %s\n", i + 1, rooms[i]);
  }

  printf("Ingrese el tipo de habitacion: ");
  scanf("%s", room);

  printf("Ingrese la cantidad de noches: ");
  scanf(" %d", &nights);

  printf("¿La reserva se realizo con anticipacion? (S/N): ");
  scanf(" %c", &anticipacion);
  anticipacion = toupper(anticipacion);

  if (strcmp(room, "simple") == 0) {
    price = 60.0;
  } else if(strcmp(room, "doble") == 0){
    price = 80.0;
  } else if(strcmp(room, "suite") == 0){
    price = 100.0;
  } else {
    printf("Habitacion no valida!!\n");
    return;
  }

  //precio final antes de los descuentos.
  final_price = (price * nights);

  if (nights > 5) {
    discount += 10; //10% de descuento si son mas de 5 noches.
  } 
  if(anticipacion == 'S'){
    discount += 5; //5% de descuento si la reserva fue con anticipacion.
  }

  //Se calcula el precio final aplicando el descuento.
  if (discount > 0) {
    final_price -= final_price * (discount / 100.0); 
  }
    printf("El precio final de la reserva es: $%.2lf\n", final_price);
  }
