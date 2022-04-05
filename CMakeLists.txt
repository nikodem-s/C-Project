cmake_minimum_required(VERSION 3.20)
project(SalaNikodem-etap2)

set(CMAKE_CXX_STANDARD 14)

add_executable(SalaNikodem-etap2 main.cpp Pracownicy.h Firma.h Pracownicy.cpp Firma.cpp Programista.h Programista.cpp Administrator.cpp Administrator.h Stazysta.cpp Stazysta.h Ksiegowy.cpp Ksiegowy.h Analityk.cpp Analityk.h Firma_obsluga.cpp Firma_obsluga.h Praca_obsluga.cpp Praca_obsluga.h Wyjatki.h Wyjatki.cpp)
