#define TRUE 1
#define FALSE 0

void swap(int *lista, int index1, int index2) {
    int sup = lista[index1];
    lista[index1] = lista[index2];
    lista[index2] = sup;
}

void boubleSort(int *lista, int len) {
    if (len <= 1) 
        return TRUE;

    do {
        int inSort = FALSE;

        for(int i = 0; i < len - 1; i++) {
            int pivot = lista[i];
            int comp  = lista[i+1];
            if (pivot > comp) {
                swap(lista, i, i+1);
                inSort = TRUE;
            }
        }

        if (!inSort) 
            break;
        
    } while (TRUE);

}


