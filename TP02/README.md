# Trabajo Práctico Número 2

## Uso del repositorio

Este repositorio utiliza [pre-commit](https://pre-commit.com) para validaciones de formato. Para trabajar con el mismo usted debería tener instalado:

1. pre-commit (https://pre-commit.com/#install)

Después de clonar el repositorio usted debería ejecutar el siguiente comando:

```
sudo apt install git
sudo apt install clang-format
sudo apt install pre-commit
sudo apt install valgrind
sudo apt install doxygen
sudo apt install ruby
sudo gem install ceedling
```

Para activar ceedling primero ejectura el siguiente comando:
```
ceedling new TP02
```

E ingresar a esa carpeta.

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc
```

Para compilar el proyecto TP02 se utiliza el siguiente comando:

```
make all
```

## License

This work is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.
