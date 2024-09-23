# Sistema de Supermercado em C

## Descrição do Projeto

Este projeto é um sistema simples de supermercado desenvolvido em linguagem C. Ele implementa conceitos de estruturas de dados, como `structs`, arrays dinâmicos e funções. O sistema permite o cadastro de produtos, a listagem de produtos cadastrados, a adição de produtos ao carrinho, a visualização do carrinho e o fechamento de pedido, calculando o valor total da compra.

## Funcionalidades

O sistema possui as seguintes funcionalidades:

1. **Cadastrar Produto**: Permite o cadastro de novos produtos, com um código único, nome e preço.
2. **Listar Produtos**: Exibe todos os produtos cadastrados no sistema, com seu código, nome e preço.
3. **Comprar Produto**: O usuário pode selecionar produtos através do código e adicioná-los ao carrinho de compras.
4. **Visualizar Carrinho**: Exibe os produtos adicionados ao carrinho com suas respectivas quantidades e preços totais.
5. **Fechar Pedido**: Calcula o valor total da compra, exibe uma fatura detalhada e esvazia o carrinho após a finalização do pedido.
6. **Sair**: Encerra o sistema de maneira segura.

## Requisitos

- Linguagem C
- Biblioteca padrão de C (`stdio.h`, `stdlib.h`, `string.h`)

## Como Rodar o Projeto

### Compilação

Para compilar o projeto, você pode utilizar um compilador de C como o GCC. O comando de compilação básico é:

```bash
gcc supermarket.c -o supermarket
```

Esse comando compila o código e gera um executável chamado `supermarket`.

### Execução

Após a compilação, execute o programa com o seguinte comando:

```bash
./supermarket
```

### Uso

Ao iniciar o programa, o menu principal será exibido, permitindo a escolha das opções disponíveis:

1. **Cadastrar Produto**: Insira um código único, nome e preço do produto.
2. **Listar Produtos**: Exibe todos os produtos já cadastrados.
3. **Comprar Produto**: Insira o código do produto desejado e ele será adicionado ao carrinho.
4. **Visualizar Carrinho**: Exibe os itens no carrinho com suas quantidades e preços.
5. **Fechar Pedido**: Calcula e exibe o valor total da compra e esvazia o carrinho.
6. **Sair**: Encerra o programa.

## Validações Implementadas

- **Entrada de dados**: O sistema valida entradas de inteiros (códigos de produtos e opções de menu) e floats (preço do produto). Caso o usuário insira uma string ou um valor inválido, uma mensagem de erro será exibida e a entrada será solicitada novamente.
- **Código único para produtos**: Cada produto cadastrado deve ter um código único. Caso o código já exista, o sistema notificará o usuário.

## Estrutura do Código

### Principais Funções

- **`menu()`**: Controla o fluxo do programa e apresenta as opções para o usuário.
- **`registerProduct()`**: Permite o cadastro de novos produtos.
- **`listProducts()`**: Exibe todos os produtos cadastrados.
- **`buyProduct()`**: Adiciona produtos ao carrinho de compras.
- **`viewCart()`**: Exibe os produtos no carrinho.
- **`checkout()`**: Calcula o valor total da compra, exibe a fatura e esvazia o carrinho.
- **`getValidInt()`**: Função auxiliar que valida a entrada de inteiros.
- **`getValidFloat()`**: Função auxiliar que valida a entrada de floats.

### Estruturas de Dados

- **`Product`**: Estrutura para armazenar informações de produtos (código, nome e preço).

  ```c
  typedef struct {
      int code;
      char name[30];
      float price;
  } Product;
  ```

- **`Cart`**: Estrutura para armazenar produtos no carrinho e suas quantidades.

  ```c
  typedef struct {
      Product product;
      int quantity;
  } Cart;
  ```

- Arrays dinâmicos são usados para armazenar produtos e itens no carrinho.

## Melhorias Futuras

Algumas possíveis melhorias para o projeto incluem:

1. **Remover itens do carrinho**: Adicionar a funcionalidade para remover produtos do carrinho.
2. **Atualizar produtos cadastrados**: Implementar a opção de editar o nome e o preço dos produtos cadastrados.
3. **Persistência de dados**: Salvar os produtos e o carrinho em arquivos para que os dados sejam preservados entre execuções do programa.

## Tratamento de Erros

O código contém tratamento básico de erros para entradas inválidas. Se o usuário tentar inserir uma string no lugar de um número, ou um número inválido, o sistema avisará e pedirá uma nova entrada.
