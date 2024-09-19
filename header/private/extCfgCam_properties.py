import os
import re
import openpyxl
import itertools
import pandas as pd
import shutil

def cleanClass(line):
    # Eliminamos comentarios en línea y limpiamos espacios
    line = re.sub(r'/\*.*\*/', '', line).strip()

    # RE para capturar el tipo de dato y las variables
    patron = r'(\w[\w\s\*]+)\s+([\w\s,=\[\]\+\(\)]+);'
    coincidence = re.match(patron, line)

    if coincidence:
        type_data = coincidence.group(1).strip()
        data = coincidence.group(2).strip()

        # Separamos las variables por comas, eliminando espacios adicionales
        variables = [var.strip() for var in re.split(r'\s*,\s*', data) if var.strip()]

        separated_lines = [f"{type_data} {var};" for var in variables if var]

        # Crear una lista con solo los nombres de las variables, sin prefijos
        variable_names = [re.sub(r'^m_[a-z]+', '', var.split('=')[0].strip()) for var in variables]
        variable_names = [name[0].upper() + name[1:] if name else '' for name in variable_names]

        return separated_lines, variable_names
    else:
        return [line], []



def processClean():
    source = os.path.join(os.getcwd(),'private')
    output_folder = os.path.join(source, r'build\private_clean')
    output_folder_names = os.path.join(source, r'build\private_reduced')
    source_folder = os.path.join(source, 'private_raw')

    for folder in [output_folder, output_folder_names]:
        if not os.path.exists(folder):
            os.makedirs(folder)

    for file in os.listdir(source_folder):
        if file.endswith('.txt'):
            source_file = os.path.join(source_folder, file)
            output_file = os.path.join(output_folder, file)
            output_file_names = os.path.join(output_folder_names, file)

            with open(source_file, 'r') as file_in, \
                 open(output_file, 'w') as file_out, \
                 open(output_file_names, 'w') as file_out_names:
                for line in file_in:
                    # Ignorar líneas de comentarios si las hubiera
                    if re.match(r'^\s*/\*.*\*/\s*$', line):
                        continue

                    new_lines, variable_names = cleanClass(line)
                    for new_line in new_lines:
                        file_out.write(new_line + '\n')
                    for var_name in variable_names:
                        if var_name:  # Asegurarse de que el nombre no esté vacío
                            file_out_names.write(var_name + ';\n')



def masterAttributes(sort = True):
    source = os.path.join(os.getcwd(),'private')
    if sort:
        source_folder = os.path.join(source, r'build\private_reduced')
        private_sorted_folder = os.path.join(source, r'build\private_sorted')
        all_private_file = os.path.join(source, 'all_private.txt')
    else:
        source_folder = os.path.join(source,r'build\private_clean')
        private_sorted_folder = os.path.join(source, r'build\private_sorted')
        all_private_file = os.path.join(source, 'all_private.txt')

    if not os.path.exists(private_sorted_folder):
        os.makedirs(private_sorted_folder)
    
    atributos_unicos = set()

    for archivo in os.listdir(source_folder):
        if archivo.endswith('.txt'):
            ruta_archivo = os.path.join(source_folder, archivo)
            with open(ruta_archivo, 'r') as f:
                atributos = f.readlines()
            
            atributos = [atributo.strip() for atributo in atributos]
            atributos_ordenados = sorted(atributos)
            
            archivo_sorted = os.path.join(private_sorted_folder, f'ordenado_{archivo}')
            with open(archivo_sorted, 'w') as f_sorted:
                for atributo in atributos_ordenados:
                    f_sorted.write(atributo + '\n')
            
            atributos_unicos.update(atributos_ordenados)

    with open(all_private_file, 'w') as f_all:
        for atributo in sorted(atributos_unicos):
            f_all.write(atributo + '\n')




def tableAttributes(sort = True):
    source = os.path.join(os.getcwd(),'private')
    all_private_file = os.path.join(source, 'all_private.txt')
    if sort:
        private_reduced_folder = os.path.join(source, r'build\private_reduced')
    else:
        private_reduced_folder = os.path.join(source, r'build\private_clean')
    archivo_excel = os.path.join(source, 'all_private_SWs.xlsx')  

    with open(all_private_file, 'r') as f:
        atributos = [linea.strip() for linea in f.readlines()]

    wb = openpyxl.Workbook()
    ws = wb.active


    columnas = ['Atributo', 'Fix', 'Distributed', 'Analytics', 'Lite']
    ws.append(columnas)


    archivos_reduced = {
        'Fix': os.path.join(private_reduced_folder, 'private_fix.txt'),
        'Distributed': os.path.join(private_reduced_folder, 'private_distributed.txt'),
        'Analytics': os.path.join(private_reduced_folder, 'private_analytics.txt'),
        'Lite': os.path.join(private_reduced_folder, 'private_lite.txt')
    }


    atributos_por_archivo = {}
    for key, ruta_archivo in archivos_reduced.items():
        if os.path.exists(ruta_archivo):
            with open(ruta_archivo, 'r') as f:
                atributos_por_archivo[key] = set([linea.strip() for linea in f.readlines()])
        else:
            atributos_por_archivo[key] = set()


    for atributo in atributos:
        fila = [atributo]
        for key in ['Fix', 'Distributed', 'Analytics', 'Lite']:
            if atributo in atributos_por_archivo[key]:
                fila.append(1)
            else:
                fila.append(0)
        ws.append(fila)


    wb.save(archivo_excel)

    print(f"Excel succesfully generated at {archivo_excel}.")
    
        
 
        
 
def readExcel():
    source = os.path.join(os.getcwd(),'private')
    excel_path = os.path.join(source,'all_private_SWs.xlsx')
    df = pd.read_excel(excel_path, usecols='A:E')

    output_path = os.path.join(os.path.dirname(excel_path), r'build\private_classified')
    os.makedirs(output_path, exist_ok=True)

    # Diccionario para almacenar los atributos clasificados
    clasificacion = {}

    for _, row in df.iterrows():
        atributo = str(row['Atributo'])  # Convertir el atributo a cadena
        categorias = tuple(col for col in ['Fix', 'Distributed', 'Analytics', 'Lite'] if row[col] == 1)
        clasificacion[atributo] = categorias

    def escribir_archivo(nombre, atributos):
        with open(os.path.join(output_path, f'{nombre}.txt'), 'w') as f:
            for atributo in sorted(atributos):  # Ahora todos son cadenas
                f.write(f'{atributo}\n')

    clasificacion_inversa = {}
    for atributo, cats in clasificacion.items():
        if cats not in clasificacion_inversa:
            clasificacion_inversa[cats] = []
        clasificacion_inversa[cats].append(atributo)


    for cats, atributos in clasificacion_inversa.items():
        nombre_archivo = '_'.join(cats).lower() if cats else 'sin_categoria'
        escribir_archivo(nombre_archivo, atributos)




def read_txt_file(file_path):
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            return [line.strip() for line in file if line.strip()]
    return []





def write_header_file():
    source = os.path.join(os.getcwd(),'private')
    programs = ['fix', 'distributed', 'analytics', 'lite']
    input_dir = os.path.join(source, r'build\private_classified')
    output_file = os.path.join(source,'extCfgCam_properties.h')
    sections = {}
    for r in range(1, len(programs) + 1):  
        for combination in itertools.combinations(programs, r):
            file_name = '_'.join(combination) + '.txt'
            sections['_'.join(combination)] = read_txt_file(os.path.join(input_dir, file_name))
            
    flag = 0
    
    with open(output_file, 'w') as file:
        file.write("class extendedCCfgCamGeneral\n{\nprivate:\n")
        
        for r in range(len(programs), 0, -1):  
            for combination in itertools.combinations(programs, r):
                section_name = '_'.join(combination)
                
                if r == 4:
                    file.write("\n\t/**************************************/\n")
                    file.write("\t/*******   COMMON PROPERTIES   *******/\n")
                    file.write("\t/**************************************/\n\n")
                elif r == 1 and flag == 0:
                    file.write("\n\t/**************************************/\n")
                    file.write("\t/******   SPECIFIC PROPERTIES   ******/\n")
                    file.write("\t/**************************************/\n\n") 
                    flag = 1
                file.write(f"\n\t/*******   {' & '.join(combination)}   *******/\n\n")
                for item in sections.get(section_name, []):
                    file.write(f"\t{item}\n")
        
        file.write("public:\n\textendedCCfgCamGeneral()\n};")
        print(f"Properties extracted and saved in {output_file}")


def deleteBuildFolder(delete = True):
    source = os.path.join(os.getcwd(),'private')
    if delete:
        binFolder = os.path.join(source, 'build')
        if os.path.exists(binFolder):
            try:
                shutil.rmtree(binFolder)
                print(f'{binFolder} removed.')
            except Exception as e:
                print(f"Error {e}")
        else:
            print(f"No Build folder in {source}")
            
            
##########################################################################################################
##########################################################################################################





