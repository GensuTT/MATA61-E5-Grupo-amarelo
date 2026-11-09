# Exercício 5 (E5) - Interpretador de expressões aritméticas com construção de AST

Considere o exemplo do capítulo 5, 
seção "5.4 Expression Trees" do livro de Douglas Thain.

Considere a linguagem de expressões aritméticas do exercício E4.
Neste exercício E5, seu programa deve criar uma árvore sintática abstrata (AST)
para expressões aritmáticas sintaticamente corretas.
A árvore deverá ser percorrida para avaliação da expressão aritmética.



- Use a gramática do exercício E4 (que incluiu números negativos e 
expressão entre parênteses).
As ações semânticas associadas às regras de produção criação nós da AST,
conforme os exemplos da seção 5.4.


## Instruções para Configuração do Repositório da Equipe

- [Leia com atenção!](./instructions.md)

---

## Descrição Geral

O programa recebe uma expressão pela entrada padrão
e mostra, na saída padrão:
- "expressão sem erro sintático"
e resultado da avaliação da expressão.

ou:

- "expressão com erro sintático".
Se houver erro léxico, ele será reportado como erro sintático.

Se não houver erro sintático, após a mensagem,
o resultado será mostrado na saída padrão.

### Testes

Os arquivos de teste devem ser texto simples. Os arquivos de entrada, com uma linha contendo uma expressão aritmética,
devem ter extensão '.in'; os arquivos com a saída esperada (oráculo) devem ter extensão '.ora' e seguir o formato de
saída ilustrado nos exemplos.

- Definir uma função main() que chama a função yyparse() 
e depois outra função para interpretar o programa.

### Testes

Colocar mais testes na pasta \tests para os cenários indicados em \tests\cenarios.md

### Entrega

A entrega do exercício E5 deve ser feita apenas via GitHub,
com o código fonte de sua implementação e arquivos indicados a seguir.

Arquivos:
- ./README-E5.md, com nomes dos membros da equipe (primeiras linhas, como comentário e orientações para compilar, executar e testar seu código.
- ./makefile, com opções 'compile' e 'test'
- ./<arquivos com código fonte>
- Pasta ./'tests', contendo seus testes I/O para os cenários indicados em \tests\cenarios.md

