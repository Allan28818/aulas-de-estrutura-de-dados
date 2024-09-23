#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int code;
    char name[30];
    float price;
} Product;

typedef struct {
    Product product;
    int quantity;
} Cart;

Product* products = NULL;
Cart* cart = NULL;
int totalProducts = 0;
int totalCart = 0;
int maxProducts = 0;
int maxCart = 0;

void menu();
void registerProduct();
void listProducts();
void buyProduct();
void viewCart();
void checkout();
int findProductByCode(int code);
int findInCart(int code);
int getValidInt(const char* message);
float getValidFloat(const char* message);

int main() {
    menu();
    free(products);
    free(cart);
    return 0;
}

void menu() {
    int option;
    do {
        option = getValidInt("\n--- Menu do Supermercado ---\n1. Cadastrar Produto\n2. Listar Produtos\n3. Comprar Produto\n4. Visualizar Carrinho\n5. Fechar Pedido\n6. Sair\nEscolha uma opção: ");
        switch(option) {
            case 1:
                registerProduct();
                break;
            case 2:
                listProducts();
                break;
            case 3:
                buyProduct();
                break;
            case 4:
                viewCart();
                break;
            case 5:
                checkout();
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(option != 6);
}

void registerProduct() {
    if (totalProducts == maxProducts) {
        maxProducts += 10;
        products = realloc(products, maxProducts * sizeof(Product));
    }

    Product newProduct;
    newProduct.code = getValidInt("Digite o código do produto: ");
    
    if (findProductByCode(newProduct.code) != -1) {
        printf("Código já cadastrado. Tente novamente com outro código.\n");
        return;
    }

    printf("Digite o nome do produto: ");
    scanf("%s", newProduct.name);
    while (getchar() != '\n');

    newProduct.price = getValidFloat("Digite o preço do produto: ");

    products[totalProducts] = newProduct;
    totalProducts++;

    printf("Produto cadastrado com sucesso!\n");
}

void listProducts() {
    if (totalProducts == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < totalProducts; i++) {
        printf("Código: %d | Nome: %s | Preço: %.2f\n", products[i].code, products[i].name, products[i].price);
    }
}

void buyProduct() {
    if (totalProducts == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int code = getValidInt("Digite o código do produto que deseja comprar: ");

    int index = findProductByCode(code);
    if (index == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    int cartIndex = findInCart(code);
    if (cartIndex != -1) {
        cart[cartIndex].quantity++;
    } else {
        if (totalCart == maxCart) {
            maxCart += 10;
            cart = realloc(cart, maxCart * sizeof(Cart));
        }
        Cart newCartItem;
        newCartItem.product = products[index];
        newCartItem.quantity = 1;
        cart[totalCart] = newCartItem;
        totalCart++;
    }

    printf("Produto adicionado ao carrinho.\n");
}

void viewCart() {
    if (totalCart == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }

    printf("\n--- Carrinho de Compras ---\n");
    for (int i = 0; i < totalCart; i++) {
        printf("Código: %d | Nome: %s | Quantidade: %d | Preço Unitário: %.2f | Total: %.2f\n",
            cart[i].product.code, cart[i].product.name, cart[i].quantity,
            cart[i].product.price, cart[i].product.price * cart[i].quantity);
    }
}

void checkout() {
    if (totalCart == 0) {
        printf("O carrinho está vazio.\n");
        return;
    }

    float totalPrice = 0;
    printf("\n--- Fatura ---\n");
    for (int i = 0; i < totalCart; i++) {
        float itemTotal = cart[i].product.price * cart[i].quantity;
        printf("Código: %d | Nome: %s | Quantidade: %d | Preço Unitário: %.2f | Total: %.2f\n",
            cart[i].product.code, cart[i].product.name, cart[i].quantity,
            cart[i].product.price, itemTotal);
        totalPrice += itemTotal;
    }
    printf("Valor total da compra: %.2f\n", totalPrice);

    totalCart = 0;
    printf("Pedido fechado com sucesso!\n");
}

int findProductByCode(int code) {
    for (int i = 0; i < totalProducts; i++) {
        if (products[i].code == code) {
            return i;
        }
    }
    return -1;
}

int findInCart(int code) {
    for (int i = 0; i < totalCart; i++) {
        if (cart[i].product.code == code) {
            return i;
        }
    }
    return -1;
}

int getValidInt(const char* message) {
    char input[100];
    char* endptr;
    long number;
    while (1) {
        printf("%s", message);
        fgets(input, 100, stdin);
        number = strtol(input, &endptr, 10);
        if (endptr == input || *endptr != '\n' && *endptr != '\0') {
            printf("Entrada inválida. Por favor, insira um número inteiro.\n");
        } else {
            return (int)number;
        }
    }
}

float getValidFloat(const char* message) {
    char input[100];
    char* endptr;
    float number;
    while (1) {
        printf("%s", message);
        fgets(input, 100, stdin);
        number = strtof(input, &endptr);
        if (endptr == input || *endptr != '\n' && *endptr != '\0') {
            printf("Entrada inválida. Por favor, insira um número válido.\n");
        } else {
            return number;
        }
    }
}
