# Version minimale de CMake
cmake_minimum_required(VERSION 3.14)

project(TP10_SMP_Gtest LANGUAGES CXX C)

#lib standard C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

# Permet d'utiliser le module FetchContent
include(FetchContent)

# Déclaration de la dépendance GoogleTest.
FetchContent_Declare(
  googletest
  # Adresse du dépôt officiel
  GIT_REPOSITORY https://github.com/google/googletest.git

  # Version précise utilisée (bonne pratique pour éviter les surprises)
  GIT_TAG v1.17.0

  # Assure que les fichiers extraits ont un timestamp cohérent
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Ne pas construire GoogleMock si on n'en a pas besoin
# Cela accélère la compilation et simplifie le projet
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

# Télécharge et configure  GoogleTest comme s'il faisait partie du projet
FetchContent_MakeAvailable(googletest)

# Active la commande "./ctest" dans CMake.
enable_testing()


# Tous les fichiers source du dossier src
file(GLOB_RECURSE SRC_FILES "src/*.cpp") 
# Tous les fichiers des googletests  (c/c++)
file(GLOB_RECURSE GTESTS_FILES "tests/*.cpp") 

# Tous les fichiers de tests unity (c/c++)
# file(GLOB_RECURSE UNITY_TESTS_FILES "tests/*.cpp" "tests/*.c") 

# Creation de l'executable principal
add_executable(mytest.out
    ${SRC_FILES}
    ${GTESTS_FILES}
)

# Creation de l'executable de test unity
# add_executable(testAnimals
#     ${SRC_FILES} 
#     ${TESTS_FILES}
# )


# Ajout d'options de compilation spécifiques à cette cible :
# -Wall   : active la plupart des warnings
# -Wextra : warnings supplémentaires
# -pthread: nécessaire pour GoogleTest
# -g      : ajoute les symboles de debug
target_compile_options(mytest.out PRIVATE -Wall -Wextra -pthread -g)

# Liaison de l'exécutable avec GoogleTest.
# GTest::gtest_main fournit :
#   - la bibliothèque GoogleTest
#   - un main() déjà implémenté qui lance les tests
target_link_libraries(mytest.out
    GTest::gtest_main
)

# Permet d'utiliser les fonctions spécifiques à GoogleTest dans CMake.
include(GoogleTest)

# Cette commande exécute automatiquement l'exécutable de test
# pour détecter tous les tests GoogleTest qu’il contient.
# Chaque test est enregistré individuellement dans CTest.
# Cela permet d'utiliser la commande "ctest" pour les exécuter.
gtest_discover_tests(mytest.out)

# On dit à la cible 'mytest.out' d'aller chercher ses headers dans le dossier 'include'
target_include_directories(mytest.out PRIVATE include)

