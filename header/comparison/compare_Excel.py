import pandas as pd
import os

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
            

source = r"C:\CODE\extendedConfigCamera"
properties = r"C:\CODE\extendedConfigCamera\private\all_private.xlsx"
attributes = r"C:\Users\ÁlvaroTovarPardo\Desktop\Redlook_attributes.xlsx"

readExcel(source,properties, 'A:E', 'all')
readExcel(source, attributes, 'B:F', 'attributes')