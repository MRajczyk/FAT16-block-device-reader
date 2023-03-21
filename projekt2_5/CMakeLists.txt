#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2021-12-19 22:07:55.795729
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-Werror=vla"
      "-ggdb3"
      "-fdiagnostics-color"
      "-pedantic"
      "-fmax-errors=5"
      "-Wno-error=unused-parameter"
      "-Wno-parentheses"
      "-DINSIDE_DANTE"
      "-D_GNU_SOURCE"
      "-xc"
      "-D_ANSI_OUTPUT"
      "-Wextra"
      "-std=c11"
      "-Wno-error=parentheses"
      "-Wall"
      "-Werror"
      "-Wno-error=implicit-fallthrough"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-cref"
        "-Wl,-Map=main.map"
        "-ggdb3"
        "-Wl,-wrap,main"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "2_5.c"
        "file_reader.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)