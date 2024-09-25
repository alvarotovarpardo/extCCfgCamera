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
            
            if (stripped_line.startswith("//") or
                stripped_line.startswith("/*") or
                stripped_line.endswith("*/") or
                stripped_line.startswith("void") or
                stripped_line.startswith("}") or
                stripped_line.startswith("{")
                ): continue
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
    output_paths = [os.path.join(os.path.join(os.getcwd(), 'init_raw'), file) for file in files]
    if not os.path.exists(os.path.join(os.getcwd(), 'init_raw')):
        os.makedirs(os.path.join(os.getcwd(), 'init_raw'))
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
    fix_path = os.path.join(os.getcwd(), 'init_raw\\init_fix.txt')
    distributed_path = os.path.join(os.getcwd(), 'init_raw\\init_distributed.txt')
    analytics_path = os.path.join(os.getcwd(), 'init_raw\\init_analytics.txt')
    lite_path = os.path.join(os.getcwd(), 'init_raw\\init_lite.txt')
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
    
    output_path = os.path.join(os.getcwd(),'extendedInitDefault.cpp')
    # Escribir los parámetros únicos en el archivo de salida
    with open(output_path, 'w') as f:
        f.write('void CCfgCamGeneral::initDefault() // Change name!!\n{\n')
        f.write("\t//################## Fix ###################\n")
        for param in fix_extended_params:
            f.write(param + '\n')
        f.write("\t//################## Distributed ###################\n")
        for param in distributed_extended_params:
            f.write(param + '\n')
        f.write("\t//################### Analytics ####################\n")    
        for param in analytics_extended_params:
            f.write(param + '\n')            
        f.write("\t//##################### Lite ######################\n")    
        for param in lite_extended_params:
            f.write(param + '\n') 
        f.write("}")
    print(f"Archivo {output_path} creado con éxito.")

# Rutas de entrada de los proyectos A, B, C, D
input_files = [
    r"C:\Users\Projects\sw_redlook_Fix\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_distributed\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_analytics\gui\util\config_camera.cpp",
    r"C:\Users\Projects\sw_redlook_Lite\gui\util\config_camera.cpp"
]


# Llamada a la función para copiar el contenido
copyInitParams(input_files)
createInit()
