#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARQUIVO "estoque.bin"

typedef struct {
    char descricao[40];
    int quantidadeEstoque;
    int minimoEstoque;
    float precoVenda;
} Produto;


void incluirProduto(Produto produto){
    FILE* file;    
    file = fopen("estoque.bin", "r+b");
    fseek(file, 0, SEEK_END);
    fwrite(&produto, sizeof(Produto), 1, file);
    fclose(file);
};


void buscarProduto(int b, Produto produto){
    FILE* file;    
    Produto produtoLeitura;
    
    file = fopen("estoque.bin", "r+b");
    fseek(file, (b * sizeof(Produto)), SEEK_SET);
    fread(&produtoLeitura, sizeof(Produto), 1, file);

    printf("%s %d %d %f", produtoLeitura.descricao, produtoLeitura.quantidadeEstoque, produtoLeitura.minimoEstoque, produtoLeitura.precoVenda);
    
    fclose(file);
};

void registrarVenda(int i, Produto produto){
    FILE* file;    
    file = fopen("estoque.bin", "r+b");
    fclose(file);
};

void relatorioEstoqueMinimo(){
    FILE* file;    
    file = fopen("estoque.bin", "r+b");
    fclose(file);
};

void limparBuffer(Produto produto){
    FILE* file;    
    file = fopen("estoque.bin", "r+b");
    fclose(file);
};


void exibirMenu(Produto produto){
    FILE* file;    
    file = fopen("estoque.bin", "r+b");
    fclose(file);
};


int main() {
    int opcao, i;

    do {
        printf("Escolha uma opcao: ");
        i = scanf("%d", &opcao);
        //limparBuffer(); 

        Produto produto;
        strcpy(produto.descricao, "descricao");
        produto.quantidadeEstoque = 1;
        produto.minimoEstoque = 2;
        produto.precoVenda = 3;

        exibirMenu(produto);
        
        switch(opcao) {
            case 1:
                incluirProduto(produto);
                break;
            case 2:
                buscarProduto(99, produto);
                break;
            case 3:
                registrarVenda(3, produto);
                break;
            case 4:
                relatorioEstoqueMinimo();
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 5);

    return 0;
}
