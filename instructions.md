# Exercício 5 (E5) - Análise Sintática, com geração de AST

## Instruções para Configuração do Repositório da Equipe

O trabalho deve ser feito em equipe. 
Siga os passos abaixo rigorosamente para configurar o ambiente do seu grupo:

### 1. Criar o Repositório Privado da Equipe
1. Um dos membros da equipe deve acessar o GitHub e criar um novo repositório.
2. Configure o repositório como **Private** (Privado).
3. **Não** adicione README, .gitignore ou licença (deixe o repositório completamente vazio).
4. Nomeie o repositório seguindo o padrão: `MATA61-E5-Grupo-X` (substitua X pelo nome do seu grupo).

### 2. Importar o Conteúdo da Especificação
Abra o terminal na sua máquina e execute os seguintes comandos para clonar o repositório da disciplina e empurrá-lo para o repositório privado do seu grupo:

```bash
# Clone o repositório base da disciplina usando a opção --bare
git clone --bare https://github.com/MATA61-20262/E5.git

# Acesse a pasta criada
cd E5.git

# Envie o conteúdo para o novo repositório privado do seu grupo
# (Substitua a URL abaixo pela URL do repositório que seu grupo criou)
git push --mirror https://github.com

- Usar tokens de acesso

# Apague a pasta temporária E5.git da sua máquina
cd ..
rm -rf E5.git
```

Agora, **clone o repositório privado do seu grupo* normalmente na sua máquina para começar a trabalhar.

### 3. Adicionar a Professora e a Equipe
1. No repositório privado do grupo, vá em **Settings** > **Collaborators** > **Add people**.
2. Adicione os outros membros da equipe.
3. Adicione o usuário da professora: `christinaflachufba`.

---

## Como Entregar

Para facilitar a correção, **não faça commits diretamente na branch `main`**. Use o fluxo de Pull Requests (PR):

1. Crie uma branch chamada `e5` (`git checkout -b e5`).
2. Desenvolva a solução nesta branch.
3. Abra um **Pull Request** da branch `e5` para a branch `main` dentro do seu repositório.
4. **Não fazer "Merge" no PR!** 
O link desse Pull Request aberto será a entrega da equipe na plataforma da disciplina.
A professora usará este PR para comentar no código e dar a nota.

