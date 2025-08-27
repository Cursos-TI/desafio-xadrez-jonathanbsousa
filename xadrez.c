#include <stdio.h>

// --- Constantes para definir os movimentos ---
// Define o número de casas que cada peça irá se mover.
const int TORRE_MOVIMENTOS = 5;
const int BISPO_MOVIMENTOS = 5;
const int RAINHA_MOVIMENTOS = 8;

// Define os componentes do movimento em "L" do Cavalo.
const int CAVALO_MOV_CIMA = 2;
const int CAVALO_MOV_DIREITA = 1;


// --- Protótipos das Funções Recursivas ---
void moverTorreRecursivo(int movimentosRestantes);
void moverBispoRecursivo(int movimentosRestantes);
void moverRainhaRecursivo(int movimentosRestantes);
void moverCavaloComplexo();


/**
 * @brief Função principal que orquestra a simulação de movimento de todas as peças.
 */
int main() {
    // --- Movimento da Torre (com recursão) ---
    printf("--- Movimento da Torre (Recursivo) ---\n");
    moverTorreRecursivo(TORRE_MOVIMENTOS);
    printf("\n"); // Adiciona uma linha em branco para separação

    // --- Movimento do Bispo (com recursão e loops aninhados) ---
    printf("--- Movimento do Bispo (Recursivo e com Loops Aninhados) ---\n");
    moverBispoRecursivo(BISPO_MOVIMENTOS);
    printf("\n"); // Adiciona uma linha em branco para separação

    // --- Movimento da Rainha (com recursão) ---
    printf("--- Movimento da Rainha (Recursivo) ---\n");
    moverRainhaRecursivo(RAINHA_MOVIMENTOS);
    printf("\n"); // Adiciona uma linha em branco para separação

    // --- Movimento do Cavalo (com loops complexos) ---
    printf("--- Movimento do Cavalo (Loop Complexo) ---\n");
    moverCavaloComplexo();
    printf("\n"); // Adiciona uma linha em branco para separação

    return 0; // Finaliza o programa com sucesso
}


/**
 * @brief Simula o movimento da Torre para a direita usando recursividade.
 * @param movimentosRestantes O número de casas que a torre ainda precisa mover.
 */
void moverTorreRecursivo(int movimentosRestantes) {
    // Caso base: Se não houver mais movimentos, a função para.
    if (movimentosRestantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento da casa atual.
    printf("Direita\n");

    // Passo recursivo: Chama a si mesma com um movimento a menos.
    moverTorreRecursivo(movimentosRestantes - 1);
}

/**
 * @brief Simula o movimento do Bispo na diagonal (cima, direita) usando
 * recursividade e loops aninhados.
 * @param movimentosRestantes O número de casas que o bispo ainda precisa mover.
 */
void moverBispoRecursivo(int movimentosRestantes) {
    // Caso base: Se não houver mais movimentos, a função para.
    if (movimentosRestantes <= 0) {
        return;
    }

    // Requisito de loops aninhados: O loop externo representa o movimento vertical
    // e o interno o horizontal para formar uma única casa na diagonal.
    // Ambos os loops executam apenas uma vez por chamada recursiva.
    for (int v = 0; v < 1; v++) {       // Loop externo para movimento vertical
        for (int h = 0; h < 1; h++) {   // Loop interno para movimento horizontal
            // Ação: Imprime o movimento combinado da diagonal.
            printf("Cima, Direita\n");
        }
    }

    // Passo recursivo: Chama a si mesma com um movimento a menos.
    moverBispoRecursivo(movimentosRestantes - 1);
}

/**
 * @brief Simula o movimento da Rainha para a esquerda usando recursividade.
 * @param movimentosRestantes O número de casas que a rainha ainda precisa mover.
 */
void moverRainhaRecursivo(int movimentosRestantes) {
    // Caso base: Se não houver mais movimentos, a função para.
    if (movimentosRestantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento da casa atual.
    printf("Esquerda\n");

    // Passo recursivo: Chama a si mesma com um movimento a menos.
    moverRainhaRecursivo(movimentosRestantes - 1);
}

/**
 * @brief Simula o movimento em "L" do Cavalo (2 para cima, 1 para a direita)
 * usando um único loop complexo com múltiplas variáveis de controle.
 */
void moverCavaloComplexo() {
    // Este loop usa duas variáveis de controle: 'vertical' e 'horizontal'.
    // A condição de parada do loop é que ambos os contadores tenham atingido
    // seus limites definidos nas constantes.
    for (int vertical = 0, horizontal = 0; vertical < CAVALO_MOV_CIMA || horizontal < CAVALO_MOV_DIREITA;) {
        
        // Condição para o movimento vertical:
        // Enquanto o contador 'vertical' não atingiu o limite, move para cima.
        if (vertical < CAVALO_MOV_CIMA) {
            printf("Cima\n");
            vertical++; // Incrementa o contador de movimentos verticais
            continue;   // O 'continue' pula para a próxima iteração, garantindo
                        // que o movimento horizontal só comece após os verticais.
        }

        // Condição para o movimento horizontal:
        // Acontece apenas após os movimentos verticais terem sido concluídos.
        if (horizontal < CAVALO_MOV_DIREITA) {
            printf("Direita\n");
            horizontal++; // Incrementa o contador de movimentos horizontais
        }
    }
}