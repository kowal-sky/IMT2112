/*
Comandos útiles:
Compilar código:    g++ -o name_output test_times.cpp -fopenmp
Correr código:      ./name_output
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
 
int linear_red(){
    int x2 = 0;
    int n = 10;
    int* array = (int*) calloc(n, sizeof(int));
    
    #pragma omp parallel for num_threads(n)
    for (int i = 0; i < 100000000; i++) {
        int id = omp_get_thread_num();
        array[id] += 1;
        // printf("Proceso %d sumó 1\n", id);  
    }

    for (int i = 0; i < n; i++) {
        x2 += array[i]; 
    }

    printf("\nSuma Final 2 = %d\n", x2);

    free(array);

    return 0;

}


int omp_red(){

    int x3 = 0; 
    
    // Agregamos el parámetro reduction al pragma
    #pragma omp parallel for num_threads(24) reduction(+:x3)
    for (int i = 0; i < 100000000; i++) {
        int id = omp_get_thread_num();
        x3 += 1;
        // printf("Proceso %d sumó 1\n", id);  
    }

    printf("\nSuma Final 3 = %d\n", x3);
    

    return 0;

}
    
    
int main() {


    // linear_red();
    omp_red();



    return 0;
}