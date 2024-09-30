import os
import shutil
import re
import pandas as pd

def isolateClasses(input_files):
    raw_folder_location = os.path.join(os.getcwd(), 'bin', 'header', 'build', 'classes_raw')
    
    # Crear la carpeta si no existe
    if not os.path.exists(raw_folder_location):
        os.makedirs(raw_folder_location)

    # Lista de archivos de salida
    output_files = [
        os.path.join(raw_folder_location, 'CCfg_fix.txt'),
        os.path.join(raw_folder_location, 'CCfg_distributed.txt'),
        os.path.join(raw_folder_location, 'CCfg_analytics.txt'),
        os.path.join(raw_folder_location, 'CCfg_lite.txt')
    ]

    # Procesar cada archivo de entrada con su archivo de salida correspondiente
    for input_file, output_file in zip(input_files, output_files):
        with open(input_file, 'r', encoding='utf-8') as file:
            lines = file.readlines()
            
        # Localizar la clase CCfgCamGeneral
        inside_class = False
        class_content = []
        for line in lines:
            # Inicia el bloque de la clase
            if 'class CCfgCamGeneral' in line:
                inside_class = True

            if inside_class:
                class_content.append(line)

                # Si se ha alcanzado el final de la clase con el cierre `};`
                if line.startswith('};'):
                    break

        # Escribir el contenido completo de la clase en el archivo de salida
        if inside_class:
            with open(output_file, 'w', encoding='utf-8') as output:
                output.write(''.join(class_content))
        else:
            print(f'No se encontró la clase CCfgCamGeneral en {input_file}.')
        
    print(f"Classes extracted in {raw_folder_location}")
###############################################################################
###############################################################################

def isolatePrivate():
    source = os.path.join(os.getcwd(), 'bin', 'header', 'build', 'classes_raw')
    class_files = []
    for file in os.listdir(source):
        if file.endswith('.txt'):
            class_files.append(os.path.join(source, file))

    output_files = ['private_fix.txt', 'private_distributed.txt', 'private_analytics.txt', 'private_lite.txt']
    output_path = os.path.join(os.getcwd(), 'bin', 'header', 'private', 'private_raw')

    # Crear la carpeta si no existe
    if not os.path.exists(output_path):
        os.makedirs(output_path)

    def findPrivate(file):
        flag = False
        private_content = []
        with open(file, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            for line in lines:
                if line.startswith('};'):
                    break
                if flag:
                    if ' [' in line:
                        line = re.sub(r' \[', '[', line)
                    private_content.append(line)
                if 'private:' in line:
                    flag = True
        return private_content
    
    def writePrivate(output_file):
        private_content = findPrivate(files)
        with open(write_path, 'w', encoding='utf-8') as f:
            f.write(''.join(private_content))  # Convertir la lista a una cadena
    
    for files in class_files:
        if 'fix' in files:
            write_path = os.path.join(output_path, output_files[0])
            writePrivate(write_path)
        if 'distributed' in files:
            write_path = os.path.join(output_path, output_files[1])
            writePrivate(write_path)
        if 'analytics' in files:
            write_path = os.path.join(output_path, output_files[2])
            writePrivate(write_path)
        if 'lite' in files:
            write_path = os.path.join(output_path, output_files[3])
            writePrivate(write_path)
    
    print(f"Properties classified in {output_path}")
###############################################################################
def isolatePublic():
    source = os.path.join(os.getcwd(), 'bin', 'header', 'build', 'classes_raw')
    class_files = []
    for file in os.listdir(source):
        if file.endswith('.txt'):
            class_files.append(os.path.join(source, file))

    output_files = ['public_fix.txt', 'public_distributed.txt', 'public_analytics.txt', 'public_lite.txt']
    output_path = os.path.join(os.getcwd(), 'bin','header', 'public', 'public_raw')

    # Crear la carpeta si no existe
    if not os.path.exists(output_path):
        os.makedirs(output_path)

    def findpublic(file):
        flag = False
        public_content = []
        with open(file, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            for line in lines:
                if line.startswith('private:'):
                    break
                if flag:
                    public_content.append(line)
                if 'public:' in line:
                    flag = True
        return public_content
    
    def writepublic(output_file):
        public_content = findpublic(files)
        with open(write_path, 'w', encoding='utf-8') as f:
            f.write(''.join(public_content))  # Convertir la lista a una cadena
    
    for files in class_files:
        if 'fix' in files:
            write_path = os.path.join(output_path, output_files[0])
            writepublic(write_path)
        if 'distributed' in files:
            write_path = os.path.join(output_path, output_files[1])
            writepublic(write_path)
        if 'analytics' in files:
            write_path = os.path.join(output_path, output_files[2])
            writepublic(write_path)
        if 'lite' in files:
            write_path = os.path.join(output_path, output_files[3])
            writepublic(write_path)
    
    print(f"Methods classified in {output_path}")
##############################################################################

def copyFilesToC_Code():
        current_dir = os.getcwd()

        c_folder = os.path.join(current_dir, 'C_code')

        header_file = os.path.join(current_dir, 'bin\\header\\config_camera.h')
        cpp_file = os.path.join(current_dir, 'bin\\cpp\\initDefault\\config_camera.cpp')
        header_config_base = os.path.join(current_dir, 'bin\\config_base\\config_base.h')
        cpp_config_base = os.path.join(current_dir,'bin\\config_base\\config_base.cpp')

        # Verifica si los archivos existen y realiza la copia
        if not os.path.exists(c_folder):
            os.makedirs(c_folder)
        if os.path.exists(header_file):
            shutil.copy(header_file, c_folder)
            print(f"'{header_file}' copiado a {c_folder}")
        else:
            print(f"'{header_file}' not found.")
        if os.path.exists(cpp_file):
            shutil.copy(cpp_file, c_folder)
            print(f"'{cpp_file}' copiado a {c_folder}")
        else:
            print(f"'{cpp_file}' not found.")            
        if os.path.exists(header_config_base):
            shutil.copy(header_config_base, c_folder)
            print(f"'{header_config_base}' copiado a {c_folder}")
        else:
            print(f"'{header_config_base}' not found.")
        if os.path.exists(cpp_config_base):
            shutil.copy(cpp_config_base, c_folder)
            print(f"'{cpp_config_base}' copiado a {c_folder}")
        else:
            print(f"'{cpp_config_base}' not found.")

        print(f"C code copied to {c_folder}")
###########################  CONFIG BASE  #####################################
def readConfigBaseHeader(input_file):
    with open(input_file, 'r') as f:
        content = f.read()

    # Capturar el contenido de la clase CCfgClass
    match = re.search(r'class\s+CCfgClass\s*{(?:[^{}]*|{[^{}]*})*};', content, re.DOTALL)
    return match.group(0) if match else None

def createConfigBaseHeader(input_paths):
    output_dir = os.path.join(os.getcwd(), 'bin\\config_base')
    os.makedirs(output_dir, exist_ok=True)

    files = ['config_base.h']

    # Procesar cada archivo de entrada
    for input_path, file_name in zip(input_paths, files):
        content = readConfigBaseHeader(input_path)
        if content:
            with open(os.path.join(output_dir, file_name), 'w') as f:
                f.write("#ifndef CCONFIG_BASE_H_\n#define CCONFIG_BASE_H_\n\n")
                f.write("#define CFGCLASS_MAX_NAME 20\n\n\n")
                f.write(content)
                f.write("\n\n\n#endif /* CCONFIG_BASE_H_ */")
        else:
            print(f"No se encontró la clase CCfgClass en {input_path}")
    
    print(f"File 'config_base.h' created in {output_dir}")

def readConfigBaseCpp(input_file):
    with open(input_file, 'r') as f:
        content = f.read()

    # Expresión regular para capturar solo el constructor y el destructor de CCfgClass
    pattern = r'CCfgClass::CCfgClass\(.*?\)\s*{[^}]*}|CCfgClass::~CCfgClass\(.*?\)\s*{[^}]*}'
    matches = re.findall(pattern, content, re.DOTALL)
    return "\n\n".join(matches) if matches else None    

def createConfigBaseCpp(input_paths):
    output_dir = os.path.join(os.getcwd(), 'bin\\config_base')
    os.makedirs(output_dir, exist_ok=True)

    files = ['config_base.cpp']

    # Procesar cada archivo de entrada
    for input_path, file_name in zip(input_paths, files):
        content = readConfigBaseCpp(input_path)
        if content:
            with open(os.path.join(output_dir, file_name), 'w') as f:
                f.write("#include 'config_base.h'\n\n")
                f.write(content)
            print(f"Constructor y destructor copiados a {file_name}")
        else:
            print(f"No se encontraron el constructor o destructor en {input_path}")

    print(f"File 'config_base.cpp' created in {output_dir}")



##############################################################################
########################### COMPARAR ATRIBUTOS ###############################
##############################################################################
def clean_attribute_name(attr_name):
    # Eliminar cualquier carácter no alfanumérico como punto y coma, espacios, etc.
    return re.sub(r'[^\w]', '', attr_name)

def compareExcel(attributes_path):
    properties_path = os.path.join(os.getcwd(), 'bin', 'header', 'private', 'all_private_SWs.xlsx')
    #def compare_excel_attributes(properties_path, attributes_path):
        # Leer las columnas necesarias de los dos archivos de Excel
    df1 = pd.read_excel(properties_path, usecols='A:E')  # 'A:E' de all_private_SWs
    df2 = pd.read_excel(attributes_path, usecols='B:F')  # 'B:F' de Redlook_attributes
    
    # Limpiar los nombres de atributos
    df1['Atributo'] = df1['Atributo'].apply(lambda x: re.sub(r'\[+.+\]', '', str(x)).strip())
    df2['Atributo'] = df2['Atributo'].apply(lambda x: re.sub(r'\[+.+\]', '', str(x)).strip())
    
    
    # Limpiar y normalizar los nombres de los atributos (sin caracteres especiales y en minúsculas)
    df1['Atributo'] = df1['Atributo'].apply(clean_attribute_name)
    df2['Atributo'] = df2['Atributo'].apply(clean_attribute_name)
    
        
    # Crear diccionarios para una comparación más rápida
    attributes1 = df1.set_index('Atributo').T.to_dict('list')
    attributes2 = df2.set_index('Atributo').T.to_dict('list')
    
    # Comparar atributos y generar la salida
    differences = []
    for attr, values1 in attributes1.items():
        if attr not in attributes2:
            differences.append(f"{attr} // Attribute missing in .CAM")
        else:
            values2 = attributes2[attr]
            if values1 != values2:
                differences.append(f"{attr} // Numbers differ: PRIVATE {values1} vs CAM {values2}")
    
    for attr in attributes2:
        if attr not in attributes1:
            differences.append(f"{attr} // Attribute missing in PRIVATE")
    
    output_path = os.path.join(os.getcwd(), 'bin', 'comparison', 'compare.txt')
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    # Guardar las diferencias en el archivo de salida
    with open(output_path, 'w') as output_file:
        output_file.write("CAM = Redlook_attributes.xlsx\nPRIVATE = properties extracted from classes\n\n\n")
        for line in differences:
            output_file.write(line + '\n')
    
    print(f"Comparation between attributes stored in {output_path}.")



