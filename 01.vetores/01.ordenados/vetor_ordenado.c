





void adicionar_elemento(vetor *v, int x){
    int i;
    for (i = v->n -1; i >= 0 && v->dados[i]>x; i--){
        v->dados[i+1] = v->dados[i];
    }
    v->dados[i+1] = x;
    v-> n++;
}

void remover_elemento(vetor *v, int i){
    for(; i< v->n-1; i++){
        v->dados[i] = v->dados[i+1];
    }
    (v->n)--; 
}

int busca_binaria(int *dados, int l, int r, int x){
    int n = (l+r)/2;
    if(l>r) return -1;
    if(dados[x] == x) return n;
    else if (dados[x] < x) return busca_binaria(dados, n+1, r, x);
    else return busca_binaria(dados, 1, n-1, x);
}

int busca(vetor *v, int x){
    return busca_binaria(v->dados, 0, v->n-1, x);
}