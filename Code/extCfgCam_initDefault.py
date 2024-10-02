import os
import re

def extractInitParams(init_path):
    with open(init_path, 'r') as f:
        content = f.read()

    # Expresión regular para capturar el contenido de la función initDefault
    pattern = r'void\s+CCfgCamGeneral::initDefault\(\)\s*{[^}]*}'
    match = re.search(pattern, content, re.DOTALL)
    
    if match:
        return match.group(0)
    else:
        return None

# Función para leer parámetros .txt
def readParameters(file):
    with open(file,'r') as f:
        parameters = []
        for line in f:
            stripped_line = line.strip()
            print(stripped_line)
            if (stripped_line.startswith("//") or
                stripped_line.startswith("/*") or
                stripped_line.endswith("*/") or
                stripped_line.startswith("void") or
                stripped_line.startswith("}") or
                stripped_line.startswith("{")
                ): continue
            
            if 'STRCPY' in stripped_line:
                stripped_line = re.sub('STRCPY', 'strcpy_s', stripped_line)
            if 'STRNCPY' in stripped_line:
                stripped_line = re.sub('STRNCPY', 'strncpy_s', stripped_line)
            if 'Crypt' in stripped_line:
                stripped_line = '//' + stripped_line
            if 'QByte' in stripped_line:
                stripped_line = '//' + stripped_line
            if 'QString' in stripped_line:
                stripped_line = '//' + stripped_line
            
            if stripped_line and stripped_line not in parameters: # Evitamos duplicados
                parameters.append(stripped_line)
    return parameters


# Copiamos los initDefault de cada SW a un .txt 
def copyInitParams(init_path):
    files = ['init_fix.txt',
        'init_distributed.txt',
        'init_analytics.txt',
        'init_lite.txt'
    ]
    output_paths = [os.path.join(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw'), file) for file in files]
    if not os.path.exists(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw')):
        os.makedirs(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw'))
    for input_path, output_path in zip(init_path, output_paths):
        content = extractInitParams(input_path)
        if content:
            with open(output_path, 'w') as f:
                f.write(content)
            print(f"Contenido copiado a {output_path}")
        else:
            print(f"No se encontró la función initDefault en {input_path}")
    
# Creamos initDefault extendido
def createInit():
    fix_path = os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw\\init_fix.txt')
    distributed_path = os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw\\init_distributed.txt')
    analytics_path = os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw\\init_analytics.txt')
    lite_path = os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw\\init_lite.txt')
    # Leer los parámetros de los archivos
    fix_params = readParameters(fix_path)
    distributed_params = readParameters(distributed_path)
    analytics_params = readParameters(analytics_path)
    lite_params = readParameters(lite_path)
    
    # Unir parámetros sin duplicados: primero fix, luego distributed sin los de fix, luego analytics sin fix ni dist., luego lite sin los anteriores
    fix_extended_params = list(fix_params)  
    distributed_extended_params = [param for param in distributed_params if param not in fix_params]  
    analytics_extended_params = [param for param in analytics_params if param not in fix_params and param not in distributed_params]  
    lite_extended_params = [param for param in lite_params if param not in fix_params and param not in distributed_params and param not in analytics_params]
    
    output_path = os.path.join(os.getcwd(),'bin\\cpp\\initDefault\\config_camera.cpp')
    # Escribir los parámetros únicos en el archivo de salida
    with open(output_path, 'w') as f:
        f.write("#include \"config_camera.h\"\n\n\n")
        f.write('void extendedCCfgCamGeneral::initDefault() // Change name!!\n{\n')
        f.write("\n\t//################## Fix ###################\n\n")
        for param in fix_extended_params:
            f.write('\t' + param + '\n')
        f.write("\n\t//################## Distributed ###################\n\n")
        for param in distributed_extended_params:
            f.write('\t' + param + '\n')
        f.write("\n\t//################### Analytics ####################\n\n")    
        for param in analytics_extended_params:
            f.write('\t' + param + '\n')            
        f.write("\n\t//##################### Lite ######################\n\n")    
        for param in lite_extended_params:
            f.write('\t' + param + '\n') 
        f.write("}")
    print(f"Archivo {output_path} creado con éxito.")


