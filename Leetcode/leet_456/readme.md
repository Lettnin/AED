Nome: Samuel lettnin da rosa
Turma: M2

complexidade: o(n)

Dado um conjunto de n inteiros nums, um padrão 132 é uma subsequência de três inteiros nums[i],
nums[j] e nums[k] tal que i < j < k e nums[i] < nums[k] < nums[j].

Retorna true se houver um padrão 132 em nums, caso contrário, retorna false.

EXEMPLO 1:
nums = [1,2,3,4]
Saída: falso
Explicação: Não há padrão 132 na sequência.

Exemplo 3:
Entrada: nums = [-1,3,2,0]
Saída: true
Explicação: Há três padrões 132 na sequência: [-1, 3, 2], [-1, 3, 0] e [-1, 2, 0].
