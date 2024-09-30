import pandas as pd
import os
import re

# Genero dos .txt con todos los atributos de los .cam y de las properties de las clases
def readExcel(source, excel_path, cols, program):

    df = pd.read_excel(excel_path, usecols = cols)

    output_path = os.path.join(source, r'comparison')
    os.makedirs(output_path, exist_ok=True)

    output_file = os.path.join(output_path, f'clasificacion_{program}.txt')
    
    # Abrir el archivo de salida
    with open(output_file, 'w') as f:
        # Escribir la cabecera
        f.write('Atributo,Fix,Distributed,Analytics,Lite\n')
        
        # Iterar sobre las filas del DataFrame
        for _, row in df.iterrows():
            atributo = str(row['Atributo'])  # Convertir el atributo a cadena
            fix = 1 if row['Fix'] == 1 else 0
            distributed = 1 if row['Distributed'] == 1 else 0
            analytics = 1 if row['Analytics'] == 1 else 0
            lite = 1 if row['Lite'] == 1 else 0
            
            # Escribir la línea en el archivo de salida
            f.write(f'{atributo},{fix},{distributed},{analytics},{lite}\n')
            
def cleanParenthesis(attr_name):
    return re.sub(r'\[+.+\]', '', attr_name).strip()

# Comparo los dos .txt y genero un tercero con las diferencias 
def compare_attributes():
    attributes1 = {}
    attributes2 = {}
    file1_path = os.path.join(os.getcwd(),'comparison\\clasificacion_all.txt')
    file2_path = os.path.join(os.getcwd(),'comparison\\clasificacion_attributes.txt')
    output_path = os.path.join(os.getcwd(),'comparison\\all.txt')
    with open(file1_path, 'r') as file1:
        for line in file1:
            parts = line.strip().split(',')
            if parts:
                attribute_name = cleanParenthesis(parts[0])
                numbers = parts[1:]
                attributes1[attribute_name] = numbers

    with open(file2_path, 'r') as file2:
        for line in file2:
            parts = line.strip().split(',')
            if parts:
                attribute_name = cleanParenthesis(parts[0])
                numbers = parts[1:]
                attributes2[attribute_name] = numbers

    # Comparar los atributos y generar la salida
    with open(output_path, 'w') as output_file:
        # Atributos que están en file1 pero no en file2
        for attr in attributes1:
            if attr not in attributes2:
                output_file.write(f"{attr} // Attribute missing\n")
            else:
                # Comprobar si los números son diferentes
                if attributes1[attr] != attributes2[attr]:
                    output_file.write(f"{attr} // Numbers differ: {attributes1[attr]} vs {attributes2[attr]}\n")

        # Atributos que están en file2 pero no en file1
        for attr in attributes2:
            if attr not in attributes1:
                output_file.write(f"{attr} // Attribute missing\n")

source = r"C:\CODE\extendedConfigCamera"
properties = r"C:\CODE\extendedConfigCamera\header\private\all_private.xlsx"
attributes = r"C:\Users\ÁlvaroTovarPardo\Desktop\Redlook_attributes.xlsx"

readExcel(source,properties, 'A:E', 'all')
readExcel(source, attributes, 'B:F', 'attributes')

compare_attributes()