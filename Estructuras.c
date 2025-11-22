#include "Estructuras.h"

MaxHeap_t *Crear_heap(){ //... crea el heap, wow como no lo pense antes
    MaxHeap_t *m = (MaxHeap_t *)malloc(sizeof(MaxHeap_t));
    m->capacidad = 100;
    m->tamaño = 0;
    m->contador = 1;
    m->alerta = (Alerta_t *)malloc(sizeof(Alerta_t) * m->capacidad);
    return m;
}

void Liberar_heap(MaxHeap_t *m){ //... lit lo dice libera el MaxHeap
    free(m->alerta);
    free(m);
}

void Cambiar(Alerta_t *a, Alerta_t *b){ //va a servir para cambiar la prioridad
    Alerta_t temporal = *a;
    *a = *b;
    *b = temporal;
}

int Mayor(Alerta_t a, Alerta_t b){ //este va a ocupar el cambiar, para definir por prioridad u orden de llegada
    if(a.prioridad > b.prioridad){ //comparamos por prioridad
        return 1;
    }
    if(a.prioridad == b.prioridad){ //comparamso por orden de llegada
        if(a.orden_llegada < b.orden_llegada){
            return 1;
        }
    }
    return 0;
}

int Calcular_prioridad(const char *tipo_desastre, float magnitud, int poblacion){ //calcula que tan urgente es el incidente
    float puntos = 0;
    
    if(strcmp(tipo_desastre, "Terremoto") == 0){
        if(magnitud >= 1 && magnitud < 4) puntos = 1.8;
        else if(magnitud >= 4 && magnitud < 7) puntos = 2.5;
        else if(magnitud >= 7 && magnitud < 9) puntos = 6;
        else if(magnitud >= 9) puntos = 10;
    }
    if(strcmp(tipo_desastre, "Tsunami") == 0){
        if(magnitud >= 1 && magnitud <= 2) puntos = 1.5;
        else if(magnitud > 2 && magnitud <= 5) puntos = 4;
        else if(magnitud > 5 && magnitud <= 10) puntos = 8;
        else if(magnitud > 10) puntos = 9.5;
    }
    if(strcmp(tipo_desastre, "Huracan") == 0 || strcmp(tipo_desastre, "Ciclon") == 0){
        if(magnitud >= 119 && magnitud < 152) puntos = 1.2;
        else if(magnitud >= 152 && magnitud < 208) puntos = 3;
        else if(magnitud >= 208 && magnitud < 251) puntos = 6.5;
        else if(magnitud >= 251) puntos = 9;
        else puntos = 0;
    }
    if(strcmp(tipo_desastre, "Erupcion Volcanica") == 0){
        if(magnitud >= 1 && magnitud <= 2) puntos = 2;
        else if(magnitud == 3) puntos = 4.5;
        else if(magnitud >= 4 && magnitud <= 5) puntos = 7.5;
        else if(magnitud >= 6) puntos = 9.8;
        else puntos = 0;
    }
    if(strcmp(tipo_desastre, "Sequia") == 0){
        if(magnitud < -2.0) puntos = 8.5;         
        else if(magnitud < -1.5) puntos = 7.0;    
        else if(magnitud < -1.0) puntos = 3.5;    
        else if(magnitud < 0) puntos = 1.0;       
        else puntos = 0;
    }
    if(strcmp(tipo_desastre, "Incendio") == 0){
        if(magnitud >= 0 && magnitud < 100) puntos = 2.6;
        else if(magnitud >= 100 && magnitud < 1000) puntos = 3.2;
        else if(magnitud >= 1000 && magnitud < 10000) puntos = 6.8;
        else if(magnitud >= 10000) puntos = 8.8;

    }
    if(strcmp(tipo_desastre, "Tornado") == 0){
        if(magnitud >= 105 && magnitud < 178) puntos = 1.3;
        else if(magnitud >= 178 && magnitud < 265) puntos = 2.5;
        else if(magnitud >= 265 && magnitud < 323) puntos = 5.5;
        else if(magnitud >= 323) puntos = 8.2;
        else puntos = 0;
    }
    if(strcmp(tipo_desastre, "Inundacion") == 0){
        if(magnitud >= 0 && magnitud <= 1) puntos = 1.8;
        else if(magnitud > 1 && magnitud <= 2.5) puntos = 2.2;
        else if(magnitud > 2.5 && magnitud  <= 4) puntos = 4.8;
        else if(magnitud > 4) puntos = 7.5;
    }
    if(strcmp(tipo_desastre, "Avalancha") == 0){
        if(magnitud >= 0 && magnitud < 100) puntos = 1.5;
        else if(magnitud >= 100 && magnitud < 1000) puntos = 2;
        else if(magnitud >= 1000 && magnitud < 10000) puntos = 5;
        else if(magnitud >= 10000) puntos = 7.8;
    }
    if(strcmp(tipo_desastre, "Vendaval") == 0){
        if(magnitud >= 50 && magnitud <= 70) puntos = 0.4;
        else if(magnitud > 70 && magnitud <= 100) puntos = 1.8;
        else if(magnitud >= 100 && magnitud <130) puntos = 4.2;
        else if(magnitud > 130) puntos = 6.2;
        else puntos = 0;
    }
    
    float prioridad = puntos * poblacion;
    
    return (int)prioridad;
}

void Heapify_up(MaxHeap_t *m, int indice){ //para insertar un nuevo elemento al final del monton biario y cambia hasta que se cumpla la prioridad del monton
    int padre = (indice - 1) / 2;
    while(indice > 0 && Mayor(m->alerta[indice], m->alerta[padre])){
        Cambiar(&m->alerta[indice], &m->alerta[padre]);
        indice = padre;
        padre = (indice - 1) / 2;
    }
}

void Heapify_down(MaxHeap_t *m, int indice){ //restaura la priopiedad del monton del arbol despues de una modificacion
    int maximo = indice;
    int derecha = 2 * indice + 1;
    int izquierda = 2 * indice + 2;

    if(izquierda < m->tamaño && Mayor(m->alerta[izquierda], m->alerta[maximo])){
        maximo = izquierda;
    }
    if(derecha < m->tamaño && Mayor(m->alerta[derecha], m->alerta[maximo])){
        maximo = derecha;
    }
    if(maximo != indice){
        Cambiar(&m->alerta[indice], &m->alerta[maximo]);
        Heapify_down(m, maximo);
    }
}

void Insertar(MaxHeap_t *m, Alerta_t nueva_alerta){ //inserta la alerta en el Heap
    if(m->tamaño == m->capacidad){ //si el heap esta lleno lo redimensionamos
        int nueva_capacidad = m->capacidad * 2;
        Alerta_t *temp = (Alerta_t *)realloc(m->alerta, sizeof(Alerta_t) * nueva_capacidad);
        if(temp == NULL){
            printf("\nError: No se pudo redimensionar el Heap.\n");
            return;
        }
        m->alerta = temp;
        m->capacidad = nueva_capacidad;
        printf("\nHeap redimensionado a capacidad %d.\n", m->capacidad);
    }
    nueva_alerta.orden_llegada = m->contador++; //asignar orden de llegada
    nueva_alerta.prioridad = Calcular_prioridad(nueva_alerta.desastre, nueva_alerta.magnitud, nueva_alerta.afectados); 

    m->alerta[m->tamaño] = nueva_alerta; //lo inserta en el heap
    Heapify_up(m, m->tamaño);
    m->tamaño++;
}

Alerta_t Extraer(MaxHeap_t *m){ //extrae la alerta en el heap
    if(m->tamaño <= 0){ //si el heap esta vacio crea una alerta vacia 
        Alerta_t alerta_vacia = {"Vacio", "N/A", 0.0, 0, 0, 0};
        return alerta_vacia;
    }

    Alerta_t maxima = m->alerta[0]; //guarda la maxima alerta en la raiz
    m->alerta[0] = m->alerta[m->tamaño - 1]; //mueve el ultimo elemento en la raiz
    m->tamaño--;

    Heapify_down(m, 0); //reestructura el heap

    return maxima;
}
