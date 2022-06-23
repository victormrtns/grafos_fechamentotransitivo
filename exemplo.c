#include <stdio.h>
#define FALSE 0
void ligar(int ponto1,int ponto2, int matriz[][20]);
int calc_caminho(int matrizadj[][20],int caminho[][20],int a,int b);
void prod_bool(int matrizadj[][20],int caminho[][20],int newprod[][20]);
int main(){
    const int n = 20;
    int a,b,i,j;
    int ponto1,ponto2;
    int matrizadj[n][n];
    int caminho[n][n];
    //Digitar de onde até onde deseja chegar
    printf("Digite o destino [a-b]:  ");
    scanf("%d %d",&a,&b);
    //Inicializar a matriz como 0
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            matrizadj[i][j] = 0;
            caminho[i][j] = 0;
        }
    } 
    printf("Insira os pontos que você deseja ligar: ");
    ponto1 = 1;
    while(ponto1!=0){
        scanf("%d",&ponto1);
        if(ponto1 ==0)
            break;
        scanf("%d",&ponto2);
    
        ligar(ponto1,ponto2, matrizadj);
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            caminho[i][j] = matrizadj[i][j] ;
        }
    } 
    //Passa a matrizadj que voce "ligou os pontos", a matriz caminho que voce passa inicializada com 0's e os pontos a e b.
    calc_caminho(matrizadj,caminho,a,b);

}

//Ligar os pontos.
void ligar(int ponto1,int ponto2, int matriz[][20]){
    matriz[ponto1][ponto2] = 1;
}

void prod_bool(int adjprod[][20],int matrizadj[][20],int newprod[][20]){
int i,j,k;
int val;
for(i=0;i<20;++i){
    for(j=0;j<20;++j){
        val = FALSE;
        for(k=0;k<20;++k){
            val = val || (adjprod[i][k] && matrizadj[k][j]);
        }
        newprod[i][j] = val;
    }
}
    for(i=0;i<20;++i){
        for(j=0;j<20;++j){
            adjprod[i][j] = newprod[i][j];
    }
    }
}
int calc_caminho(int matrizadj[][20],int caminho[][20],int a,int b){
int i,j,k;
//Cria duas matrizes auxiliares, a newprod é inicializado com 0 e a matriz caminho e adjprod recebe a matriz original
int newprod[20][20];
int adjprod[20][20];
//Cria uma variável auxiliar.
//Não preciso inicializar newprod[i][j] com 0's
int val;
for(i=0;i<20;++i){
for(j=0;j<20;++j){
        adjprod[i][j] = matrizadj[i][j];
}
}

for(k=0;k<20;++k){
//Faz o produto booleano cerca de 20 vezes
//prod_bool recebe a matriz adjprod que é a matriz que multiplica, a matrizadj que é a matriz original e a newprod que é a auxiliar.
prod_bool(adjprod,matrizadj,newprod);

//Faz o produto booleano, ve se a matriz original na posicao [i][k] = 1 (tem caminho de comp 1) e a matriz produto adjprod na
//posicao [k][j] = 1 (tem caminho de comp k), transformando a matriz newprod[i][j] = 1 se for achado.
for(i=0;i<20;i++){
    for(j=0;j<20;j++){
       //Se caminho[i][j] == 0 e newprod tambem, a matriz caminho recebe 0
       //Se nao, recebe 1, sabendo que newprod é a matriz adjI, ou seja, pode ser a matriz adj1,adj2,...,adj20
       //Entao se um dos dois for 1, caminho[i][j] assume 1, pois ele so quer saber se possui caminho, independente do tamanho
    caminho[i][j] = caminho[i][j] || newprod[i][j];
    }
}

}
//Assume se caminho na pos [a][b] é igual a 1, ou seja, tem caminho independente do comprimento
if(caminho[a][b] ==1){
    printf("Tem caminho\n");
}
else{
    printf("Nao tem caminho\n");
}

//Printar a matriz caminho
for (i = 0; i < 20; i++)
    {
        printf("%d [ ", i);
        for (j = 0; j < 20; j++)
            printf("%d ", caminho[i][j]);
        printf("]\n");
    }

}

