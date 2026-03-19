# Desafio: Agenda com Buffer de Memória Dinâmico
**Disciplina:** Algoritmos e Estruturas de Dados | **Turma:** M2  
**Desenvolvedor:** Samuel Lettnin da Rosa

---

## 📝 Descrição do Projeto
O objetivo deste projeto é desenvolver uma agenda de contatos em C, simulando o gerenciamento de memória que um Sistema Operacional realiza. O diferencial técnico é a proibição total do uso de variáveis locais, globais ou estruturas (`struct`).

### 🛠️ Funcionalidades (Menu)
1. **Adicionar Pessoa:** Registra Nome, Idade e E-mail.
2. **Remover Pessoa:** Exclui um contato do buffer.
3. **Buscar Pessoa:** Localiza um registro específico.
4. **Listar todos:** Exibe todos os contatos armazenados.
5. **Sair:** Encerra o programa e libera a memória.

---

## ⚠️ Regras de Implementação (Restrições)
Para simular o baixo nível, o projeto segue as seguintes diretrizes estritas:

*   **Buffer Único:** Todo e qualquer dado deve ser armazenado em um único `void *pBuffer`.
*   **Proibido Variáveis:** Nenhuma variável (como `int c`, `char a`, etc.) pode ser declarada em qualquer parte do programa.
*   **Apenas Ponteiros:** O controle do fluxo e armazenamento deve ser feito exclusivamente via ponteiros que apontam para dentro do `pBuffer`.
*   **Sem Parâmetros de Valor:** Funções não podem receber cópias de valores, apenas ponteiros para endereços no buffer.
*   **Sem Structs:** É proibido o uso de `struct` para organizar os dados. A organização deve ser feita via aritmética de ponteiros manualmente.

---

## 🚀 Como Executar
1. Compile o arquivo:
   ```bash
   gcc -o agenda main.c
