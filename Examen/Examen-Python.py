# Programa indicador de semáforo COVID con base de datos en excel
#           Por: Elisa Daniela Rios Herrera

import pandas as pd #La libreria "pandas" se especializa en el manejo y análisis de estructuras de datos
datos = pd.read_csv('bd.csv',header=0) #En esta línea pedimos al programa que lea nuestro archivo csv (base
# de datos) y que la línea del encabezado corresponde a 0

print('--- Esta es la base de datos COVID-19 ---')
print(datos) #El programa mostrará la base de datos al usuario

nombre = datos['Nombre'] #Se asignan los datos de la columna Nombre de nuestro archivo csv a una variable designada
n = list(datos['Nombre']) #Estos datos se convierten en una lista para facilitar su manejo

edad = datos['Edad'] #Se asignan los datos de la columna Edad de nuestro archivo csv a una variable designada
e = list(datos['Edad'])

indicador = datos['Indicador'] #Se asignan los datos de la columna Indicador de nuestro archivo csv a una variable designada
i = list(datos['Indicador'])

semáforo = datos['Resultado'] #Se asignan los datos de la columna Resultado de nuestro archivo csv a una variable designada
s = list(datos['Resultado'])

totalcovid = int((s.count('Tiene COVID')))
#Count se utiliza para contabilizar cuantas veces aparece tal cadena, número, etc en una lista

#Desplegamos un menú y preguntamos al usuario que desea consultar
print('¿Qué operación desea realizar?\n1) Consultar el color de semáforo covid\n2) Calcular el promedio de edad')
opción = input('Ingrese el número de opción: ')

#PARA CONSULTAR EL COLOR DE SEMÁFORO COVID
if opción == '1':
    if totalcovid == 0:
        print('El semáforo COVID se encuentra en color verde')
        print('\n ¡GRACIAS POR USAR MI PROGRAMA, TENGA UN EXCELENTE DÍA!')

    elif 1 <= totalcovid <= 30:
        print('El semáforo COVID se encuentra en color amarillo')
        print('\n ¡GRACIAS POR USAR MI PROGRAMA, TENGA UN EXCELENTE DÍA!')

    elif 31 <= totalcovid <= 70:
        print('El semáforo COVID se encuentra en color naranja')
        print('\n ¡GRACIAS POR USAR MI PROGRAMA, TENGA UN EXCELENTE DÍA!')

    elif 71 <= totalcovid <= 100:
        print('El semáforo COVID se encuentra en color rojo')
        print('\n ¡GRACIAS POR USAR MI PROGRAMA, TENGA UN EXCELENTE DÍA!')
    else:
        print('Opción inválida')

#PARA CONSULTAR EL PROMEDIO DE EDAD EN LOS REGISTRADOS
elif opción == '2':
    promedioedad = sum(edad)/100
    print(f'El promedio de edad de las personas registradas en la base de datos es de {promedioedad}')
    print('\n ¡GRACIAS POR USAR MI PROGRAMA, TENGA UN EXCELENTE DÍA!')
else:
    print('Opción inválida')











