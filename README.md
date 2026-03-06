# Ticket System

Programa que simula la creación de tickets de reclamación por medio de una interfaz de comandos (CLI).

## Tecnologías
- C

## Features
- Ingreso de datos por medio de la terminal
- Validación de las entradas del usuario
- Mensajes de errores claros
- Creación archivos con IDs únicos con la informacion del ticket

## Estructura del Código

```text
.
├── include/                     # Cabeceras públicas del proyecto
│   ├── ticket/                  # Módulo relacionado con la gestión de tickets
│   │   └── ticket.h            
│   └── utils/                   # Módulo de utilidades generales y validación del proyecto
│       ├── utils.h              
│       └── validation.h         
├── src/                         # Código fuente del proyecto
├── .gitignore                   
├── compile_commands.json        # Base de datos de compilación para herramientas como clangd
├── Makefile                     
└── README.md                    
```

### Makefile

```bash
make all     # Compila todo el proyecto
make clean   # Elimina archivos generados durante la compilación
make run     # Compila y ejecuta el programa compilado
```

## Getting Started

Sigue estos pasos para clonar, compilar y ejecutar el proyecto.

```bash
# Clonar el repositorio
git clone <URL_DEL_REPOSITORIO>
cd <NOMBRE_DEL_REPOSITORIO>

# Compilar y ejecutar el programa
make run

# Limpiar archivos de compilación (opcional)
make clean
```
