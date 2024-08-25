#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*Declaracion de las funciones 
 * a usar para los ejercicios.
 * Las implementaciones estan en la parte
 * de abajo del archivo despues de la funcion main() 
 */

//Funcion primer ejercicio
int check_condition(int n);
//Funcion segundo ejercicio
int sum_numbers(int a, int b, int c);
//Funcion tercer ejercicio.
int valid_number(int number);
//Funciones cuarto ejercicio.
typedef float (*Discount_func)(float, int); //Puntero a una funcion.
char* age_category(int age);  //Funcion para determinar la edad.
float discount_by_age(float original_price, int age);
float final_price(float original_price, int age, Discount_func discount_function);
//Funcion quinto ejercicio.
double calculator(void);
//Funcion sexto ejercicio.
int secret_number(void);
//Funcion septimo ejercicio.
void password();

int main(){
  //Primer ejercicio
  check_condition(20);
  check_condition(2);
  
  //Segundo ejercicio (DEBE DE HABER UNA MEJOR FORMA DE HACER ESTO)
  int num1 = 5;
  int num2 = 10;
  int num3 = 20;
  int mayor;
  int sum;
  mayor = sum_numbers(num1,num2,num3);
  //Mostrar cual es mayor
  printf("El numero mayor es: %d\n", mayor);
  
  if (mayor >= 0) {
    sum = num1 + num2 + num3;
    printf("La suma de los tres valores es: %d\n", sum);
  }

  //Tercer ejercicio.
  valid_number(9);
  
  //Cuarto ejercicio.
  int age = 67;
  float buy_price = 55.10;
  float price_final;

  char* category = age_category(age);
  printf("la persona es: %s\n", category);
  //Verificar si la edad es mayor a 65 y aplicar el descuento.
  if (age >= 65) {
    printf("Ingrese el precio de la compra: %.2f\n", buy_price);
    //Se pasa la funcion de descuento como parametro a final_price()
    price_final = final_price(buy_price, age, discount_by_age);
    
    printf("El precio despues de el descuento es: %.2f\n", price_final);
  }

  //Quinto ejercicio.
  calculator();
  
  //Sexto ejercicio.
  secret_number();
  
  //Septimo ejercicio.
  password();
  return 0;
}

/*Implementacion de las funciones 
 *declaradas al inicio del 
 *archivo :)
 */

//Implementacion de la funcion del 1er ejercicio
int check_condition(int n){
   if (n %2 == 0 && n %5 == 0) {
    printf("Es par y multiplo de cinco\n"); 
  } else {
    printf("No es par\n"); 
  }
}

//Implementacion de la funcion del segundo ejercicio
int sum_numbers(int a, int b, int c){
  //Determinar el numero mayor
  if (a >= b && a >= c) {
    return a;
  } else if (b >= a && b >= c) {
    return b;
  } else {
    return c;
  }
}

//Implementacion de la funcion del tercer ejercicio.
int valid_number(int number){
  if(number > 10 || number <= 0) {
    printf("Ingrese un numero valido\n");
  }else if(number > 5) {
    printf("El numero es mayor que cinco\n");
  } else {
    printf("El numero es menor que cinco\n");
  }
}

//Implementacion de la funcion del cuarto ejercicio.
char* age_category(int age){
  if (age <= 12) {
    return "niño";
  } else if (age > 12 && age <= 17) {
      return "un adolescente";
  } else if(age > 18 && age >= 65){
      return "un adulto";
  } else {
      return "un adulto mayor";
  } 
}

float discount_by_age(float original_price, int age){
  if (age >= 65) {
    return original_price * 0.8;
  }else {
    return original_price;
  }
}

float final_price(float original_price, int age, Discount_func discount_function){
  return discount_function(original_price, age);
}

//Implementacion de la funcion para el quinto ejercicio.
double calculator(void){
  char operator;
  double num1;
  double num2;
  double result;

  operator = printf("Escoja una operación (+, -, *. /): ");
  scanf("%c", &operator);
  
  num1 = printf("Inserte un numero: ");
  scanf("%lf", &num1);
  
  num2 = printf("Inserte otro numero: ");
  scanf("%lf", &num2);

  if (operator == '+') {
      result = num1 + num2;
      printf("%.1lf\n", result); 
  } else if(operator == '-'){
      result = num1 - num2;
      printf("%.1lf\n", result);
  } else if(operator == '*'){
      result = num1 * num2;
      printf("%.1lf\n", result);
  } else if(operator == '/' && num2 == 0){
      printf("Divisor incorrecto, pruebe otra vez\n");      
  } else {
      result = num1 / num2;
      printf("%.1lf\n", result);
  }
}

//Implementacion de la funcion del sexto ejercicio.
int secret_number(void){
  const int MIN = 1;
  const int MAX = 130;
  const int CORRECT_NUMBER = 125;  
  int user_number;
  
    srand(time(0));

    do {
      printf("Enter a number: ");
      scanf("%d", &user_number);
      if (user_number > CORRECT_NUMBER) {
        printf("Numero demasiado grande!!!\n");   
      } else if(user_number < CORRECT_NUMBER){
        printf("No es el numero correcto\n");
      } else {
        printf("¡Es el numero correcto!\n");  
      }
    } while (user_number != CORRECT_NUMBER);
    
}

//Implementacion de la funcion del sexto ejercicio.
void password(){
  const char CORRECT_PASSWD[]  = "Admin";
  char user_passwd[20];
  int attempts = 0;
  
  do {
    printf("Password: ");
    fgets(user_passwd, sizeof(user_passwd), stdin);
    //Se elimina el salto de linea que agrefa fgets
    user_passwd[strcspn(user_passwd, "\n")] = 0;
      if (strcmp(user_passwd, CORRECT_PASSWD) == 0) {
        printf("Correct password\n");
        break;
    } else {
        printf("Error, try again\n");
    }
    attempts++;
  } while (attempts < 3);

  if (attempts == 3) {
    printf("Too many failed attempts\n");
  }
}
