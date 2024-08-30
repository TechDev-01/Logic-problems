#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//Funcion onceavo ejercicio.
void to_farenheit();
//Funcion doceavo ejercicio.
int average();
//Funcion 13 ejercicio.
void leap_year();
//Funcion 14 ejercicio.
void score();
//Funcion 15 ejercicio.
void tax_by_category();
//Funcion 16 ejercicio.
void date_validator();
//Funcion 17 ejercicio.
void discount();
//Funcion 18 ejercicio.
void bmi();
//Funcion ejercicio num 19.
void triangles_side();
//Funcion ejercicio num 20.
void numero_primo();
int main(){
    //Onceavo ejercicio.
    to_farenheit();
    //Doceavo ejercicio.
    average();
    //Ejercicio num 13.
    leap_year();
    //Ejercicio num 14.
    //score();
    //Ejercicio num 15.
    tax_by_category();
    //Ejercicio num 16.
    date_validator();
    //Ejercicio num 17.
    discount();
    //Ejercicio num 18.
    bmi();
    //Ejercicio num 19.
    triangles_side();
    //Ejercicio num 20.
    numero_primo();
    return 0;   
}

//Implentacion de la funcion del onceavo ejercicio.
void to_farenheit(){
    double temp_cels;

    printf("inserte una temperatura en el rango correcto: ");
    scanf("%lf", &temp_cels);

    if (temp_cels > -273.15 && temp_cels < 1000){
        temp_cels = (temp_cels * 9 / 5) + 32;
        printf("La temperatura en Fahrenheit es: %.1lf\n", temp_cels);
    } else {
        printf("Inserte una temperatura valida");
    }  
}

//Implentacion de la funcion del doceavo ejercicio.
int average(){
    int note_one, note_two, note_three; 
    int avrge;

    printf("Nota uno: ");
    scanf("%d", &note_one);
    
    printf("Nota dos: ");
    scanf("%d", &note_two);
    
    printf("Nota tres: ");
    scanf("%d", &note_three);

    avrge = (note_one + note_two + note_three) / 3;

    if (note_one < 5 || note_two < 5 || note_three < 5){
        printf("Alguna calificacion esta por de debajo de 5. \n");
    }
    
    if (avrge >= 6){
        printf("Felicidades aprobaste\n");
    } else {
        printf("NO has aprobado\n");
    }
}

//Implentacion de la funcion del decimo tercero ejercicio.
void leap_year(){
    int year;
    printf("Ingrese un anio: ");
    scanf("%d", &year);

    if (year < 1582){
        printf("Error, el calendario gregoriano aun no exisistia\n");
    } else if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        printf("El anio %d es bisiesto\n", year);
    } else {
        printf("El anio %d no es bisiesto\n", year);
    } 
}

//Implentacion de la funcion del 15 ejercicio.
void score(){
    char student_answers[10];
    char real_score[] = {'A', 'C', 'B', 'D', 'A', 'B', 'C', 'D', 'A', 'B'};
    int correct = 0;

    printf("Inserte las respuestas del examen: \n");
    for(int i = 0; i < 10; i++){
        printf("Respuesta: ", i + 1);
        scanf(" %c", &student_answers[i]);
    }

    for(int i = 0; i < 10; i++){
       if(student_answers[i] == real_score[i]){
            correct++;
       }   
    }
    
    printf("Puntaje final %d/10\n", correct);
    if(correct >= 7){
        printf("Aprobo el examen\n");
    }else {
        printf("NO aprobo el examen\n");
    }   
}

//Implentacion de la funcion del 15 ejercicio.
void tax_by_category(){
    double salary, tax;
    int category;

    printf("Ingrese su salario: ");
    scanf("%lf", &salary);

    if(salary < 30000){
        tax = salary * 0.5;
        category = 1;
    } else if (salary <= 60000){
        tax = salary * 0.15;
        category = 2;
    } else {
        tax = salary * 0.25;
        category = 3;
    }

    printf("El impuesto a pagar es del $%.2lf\n", tax);
    printf("Categoria de impuesto %d\n", category);
}

//Implentacion de la funcion del 16 ejercicio.
void date_validator(){
    int day, month, year;

    printf("Ingrese un dia: ", day);
    scanf("%d", &day);

    printf("Ingrese un mes: ", month);
    scanf("%d", &month);

    printf("Ingrese un anio: ", year);
    scanf("%d", &year);

    if (day >= 31 || month > 12 || year > 2024){
        printf("Fecha invalida\n");
    } else {
        printf("Fecha valida\n");
    }

    printf("La fecha ingresada es: %d", day);
    printf("/%d/", month);
    printf("%d\n", year);
}

//Implentacion de la funcion del 17 ejercicio.
void discount(){
    int amount;
    double price;
    double product_discount = 0.0;
    char is_electronic;

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &amount);

    printf("Precio de los productos: ");
    scanf("%lf", &price);

    while ((getchar()) != '\n'); 

    printf("El producto es electronico (S/N):");
    scanf("%c", &is_electronic);
    is_electronic = toupper(is_electronic);    

    if (amount >= 10 && is_electronic == 'S'){
        product_discount = price * 0.10;
    } else if(amount >= 5 && is_electronic == 'N'){
        product_discount = price * 0.05;
    }
    printf("El descuento sobre el producto es: $%.2lf\n", product_discount);
}

//Implentacion de la funcion del 18 ejercicio.
void bmi(){
    double height;
    int body_weight;
    double imc;

    printf("Ingrese su peso en KG: ");
    scanf("%d", &body_weight);
    
    printf("Ingrese su altura en m2: ");
    scanf("%lf", &height);
    
    //Calcula el IMC
    imc = (body_weight / (height * height));
    printf("Tu IMC es: %.2lf\n", imc);

    //Indica en que categoria se encuentra el usuario.
    if(imc < 18.5){
        printf("Bajo peso\n");
    } else if(imc >= 18.5 && imc <= 24.9){
        printf("Peso normal\n");
    } else if(imc >= 25.0 && imc <= 29.9){
        printf("Sobrepeso, gordo\n");
    } else {
        printf("Estas obeso\n");
    }
}

//Implentacion de la funcion del 19 ejercicio.
void triangles_side(){
    double a_side, b_side, c_side;

    printf("Lado A: ");
    scanf("%lf", &a_side);
    
    printf("Lado B: ");
    scanf("%lf", &b_side);
    
    printf("Lado C: ");
    scanf("%lf", &c_side);

    //Verifica si los lados forman un triangulo valido.
    if((a_side + b_side > c_side) && (a_side + c_side > b_side) && (b_side + c_side > a_side)){
        printf("Los lados foman un triangulo valido\n");

        // Determina el tipo de triángulo
        if (a_side == b_side && b_side == c_side) {
            printf("El triangulo es equilatero.\n");
        } else if (a_side == b_side || a_side == c_side || b_side == c_side) {
            printf("El triangulo es isosceles.\n");
        } else {
            printf("El triangulo es escaleno.\n");
        }
    } else {
        printf("Error, los lados no forman un triangulo valido\n");
    }
}

//Implentacion de la funcion del ejercicio num 20.
void numero_primo(){
    int num, i;
    bool is_prime = true;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if(num <= 1) {
        is_prime = false;
    } else{
        for(i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                is_prime = false;
                break;
            }
        }
    }

    // Imprime el resultado
    if(is_prime) {
        printf("El numero %d es primo\n", num);
    } else{
        printf("El numero %d no es primo. Sus divisores son: 1", num);
        for(i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                printf(", %d", i);
            }
        }
        printf(", %d\n", num); // El número siempre es divisible por sí mismo
    }
}
