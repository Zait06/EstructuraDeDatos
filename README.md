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

## Ejecutar código C

Dirigirse a la carpeta `src-c` y alojarse en la carpeta de alguna de las estructuras

```shell
cd struct/path
mkdir build
cd build
cmake ..
make
./project_name
```

## Ejecutar código Typescript

Para poder correr cualquier tipo de codigo, debemos instalar los paquetes del repositorio (se recomienda usar `yarn`). Basta con escribir la siguiente sentencia.

```shell
# Build all projects
yarn run build_ts

# Run some project
yarn run [struct]:[type]
```

Donde `[struct]` es el nombre de la esctructura y `[type]` si es `dynamic` o `static`

## Ejecutar código Python

```shell
cd struct/path
python main.py
```
