# 👻 Trabalho 1 - Racionais

> [!NOTE]
> O trabalho é um projeto pequeno que manipula uma TAD de números racionais. Totalmente feito em `C` como trabalho final de programação 1 na faculdade [^1]

## ☕ Info

- **Matéria**: Programação 1 [^1]
- **Data**: segundo semestre de 2023
- **Linguagem**: `C`

## 🐛 Comandos

### Setup:
```bash
# Compilar o programa em um arquivo ./tp1
make

# Rodar o programa
./tp1
```

### Debug
```bash
# Verifica vazamentos de memoria
valgrind --leak-check=full --track-origins=yes -s ./theboys
```

### Limpeza
```bash
# Remove arquivos .o e executaveis
make clean
```

## 🚀 Arquivos

    .
    ├── racionais                   # funções de manipulação de racionais
    ├── tp1                         # função MAIN()
    |
    └── README.md                   

[^1]: Faculdade de **Informática Biomédica** na Universidade Federal do Paraná no ano de 2023 (segundo semestre), o curso se consiste em uma matriz de ciência da computação com matérias focadas as áreas biomédicas e aplicações da computação em áreas médicas, como genética.
