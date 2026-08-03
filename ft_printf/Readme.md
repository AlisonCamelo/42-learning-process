# 🖨️ ft_printf — Progressive Learning & Variadic Functions Log

This directory documents my step-by-step implementation of `ft_printf`, a custom re-creation of standard C's `printf` function for the 42 School curriculum.

The core challenge of this project is mastering **variadic functions** (handling an unknown number of arguments at runtime) and managing **formatted output conversion**.

---

## 🧠 Core Architecture & Mental Model

`ft_printf` parses a format string character-by-character. Regular characters are written directly to stdout, while `%` triggers a specifier handler that extracts the next argument from `stdarg` macros.


```

+-------------------------------------------------------------------+
|                        FT_PRINTF LIFECYCLE                        |
|                                                                   |
| 1. PARSE FORMAT STRING:                                           |
|    "Hello %s, num: %d\n" ---> Loop through each character         |
|                                                                   |
| 2. DETECT SPECIFIER (%):                                          |
|    Found '%' ---> Read next char ('s') ---> Call specifier handler|
|                                                                   |
| 3. VA_ARG EXTRACTION:                                             |
|    va_arg(args, char *) ---> Extract "Alison" ---> write & count  |
|                                                                   |
| 4. RETURN TOTAL COUNT:                                            |
|    Accumulate bytes printed and return total count to caller.     |
+-------------------------------------------------------------------+

```

---

## 🛠️ Supported Specifiers

| Specifier | Description | Handled Types | Key Consideration |
| :---: | :--- | :--- | :--- |
| **`%c`** | Single character | `int` (promoted) | Writes 1 byte to stdout |
| **`%s`** | String of characters | `char *` | Handles `(null)` safely if pointer is NULL |
| **`%p`** | Pointer address | `void *` | Formats as `0x...` in base 16 (hexadecimal lowercase) |
| **`%d` / `%i`** | Signed integer | `int` | Handles negative numbers (`-`) and `INT_MIN` |
| **`%u`** | Unsigned integer | `unsigned int` | Base 10 arithmetic without negative values |
| **`%x`** | Hexadecimal lowercase | `unsigned int` | Base 16 conversion (`0123456789abcdef`) |
| **`%X`** | Hexadecimal uppercase | `unsigned int` | Base 16 conversion (`0123456789ABCDEF`) |
| **`%%`** | Percent sign | None | Writes literal `%` to stdout |

---

## 📚 Key Concepts & Variadic Macros (`<stdarg.h>`)

### 1. The Variadic Lifecycle
```c
#include <stdarg.h>

va_list args;          // 1. Declare the argument pointer
va_start(args, format);// 2. Initialize pointer right after fixed param
va_arg(args, int);     // 3. Extract the next argument specifying type
va_end(args);          // 4. Clean up the memory stack

```

### 2. Type Promotions in `va_arg`

* `char` and `short` are automatically promoted to `int` when passed through variadic arguments (`...`). Therefore, for `%c`, we extract using `va_arg(args, int)`.
* Pointers require casting to `uintptr_t` (or `unsigned long`) to safely handle 64-bit addresses during base 16 conversions.

---

## 🎨 Diagrams & Visual Schematics

Visual architectures for the variadic argument stack and specifier routing are located in the assets folder:

* Diagrams: `assets/ft_printf_stack.png`
* Excalidraw Source: `assets/ft_printf_stack.excalidraw`

```

```