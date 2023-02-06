# Estructura de datos

Este repositorio se hizo con el propósito de darle a los curiosos de la programación un lugar más dónde puedan investigar e interactuar con algunas estrcuturas de datos.

Las estructuras están programadas en los siguientes lenguajes de programación:

- C
- Typescript
- Python

Para saber el contenido de este repositorio, puede ver el [temario](/docs/README.md) de este repositorio

## Prerequisitos

- Compilador C
- CMake
- Node.js >= 16

## Ejecutar código c

al código fuente de alguna de las estructuras y ejecuta la siguiente

```sh
mkdir build
cd build
cmake ..
make
./project_name
```

Dónde `name` es el nombre del ejecutable de cada una de las estructuras. Puedes ver mas informacion en cada archivo de configuración `CMakeLists.txt`.

## Ejecutar codigo typescript

Para poder correr cualquier tipo de codigo, debemos instalar los paquetes del repositorio (se recomienda usar `yarn`). Basta con escribir la siguiente sentencia.

```shell
    yarn run [struct]:[type]
```

Donde `[struct]` es el nombre de la esctructura y `[type]` si es `dynamic` o `static`
